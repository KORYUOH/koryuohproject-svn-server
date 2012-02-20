#ifndef __DxLibInterFace
#define __DxLibInterFace
#include	<Define/DefineManager.h>
class DxLibInterFace{
public:
	virtual void	run()			=0;
protected:
	//仮想デストラクタ
	virtual ~DxLibInterFace(){};
};

#endif