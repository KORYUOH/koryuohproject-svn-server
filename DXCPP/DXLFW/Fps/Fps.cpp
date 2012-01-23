#include	<Fps/Fps.h>
#include	<../Include/DxLib.h>

int FPS_Ctrl::Phase_first(const int t){
	if(m_fpsCount != 0)
		return (int)(m_count0t+m_fpsCount*(1000.0/FPS_DEFINE))-GetNowCount();
	if(t == 0)
		return 0;
	return m_count0t+1000-GetNowCount();
}

int FPS_Ctrl::CreateBase(const int t){
	int gnt = GetNowCount();
	if(m_fpsCount ==0)
		m_count0t = gnt;
	m_f[m_fpsCount] = gnt -t;
	return gnt;
}

void FPS_Ctrl::calc_ave(){
	if(m_fpsCount != FPS_DEFINE-1)
		return;

	m_average = 0;

	for(int i=0;i<FPS_DEFINE;i++)
		m_average +=m_f[i];
	m_average/=FPS_DEFINE;
}

void FPS_Ctrl::fps_wait(){
	int term;
	static int t = 0;
	term = Phase_first(t);

	if(m_average >59.0)
		if(term>0)//Wait
			Sleep(term);

	t = CreateBase(t);

	calc_ave();

	m_fpsCount = (++m_fpsCount)%FPS_DEFINE;

}

void FPS_Ctrl::draw_fps(int x,int y){
	if(m_average != 0)
		DrawFormatString(x,y,GetColor(255,255,255),"[%.1f]",1000/m_average);
	return;
}