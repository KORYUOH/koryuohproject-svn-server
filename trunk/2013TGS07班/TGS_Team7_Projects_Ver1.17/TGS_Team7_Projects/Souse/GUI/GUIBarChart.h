/******************************************************************************
* File Name : GUIBarChart.h                       Ver : 1.00  Date : 2013-05-06
*
* Description :
*
*		棒グラフGUIクラス．
*
* Author : Shouta Takemura.
*
******************************************************************************/
#ifndef _GUI_BAR_CHART_H_
#define _GUI_BAR_CHART_H_

/*---- ヘッダファイルの読み込み ---------------------------------------------*/

#include"GUI.h"

/*---- 先行宣言 -------------------------------------------------------------*/

class IFlagManager;


/// <summary>
/// 棒グラフGUI.
/// </summary>
class GUIBarChart : public GUI
{
public:
	/// <summary>
	/// コンストラクタ.
	/// </summary>
	/// <param name="collider">衝突情報</param>
	/// <param name="flagManager">フラグ管理者</param>
	/// <param name="maxValue">値へのパス</param>
	/// <param name="angle">角度</param>
	/// <param name="color">色</param>
	GUIBarChart( Collider& collider, IFlagManager& flagManager, float* value, float angle, const GScolor& color );
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
	/// <summary>
	/// 値へのパス.
	/// </summary>
	float*		mValue;
	/// <summary>
	/// 角度.
	/// </summary>
	float		mAngle;
	/// <summary>
	/// 棒グラフの描画色.
	/// </summary>
	GScolor		mColor;
	/// <summary>
	/// スケール倍率.
	/// </summary>
	static const float SCALE_RATE;

}; // class GUIBarChart end


#endif // _GUI_BAR_CHART_H_ end

/********** End of File ******************************************************/
