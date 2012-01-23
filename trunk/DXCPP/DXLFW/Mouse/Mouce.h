#ifndef _MOUCE_H_INCLUDED_
#define _MOUCE_H_INCLUDED_
#include	<../Include/DxLib.h>
#include	<Define/DefineManager.h>

class Mouse{
private:
	Mouse():m_Dispflag(false),m_pos_x(0),m_pos_y(0){};
	Mouse(const Mouse& it);
	Mouse&  operator = (const Mouse& are);
public:
	virtual ~Mouse(){};
private:
	bool m_Dispflag;
	int m_pos_x,m_pos_y;
public:
	static Mouse& getInstance(){
		static Mouse Instance;
		return Instance;
	}

public:
	void setMouseCursolDispFlag(bool flag);
	void MousePositionUpdate();
	bool onClick();
	bool onClickR();
	bool onClickM();
	bool onClickInRect(Rect accept);
	bool onClickInCircle(Circle accept);
private:
	bool CheckRect(Rect accept);
};
#endif // _MOUCE_H_INCLUDED_
