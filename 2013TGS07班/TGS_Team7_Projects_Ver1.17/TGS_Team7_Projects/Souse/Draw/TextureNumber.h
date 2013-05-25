/******************************************************************************
* File Name : TextureNumber.h                    Ver : 1.00  Date : 2012-12-14
*
* Description :
*
*		����\���N���X�D
*
* Author : Shouta Takemura.
*
******************************************************************************/
#ifndef _TEXTURE_NUMBER_H_
#define _TEXTURE_NUMBER_H_
/*---- �w�b�_�t�@�C���̓ǂݍ��� ---------------------------------------------*/

#include<string>
#include<gslib.h>

/*---- ��s�錾 -------------------------------------------------------------*/

//�e�N�X�`��ID
enum TextureID;

/// <summary>
/// �e�N�X�`���i���o�[�N���X.
/// </summary>
class TextureNumber
{
public:
	/// <summary>
	/// �R���X�g���N�^.
	/// <para>�e�N�X�`���i���o�[�N���X�̐V�K�쐬</para>
	/// </summary>
	/// <param name="textureID">�e�N�X�`��ID</param>
	/// <param name="width">�摜1�����̉���</param>
	/// <param name="height">�摜1�����̏c��</param>
	TextureNumber(TextureID textureID,float width,float height);
	/// <summary>
	/// ������`��.
	/// </summary>
	/// <param name="position">�\���ʒu</param>
	/// <param name="number">�\������</param>
	void Draw(const GSvector2& position,int number) const;
	/// <summary>
	/// ������`��.
	/// </summary>
	/// <param name="position">�\���ʒu</param>
	/// <param name="number">�\������</param>
	void Draw(const GSvector2& position,float number) const;
	/// <summary>
	/// �󂢂Ă���ꏊ�𖄂߂镶�����w��.
	/// </summary>
	/// <param name="c">�󔒂𖄂߂镶��</param>
	void SetFill(char c);
	/// <summary>
	/// �\���������w��.
	/// </summary>
	/// <param name="width">�\�����錅��</param>
	void SetField(int width);
	/// <summary>
	/// �����\��.
	/// </summary>
	/// <param name="position">�\���ʒu</param>
	/// <param name="number">�\������(������)</param>
	void DrawString(const GSvector2& position,const std::string& number) const;
	/// <summary>
	/// 1����(����)��\��.
	/// </summary>
	/// <param name="position">�\���ʒu</param>
	/// <param name="number">�\������(����)</param>
	void DrawChar(const GSvector2& position,char number) const;
	/// <summary>
	/// 1����(����)��\��.
	/// </summary>
	/// <param name="position">�\���ʒu</param>
	/// <param name="number">�\������(����)</param>
	void DrawDot(const GSvector2& position,char number) const;

private:
	/// <summary>
	/// �e�N�X�`��ID.
	/// </summary>
	TextureID	mTextureID;
	/// <summary>
	/// �摜�̉���.
	/// </summary>
	float		mWidth;
	/// <summary>
	/// �摜�̏c��.
	/// </summary>
	float		mHeight;
	/// <summary>
	/// �󔒂𖄂߂镶��.
	/// </summary>
	char		mFill;
	/// <summary>
	/// �t�B�[���h��(�����ŕ\�����邩).
	/// </summary>
	int			mField;
};

#endif
/********** End of File ******************************************************/
