#ifndef __DxLibInterFace
#define __DxLibInterFace
class DxLibInterFace{
public:
	virtual int	init()			=0;
	virtual void	update()		=0;
	virtual void	draw()		=0;
	virtual void	finish()		=0;
	//���z�f�X�g���N�^
	virtual ~DxLibInterFace(){};
};

#endif