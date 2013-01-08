/**===File Commentary=======================================*/
/**
 *	@file	Math_Utility.h
 *
 *	@brief	���w�⏕�N���X
 *
 *	@author	KORYUOH
 *
 *	@date	2012/06/26
 */
/**===Include Guard========================================*/
#ifndef	_MATH_H_
#define	_MATH_H_
/**===File Include=========================================*/
/**===Class Definition=====================================*/
class Math{
public:
	/* �~���� */
	static const float PI;
	/**
	 *	@brief	������
	 *	@param[in]	��
	 *	@return	������
	 */
	static float sqrt(float x);
	/**
	 *	@brief	����
	 *	@param[in]	�p�x
	 *	@return	����
	 */
	static float sin	(float Degree);
	/**
	 *	@brief	�]��
	 *	@param[in]	�p�x
	 *	@return	�]��
	 */
	static float cos	(float Degree);
	/**
	 *	@brief	����
	 *	@param[in]	�p�x
	 *	@return	����
	 */
	static float tan	(float Degree);

	/**
	 *	@brief	�ʓx�@�ϊ�
	 *	@param[in]	�x���@
	 *	@return	�ʓx
	 */
	static float toRadians	(float Degree);
	/**
	 *	@brief	�x���@�ϊ�
	 *	@param[in]	�ʓx�@
	 *	@return	�x���@
	 */
	static float toDegrees	(float Radian);



};
/**===End Class Definition=================================*/
#endif
/**===End Of File==========================================*/