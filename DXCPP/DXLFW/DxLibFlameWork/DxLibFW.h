#ifndef __DxLibFW
#define __DxLibFW
#include "../Define/DefineManager.h"
#include "../../Include/DxLib.h"
#include "DxLibInterFace.h"
#include "../Key/KeyManager.h"

class DXFW:public DxLibInterFace{
public:
	void run();
private:
	int		init();
	void	update();
	void	draw();
	void	finish();
	int ProcessLoop();
	void MessegeBox();
};
#endif
