/******************************************************************************
* File Name : UnitElement.h                      Ver : 1.00  Date : 2013-04-25
*
* Description :
*
*		���j�b�g�v�f�\���́D
*
* Author : Shouta Takemura.
*
******************************************************************************/
#ifndef _UNIT_ELEMENT_H_
#define _UNIT_ELEMENT_H_


/*---- �w�b�_�t�@�C���̓ǂݍ��� ---------------------------------------------*/

#include"../Managers/Human.h"
#include"../GUI/GUIFrame.h"
#include"../GUI/GUIFramePtr.h"

/*---- ��s�錾 -------------------------------------------------------------*/

/// <summary>���j�b�gID.</summary>
enum UnitID;

/// <summary>
/// ���j�b�g�v�f�\����.
/// </summary>
struct UnitElement
{
public:
	/// <summary>
	/// �R���X�g���N�^.
	/// </summary>
	/// <param name="id">���j�b�gID</param>
	/// <param name="unit">�v�f�������j�b�g</param>
	UnitElement( UnitID id, Unit& unit ) : 
		mID( id ),
		mLevel( 1 ),
		mHuman(),
		mGUIframe( std::make_shared<GUIFrame>() )
	{
	}	


public:
	/// <summary>
	/// ���j�b�gID.
	/// </summary>
	UnitID			mID;
	/// <summary>
	/// �ő�l����.
	/// </summary>
	int				mLevel;
	/// <summary>
	/// �l��.
	/// </summary>
	Human			mHuman;
	/// <summary>
	/// ���[�U�[�C���^�[�t�F�[�X.
	/// </summary>
	GUIFramePtr		mGUIframe;

}; // class UnitElement end


#endif // _UNIT_ELEMENT_H_ end

/********** End of File ******************************************************/
