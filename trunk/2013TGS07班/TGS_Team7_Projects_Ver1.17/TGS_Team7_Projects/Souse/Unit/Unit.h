/******************************************************************************
* File Name : Unit.h                              Ver : 1.00  Date : 2013-04-25
*
* Description :
*
*		���j�b�g���ۃN���X�D
*
* Author : Shouta Takemura.
*
******************************************************************************/
#ifndef _UNIT_H_
#define _UNIT_H_

/*---- �w�b�_�t�@�C���̓ǂݍ��� ---------------------------------------------*/

#include"Actor.h"
#include"UnitPtr.h"
#include"UnitElement.h"
#include"UnitHierarchy.h"
#include"UnitParameter.h"


/*---- ��s�錾 -------------------------------------------------------------*/

/// <summary>���[���h���ۃN���X.</summary>
class IWorld;
/// <summary>���j�b�gID.</summary>
enum UnitID;


/// <summary>
/// ���j�b�g���ۃN���X.
/// </summary>
class Unit : public Actor
{

public:
	/// <summary>
	/// �R���X�g���N�^.
	/// </summary>
	/// <param name="world">���[���h</param>
	/// <param name="flag">�t���O�Ǘ���</param>
	/// <param name="parent">�e���j�b�g</param>
	/// <param name="id">���j�b�gID</param>
	///	 <param name="position">�������W</param>
	/// <param name="radius">�Փ˔���p�̔��a</param>
	Unit( IWorld& world, IFlagManager& flag, Unit* parent, UnitID id , const GSvector2& position ,float radius );


#pragma region �Փ˗p�֐�.

public:
	/// <summary>
	/// �Փˏ���.
	/// </summary>
	/// <param name="unit">�Փˑ��胆�j�b�g</param>
	/// <returns>�Փ˂��Ă�ΐ^�A���Ă��Ȃ���΋U��Ԃ�</returns>
	bool IsCollide( Unit& unit );
	/// <summary>
	/// �Փ˂����u�Ԃ̏���.
	/// </summary>
	/// <param name="other">���胆�j�b�g</param>
	virtual void OnCollideEnter( Unit& other );
	/// <summary>
	/// �Փ˂��Ă���Ԃ̏���.
	/// </summary>
	/// <param name="other">���胆�j�b�g</param>
	virtual void OnCollideStay( Unit& other );
	/// <summary>
	/// �Փ˂����I�u�W�F�N�g�����ꂽ���̏���.
	/// </summary>
	/// <param name="other">���胆�j�b�g</param>
	virtual void OnCollideExit( Unit& other );

#pragma endregion

public:
	/// <summary>
	/// ���x���A�b�v.
	/// </summary>
	/// <returns>����������ɏI���ΐ^�A�����łȂ���΋U��Ԃ�.</returns>
	bool LevelUp();
	/// <summary>
	/// ���x���_�E��.
	/// </summary>
	/// <returns>����������ɏI���ΐ^�A�����łȂ���΋U��Ԃ�.</returns>
	bool LevelDown();
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
	/// <summary>
	/// �v�f�̎擾.
	/// </summary>
	/// <returns>���j�b�g�̗v�f��Ԃ�</returns>
	const UnitElement& GetElement() const;
	/// <summary>
	/// GUI�̓o�^.
	/// </summary>
	void GUIEntry();
	/// <summary>
	/// GUI�̓o�^����.
	/// </summary>
	void GUILeave();
	/// <summary>
	/// �e�K�w������������.
	/// </summary>
	/// <param name="other">��r���j�b�g</param>
	/// <returns>��������ΐ^�A�����łȂ���΋U��Ԃ�.</returns>
	bool IsParent( const Unit& other ) const;


protected:
	/// <summary>
	/// ���j�b�g�̒ǉ�.
	/// </summary>
	/// <param name="id">�ǉ�������</param>
	/// <param name="frameTimer">���j�b�g</param>
	virtual void AddUnit( UnitID id, UnitPtr unit );
	/// <summary>
	/// ���j�b�g�̍폜.
	/// </summary>
	/// <param name="frameTimer">���j�b�g</param>
	virtual void DeletUnit( Unit* unit );

protected:
	/// <summary>
	/// �v�f.
	/// </summary>
	UnitElement		mElement;
	/// <summary>
	/// ���j�b�g�K�w.
	/// </summary>
	UnitHierarchy	mHierarchy;


}; // class Unit end

#endif // _UNIT_H_ end

/********** End of File ******************************************************/
