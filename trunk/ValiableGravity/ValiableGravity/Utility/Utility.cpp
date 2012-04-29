/**===File Commentary=======================================*/
/**
*	@file	Utility.cpp
*
*	@brief	ゲーム用ユーティリティー実装
*
*	@author	KORYUOH
*
*	@date	2012/04/23
*/
/**===File Include=========================================*/
#include	<Utility/Utility.h>
#include	<Type/Vector3.h>
#include	<Type/Rect.h>
/**===Class Implementation=================================*/
namespace KORYUOH{
	/**========================================================*/
	/**
	*	@brief	判定
	*	@param[in]	矩形情報1
	*	@param[in]	矩形情報2
	*	@author	KORYUOH
	*	@return	当たり判定
	*/
	/**========================================================*/
	namespace{
		bool rectCheck(const Rect& t1,const Rect& t2){
			if(t1.top()<t2.bottom()&&t1.left()<t2.right())
					return true;
			return false;
		}
	}
	/**========================================================*/
	/**
	*	@brief	衝突判定
	*	@param[in]	円情報1
	*	@param[in]	円情報2
	*	@author	KORYUOH
	*	@return	当たり判定
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
	*	@brief	衝突判定
	*	@param[in]	球情報1
	*	@param[in]	半径1
	*	@param[in]	球情報2
	*	@param[in]	半径2
	*	@author	KORYUOH
	*	@return	当たり判定
	*/
	/**========================================================*/
	const bool isCollision(const Vector3& v1,float r1,const Vector3& v2,float r2){
		float X = v1.x - v2.x;
		float Y = v1.y - v2.y;
		float Z = v1.z - v2.z;
		float R = r1+r2;
		return (X*X+Y*Y+Z*Z<R*R)? true:false;
	}
	/**========================================================*/
	/**
	*	@brief	衝突判定
	*	@param[in]	矩形情報1
	*	@param[in]	矩形情報2
	*	@author	KORYUOH
	*	@return	当たり判定
	*/
	/**========================================================*/
	const bool isCollision(const Rect& t1,const Rect& t2){
		if(rectCheck(t1,t2)&&rectCheck(t2,t1))
			return true;
		return false;
	}

};
/**===End Of File==========================================*/