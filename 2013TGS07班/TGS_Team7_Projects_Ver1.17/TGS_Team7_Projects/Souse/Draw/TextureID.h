/******************************************************************************
* File Name : TextureID.h                         Ver : 1.00  Date : 2012-12-14
*
* Description :
*
*		�e�N�X�`��ID�D
*
* Author : Shouta Takemura.
*
******************************************************************************/
#ifndef _TEXTURE_ID_H_
#define _TEXTURE_ID_H_


/// <summary>
/// �e�N�X�`��ID�񋓌^.
/// </summary>
enum TextureID
{

	/*---- ���j�b�g�摜 -----------------------------------------------------*/

	/// <summary>
	/// �F���摜.
	/// </summary>
	TEXTURE_UNIT_SPACE= 0,

	/// <summary>
	/// �f���摜1.
	/// </summary>
	TEXTURE_UNIT_STAR,

	/// <summary>
	/// �Z��{�݉摜1
	/// </summary>
	TEXTURE_UNIT_HOUSE,

	/// <summary>
	/// �_��{�݉摜.
	/// </summary>
	TEXTURE_UNIT_FARM,

	/// <summary>
	/// �H��{�݉摜.
	/// </summary>
	TEXTURE_UNIT_FACTORY,

	/// <summary>
	/// �ړ��{�݉摜.
	/// </summary>
	TEXTURE_UNIT_AIRFIELD,


	/*---- �L�����N�^�[�摜ID -----------------------------------------------*/

	/// <summary>
	/// �v���C���[�摜.
	/// </summary>
	TEXTURE_UNIT_PLAYER,
	/// <summary>
	/// �v���C���[�摜.
	/// </summary>
	TEXTURE_UNIT_PLAYER2,


	/*---- UI�摜 -------------------------------------------------------*/

	/// <summary>
	/// UI�t���[���摜.
	/// </summary>
	TEXTURE_GUI_FRAME,
	/// <summary>
	/// �{�^��GUI�摜.
	/// </summary>
	TEXTURE_GUI_BUTTON,	
	/// <summary>
	/// �{�^��GUI�摜.
	/// </summary>
	TEXTURE_GUI_BOTTON_CLOSE,
	/// <summary>
	/// ���x���A�b�v�{�^���摜.
	/// </summary>
	TEXTURE_GUI_BOTTON_LEVEL_UP,
	/// <summary>
	/// �Z��{�^���摜.
	/// </summary>
	TEXTURE_GUI_BOTTON_HOUSING,
	/// <summary>
	/// �H��{�^���摜.
	/// </summary>
	TEXTURE_GUI_BOTTON_FACTORY,
	/// <summary>
	/// �_��{�^���摜.
	/// </summary>
	TEXTURE_GUI_BOTTON_FRAM,
	/// <summary>
	/// �_�O���t�̉摜.
	/// </summary>
	TEXTURE_GUI_BAR_CHART,

	/// <summary>
	/// �X�R�A�摜
	/// </summary>
	TEXTURE_GUI_SCORE,
	/// <summary>
	/// �^�C�}�[�摜.
	/// </summary>
	TEXTURE_GUI_TIMER,
	/// <summary>
	/// �����摜.
	/// </summary>
	TEXTURE_GUI_MONEY,	
	/// <summary>
	/// �l�މ摜.
	/// </summary>
	TEXTURE_GUI_HUMAN,
	/// <summary>
	/// �l�ލő�摜.
	/// </summary>
	TEXTURE_GUI_HUMAN_MAX,
	/// <summary>
	/// �H���摜.
	/// </summary>
	TEXTURE_GUI_FOOD,
	/// <summary>
	/// ���x���摜.
	/// </summary>
	TEXTURE_GUI_LEVEL,
	/// <summary>
	/// �����摜.
	/// </summary>
	TEXTURE_GUI_NUMBER,

	/*---- �V�[���摜 ---------------------------------------------------*/

	//�^�C�g���摜
	TEXTURE_SCENE_TITLE,
	//�^�C�g�������摜
	TEXTURE_SCENE_TITLE_NAME,
	//�^�C�g�������摜
	TEXTURE_SCENE_TITLE_TUTOLAL,
	//�G���f�B���O�摜
	TEXTURE_SCENE_ENDING,

	/*---- ���̑��̉摜 -------------------------------------------------*/

	/// <summary>
	/// �f�o�b�O�p�摜.
	/// </summary>
	TEXTURE_DEBUG,

	/// <summary>
	/// ��̃e�N�X�`��ID.
	/// </summary>
	TEXTURE_NULL,

}; // enum TextureID end


#endif // _TEXTURE_ID_H_ end

/********** End of File ******************************************************/
