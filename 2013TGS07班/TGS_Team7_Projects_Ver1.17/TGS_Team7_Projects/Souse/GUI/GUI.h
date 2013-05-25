/******************************************************************************
* File Name : UIFrame.h                          Ver : 1.00  Date : 2013-04-25
*
* Description :
*
*		ユーザーインターフェースフレームクラス．
*
* Author : Shouta Takemura.
*
******************************************************************************/
#ifndef _GUI_H_
#define _GUI_H_

/*---- ヘッダファイルの読み込み ---------------------------------------------*/

#include"../Collider/Collider.h"
#include<list>
#include<memory>


/*---- 先行宣言 -------------------------------------------------------------*/

/// <summary>GUIコマンド.</summary>
enum GUICommand;
class IFlagManager;
enum FlagID;


/// <summary>
/// UIフレームクラス.
/// </summary>
class GUI
{
public:
	/// <summary>
	/// コンストラクタ.
	/// </summary>
	/// <param name="collider">衝突情報</param>
	/// <param name="flag">フラグ管理者.</param>
	/// <param name="id">フラグID.</param>
	GUI( Collider& collider, IFlagManager& flag, FlagID id );
	/// <summary>
	/// 仮想デストラクタ.
	/// </summary>
	virtual ~GUI() {}
	/// <summary>
	/// 更新.
	/// </summary>
	/// <param name="frameTimer">フレームレート</param>
	virtual void Update( float frameTimer );
	/// <summary>
	/// 描画.
	/// </summary>
	/// <param name="position">フレームの位置</param>
	/// <param name="angle">角度</param>
	virtual void Draw( const GSvector2& position, float angle ) const = 0;
	/// <summary>
	/// 衝突フラグを更新する.
	/// </summary>
	/// <param name="other">衝突相手</param>
	void CollisionUpdate( GUI& other );
	/// <summary>
	/// フレームとの位置関係を取得する.
	/// </summary>
	/// <param name="angle">角度</param>
	const GSvector2& GetFreamPositon( float angle ) const;
	/// <summary>
	/// 衝突情報を取得.
	/// </summary>
	/// <returns>衝突情報を返す.</returns>
	Collider GetCollider() const;
	/// <summary>
	/// フラグの無効化.
	/// </summary>
	void FlagDisable();
protected:
	/// <summary>
	/// フラグの有効化.
	/// </summary>
	void FlagEnable();

protected:
	/// <summary>
	/// 衝突情報.
	/// </summary>
	Collider		mCollider;
private:
	/// <summary>
	/// フラグ管理者.
	/// </summary>
	IFlagManager&	mFlagManager;
	/// <summary>
	/// フラグ.
	/// </summary>
	FlagID			mFlagID;


}; // class UI end

#endif // !_GUI_H_

/********** End of File ******************************************************/

