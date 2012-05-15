/**===File Commentary=======================================*/
/**
 *	@file	Utility.cpp
 *
 *	@brief	���[���e�B�N���X
 *
 *	@author	KORYUOH
 *
 *	@date	2012/05/10
 */
/**===File Include=========================================*/
#include	<Koryuoh/Utility/ClassCheck/Utility.h>
/**===Class Implementation=================================*/
namespace KORYUOH{
	/**========================================================*/
	/**
	 *	@brief	�w�肳�ꂽ�N���X���`�F�b�N����
	*	@param[in]	�`�F�b�N����|�C���^	����:typeid(*pointer)
	 *	@note	�`�F�b�N�������N���X���w�肷�邱��
	 *	@note	����:isClass<�`�F�b�N�������N���X>(typeid(*pointer))
	 *	@return	�w�肳�ꂽ�N���X�Ȃ�^
	 */
	/**========================================================*/
	template<class _Ty>
	bool isClass(const type_info& info){
		return info == typeid(_Ty);
	}
};
/**===End Of File==========================================*/