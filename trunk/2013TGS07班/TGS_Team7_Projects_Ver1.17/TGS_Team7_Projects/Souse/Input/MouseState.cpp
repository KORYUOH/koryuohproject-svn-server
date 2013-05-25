/******************************************************************************
* File Name : Mouse.h                             Ver : 1.00  Date : 2013-05-09
*
* Description :
*
*		�}�E�X���̓N���X�D
*
* Author : Shouta Takemura.
*
******************************************************************************/
#include"MouseState.h"
#include"../Utility/Screen.h"

/// <summary>
/// �R���X�g���N�^.
/// </summary>
MouseState::MouseState()
{
	initialize();
}

/// <summary>
/// �f�X�g���N�^.
/// </summary>
MouseState::~MouseState()
{
}

/// <summary>
/// ������.
/// </summary>
void MouseState::initialize()
{
	// �ړ��䗦��ݒ�.
	gsSetMouseMoveRatio( (float)Screen::WIDTH / (float)Screen::HEIGHT );

	// �}�E�X�J�[�\���̈ړ��͈͂�ݒ�.
	gsSetMousePhysicalBlock( 0, Screen::WIDTH, 0, Screen::HEIGHT );
}

/// <summary>
/// �ړ������̎擾.
/// </summary>
/// <returns>�ړ�����</returns>
GSvector2 MouseState::GetVelocity() const
{
	// �ʒu���C������.
	MouseMoveLimit();

	// �ړ��ʕۑ��p�ϐ�.
	int x, y, z;

	gsGetMouseOffsetPosition( &x, &y, &z );

	// �ړ��ʂ���x�N�g�����쐬.
	GSvector2 velocity( x, y );

	return velocity.getNormalized();
}

/// <summary>
/// �}�E�X�̈ʒu���擾.
/// </summary>
/// <returns>�ʒu���</returns>
GSvector2 MouseState::GetMousePosition() const
{
	// �}�E�X�ۑ��p�̕ϐ���錾.
	int mouseX, mouseY;

	// �}�E�X�̈ʒu��ۑ�.
	gsGetMouseCursorPosition( &mouseX, &mouseY );

	// �}�E�X�̈ʒu��ۑ�.
	GSvector2 mousePosition( mouseX, mouseY );

	// �}�E�X�̈ʒu��Ԃ�.
	return mousePosition;
}

/// <summary>
/// �}�E�X�̃{�^���̉�����Ԃ��擾.
/// </summary>
/// <param name="state">���ׂ����}�E�X�̃{�^��</param>
/// <returns>������Ă���ΐ^�C������Ă��Ȃ���΋U��Ԃ�.</returns>
bool MouseState::IsMouseButtonDown( GMOUSTATE state ) const
{
	return gsGetMouseButtonState( state ) == GS_TRUE;
}

/// <summary>
/// �}�E�X�̃{�^���������ꂽ�����ׂ�D
/// </summary>
/// <param name="state">���ׂ����}�E�X�̃{�^��</param>
/// <returns>�����ꂽ��^�C������Ȃ���΋U��Ԃ��D</returns>
bool MouseState::IsMouseButtonTrigger( GMOUSTATE state ) const
{
	return gsGetMouseButtonTrigger( state ) == GS_TRUE;
}

/// <summary>
/// �}�E�X�̃{�^���������ꂽ�����ׂ�.
/// </summary>
/// <param name="state">���ׂ����}�E�X�̃{�^��</param>
/// <returns>�}�E�X�̃{�^���̗����ꂽ��Ԃ�Ԃ�.</returns>
bool MouseState::IsMouseButtonUp( GMOUSTATE state ) const
{
	return gsGetMouseButtonDetach( state ) == GS_TRUE;
}

/// <summary>
/// �}�E�X�̈ړ��͈͂��Œ肷��.
/// </summary>
void MouseState::MouseMoveLimit() const
{
	// �ړ��䗦��ݒ�.
	gsSetMouseMoveRatio( (float)Screen::WIDTH / (float)Screen::HEIGHT );

	// �}�E�X�J�[�\���̈ړ��͈͂�ݒ�.
	gsSetMousePhysicalBlock( 0, Screen::WIDTH, 0, Screen::HEIGHT );

	// �ʒu���擾.
	GSvector2 position = GetMousePosition();

	position.x = CLAMP( position.x, 0, Screen::WIDTH );
	position.y = CLAMP( position.y, 0, Screen::WIDTH );

	// �ʒu���C��.
	gsSetMouseCursorPosition( position.x, position.y );
}

/********** End of File ******************************************************/
