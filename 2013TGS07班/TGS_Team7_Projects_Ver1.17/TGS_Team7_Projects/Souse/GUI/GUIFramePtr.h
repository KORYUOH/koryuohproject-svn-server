/******************************************************************************
* File Name : GUIFramePtr.h                          Ver : 1.00  Date : 2013-04-25
*
* Description :
*
*		���[�U�[�C���^�[�t�F�[�X�t���[���V�F�A�h�|�C���^�D
*
* Author : Shouta Takemura.
*
******************************************************************************/
#ifndef _GUI_FRAME_PTR_H_
#define _GUI_FRAME_PTR_H_

/*---- �w�b�_�t�@�C���̓ǂݍ��� ---------------------------------------------*/

#include<memory>
#include<list>

/*---- ��s�錾 -------------------------------------------------------------*/

class GUIFrame;

/// <summary>
/// GUI�t���[���V�F�A�h�|�C���^.
/// </summary>
typedef std::shared_ptr<GUIFrame>	GUIFramePtr;
/// <summary>
/// GUI�t���[���R���e�i.
/// </summary>
typedef std::list<GUIFramePtr>	GUIFrameContainer;


#endif // _GUI_FRAME_PTR_H_ end

/********** End of File ******************************************************/
