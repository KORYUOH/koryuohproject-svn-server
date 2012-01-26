#ifndef _XMLREADER_H_INCLUDED_
#define _XMLREADER_H_INCLUDED_
#include	<string>
#include	<vector>

class XmlReader{
private:
	/*
	 *		@brief	�R���X�g���N�^
	 *		@brief	�R�s�[�R���X�g���N�^
	 *		@brief	������Z�q�I�[�o�[���[�h
	 *		@note	XmlReader�̃R���X�g���N�^�A�R�s�[�R���X�g���N�^�A������Z�q�I�[�o�[���[�h�̊O���Ăяo���֎~
	 */

	XmlReader(){};
	XmlReader(const XmlReader& xml){};
	XmlReader& operator= (const XmlReader& xml){};

public:
	/*
	 *	�V���O���g���f�U�C���p�^�[��
	 *	���̂𓾂�
	 */
	static XmlReader& getInstance(){
		static XmlReader Instance;
		return Instance;
	}

	/*
	 *	@brief	���z�f�X�g���N�^
	 */
	virtual ~XmlReader(){};
public:
	/*
	 *	@brief	�ǂݍ���
	 *	@param[in]	xmlName	string	�ǂݍ��݃t�@�C����
	 *	@note	��{�I�ɃI�[�o�[���C�h���Ďg��
	 */
	virtual void read(std::string xmlName);
	/*===============================================
	 *				���̐�I�[�o�[���C�h
	 *===============================================
	 *	��������
	 */



	/*===============================================
	 *	�����܂�
	 *===============================================
	 */
};



#endif // _XMLREADER_H_INCLUDED_
