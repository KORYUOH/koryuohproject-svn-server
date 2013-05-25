/******************************************************************************
* File Name : Farm.h                          Ver : 1.00  Date : 2013-04-25
*
* Description :
*
*		�_��{�݃N���X�D
*
* Author : Shouta Takemura.
*
******************************************************************************/
#ifndef _UNIT_FARM_H_
#define _UNIT_FARM_H_

/*---- �w�b�_�t�@�C���̓ǂݍ��� ---------------------------------------------*/

#include"Unit.h"
#include"../Draw/TextureNumber.h"

/*---- ��s�錾 -------------------------------------------------------------*/

/// <summary>���[���h���ۃN���X.</summary>
class IWorld;


/// <summary>
/// �_��{�݃N���X.
/// </summary>
class Farm : public Unit 
{

public:
	/// <summary>
	/// �R���X�g���N�^.
	/// </summary>
	/// <param name="world">���[���h</param>
	/// <param name="flag">�t���O�Ǘ���</param>
	/// <param name="parent">�e���j�b�g</param>
	///	 <param name="collider">���̏Փˏ��</param>
	/// <param name="angle">�����猩���p�x</param>
	Farm( IWorld& world, IFlagManager& flag, Unit* parent, const Collider& collider, float angle );


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


private:
	/// <summary>
	/// �����`��Ǘ���.
	/// </summary>
	TextureNumber	mNumber;
	/// <summary>
	/// �p�x.
	/// </summary>
	float			mAngle;
};

#endif // _UNIT_FARM_H_ end

/********** End of File ******************************************************/
