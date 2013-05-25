/******************************************************************************
* File Name : Space.h                              Ver : 1.00  Date : 2013-04-25
*
* Description :
*
*		�F���N���X�D
*
* Author : Shouta Takemura.
*
******************************************************************************/
#ifndef _UNIT_SPACE_H_
#define _UNIT_SPACE_H_

/*---- �w�b�_�t�@�C���̓ǂݍ��� ---------------------------------------------*/

#include"Unit.h"
#include"../Draw/TextureNumber.h"

/*---- ��s�錾 -------------------------------------------------------------*/

/// <summary>���[���h���ۃN���X.</summary>
class IWorld;


/// <summary>
/// �F���N���X.
/// </summary>
class Space : public Unit 
{

public:
	/// <summary>
	/// �R���X�g���N�^.
	/// </summary>
	/// <param name="world">���[���h</param>
	/// <param name="flag">�t���O�Ǘ���</param>
	///	 <param name="position">�������W</param>
	/// <param name="radius">�Փ˔���p�̔��a</param>
	Space( IWorld& world, IFlagManager& flag, const GSvector2& position, float radius );


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

protected:	
	/// <summary>
	/// �����ւ̃A�N�Z�X.
	/// </summary>
	/// <param name="money">�����̑�����</param>
	/// <returns>����ɃA�N�Z�X�ł���ΐ^�A�ł��Ȃ���΋U��Ԃ�.</returns>
	virtual bool AccessMoney( float money );

private:
	/// <summary>
	/// ����.
	/// </summary>
	float			mManey;
	/// <summary>
	/// �����`��Ǘ���.
	/// </summary>
	TextureNumber	mNumber;
};

#endif

/********** End of File ******************************************************/
