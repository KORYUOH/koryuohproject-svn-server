/******************************************************************************
* File Name : UnitID.h                           Ver : 1.00  Date : 2012-12-14
*
* Description :
*
*		���j�b�g�񋓌^�D
*
* Author : Shouta Takemura.
*
******************************************************************************/
#ifndef _UNIT_ID_H_
#define _UNIT_ID_H_

/// <summary>
/// �A�N�^�[ID�񋓌^.
/// </summary>
enum UnitID
{
	/// <summary>
	/// ID�Ȃ��̃A�N�^�[.
	/// </summary>
	UNIT_NONE = 0,
	/// <summary>
	/// �F��.
	/// </summary>
	UNIT_SPACE = 1,
	/// <summary>
	/// ��.
	/// </summary>
	UNIT_STAR,
	/// <summary>
	/// �_��{��.
	/// </summary>
	UNIT_FARM,
	/// <summary>
	/// �H��{��.
	/// </summary>
	UNIT_FACTORY,
	/// <summary>
	/// �Z��{��.
	/// </summary>
	UNIT_HOUSING,
	/// <summary>
	/// �ړ��{��.
	/// </summary>
	UNIT_AIRFIELD,

	/// <summary>
	/// �v���C���[ID.
	///	</summary>
	UNIT_PLAYER,
	/// <summary>
	/// �J����ID.
	/// </summary>
	UNIT_CAMERA,

};

#endif

/********** End of File ******************************************************/
