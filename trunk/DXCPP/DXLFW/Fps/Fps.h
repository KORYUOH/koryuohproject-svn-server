/**===File Commentary=======================================*/
/**
 *	@file	Fps.h
 *
 *	@brief	FPSí≤êÆ
 *
 *	@author	KORYUOH
 *
 *	@date	2012/01/01
 */
/**===Include Guard========================================*/
#ifndef	__Fps_Contorol
#define	__Fps_Contorol
/**===File Include=========================================*/
#define FPS_DEFINE 60
/**===Class Definition=======================================*/
class FPS_Ctrl{
private:
	int m_fpsCount,m_count0t;
	int m_f[FPS_DEFINE];
	double m_average;

private:
	FPS_Ctrl():m_fpsCount(0),m_count0t(0),m_average(0.0f){};
public:
	virtual ~FPS_Ctrl(){};

	static FPS_Ctrl& getInstance(){
		static FPS_Ctrl Instance;
		return Instance;
	}

public:
	void fps_wait();
	void draw_fps(int x,int y);
private:
	void calc_ave();
	int Phase_first(const int t);
	int CreateBase(const int t);
};


#endif	//__Fps_Contorol
