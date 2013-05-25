/******************************************************************************
* File Name : GUINumber.h                         Ver : 1.00  Date : 2013-04-25
*
* Description :
*
*		ユーザーインターフェースフレームクラス．
*
* Author : Shouta Takemura.
*
******************************************************************************/
#ifndef _GUI_NUMBER_H_
#define _GUI_NUMBER_H_

/*---- ヘッダファイルの読み込み ---------------------------------------------*/

#include<list>
#include"GUI.h"
#include"../Draw/TextureNumber.h"

/*---- 先行宣言 -------------------------------------------------------------*/

class IFlagManager;


/// <summary>
/// UIフレームクラス.
/// </summary>
class GUINumber : public GUI
{
public:
	/// <summary>
	/// コンストラクタ.
	/// </summary>
	/// <param name="collider">衝突情報</param>
	/// <param name="flagManager">フラグ管理者</param>
		/// <param name="drawNumber">描画する数字へのパス</param>
	GUINumber( Collider& collider, IFlagManager& flagManager, float* drawNumber  );
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
	virtual void Draw( const GSvector2& position, float angle ) const;
private:
	/// </summary>
	/// 描画する数字.
	/// </summary>
	float*			mNumber;
	/// <summary>
	/// 数字描画用オブジェクト.
	/// </summary>
	TextureNumber	mDrawNumber;

}; // class Button end


#endif // _GUI_NUMBER_H_ end

/********** End of File ******************************************************/
