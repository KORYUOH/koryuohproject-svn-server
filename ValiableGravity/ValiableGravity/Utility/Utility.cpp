/**===File Commentary=======================================*/
/**
*	@file	Utility.cpp
*
*	@brief	�Q�[���p���[�e�B���e�B�[����
*
*	@author	<��Җ�>
*
*	@date	2012/04/23
*/
/**===File Include=========================================*/
#include	<Type/Vector3.h>
/**===Class Implementation=================================*/
namespace KORYUOH{
	/**========================================================*/
	/**
	*	@brief	�Փ˔���
	*	@param[in]	�~���1
	*	@param[in]	�~���2
	*	@author	<��Җ�>
	*	@return	�����蔻��
	*/
	/**========================================================*/
	const bool isCollision(const Vector3& v1,const Vector3& v2){
		float X = v1.x - v2.x;
		float Y = v1.y - v2.y;
		float R = v1.z + v2.z;
		return (X*X+Y*Y<R*R)? true:false;
	}
	/**========================================================*/
	/**
	*	@brief	�Փ˔���
	*	@param[in]	�����1
	*	@param[in]	���a1
	*	@param[in]	�����2
	*	@param[in]	���a2
	*	@author	<��Җ�>
	*	@return	�����蔻��
	*/
	/**========================================================*/
	const bool isCollision(const Vector3& v1,float r1,const Vector3& v2,float r2){
		float X = v1.x - v2.x;
		float Y = v1.y - v2.y;
		float Z = v1.z - v2.z;
		float R = r1+r2;
		return (X*X+Y*Y+Z*Z<R*R)? true:false;
	}

};
/**===End Of File==========================================*/