#ifndef __DxLibFW
#define __DxLibFW
#include "../../Include/DxLib.h"
#include "DxLibInterFace.h"
#include "../Key/KeyManager.h"

class DXFW:public DxLibInterFace{
private:
	bool m_isWindowMode;
public:
	DXFW():m_isWindowMode(WINDOW_MODE){};
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
