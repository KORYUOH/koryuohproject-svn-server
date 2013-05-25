/******************************************************************************
* File Name : GUIPtr.h                           Ver : 1.00  Date : 2013-05-06
*
* Description :
*
*		GUIシェアドポインタ宣言．
*
* Author : Shouta Takemura.
*
******************************************************************************/
#ifndef _GUI_PTR_H_
#define _GUI_PTR_H_

/*---- ヘッダファイルの読み込み ---------------------------------------------*/

#include<memory>
#include<list>

class GUI;

/*---- 先行宣言 -------------------------------------------------------------*/

/// <summary>
/// GUIシェアドポインタ.
/// </summary>
typedef std::shared_ptr<GUI>	GUIPtr;

/// <summary>
/// GUIコンテナ.
/// </summary>
typedef std::list<GUIPtr>	GUIContainer;

#endif // _GUI_PTR_H_ end

/********** End of File ******************************************************/
