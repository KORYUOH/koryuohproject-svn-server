/******************************************************************************
* File Name : FlagManager.h                      Ver : 1.00  Date : 2013-05-09
*
* Description :
*
*		�t���O�Ǘ��҃N���X�D
*
******************************************************************************/
#ifndef _FLAG_MANAGER_H_
#define _FLAG_MANAGER_H_

/*---- �w�b�_�t�@�C���̓ǂݍ��� ---------------------------------------------*/

#include<map>
#include"FlagID.h"
#include"IFlagManager.h"

typedef std::map<FlagID, bool>	FlagContainer;

/// <summary>
/// �t���O�Ǘ���.
/// </summary>
class FlagManager : public IFlagManager
{
public:
	/// <summary>
	/// �R���X�g���N�^.
	/// </summary>
	FlagManager();
	/// <summary>
	/// ������.
	/// </summary>
	void Initialize();
	/// <summary>
	/// �t���O�̒ǉ�.
	/// </summary>
	/// <param name="id">�t���OID</param>
	void Add( FlagID id );
	/// <summary>
	/// �t���O���擾����.
	/// </summary>
	/// <param name="id">�t���OID</param>
	/// <returns>�t���O��Ԃ�.</returns>
	virtual bool IsFlag( FlagID id ) const;
	/// <summary>
	/// �t���O��L���ɂ���.
	/// </summary>
	/// <param name="id">�t���OID</param>
	virtual void FlagEnable( FlagID id );
	/// <summary>
	/// �t���O�𖳌��ɂ���.
	/// </summary>
	/// <param name="id">�t���OID</param>
	virtual void FlagDisable( FlagID id );
	/// <summary>
	/// �t���O����������.
	/// </summary>
	/// <param name="id">�t���OID</param>
	virtual void ChangeFlag( FlagID id );
	/// <summary>
	/// ����.
	/// </summary>
	void Clear();
private:
	/// <summary>
	/// �t���O�R���e�i.
	/// </summary>
	FlagContainer	mFlagContainer;

};


#endif // !_FLAG_MANAGER_H_

/********** End of File ******************************************************/