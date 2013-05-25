/******************************************************************************
* File Name : Collider.h                          Ver : 1.00  Date : 2013-04-25
*
* Description :
*
*		衝突クラス．
*
* Author : Shouta Takemura.
*
******************************************************************************/
#ifndef _COLLIDER_H_
#define _COLLIDER_H_

/*---- ヘッダファイルの読み込み ---------------------------------------------*/

#include<gslib.h>

/*---- 先行宣言 -------------------------------------------------------------*/

/// <summary>ワールド抽象クラス.</summary>
class IWorld;


/// <summary>
/// 衝突クラス.
/// </summary>
class Collider
{
public:
	/// <summary>
	/// コンストラクタ.
	/// </summary>
	/// <param name="position">位置情報</param>
	/// <param name="radius">衝突用半径</param>
	Collider( const GSvector2& position, float radius );
	/// <summary>
	/// 衝突判定.
	/// </summary>
	/// <param name="other">衝突相手</param>
	virtual bool IsCollide( const Collider& other );
public:
	/// <summary>
	/// 位置情報.
	/// </summary>
	GSvector2	mPosition;
	/// <summary>
	/// 位置情報.
	/// </summary>
	float		mRadius;
	/// <summary>
	/// 衝突フラグ.
	/// </summary>
	bool		mIsCollision;


}; // class Collider end


#endif // _COLLIDER_H_ end

/********** End of File ******************************************************/
