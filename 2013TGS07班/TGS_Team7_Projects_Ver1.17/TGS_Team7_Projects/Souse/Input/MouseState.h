/******************************************************************************
* File Name : MouseState.h                             Ver : 1.00  Date : 2013-05-09
*
* Description :
*
*		�}�E�X�N���X�D
*
* Author : Shouta Takemura.
*
******************************************************************************/
#ifndef		_MOUSE_STATE_H_
#define		_MOUSE_STATE_H_

/*---- �w�b�_�t�@�C���̓ǂݍ��� ---------------------------------------------*/

#include<gslib.h>


/// <summary>
/// �}�E�X�N���X.
/// </summary>
class MouseState
{

public:
	/// <summary>
	/// �R���X�g���N�^.
	/// </summary>
	MouseState();
	/// <summary>
	/// �f�X�g���N�^.
	/// </summary>
	~MouseState();
	/// <summary>
	/// ������.
	/// </summary>
	void initialize();
	/// <summary>
	/// �ړ������̎擾.
	/// </summary>
	/// <returns>�ړ�����</returns>
	GSvector2 GetVelocity() const;
	/// <summary>
	/// �}�E�X�̈ʒu���擾.
	/// </summary>
	/// <returns>�ʒu���</returns>
	GSvector2 GetMousePosition() const;
	/// <summary>
	/// �}�E�X�̃{�^���̉�����Ԃ��擾.
	/// </summary>
	/// <param name="state">���ׂ����}�E�X�̃{�^��</param>
	/// <returns>������Ă���ΐ^�C������Ă��Ȃ���΋U��Ԃ�.</returns>
	bool IsMouseButtonDown( GMOUSTATE state ) const;
	/// <summary>
	/// �}�E�X�̃{�^���������ꂽ�����ׂ�D
	/// </summary>
	/// <param name="state">���ׂ����}�E�X�̃{�^��</param>
	/// <returns>�����ꂽ��^�C������Ȃ���΋U��Ԃ��D</returns>
	bool IsMouseButtonTrigger( GMOUSTATE state ) const;
	/// <summary>
	/// �}�E�X�̃{�^���������ꂽ�����ׂ�.
	/// </summary>
	/// <param name="state">���ׂ����}�E�X�̃{�^��</param>
	/// <returns>�}�E�X�̃{�^���̗����ꂽ��Ԃ�Ԃ�.</returns>
	bool IsMouseButtonUp( GMOUSTATE state ) const;
	/// <summary>
	/// �}�E�X�̈ړ��͈͂��Œ肷��.
	/// </summary>
	void MouseMoveLimit() const;


private:
	/// <summary>
	/// �R�s�[�R���X�g���N�^.
	/// <para>�O���A�N�Z�X�̋֎~.</para>
	/// </summary>
	MouseState( const MouseState& other );
	/// <summary>
	/// ������Z�q.
	/// <para>�O���A�N�Z�X�̋֎~.</para>
	/// </summary>
	MouseState& operator =( const MouseState& other );

};

#endif // !_MOUSE_STATE_H_

/********** End of File ******************************************************/
