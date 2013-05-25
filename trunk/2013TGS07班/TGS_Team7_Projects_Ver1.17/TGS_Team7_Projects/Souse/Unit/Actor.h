/******************************************************************************
* File Name : Actor.h                              Ver : 1.00  Date : 2013-04-25
*
* Description :
*
*		�A�N�^�[���ۃN���X�D
*
* Author : Shouta Takemura.
*
******************************************************************************/
#ifndef _I_ACTOR_H_
#define _I_ACTOR_H_

/*---- �w�b�_�t�@�C���̓ǂݍ��� ---------------------------------------------*/

#include<gslib.h>
#include"../Draw/Animation.h"
#include"../Collider/Collider.h"


/*---- ��s�錾 -------------------------------------------------------------*/

/// <summary>���[���h���ۃN���X.</summary>
class IWorld;
/// <summary>�t���O�Ǘ��Ғ��ۃN���X.</summary>
class IFlagManager;
/// <summary>���j�b�gID.</summary>
enum UnitID;


/// <summary>
/// �A�N�^�[���ۃN���X.
/// </summary>
class Actor
{

public:
	/// <summary>
	/// �R���X�g���N�^.
	/// </summary>
	/// <param name="world">���[���h</param>
	/// <param name="flag">�t���O�Ǘ���</param>
	///	 <param name="position">�������W</param>
	/// <param name="radius">�Փ˔���p�̔��a</param>
	Actor( IWorld& world, IFlagManager& flag, const GSvector2& position ,float radius );
	/// <summary>
	/// ���z�f�X�g���N�^.
	/// </summary>
	virtual ~Actor() {}

#pragma region �O���Q�ƑO��̃N���X.

public:
	/// <summary>
	/// �X�V.
	/// </summary>
	/// <param name="frameTimer">�t���[���^�C�}�[</param>
	virtual void Update( float frameTimer ) = 0;
	/// <summary>
	/// ���Y����.
	/// </summary>
	/// <param name="frameTimer">�t���[���^�C�}�[</param>
	virtual void Production( float frameTimer ) = 0;
	/// <summary>
	/// �ێ��R�X�g�x��������.
	/// </summary>
	/// <param name="frameTimer">�t���[���^�C�}�[</param>
	virtual void Maintenance( float frameTimer ) = 0;
	/// <summary>
	/// �`��.
	/// </summary>
	virtual void Draw() = 0;
	/// <summary>
	/// UI�̕`��.
	/// </summary>
	virtual void DrawUI() = 0;
	/// <summary>
	/// ���S����.
	/// </summary>
	/// <returns>���S���Ă���ΐ^�A���Ă��Ȃ���΋U��Ԃ�</returns>
	virtual bool IsDead() const;


#pragma endregion


protected:
	/// <summary>
	/// �������S����.
	/// </summary>
	void Dead();



#pragma region �A�N�Z�X�֎~�֐�


private:
	/// <summary>
	/// �R�s�[�R���X�g���N�^�̋֎~.
	/// <para>�O���A�N�Z�X�̋֎~.</para>
	/// </summary>
	Actor( const Actor& other );
	/// <summary>
	/// ������Z�q�I�[�o�[���[�h�̋֎~
	/// <para>�O���A�N�Z�X�̋֎~.</para>
	/// </summary>
	Actor& operator = ( const Actor& other );


#pragma endregion


protected:
	/// <summary>
	/// ���[���h.
	/// </summary>
	IWorld&			mWorld;
	/// <summary>
	/// �t���O�Ǘ���.
	/// </summary>
	IFlagManager&	mFlags;
	/// <summary>
	/// �Փˏ��.
	/// </summary>
	Collider		mCollder;
	/// <summary>
	/// �A�j���[�V����.
	/// </summary>
	Animation		mAnimation;
	/// <summary>
	/// ��������t���O(�������Ă���ΐ^).
	/// </summary>
	bool			mIsAlive;

}; // class Actor end

#endif // _I_ACTOR_H_ end

/********** End of File ******************************************************/
