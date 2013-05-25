/******************************************************************************
* File Name : Star.h                             Ver : 1.00  Date : 2013-04-25
*
* Description :
*
*		�f���N���X�D
*
* Author : Shouta Takemura.
*
******************************************************************************/
#ifndef _UNIT_STAR_H_
#define _UNIT_STAR_H_

/*---- �w�b�_�t�@�C���̓ǂݍ��� ---------------------------------------------*/

#include"Unit.h"
#include"../Draw/TextureNumber.h"

/*---- ��s�錾 -------------------------------------------------------------*/

/// <summary>���[���h���ۃN���X.</summary>
class IWorld;


/// <summary>
/// �f���N���X.
/// </summary>
class Star : public Unit
{

public:
	/// <summary>
	/// �R���X�g���N�^.
	/// </summary>
	/// <param name="world">���[���h</param>
	/// <param name="flag">�t���O�Ǘ���</param>
	/// <param name="parent">�e���j�b�g</param>
	///	 <param name="position">�������W</param>
	/// <param name="radius">�Փ˔���p�̔��a</param>
	Star( IWorld& world, IFlagManager& flag, Unit* parent, const GSvector2& position );


public:
	/// <summary>
	/// �X�V.
	/// </summary>
	/// <param name="frameTimer">�t���[���^�C�}�[</param>
	virtual void Update( float frameTimer );
	/// <summary>
	/// ���Y����.
	/// </summary>
	/// <param name="frameTimer">�t���[���^�C�}�[</param>
	virtual void Production( float frameTimer );
	/// <summary>
	/// �ێ��R�X�g�x��������.
	/// </summary>
	/// <param name="frameTimer">�t���[���^�C�}�[</param>
	virtual void Maintenance( float frameTimer );
	/// <summary>
	/// �`��.
	/// </summary>
	virtual void Draw();
	/// <summary>
	/// UI�̕`��.
	/// </summary>
	virtual void DrawUI();

public:
	/// <summary>
	/// �H���ւ̃A�N�Z�X.
	/// </summary>
	/// <param name="food">�H���̑�����</param>
	/// <returns>����ɃA�N�Z�X�ł���ΐ^�A�ł��Ȃ���΋U��Ԃ�.</returns>
	virtual bool AccessFood( float food );
	/// <summary>
	/// �����ւ̃A�N�Z�X.
	/// </summary>
	/// <param name="money">�����̑�����</param>
	/// <returns>����ɃA�N�Z�X�ł���ΐ^�A�ł��Ȃ���΋U��Ԃ�.</returns>
	virtual bool AccessMoney( float money );
	/// <summary>
	/// �l�ނւ̃A�N�Z�X.
	/// </summary>
	/// <param name="human">�l�̑�����</param>
	/// <returns>����ɃA�N�Z�X�ł���ΐ^�A�ł��Ȃ���΋U��Ԃ�.</returns>
	virtual bool AccessHuman( float human );

private:
	/// <summary>
	/// �{�݂̍쐬.
	/// </summary>
	void CreateFacility();
	/// <summary>
	/// �Z��{�݂̍쐬.
	/// </summary>
	/// <param name="angle">�p�x</param>
	void CreateHousing( float angle );
	/// <summary>
	/// �{�݂̍쐬.
	/// </summary>
	/// <param name="angle">�p�x</param>
	void CreateFactory( float angle );
	/// <summary>
	/// �{�݂̍쐬.
	/// </summary>
	/// <param name="angle">�p�x</param>
	void CreateFarm( float angle );


private:
	/// <summary>
	/// �l��.
	/// </summary>
	float			mHumanResources;
	/// <summary>
	/// �H��.
	/// </summary>
	float			mFood;
	/// <summary>
	/// �����`��Ǘ���.
	/// </summary>
	TextureNumber	mNumber;

};

#endif

/********** End of File ******************************************************/
