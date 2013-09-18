/**===File Commentary=======================================*/
/**
 *	@file	DebugUtility.h
 *
 *	@brief	�f�o�b�O�p���[�e�B���e�B�[
 *
 *	@note	���ʂ̓f�o�b�O���̂�
 *
 *	@author	KORYUOH
 *
 *	@date	2012/11/19
 */
/**===Include Guard========================================*/
#ifndef	_DEBUGUTILITY_H_
#define	_DEBUGUTILITY_H_
/**===File Include=========================================*/

/**===Class Definition=====================================*/
class DebugUtility{
public:
	/**
	 *	@brief	�f�o�b�O�R���\�[���ɕ����o��
	 *	@param[in]	�ϒ�����
	 *	@note	���@��printf�ɏ�����
	 */
	static void print(const char* format,...);
	static void println(const char* format,...);
private:
	/**	�����o�[�ϐ�*/

};
/**===End Class Definition=================================*/
#endif
/**===End Of File==========================================*/