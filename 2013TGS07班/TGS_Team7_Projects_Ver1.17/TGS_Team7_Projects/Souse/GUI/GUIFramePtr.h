/******************************************************************************
* File Name : GUIFramePtr.h                          Ver : 1.00  Date : 2013-04-25
*
* Description :
*
*		ユーザーインターフェースフレームシェアドポインタ．
*
* Author : Shouta Takemura.
*
******************************************************************************/
#ifndef _GUI_FRAME_PTR_H_
#define _GUI_FRAME_PTR_H_

/*---- ヘッダファイルの読み込み ---------------------------------------------*/

#include<memory>
#include<list>

/*---- 先行宣言 -------------------------------------------------------------*/

class GUIFrame;

/// <summary>
/// GUIフレームシェアドポインタ.
/// </summary>
typedef std::shared_ptr<GUIFrame>	GUIFramePtr;
/// <summary>
/// GUIフレームコンテナ.
/// </summary>
typedef std::list<GUIFramePtr>	GUIFrameContainer;


#endif // _GUI_FRAME_PTR_H_ end

/********** End of File ******************************************************/
