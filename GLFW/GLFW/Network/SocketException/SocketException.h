/**===File Commentary=======================================*/
/**
 *	@file	SocketException.h
 *
 *	@brief	�\�P�b�g��O�N���X�w�b�_�t�@�C��
 *
 *	@note	�����^�C���G���[�p��
 *
 *	@author	KORYUOH
 *
 *	@date	2012/05/08
 */
/**===Include Guard========================================*/
#ifndef	_SOCKETEXCEPTION_H_
#define	_SOCKETEXCEPTION_H_
/**===File Include=========================================*/
#include	<stdexcept>
/**===Class Definition=====================================*/
class SocketException:public std::runtime_error{
public:
	/**
	 *	@brief	�R���X�g���N�^
	 *	@param[in]	��O���b�Z�[�W
	 */
	SocketException(const std::string& msg)
		:std::runtime_error(msg){
	}
};
/**===End Class Definition=================================*/
#endif
/**===End Of File==========================================*/