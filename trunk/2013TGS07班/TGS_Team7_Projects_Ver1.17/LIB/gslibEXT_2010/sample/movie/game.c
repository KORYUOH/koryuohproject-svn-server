/******************************************************************************
* File Name : game.c                             Ver : 1.00  Date : 2009-12-04
*
* Description :
*
*		���[�r�[�t�@�C���Đ��̃T���v���B
*
* Author : Moriharu Ohzu.
*
******************************************************************************/
#include	"game.h"
#include	<GSmovie.h>	// movie�p�̃w�b�_�t�@�C��

/****** �O���[�o���ϐ��錾 ***************************************************/

static float volume = 1.0f;

/*=============================================================================
*
* Purpose : �Q�[���������D
*
* Return  : �Ȃ�
*
*============================================================================*/
void gameInit( void )
{
	// ���[�r�[�̓ǂݍ���
	gsLoadMovie( "kouchou_last.wmv" );

	// ���[�r�[�̍Đ�
	gsPlayMovie();
}

/*=============================================================================
*
* Purpose : �Q�[�����C�������D
*
* Return  : �Ȃ��D
*
*============================================================================*/
void gameMain( void )
{
	// ��~�e�X�g
	if ( gsGetKeyTrigger( GKEY_P ) == GS_TRUE ) {
		gsStopMovie();
	}
	// �Đ��e�X�g
	if ( gsGetKeyTrigger( GKEY_R ) == GS_TRUE ) {
		gsPlayMovie();
	}

	// �{�����[���e�X�g
	if ( gsGetKeyState( GKEY_UP ) == GS_TRUE ) {
		volume += 0.01f;
	}
	if ( gsGetKeyState( GKEY_DOWN ) == GS_TRUE ) {
		volume -= 0.01f;
	}
	// �{�����[���̐ݒ� (�O�i�~���[�g�j�`1.0�i�ő�j�j
	gsSetMovieVolume( volume );

	// ���[�v�Đ��̃e�X�g
	if ( gsGetMovieTime() >= gsGetMovieEndTime() ) {
		gsStopMovie();
		gsSetMovieTime(0);
		gsPlayMovie();
	}
}

/*=============================================================================
*
* Purpose : �Q�[���`�揈���D
*
* Return  : �Ȃ��D
*
*============================================================================*/
void gameDraw( void )
{
	// ���[�r�[�̍X�V
	gsUpdateMovie();

	// ���[�r�[�̍Đ�
	gsDrawMovie();

	// �{�����[���̕`��
	gsDrawText( "Volume = %f", gsGetMovieVolume() );
}

/*=============================================================================
*
* Purpose : �Q�[���I�������D
*
* Return  : �Ȃ��D
*
*============================================================================*/
void gameFinish( void )
{
	// ���[�r�[�̍폜
	gsDeleteMovie();
}

/********** End of File ******************************************************/
