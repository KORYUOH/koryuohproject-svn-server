/******************************************************************************
* File Name : game.c                             Ver : 1.00  Date : 2010-12-03
*
* Description :
*
*		���y�Đ��̃T���v���D
*
* Author : Moriharu Ohzu.
*
******************************************************************************/
#include "game.h"
#include <GSmusic.h> // ���y�Đ��̂��߂̃w�b�_�t�@�C��

/****** �O���[�o���ϐ��錾 ***************************************************/

// �{�����[��
static float volume = 1.0f;

// ���E�o�����X
static float balance = 0.0f;

/*=============================================================================
*
* Purpose : �Q�[���������D
*
* Return  : �Ȃ�
*
*============================================================================*/
void gameInit( void )
{
	// ���y�t�@�C���̓ǂݍ��� (mp3, wma, wav, mid�Ȃǎg�p��)
	gsLoadMusic( 0, "hyperbeat_01.mp3", GS_TRUE ); // GS_TRUE�Ń��[�v�Đ�����
	// ���삵�������yID���o�C���h
	gsBindMusic( 0 );
	// �o�C���h���̉��y���Đ�
	gsPlayMusic();
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
	// ���삵�������yID���o�C���h
	gsBindMusic(0);

	// �ꎞ��~
	if ( gsGetKeyTrigger( GKEY_P ) == GS_TRUE ) {
		gsPauseMusic();
	}
	// �ꎞ��~����̕��A
	if ( gsGetKeyTrigger( GKEY_R ) == GS_TRUE ) {
		gsRestartMusic();
	}

	// �Đ�
	if ( gsGetKeyTrigger( GKEY_Z ) == GS_TRUE ) {
		gsPlayMusic();
	}
	// ��~
	if ( gsGetKeyTrigger( GKEY_S ) == GS_TRUE ) {
		gsStopMusic();
	}

	// �{�����[���̒��� ( 0.0(�~���[�g�j�`1.0(�ő�) )
	if ( gsGetKeyState( GKEY_UP )== GS_TRUE ) {
		volume += 0.01f;
	}
	if ( gsGetKeyState( GKEY_DOWN ) == GS_TRUE ) {
		volume -= 0.01f;
	}
	gsSetMusicVolume(volume);
	
	// ���E�o�����X ( -1.0f �` 1.0f )
	if ( gsGetKeyState( GKEY_LEFT ) == GS_TRUE ) {
		balance += 0.01f;
	}
	if ( gsGetKeyState( GKEY_RIGHT ) == GS_TRUE ) {
		balance -= 0.01f;
	}
	gsSetMusicBalance(balance);
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
	// ���삵�������yID���o�C���h
	gsBindMusic(0);

	// �I�����Ԃ�`��
	gsTextPos(0,0);
	gsDrawText( "EndTime = %f", gsGetMusicEndTime() );

	// ���݂̍Đ����Ԃ̕`��
	gsTextPos(0,16);
	gsDrawText( "Time = %f", gsGetMusicTime() );

	// �{�����[���̕`��
	gsTextPos(0,32);
	gsDrawText( "Volume = %f", gsGetMusicVolume() );

	// ���E�o�����X�̕`��
	gsTextPos(0,48);
	gsDrawText( "Balance = %f", gsGetMusicBalance() );
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
	// ���y�̍폜
	gsDeleteMusic(0);
}

/********** End of File ******************************************************/
