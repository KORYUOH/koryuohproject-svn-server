/******************************************************************************
* File Name : UIFrame.h                          Ver : 1.00  Date : 2013-04-25
*
* Description :
*
*		���[�U�[�C���^�[�t�F�[�X�t���[���N���X�D
*
* Author : Shouta Takemura.
*
******************************************************************************/
#include"GUIFrame.h"
#include<algorithm>
#include"GUI.h"
#include"GUIPtr.h"
#include"Button.h"
#include"../Draw/Renderer.h"
#include"../Flag/FlagID.h"

/// <summary>
/// �R���X�g���N�^.
/// </summary>
GUIFrame::GUIFrame() :
	mPosition( 0.0f, 0.0f ),
	mAngle( 0.0f ),
	mRange( 0.0f, 0.0f, 0.0, 0.0f ),
	mIsWindow( false )
{
	mGUIs.clear();
}

/// <summary>
/// �R���X�g���N�^.
/// </summary>
/// <param name="position">�t���[���̒������W</param>
/// <param name="angle">�p�x</param>
GUIFrame::GUIFrame( const GSvector2& position, float angle ) :
	mPosition( position ),
	mAngle( angle ),
	mRange( 0.0f, 0.0f, 0.0, 0.0f ),
	mIsWindow( false )
{
	mGUIs.clear();
}

/// <summary>
/// �`��.
/// </summary>
void GUIFrame::Draw() const
{
	if( mIsWindow )
	{
		//
		GSvector2 vec;

		// �E�C���h�E��\������.
		Renderer::GetInstance()->DrawRectTexture( TEXTURE_GUI_FRAME, GSvector2(mRange.left,mRange.top), mRange, GSvector2(0.0f,0.0f) );
	}

	// UI�����ɑ��݂��Ȃ���.
	if( mGUIs.size() == 0 )
	{
		// �����I��.
		return; 
	}

	// ���ׂĂ�UI��`�悷��.
	std::for_each( mGUIs.begin(), mGUIs.end(), [&]( GUIPtr gui )
	{
		// GUI��`�悷��.
		gui->Draw( mPosition, mAngle );
	});
}

/// <summary>
/// �͈͂��g��.
/// </summary>
void GUIFrame::RangeExpansion( Collider& collider )
{
	GSvector2 start( collider.mPosition.x - collider.mRadius, collider.mPosition.y - collider.mRadius );
	GSvector2 end( collider.mPosition.x + collider.mRadius, collider.mPosition.y + collider.mRadius );

	// �ŏ��̂ЂƂڂ̎�.
	if( mGUIs.size() == 1 )
	{
		mRange.left = start.x;
		mRange.right = end.x;
		mRange.top = start.y;
		mRange.bottom = end.y;
		// �����I��.
		return;
	}

	// �傫�����g������.
	mRange.left = MIN( mRange.left, start.x );
	mRange.top = MIN( mRange.top, start.y );
	mRange.right = MAX( mRange.right, end.x );
	mRange.bottom = MAX( mRange.bottom, end.y );
}

/// <summary>
/// UI��ǉ�����.
/// </summary>
/// <param name="addUI">�ǉ�����UI</param>
void GUIFrame::AddGUI( GUIPtr addUI )
{
	// UI��ǉ�����.
	mGUIs.push_back( addUI );

	// GUI�͈͂��g�傷��.
	RangeExpansion( addUI->GetCollider() );
}

/// <summary>
/// �E�C���h�E��ǉ�����.
/// </summary>
/// <param name="frameTimer">�t���O�Ǘ���</param>
void GUIFrame::AddWindow( IFlagManager& flagManager )
{
	GUIPtr gui = std::make_shared<Button>( Collider( GSvector2(250.0f,20.0f),16.0f ), flagManager, FLAG_WINDOW_CLOSE, TEXTURE_GUI_BOTTON_CLOSE);
	// �E�C���h�E����{�^����ǉ�����.
	AddGUI( gui );

	// GUI�͈͂��g������.
	RangeExpansion( gui->GetCollider() );

	// �E�C���h�E���쐬����.
	mIsWindow = true;
}

/// <summary>
/// �X�V.
/// </summary>
/// <param name="frameTimer">�t���[�����[�g</param>
void GUIFrame::Update( float frameTimer )
{
	// GUI�����݂��Ă��Ȃ���.
	if( mGUIs.size() == 0 )
	{
		return;
	}

	// ���ׂĂ�UI���X�V����.
	std::for_each( mGUIs.begin(), mGUIs.end(), [&]( GUIPtr gui )
	{
		// GUI���X�V����.
		gui->Update( frameTimer );
	});
}

/// <summary>
/// �Փ˂̍X�V.
/// </summary>
/// <param name="other">�Փˑ���GUI</param>
void GUIFrame::CollisionUpdate( GUIFrame& other )
{
	std::for_each( mGUIs.begin(), mGUIs.end(), [&]( GUIPtr gui )
	{
		other.CollisionUpdate( *gui );
	});
}

/// <summary>
/// �Փ˂̍X�V.
/// </summary>
/// <param name="other">�Փˑ���GUI</param>
/// <returns>�Փ˂��Ă��鎞�^�A�����łȂ���΋U��Ԃ�.</returns>
void GUIFrame::CollisionUpdate( GUI& other )
{
	std::for_each( mGUIs.begin(), mGUIs.end(), [&]( GUIPtr gui )
	{
		gui->CollisionUpdate( other );
	});
}

/// <summary>
/// �t���O�̖�����.
/// </summary>
void GUIFrame::FlagDisable()
{
	std::for_each( mGUIs.begin(), mGUIs.end(), []( GUIPtr gui )
	{
		gui->FlagDisable();
	});
}

/********** End of File ******************************************************/
