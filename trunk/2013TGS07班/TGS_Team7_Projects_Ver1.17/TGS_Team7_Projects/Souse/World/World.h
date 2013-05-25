/******************************************************************************
* File Name : World.h                             Ver : 1.00  Date : 2012-12-14
*
* Description :
*
*		���[���h�N���X�D
*
******************************************************************************/
#ifndef _WORLD_H_
#define _WORLD_H_

/*---- �w�b�_�t�@�C���̓ǂݍ��� ---------------------------------------------*/

#include"IWorld.h"
#include"WorldUnit.h"
#include"../Unit/UnitID.h"
#include"../Unit/UnitParameter.h"
#include"Timer.h"
#include"Camera.h"
#include"../GUI/GUIManager.h"

/*---- ��s�錾 -------------------------------------------------------------*/


/// <summary>
/// ���[���h�N���X.
/// </summary>
class World : public IWorld
{
#pragma region "�R���X�g���N�^."

public:
	/// <summary>
	/// �R���X�g���N�^.
	/// </summary>
	World();
	/// <summary>
	/// �f�X�g���N�^.
	/// </summary>
	~World();


#pragma endregion


#pragma region "���ۂł��Ăяo���鏈��."

public:
	/// <summary>
	/// �A�N�^�[�̒ǉ�.
	/// </summary>
	/// <param name="id">���j�b�g�}�l�[�W��ID</param>
	/// <param name="actor">�ǉ�����A�N�^�[</param>
	virtual void Add( UnitID id,UnitPtr actor );
	/// <summary>
	/// �v���C���[�̐���.
	/// </summary>
	/// <param name="actor">�ǉ�����v���C���[�A�N�^�[</param>
	virtual void AddPlayer( UnitPtr actor );
	/// <summary>
	/// �I�u�W�F�N�g�̒ǉ�.
	/// </summary>
	/// <param name="object">�ǉ�����A�N�^�[�I�u�W�F�N�g</param>
	virtual void AddObject( UnitPtr object );
	/// <summary>
	/// �v���C���[�̎擾.
	/// </summary>
	/// <returns>�v���C���[�A�N�^�[���擾</returns>
	virtual UnitPtr GetPlayer()const;
	/// <summary>
	/// �J�������擾.
	/// </summary>
	/// <returns>�J������Ԃ�</returns>
	virtual const Camera& GetCamera() const;
	/// <summary>
	/// �^�C�}�[���擾.
	/// </summary>
	/// <returns>�^�C�}�[��Ԃ�</returns>
	virtual const Timer& GetTimer() const;
	/// <summary>
	/// �p�����[�^���擾.
	/// </summary>
	/// <returns>�p�����[�^��Ԃ�.</returns>
	virtual const UnitParameter& GetParameter() const;
	/// <summary>
	/// GUI��o�^����.
	/// </summary>
	/// <param name="gui">�ǉ�����GUI</param>
	virtual void AddGUI( GUIFramePtr gui );
	/// <summary>
	/// �v���C���[��GUI��o�^����.
	/// </summary>
	/// <param name="gui">�ǉ�����GUI</param>
	virtual void AddPlayerGUI( GUIFramePtr gui );
	/// <summary>
	/// GUI��o�^����͂���.
	/// </summary>
	/// <param name="gui">�폜����GUI</param>
	virtual void DeleteGUI( GUIFramePtr gui );
	/// <summary>
	/// GUI�R�}���h���擾����.
	/// <para>�}�E�X�̍��N���b�N��������Ă��鎞���s����܂�.</para>
	/// </summary>
	/// <returns>�R�}���h��Ԃ�.</returns>
	virtual GUICommand GetGUICommand() const;

#pragma endregion


#pragma region "���ۂł͌Ăяo���Ȃ�����."

public:
	/// <summary>
	/// �X�V.
	/// </summary>
	/// <param name="frameTimer">�t���[�����[�g</param>
	void Update( float frameTimer );
	/// <summary>
	/// �`��.
	/// </summary>
	void Draw();
	/// <summary>
	/// UI�̕`��.
	/// </summary>
	void DrawUI();
	/// <summary>
	/// ����.
	/// </summary>
	void Clear();

#pragma endregion


#pragma region "�A�N�Z�X�̋֎~"

private:
	/// <summary>
	/// �R�s�[�R���X�g���N�^(�O������͋֎~).
	/// </summary>
	World( const World& world );
	/// <summary>
	/// ������Z�q�I�[�o���[�h�֎~.
	/// </summary>
	World& operator =(const World& world);


#pragma endregion


#pragma region "�����o�ϐ�"

private:
	/// <summary>
	/// ���[���h�A�N�^�[.
	/// </summary>
	WorldUnit		mUnits;
	/// <summary>
	/// �v���C���[.
	/// </summary>
	UnitPtr			mPlayer;
	/// <summary>
	/// GUI�}�l�[�W���[.
	/// </summary>
	GUIManager		mGUIManager;
	/// <summary>
	/// �J����.
	/// </summary>
	Camera			mCamera;
	/// <summary>
	/// �^�C�}�[.
	/// </summary>
	Timer			mTimer;
	/// <summary>
	/// ���j�b�g�̃p�����[�^.
	/// </summary>
	UnitParameter	mParameter;

#pragma endregion


};

#endif

/********** End of File ******************************************************/
