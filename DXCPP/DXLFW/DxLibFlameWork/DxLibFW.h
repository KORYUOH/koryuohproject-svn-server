#ifndef __DxLibFW
#define __DxLibFW
#include	 "../../Include/DxLib.h"
#include	 "DxLibInterFace.h"
#include	<string>
class DXFW:public DxLibInterFace{
private:
	bool m_isWindowMode;
	std::string m_WindowTitle;
	bool m_isOutLog;
public:
	DXFW():
		m_isWindowMode(WINDOW_MODE),
		m_WindowTitle(APPLICATIONTITLE),
		m_isOutLog(OUTLOGFILE){};
	void run();
	virtual ~DXFW(){};
private:
	int		init();
	void	update();
	void	draw();
	void	finish();
	int ProcessLoop();
	void MessegeBox();
};
#endif
