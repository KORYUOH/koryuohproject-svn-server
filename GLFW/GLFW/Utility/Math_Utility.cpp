/**===File Commentary=======================================*/
/**
 *	@file	Math_Utility.cpp
 *
 *	@brief	���w�⏕���[�e�B���e�B�[
 *
 *	@author	KORYUOH
 *
 *	@date	2012/06/26
 */
/**===File Include=========================================*/
#include	<Utility/Math_Utility.h>
#include	<cmath>
/**===Class Implementation=================================*/
const float Math::PI = 3.1415926535897932384;
/**========================================================*/
/**
 *	@brief	����
 *	@param[in]	�p�x
 *	@return	�x��
 */
/**========================================================*/
float Math::sin(float theta){
	return std::sinf(toRadians(theta));
}
/**========================================================*/
/**
 *	@brief	�]��
 *	@param[in]	�p�x
 *	@return	�x��
 */
/**========================================================*/
float Math::cos(float theta){
	return std::cosf(toRadians(theta));
}
/**========================================================*/
/**
 *	@brief	����
 *	@param[in]	�p�x
 *	@return	�x���@
 */
/**========================================================*/
float Math::tan(float theta){
	return std::tanf(toRadians(theta));
}
/**========================================================*/
/**
 *	@brief	������
 *	@param[in]	��
 *	@return	�l
 */
/**========================================================*/
float Math::sqrt(float root){
	return std::sqrtf(root);
}
/**========================================================*/
/**
 *	@brief	�x���@�ɕϊ�
 *	@param[in]	�ʓx�@
 *	@return	�x��
 */
/**========================================================*/
float Math::toDegrees(float radian){
	return radian*(180.0f/PI);
}
/**========================================================*/
/**
 *	@brief	�ʓx�@�ɕϊ�
 *	@param[in]	�x���@
 *	@return	�ʓx�@
 */
/**========================================================*/
float Math::toRadians(float degree){
	return degree *(PI/180.0f);
}



/**===End Of File==========================================*/