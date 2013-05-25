/******************************************************************************
* File Name : IFlagManager.h                      Ver : 1.00  Date : 2013-05-09
*
* Description :
*
*		���ۃt���O�Ǘ��҃N���X�D
*
******************************************************************************/
#ifndef _I_FLAG_MANAGER_H_
#define _I_FLAG_MANAGER_H_

/*---- �w�b�_�t�@�C���̓ǂݍ��� ---------------------------------------------*/

#include"FlagID.h"


/// <summary>
/// ���ۃt���O�Ǘ���.
/// </summary>
class IFlagManager
{
public:
	/// <summary>
	/// ���z�f�X�g���N�^.
	/// </summary>
	~IFlagManager() {}
	/// <summary>
	/// �t���O���擾����.
	/// </summary>
	/// <param name="id">�t���OID</param>
	/// <returns>�t���O��Ԃ�.</returns>
	virtual bool IsFlag( FlagID id ) const = 0;
	/// <summary>
	/// �t���O��L���ɂ���.
	/// </summary>
	/// <param name="id">�t���OID</param>
	virtual void FlagEnable( FlagID id ) = 0;
	/// <summary>
	/// �t���O�𖳌��ɂ���.
	/// </summary>
	/// <param name="id">�t���OID</param>
	virtual void FlagDisable( FlagID id ) = 0;
	/// <summary>
	/// �t���O����������.
	/// </summary>
	/// <param name="id">�t���OID</param>
	virtual void ChangeFlag( FlagID id ) = 0;

};

#endif // !_I_FLAG_MANAGER_H_

/********** End of File ******************************************************/