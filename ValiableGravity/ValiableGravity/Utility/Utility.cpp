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
#include	<Type/Rect.h>
/**===Class Implementation=================================*/
namespace KORYUOH{
	namespace{
		bool LRCheck(const Rect& box1,const Rect& box2){
			return (box1.getLeft()<box2.getRight()) ? true:false;
		}
		bool TBCheck(const Rect& box1,const Rect& box2){
			return (box1.getTop()<box2.getBottom()) ? true:false;
		}
	}
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
	/**
	*	@brief	�Փ˔���
	*	@param[in]	��`���1
	*	@param[in]	��`���2
	*	@author	<��Җ�>
	*	@return	�����蔻��
	*/
	/**========================================================*/
	const bool isCollision(const Rect& v1,const Rect& v2){
		if(LRCheck(v1,v2)||LRCheck(v2,v1))
			if(TBCheck(v1,v2)||TBCheck(v2,v1))
				return true;
		return false;
	}
};
/**===End Of File==========================================*/