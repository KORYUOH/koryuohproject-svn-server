/******************************************************************************
* File Name : IWorld.h                           Ver : 1.00  Date : 2012-12-14
*
* Description :
*
*		���[���h���ۃN���X�D
*
******************************************************************************/
#ifndef _I_WORLD_H_
#define _I_WORLD_H_

/*---- �w�b�_�t�@�C���̓ǂݍ��� ---------------------------------------------*/

#include	"../Unit/UnitPtr.h"
#include	"../GUI/GUIFramePtr.h"

/*---- ��s�錾 -------------------------------------------------------------*/

class Camera;
class Timer;
enum UnitID;
enum GUICommand;
class UnitParameter;

/// <summary>
/// ���[���h���ۃN���X.
/// </summary>
class IWorld
{
public:
	/// <summary>
	/// ���z�f�X�g���N�^.
	/// </summary>
	virtual ~IWorld() {}
	/// <summary>
	/// �A�N�^�[�̒ǉ�.
	/// </summary>
	/// <param name="id">�A�N�^�[�}�l�[�W��ID</param>
	/// <param name="actor">�ǉ�����A�N�^�[</param>
	virtual void Add( UnitID id,UnitPtr actor ) = 0;
	/// <summary>
	/// �v���C���[�̐���.
	/// </summary>
	/// <param name="actor">�ǉ�����v���C���[�A�N�^�[</param>
	virtual void AddPlayer( UnitPtr actor ) = 0;
	/// <summary>
	/// �v���C���[�̎擾.
	/// </summary>
	/// <returns>�v���C���[�A�N�^�[���擾</returns>
	virtual UnitPtr GetPlayer() const = 0;
	/// <summary>
	/// �J�������擾.
	/// </summary>
	/// <returns>�J������Ԃ�</returns>
	virtual const Camera& GetCamera() const = 0;
	/// <summary>
	/// �^�C�}�[���擾.
	/// </summary>
	/// <returns>�^�C�}�[��Ԃ�</returns>
	virtual const Timer& GetTimer() const = 0;
	/// <summary>
	/// �p�����[�^���擾.
	/// </summary>
	/// <returns>�p�����[�^��Ԃ�.</returns>
	virtual const UnitParameter& GetParameter() const = 0;
	/// <summary>
	/// GUI��o�^����.
	/// </summary>
	/// <param name="gui">�ǉ�����GUI</param>
	virtual void AddGUI( GUIFramePtr gui ) = 0;
	/// <summary>
	/// �v���C���[��GUI��o�^����.
	/// </summary>
	/// <param name="gui">�ǉ�����GUI</param>
	virtual void AddPlayerGUI( GUIFramePtr gui ) = 0;
	/// <summary>
	/// GUI��o�^����͂���.
	/// </summary>
	/// <param name="gui">�폜����GUI</param>
	virtual void DeleteGUI( GUIFramePtr gui ) = 0;
	/// <summary>
	/// GUI�R�}���h���擾����.
	/// <para>�}�E�X�̍��N���b�N��������Ă��鎞���s����܂�.</para>
	/// </summary>
	/// <returns>�R�}���h��Ԃ�.</returns>
	virtual GUICommand GetGUICommand() const = 0;
};

#endif

/********** End of File ******************************************************/
