/******************************************************************************
* File Name : UIFrame.h                          Ver : 1.00  Date : 2013-04-25
*
* Description :
*
*		���[�U�[�C���^�[�t�F�[�X�t���[���N���X�D
*
* Author : Shouta Takemura.
*
******************************************************************************/
#ifndef _GUI_H_
#define _GUI_H_

/*---- �w�b�_�t�@�C���̓ǂݍ��� ---------------------------------------------*/

#include"../Collider/Collider.h"
#include<list>
#include<memory>


/*---- ��s�錾 -------------------------------------------------------------*/

/// <summary>GUI�R�}���h.</summary>
enum GUICommand;
class IFlagManager;
enum FlagID;


/// <summary>
/// UI�t���[���N���X.
/// </summary>
class GUI
{
public:
	/// <summary>
	/// �R���X�g���N�^.
	/// </summary>
	/// <param name="collider">�Փˏ��</param>
	/// <param name="flag">�t���O�Ǘ���.</param>
	/// <param name="id">�t���OID.</param>
	GUI( Collider& collider, IFlagManager& flag, FlagID id );
	/// <summary>
	/// ���z�f�X�g���N�^.
	/// </summary>
	virtual ~GUI() {}
	/// <summary>
	/// �X�V.
	/// </summary>
	/// <param name="frameTimer">�t���[�����[�g</param>
	virtual void Update( float frameTimer );
	/// <summary>
	/// �`��.
	/// </summary>
	/// <param name="position">�t���[���̈ʒu</param>
	/// <param name="angle">�p�x</param>
	virtual void Draw( const GSvector2& position, float angle ) const = 0;
	/// <summary>
	/// �Փ˃t���O���X�V����.
	/// </summary>
	/// <param name="other">�Փˑ���</param>
	void CollisionUpdate( GUI& other );
	/// <summary>
	/// �t���[���Ƃ̈ʒu�֌W���擾����.
	/// </summary>
	/// <param name="angle">�p�x</param>
	const GSvector2& GetFreamPositon( float angle ) const;
	/// <summary>
	/// �Փˏ����擾.
	/// </summary>
	/// <returns>�Փˏ���Ԃ�.</returns>
	Collider GetCollider() const;
	/// <summary>
	/// �t���O�̖�����.
	/// </summary>
	void FlagDisable();
protected:
	/// <summary>
	/// �t���O�̗L����.
	/// </summary>
	void FlagEnable();

protected:
	/// <summary>
	/// �Փˏ��.
	/// </summary>
	Collider		mCollider;
private:
	/// <summary>
	/// �t���O�Ǘ���.
	/// </summary>
	IFlagManager&	mFlagManager;
	/// <summary>
	/// �t���O.
	/// </summary>
	FlagID			mFlagID;


}; // class UI end

#endif // !_GUI_H_

/********** End of File ******************************************************/

