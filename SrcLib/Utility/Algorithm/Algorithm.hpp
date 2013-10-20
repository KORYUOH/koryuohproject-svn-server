/**===File Commentary=======================================*/
/**
 *	@file	Algorithm.h
 *
 *	@brief	�ȗ��A���S���Y���\��
 *
 *	@author	KORYUOH
 *
 *	@date	2013/10/20
 *
 *	@virsion	ver.1.20
 */
/**===Include Guard========================================*/
#ifndef	_UTILITY_ALGORITHM_H_
#define	_UTILITY_ALGORITHM_H_
/**===File Include=========================================*/
/**===Class Definition=====================================*/
template<typename CONTAINER,typename FUNCTION>
class Algorithm{
public:
	/**
	 *	@brief	�ȗ��`For_each
	 *	@param[in]	�R���e�i
	 *	@param[in]	�֐�
	 *	@return	���s����
	 */
	static FUNCTION ForEach(CONTAINER& container,FUNCTION function);

};
/**===End Class Definition=================================*/
#include <Utility/Argorithm/Algorithm.h>
#endif
/**===End Of File==========================================*/