/******************************************************************************
* File Name : WorldUnit.h                        Ver : 1.00  Date : 2012-12-14
*
* Description :
*
*		���[���h�A�N�^�[�N���X�D
*
******************************************************************************/
#ifndef _WORLD_UNIT_H_
#define _WORLD_UNIT_H_

/*---- �w�b�_�t�@�C���̓ǂݍ��� ---------------------------------------------*/

#include	"../Unit/UnitPtr.h"
#include	"../Collider/ColliderPairManager.h"
#include	<map>
#include	<memory>
#include	<functional>

/*---- ��s�錾 -------------------------------------------------------------*/

/// <summary>���j�b�g�}�l�[�W���[</summary>
class UnitManager;
class IRenderer;
/// <summary>�A�N�^�[ID</summary>
enum UnitID;




/// <summary>
/// ���[���h�A�N�^�[�N���X.
/// </summary>
class WorldUnit
{
public:
	/// <summary>
	/// �R���X�g���N�^.
	/// </summary>
	WorldUnit();
	/// <summary>
	/// �f�X�g���N�^.
	/// </summary>
	~WorldUnit();

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
	/// <param name="id">�A�N�^�[�}�l�[�W��ID</param>
	/// <param name="actor">�ǉ�����A�N�^�[</param>
	void Add( UnitID id, UnitPtr unit );
	/// <summary>
	/// ����.
	/// </summary>
	void Clear();

private:
	/// <summary>
	/// �}�l�[�W���[�̒ǉ�.
	/// </summary>
	/// <param name="id">�ǉ�����A�N�^�[�}�l�[�W��ID</param>
	void AddManager( UnitID id );

#pragma region "�A�N�Z�X�̋֎~"

private:
	/// <summary>
	/// �R�s�[�R���X�g���N�^(�O������͋֎~).
	/// </summary>
	WorldUnit( const WorldUnit& other );
	/// <summary>
	/// ������Z�q�I�[�o���[�h�֎~.
	/// </summary>
	WorldUnit& operator = ( const WorldUnit& other );

#pragma endregion


private:
	/*�A�N�^�[�}�l�[�W���V�F�A�h�|�C���^*/
	typedef std::shared_ptr<UnitManager> UnitManagerPtr;
	/*�A�N�^�[�}�l�[�W���R���e�i*/
	typedef std::map<UnitID,UnitManagerPtr> UnitManagerContainer;

	/*�A�N�^�[�}�l�[�W���[*/
	typedef std::pair<UnitID,UnitManagerPtr> UnitManagerPair;
	/*Function�錾*/
	typedef std::function<void (UnitManagerPtr)> UnitManagerFunction;

	/// <summary>
	/// foreach�̏ȗ��錾.
	/// </summary>
	void each(UnitManagerFunction f);

	/// <summary>
	/// �}�l�[�W���[�Ǘ���.
	/// </summary>
	UnitManagerContainer mManagers;
	/// <summary>
	/// �ՓˊǗ���.
	/// </summary>
	ColliderPairManager	mColliderManager;

};

#endif

/********** End of File ******************************************************/
