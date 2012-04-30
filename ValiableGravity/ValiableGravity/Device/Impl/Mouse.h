/**===File Commentary=======================================*/
/**
 *	@file	GL_Mouse.h
 *
 *	@brief	OpenGL�}�E�X�N���X
 *
 *	@author	KORYUOH
 *
 *	@date	2012/04/29
 */
/**===Include Guard========================================*/
#ifndef	_GL_MOUSE_H_
#define	_GL_MOUSE_H_
/**===File Include=========================================*/
#include	<gslib.h>
#include	<Device/IDevice.h>
/**===Class Definition=====================================*/
class GLMouse:public IDevice{
public
	/**
	 *	@brief	�R���X�g���N�^
	 *	@author	KORYUOH
	 */:
	GLMouse();
	/**
	 *	@brief	�f�X�g���N�^
	 *	@author	KORYUOH
	 */
	virtual ~GLMouse(){};
	/**
	 *	@brief	�X�V����
	 *	@author	KORYUOH
	 */
	virtual void update(void);
	/**
	 *	test
	 */
	virtual GLMouse& getInstance(){
		return *this;
	}
	/**
	 *	@brief	�N���b�N����Ă��邩�H
	 *	@param[in]	�{�^��
	 *	@param[in]	���
	 *	@author	KORYUOH
	 *	@return	button��state�Ȃ�ΐ^
	 */
	bool MouseClick(int button,int state)const;
	/**
	 *	@brief	�Փ˔���
	 *	@param[in]	����͈�
	 *	@param[in]	�{�^��
	 *	@param[in]	���
	 *	@author	KORYUOH
	 *	@return	������Ń{�^���������ԂȂ�^
	 */
	bool MouseCollision(GSrect& rect,int button,int state)const;
	/**
	 *	@brief	�}�E�X�ʒu�̎擾
	 *	@author	KORYUOH
	 *	@return	�}�E�X�̈ʒu
	 */
	GSvector2 getMousePosition()const;
private:
	/**
	 *	@brief	�R�[���o�b�N�֐�
	 *	@param[in]	�{�^��
	 *	@param[in]	���
	 *	@param[in]	x���W
	 *	@param[in]	y���W
	 *	@note	
	 *	[ button ]
	 *	GLUT_LEFT_BUTTON�F�u���{�^���v
	 *	GLUT_MIDDLE_BUTTON�F�u�����{�^���v
	 *	GLUT_RIGHT_BUTTON�F�u�E�{�^���v
	 *	
	 *	[ state ]
	 *	GLUT_DOWN�F�u�{�^���v���u�����ꂽ�v
	 *	GLUT_UP�F�u�{�^���v���u���ꂽ�v
	 *	
	 *	@author	KORYUOH
	 */
	static void callBack(int button,int state,int x,int y);
	/**
	 *	@brief	�h���b�O���R�[���o�b�N�֐�
	 *	@param[in]	x���W
	 *	@param[in]	y���W
	 *	@author	KORYUOH
	 */
	static void drug(int x,int y);
public:
	/**
	 *	@brief	�h���b�O���
	 *	@param[in]	�{�^��
	 *	@param[in]	���
	 *	@author	KORYUOH
	 *	@return	���
	 */
	void toDrag(int button,int state);
	/**
	 *	@brief	X���W�擾
	 *	@author	KORYUOH
	 *	@return	X���W
	 */
	int getMousePositionX()const{return mX;};
	/**
	 *	@brief	Y���W�擾
	 *	@author	KORYUOH
	 *	@return	Y���W
	 */
	int getMousePositionY()const{return mY;};

private:
	/**	�����o�[�ϐ�*/
	/**
	[ button ]
  GLUT_LEFT_BUTTON�F�u���{�^���v
  GLUT_MIDDLE_BUTTON�F�u�����{�^���v
  GLUT_RIGHT_BUTTON�F�u�E�{�^���v
 
	[ state ]
  GLUT_DOWN�F�u�{�^���v���u�����ꂽ�v
  GLUT_UP�F�u�{�^���v���u���ꂽ�v
 */
	//���W
	static int	mX,mY;
	//�{�^���̎��
	static int mButton;
	//���
	static int mState;

};
/**===End Class Definition=================================*/
#endif
/**===End Of File==========================================*/