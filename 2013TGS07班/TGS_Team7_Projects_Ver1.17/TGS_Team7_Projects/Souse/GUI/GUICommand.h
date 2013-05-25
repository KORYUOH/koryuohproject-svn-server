/******************************************************************************
* File Name : GUICommand.h                        Ver : 1.00  Date : 2013-04-25
*
* Description :
*
*		���[�U�[�C���^�[�t�F�[�X�t���[���N���X�D
*
* Author : Shouta Takemura.
*
******************************************************************************/
#ifndef _GUI_COMMAND_H_
#define _GUI_COMMAND_H_


/// <summary>
/// GUI�R�}���h�񋓌^.
/// </summary>
enum GUICommand
{
	/// <summary>
	/// �U�R�}���h.
	/// </summary>
	GUI_COMMAND_FALSE = 0,
	/// <summary>
	/// �^�R�}���h.
	/// </summary>
	GUI_COMMAND_TRUE = 1,
	/// <summary>
	/// �R�}���h�������Ȃ�GUI.
	/// </summary>
	GUI_COMMAND_NOT_COLLIDER,
	/// <summary>
	/// �E�C���h�E�����.
	/// </summary>
	GUI_COMMAND_WINDOW_CLOSE,
	/// <summary>
	/// �l�ނ̈ړ�.
	/// </summary>
	GUI_COMMAND_HUMAN_MUVEMENT,
	/// <summary>
	/// ���x���A�b�v.
	/// </summary>
	GUI_COMMAND_FACILITY_LEVEL_UP,
	/// <summary>
	/// �H��쐬�R�}���h.
	/// </summary>
	GUI_COMMAND_CREATE_FACTORY,
	/// <summary>
	/// �_��쐬�R�}���h.
	/// </summary>
	GUI_COMMAND_CREATE_FARM,
	/// <summary>
	/// �Z��쐬�R�}���h.
	/// </summary>
	GUI_COMMAND_CREATE_HOUSING,
	/// <summary>
	/// �ړ��{�ݍ쐬�R�}���h.
	/// </summary>
	GUI_COMMAND_CREATE_AIRFIELD,


}; // enum GUICommand end


#endif // _GUI_COMMAND_H_ end

/********** End of File ******************************************************/
