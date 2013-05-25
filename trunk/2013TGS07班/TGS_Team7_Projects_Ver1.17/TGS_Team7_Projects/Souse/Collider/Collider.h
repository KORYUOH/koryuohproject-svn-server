/******************************************************************************
* File Name : Collider.h                          Ver : 1.00  Date : 2013-04-25
*
* Description :
*
*		�Փ˃N���X�D
*
* Author : Shouta Takemura.
*
******************************************************************************/
#ifndef _COLLIDER_H_
#define _COLLIDER_H_

/*---- �w�b�_�t�@�C���̓ǂݍ��� ---------------------------------------------*/

#include<gslib.h>

/*---- ��s�錾 -------------------------------------------------------------*/

/// <summary>���[���h���ۃN���X.</summary>
class IWorld;


/// <summary>
/// �Փ˃N���X.
/// </summary>
class Collider
{
public:
	/// <summary>
	/// �R���X�g���N�^.
	/// </summary>
	/// <param name="position">�ʒu���</param>
	/// <param name="radius">�Փ˗p���a</param>
	Collider( const GSvector2& position, float radius );
	/// <summary>
	/// �Փ˔���.
	/// </summary>
	/// <param name="other">�Փˑ���</param>
	virtual bool IsCollide( const Collider& other );
public:
	/// <summary>
	/// �ʒu���.
	/// </summary>
	GSvector2	mPosition;
	/// <summary>
	/// �ʒu���.
	/// </summary>
	float		mRadius;
	/// <summary>
	/// �Փ˃t���O.
	/// </summary>
	bool		mIsCollision;


}; // class Collider end


#endif // _COLLIDER_H_ end

/********** End of File ******************************************************/
