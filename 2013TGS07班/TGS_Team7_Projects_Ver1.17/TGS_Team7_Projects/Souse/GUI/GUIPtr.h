/******************************************************************************
* File Name : GUIPtr.h                           Ver : 1.00  Date : 2013-05-06
*
* Description :
*
*		GUI�V�F�A�h�|�C���^�錾�D
*
* Author : Shouta Takemura.
*
******************************************************************************/
#ifndef _GUI_PTR_H_
#define _GUI_PTR_H_

/*---- �w�b�_�t�@�C���̓ǂݍ��� ---------------------------------------------*/

#include<memory>
#include<list>

class GUI;

/*---- ��s�錾 -------------------------------------------------------------*/

/// <summary>
/// GUI�V�F�A�h�|�C���^.
/// </summary>
typedef std::shared_ptr<GUI>	GUIPtr;

/// <summary>
/// GUI�R���e�i.
/// </summary>
typedef std::list<GUIPtr>	GUIContainer;

#endif // _GUI_PTR_H_ end

/********** End of File ******************************************************/
