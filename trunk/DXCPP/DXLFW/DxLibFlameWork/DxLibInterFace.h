#ifndef __DxLibInterFace
#define __DxLibInterFace
#include "../Define/DefineManager.h"
class DxLibInterFace{
public:
	virtual int	init()			=0;
	virtual void	update()		=0;
	virtual void	draw()		=0;
	virtual void	finish()		=0;
	//仮想デストラクタ
	virtual ~DxLibInterFace(){};
};

#endif