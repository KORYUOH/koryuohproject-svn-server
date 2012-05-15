/**===File Commentary=======================================*/
/**
 *	@file	Utility.h
 *
 *	@brief	���[���e�B�[�w�b�_
 *
 *	@author	KORYUOH
 *
 *	@date	2012/05/10
 */
/**===Include Guard========================================*/
#ifndef	_UTILITY_H_
#define	_UTILITY_H_
/**===File Include=========================================*/

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
	bool isClass(const type_info& info);
};
/**===End Class Definition=================================*/
#endif
/**===End Of File==========================================*/