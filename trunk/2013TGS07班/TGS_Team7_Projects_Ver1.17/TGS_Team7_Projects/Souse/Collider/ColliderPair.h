/******************************************************************************
* File Name : ColliderPair.h                      Ver : 1.00  Date : 2013-04-25
*
* Description :
*
*		�Փ˃N���X�D
*
* Author : Shouta Takemura.
*
******************************************************************************/
#ifndef _COLLIDER_PAIR_H_
#define _COLLIDER_PAIR_H_

/*---- �w�b�_�t�@�C���̓ǂݍ��� ---------------------------------------------*/

#include<gslib.h>
#include<memory>

/*---- ��s�錾 -------------------------------------------------------------*/

/// <summary>���[���h���ۃN���X.</summary>
class IWorld;
/// <summary>���j�b�g.</summary>
class Unit;

/// <summary>
/// �y�A�^�C�v.
/// </summary>
enum PairType
{
	/// <summary>
	/// �V�K�y�A.
	/// </summary>
	PAIR_NEW = 0,
	/// <summary>
	/// �p���y�A.
	/// </summary>
	PAIR_KEEP,
	/// <summary>
	/// �폜�y�A.
	/// </summary>
	PAIR_DELLETE,
};

/// <summary>
/// �Փ˃y�A�N���X.
/// </summary>
class ColliderPair
{
public:
	/// <summary>
	/// �R���X�g���N�^.
	/// </summary>
	/// <param name="unitA">���j�b�gA</param>
	/// <param name="unitB">���j�b�gB</param>
	ColliderPair( Unit& unitA, Unit& unitB );
	/// <summary>
	/// �Փˉ�������.
	/// </summary>
	void CollisionResponse();
	/// <summary>
	/// �V�K�Փˏ���.
	/// </summary>
	void CollideEnter();
	/// <summary>
	/// �p���Փˏ���.
	/// </summary>
	void CollideStay();
	/// <summary>
	/// �Փˉ����㏈��.
	/// </summary>
	void CollideExit();

public:
	bool operator == ( const ColliderPair& other );
private:
	/// <summary>
	/// �R�s�[�R���X�g���N�^�̋֎~.
	/// <para>�O���A�N�Z�X�̋֎~.</para>
	/// </summary>
	ColliderPair( const ColliderPair& other );
	/// <summary>
	/// ������Z�q�I�[�o�[���[�h�̋֎~
	/// <para>�O���A�N�Z�X�̋֎~.</para>
	/// </summary>
	ColliderPair& operator = ( const ColliderPair& other );


public:
	/// <summary>
	/// ���j�b�gA.
	/// </summary>
	PairType	mType;
	/// <summary>
	/// ���j�b�gA.
	/// </summary>
	Unit&		mUnitA;
	/// <summary>
	/// ���j�b�gB.
	/// </summary>
	Unit&		mUnitB;

};

/// <summary>
/// ���j�b�g�V�F�A�h�|�C���^.
/// </summary>
typedef std::shared_ptr<ColliderPair> PairPtr;


#endif // _UNIT_FACTORY_H_ end

/********** End of File ******************************************************/
