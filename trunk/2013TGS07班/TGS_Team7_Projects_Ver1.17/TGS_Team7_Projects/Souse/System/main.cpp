/******************************************************************************
* File Name : main.cpp                           Ver : 1.00  Date : 2013-02-05
*
* Description :
*
*		���C�������D
*
******************************************************************************/
#include"ShootingApplication.h"

// �����J�I�v�V����
#pragma comment( linker, "/entry:mainCRTStartup" )
#pragma comment( linker, "/SUBSYSTEM:WINDOWS" )


/// <summary>
//  ���C���֐��D
/// </summary>
/// <param name="argc">�R�}���h���C���I�v�V�����̐��̃|�C���^</param>
/// <param name="argv">�R�}���h���C���I�v�V������\��������̔z��</param>
void main( int argc, char* argv[] )
{
	/* �A�v���P�[�V�����̍쐬. */
	ShootingApplication application( argc, argv );

	/* �A�v���P�[�V���������s����. */
	application.Run();

}

/********** End of File ******************************************************/
