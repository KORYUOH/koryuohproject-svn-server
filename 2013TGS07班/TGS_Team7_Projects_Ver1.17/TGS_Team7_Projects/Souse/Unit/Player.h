/******************************************************************************
* File Name : Player.h                            Ver : 1.00  Date : 2013-04-25
*
* Description :
*
*		宇宙抽象クラス．
*
* Author : Shouta Takemura.
*
******************************************************************************/
#ifndef _UNIT_PLAYER_H_
#define _UNIT_PLAYER_H_

/*---- ヘッダファイルの読み込み ---------------------------------------------*/

#include"Unit.h"
#include"../Draw/TextureNumber.h"

/*---- 先行宣言 -------------------------------------------------------------*/

/// <summary>ワールド抽象クラス.</summary>
class IWorld;


/// <summary>
/// プレイヤークラス.
/// </summary>
class Player : public Unit
{

public:
	/// <summary>
	/// コンストラクタ.
	/// </summary>
	/// <param name="world">ワールド</param>
	/// <param name="flag">フラグ管理者</param>
	///	 <param name="position">初期座標</param>
	Player( IWorld& world, IFlagManager& flag, const GSvector2& position );


public:
	/// <summary>
	/// 更新.
	/// </summary>
	/// <param name="frameTimer">フレームタイマー</param>
	virtual void Update( float frameTimer );
	/// <summary>
	/// 生産処理.
	/// </summary>
	/// <param name="frameTimer">フレームタイマー</param>
	virtual void Production( float frameTimer ){ (void)frameTimer; }
	/// <summary>
	/// 維持コスト支払い処理.
	/// </summary>
	/// <param name="frameTimer">フレームタイマー</param>
	virtual void Maintenance( float frameTimer ){ (void)frameTimer; }
	/// <summary>
	/// 描画.
	/// </summary>
	virtual void Draw() {};
	/// <summary>
	/// UIの描画.
	/// </summary>
	virtual void DrawUI();
public:
	/// <summary>
	/// 衝突した瞬間の処理.
	/// </summary>
	/// <param name="other">相手ユニット</param>
	virtual void OnCollideEnter( Unit& other );
	/// <summary>
	/// 衝突している間の処理.
	/// </summary>
	/// <param name="other">相手ユニット</param>
	virtual void OnCollideStay( Unit& other );
	/// <summary>
	/// 衝突したオブジェクトが離れた時の処理.
	/// </summary>
	/// <param name="other">相手ユニット</param>
	virtual void OnCollideExit( Unit& other );

private:
	/// <summary>
	/// GUI操作.
	/// </summary>
	void GUIOperation();
	/// <summary>
	/// GUIの選択解除.
	/// </summary>
	void GUIDeselect();
	/// <summary>
	/// 対象のレベルを上げる.
	/// </summary>
	void GUILevelUp();
	/// <summary>
	/// 現在の選択があるか判定.
	/// </summary>
	/// <returns>選択がある時真、そうでなければ偽を返す.</returns>
	bool IsSelectUnit() const;
	/// <summary>
	/// 人材の移動.
	/// </summary>
	/// <param name="target">目標ユニット</param>
	void PersonnelChange( Unit& target );
	/// <summary>
	/// ウインドウを閉じる.
	/// </summary>
	void WindowClose();


private:

	/// <summary>
	/// 選択中のユニット.
	/// </summary>
	Unit*			mSelectUnit;
	/// <summary>
	/// 数字描画用オブジェクト.
	/// </summary>
	TextureNumber	mNumber;


}; // class Player end

#endif // _UNIT_PLAYER_H_ end

/********** End of File ******************************************************/
