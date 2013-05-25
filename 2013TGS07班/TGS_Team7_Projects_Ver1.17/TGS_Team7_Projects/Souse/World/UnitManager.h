/******************************************************************************
* File Name : UnitManager.h                       Ver : 1.00  Date : 2013-04-25
*
* Description :
*
*		���j�b�g�}�l�[�W���[�N���X�D
*
* Author : Shouta Takemura.
*
******************************************************************************/
#ifndef _UNIT_MANAGER_H_
#define _UNIT_MANAGER_H_

/*---- �w�b�_�t�@�C���̓ǂݍ��� ---------------------------------------------*/

#include	"../Unit/UnitPtr.h"
#include	"../Collider/ColliderPairManager.h"
#include	<list>
#include	<functional>


/// <summary>
/// �A�N�^�[�}�l�[�W���[.
/// </summary>
class UnitManager
{

public:
	/*�t�@���N�V������`*/
	typedef std::function<void (UnitPtr)> ActorFunction;

public:
	/// <summary>
	/// �R���X�g���N�^.
	/// </summary>
	/// <param name="collder">�ՓˊǗ���/param>
	UnitManager( ColliderPairManager& collder );
	/// <summary>
	/// �f�X�g���N�^.
	/// </summary>
	~UnitManager();

public:
	/// <summary>
	/// �X�V.
	/// </summary>
	/// <param name="frameTimer">�t���[���^�C�}�[</param>
	void Update( float frameTimer );
	/// <summary>
	/// ���Y����.
	/// </summary>
	/// <param name="frameTimer">�t���[���^�C�}�[</param>
	void Production( float frameTimer );
	/// <summary>
	/// �ێ��R�X�g�x��������.
	/// </summary>
	/// <param name="frameTimer">�t���[���^�C�}�[</param>
	void Maintenance( float frameTimer );
	/// <summary>
	/// �`��.
	/// </summary>
	void Draw();	
	/// <summary>
	/// UI�̕`��.
	/// </summary>
	void DrawUI();
	/// <summary>
	/// �A�N�^�[�̒ǉ�.
	/// </summary>
	/// <param name="actor">�ǉ�����A�N�^�[</param>
	void Add( UnitPtr unit );
	/// <summary>
	/// ����.
	/// </summary>
	void Clear();
	/// <summary>
	/// ���S���Ă���A�N�^�[�̍폜.
	/// </summary>
	void Remove();
	/// <summary>
	/// �A�N�^�[�Ԃ̏Փ˔���.
	/// </summary>
	/// <param name="other">����A�N�^�[</param>
	void Collide( Unit& other );
	/// <summary>
	/// ���̃}�l�[�W���[���Փ˔���.
	/// </summary>
	/// <param name="other">����}�l�[�W���[</param>
	void Collide( UnitManager& other );
	/*foreach���ȗ�����֐�*/
	void each(ActorFunction f);

#pragma region "�A�N�Z�X�̋֎~"

private:
	/*�R�s�[�֎~����*/
	UnitManager( const UnitManager& other );
	/*������Z�q�I�[�o���[�h�̋֎~*/
	UnitManager& operator = ( const UnitManager& other );

#pragma endregion

private:
	/*�^�̒u�������A�N�^�[�R���e�i(�A�N�^�[�V�F�A�h�|�C���^���X�g)*/
	typedef std::list<UnitPtr> UnitContainer;
	/// <summary>
	/// �ՓˊǗ���.
	/// </summary>
	ColliderPairManager&	mColliderManager;
	/// <summary>
	/// ���j�b�g���X�g.
	/// </summary>
	UnitContainer			mUnits;
};

#endif

/********** End of File ******************************************************/
