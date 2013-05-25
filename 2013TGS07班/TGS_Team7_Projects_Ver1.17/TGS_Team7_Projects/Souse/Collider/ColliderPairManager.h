/******************************************************************************
* File Name : ColliderPair.h                      Ver : 1.00  Date : 2013-04-25
*
* Description :
*
*		�Փ˃y�A�Ǘ��҃N���X�D
*
* Author : Shouta Takemura.
*
******************************************************************************/
#ifndef _COLLIDER_PAIR_MANAGER_H_
#define _COLLIDER_PAIR_MANAGER_H_

/*---- �w�b�_�t�@�C���̓ǂݍ��� ---------------------------------------------*/

#include<list>
#include"ColliderPair.h"

/*---- ��s�錾 -------------------------------------------------------------*/

/// <summary>
/// �Փ˃y�A�R���e�i.
/// </summary>
//typedef std::list<ColliderPair&> PairConter;
typedef std::list<PairPtr> PairConter;


/// <summary>
/// �Փ˃y�A�Ǘ��҃N���X.
/// </summary>
class ColliderPairManager
{
public:
	/// <summary>
	/// �R���X�g���N�^.
	/// </summary>
	ColliderPairManager();
	/// <summary>
	/// �y�A�̒ǉ�.
	/// </summary>
	void AddPair( PairPtr& pair );
	/// <summary>
	/// �y�A�̃\�[�g.
	/// </summary>
	void SortPair();
	/// <summary>
	/// �Փˉ�������.
	/// </summary>
	void CollisionResponse();
	/// <summary>
	/// ����.
	/// </summary>
	void Clear();
private:
	/// <summary>
	/// �V�K�y�A�̃\�[�g.
	/// </summary>
	/// <param name="run">���s�y�A</param>
	void SortEntryPair( PairConter::iterator& run );
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
	/// <summary>
	/// �Փ˃y�A�R���e�i
	/// </summary>
	PairConter	mPairsRun;
	/// <summary>
	/// �V�K�y�A�R���e�i.
	/// </summary>
	PairConter mPairEntry;
	/// <summary>
	/// �폜�����y�A�R���e�i.
	/// </summary>
	PairConter	mPairsDel;


}; // class ColliderPairMangaer end

#endif // _COLLIDER_PAIR_MANAGER_H_ end

/********** End of File ******************************************************/
