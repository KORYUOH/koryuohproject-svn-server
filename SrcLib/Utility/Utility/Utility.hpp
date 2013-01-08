/**===File Commentary=======================================*/
/**
 *	@file	Utility.h
 *
 *	@brief	�Q�[���p���[�e�B���e�B�[
 *
 *	@author	KORYUOH
 *
 *	@date	2012/04/23
 */
/**===Include Guard========================================*/
#ifndef	_UTILITY_H_
#define	_UTILITY_H_
/**===File Include=========================================*/
#include	<cmath>
#include	<xutility>
/**===Class Definition=====================================*/
class Utility{
public:
	/**
	 *	@brief	�N�����v
	 *	@param[in]	�ŏ��l
	 *	@param[in]	�ő�l
	 *	@param[in]	�N�����v�Ώ�
	 *	@return	�N�����v���ꂽ�l
	 */
	template<typename Ty>
	static Ty clamp(const Ty& minimum,const Ty& maximum,const Ty& target){
		return std::min(maximum,std::max(minimum,target));
	}

	/**
	 *	@brief	�����W����
	 *	@param[in]	���ݒl
	 *	@param[in]	�ŏ��l
	 *	@param[in]	�ő�l
	 *	@return �͈͓��Ȃ�true
	 */
	template<typename Ty>
	static bool isInRange(const Ty& now ,const Ty& minimum , const Ty& maximum){
		if(now < minimum)
			return false;
		if(now > maximum)
			return false;
		return true;
	}
	/**
	 *	@brief	���`�⊮
	 *	@param[in]	�o��
	 *	@param[in]	����
	 *	@param[in]	�p�[�Z���g
	 *	@return ���`�ۊǂ��ꂽ�l
	 */
	template <typename T>
	static T lerp(const T& start,const T& end,float persent){
		return (start + persent*(end-start));
	}

};
/**===End Class Definition=================================*/
#endif
/**===End Of File==========================================*/