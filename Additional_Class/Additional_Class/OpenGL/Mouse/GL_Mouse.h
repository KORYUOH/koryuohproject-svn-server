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
#include	<glut.h>
/**===Class Definition=====================================*/
class GLMouse{
public:
	/**
	 *	@brief	<�v��>
	 *	@param[in]	<[������]:[�^�C�v]>			<�T�v>
	 *	@note	<��������>
	 *	@author	<��Җ�>
	 *	@return	<�߂�l>
	 */
	virtual void update();
private:
	/**
	 *	@brief	�R�[���o�b�N�֐�
	 *	@param[in]	�{�^��
	 *	@param[in]	���
	 *	@param[in]	x���W
	 *	@param[in]	y���W
	 *	@note	
	 *	 [ button ]
   *	GLUT_LEFT_BUTTON�F�u���{�^���v
   *	GLUT_MIDDLE_BUTTON�F�u�����{�^���v
   *	GLUT_RIGHT_BUTTON�F�u�E�{�^���v
	 *	
	 *	[ state ]
   *	GLUT_DOWN�F�u�{�^���v���u�����ꂽ�v
   *	GLUT_UP�F�u�{�^���v���u���ꂽ�v
	 *	
	 *	@author	<��Җ�>
	 */
	static void callBack(int button,int state,int x,int y);
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
	int	mX,mY;
	//�{�^���̎��
	int mButton;
	//���
	int mState;

};
/**===End Class Definition=================================*/
#endif
/**===End Of File==========================================*/