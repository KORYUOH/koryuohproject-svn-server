/******************************************************************************
* File Name : CsvReader.h                         Ver : 1.00  Date : 2012-12-14
*
* Description :
*
*		CSV�t�@�C���̏������݃N���X�D
*
******************************************************************************/
#ifndef _CSV_WRITER_H_
#define _CSV_WRITER_H_


/*---- �w�b�_�t�@�C���̓ǂݍ��� ---------------------------------------------*/

#include<string>
#include<vector>

/*---- CSV�������݃N���X�̐錾 ----------------------------------------------*/

class CSVWriter
{

private:
	//�s���p�̔z��錾
	typedef std::vector<std::string>	Row;
	typedef std::vector<Row>			Rows;


public:
	/** �R���X�g���N�^ **/
	CSVWriter();
	/** �f�X�g���N�^ **/
	~CSVWriter();

public:
	//�ۑ�(fileName:�t�@�C����)
	bool save(const std::string& fileName, Rows data);
	//�f�[�^�̕ۑ�(fileName:�t�@�C����,row:�s���l,col:�񐔒l)
	bool dataSave(const std::string& fileName,int row,int col,std::string data);
	//�f�[�^�̕ۑ�(fileName:�t�@�C����,row:�s���l,col:�񐔒l)
	bool dataSave(const std::string& fileName,int row,int col,int data);
	//�f�[�^�̕ۑ�(fileName:�t�@�C����,row:�s���l,col:�񐔒l)
	bool dataSave(const std::string& fileName,int row,int col,float data);

};

#endif

/********** End of File ******************************************************/