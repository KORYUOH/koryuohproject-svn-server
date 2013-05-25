/******************************************************************************
* File Name : CSVWriter.h                         Ver : 1.00  Date : 2012-12-14
*
* Description :
*
*		CSV�t�@�C���̏������݃N���X�D
*
******************************************************************************/
#include"CSVWriter.h"
#include<fstream>
#include<iostream>
#include<sstream>


/*=============================================================================
*
* Purpose : �R���X�g���N�^�D
*
* Return  : �Ȃ�
*
*============================================================================*/
CSVWriter::CSVWriter()
{
}

/*=============================================================================
*
* Purpose : �f�X�g���N�^�D
*
* Return  : �Ȃ�
*
*============================================================================*/
CSVWriter::~CSVWriter()
{
}

/*=============================================================================
*
* Purpose : �ۑ�(fileName:�t�@�C����)�D
*
* Return  : �Ȃ�
*
*============================================================================*/
bool CSVWriter::save(const std::string& fileName,Rows data)
{
	//�t�@�C���̏������ݗp�ɃI�[�v������
	std::ofstream file(fileName);

	//�t�@�C���I�[�v���`�F�b�N
	if( file == 0 )
	{
		return false;
	}

	for( unsigned int row = 0 ; row < data.size() ; ++row )
	{
		unsigned int col;
		
		for( col = 0 ; col < data[row].size() - 1 ; ++col )
		{
			//�f�[�^���������݌�ɃJ���}��t����
			file << data[row][col] << ",";
		}

		//�Ō�̍s�̂݃J���}��t�������s���s��
		file << data[row][col] << "\n";

	}

	return true;

}

/*=============================================================================
*
* Purpose : �f�[�^�̕ۑ�(fileName:�t�@�C����,row:�s���l,col:�񐔒l)�D
*
* Return  : �Ȃ�
*
*============================================================================*/
bool CSVWriter::dataSave(const std::string& fileName,int row,int col,std::string data)
{
	//�t�@�C���̏������ݗp�ɃI�[�v������
	std::ofstream file(fileName);

	//�t�@�C���I�[�v���`�F�b�N
	if( file == 0 )
	{
		return false;
	}

	return true;
}

/*=============================================================================
*
* Purpose : �f�[�^�̕ۑ�(fileName:�t�@�C����,row:�s���l,col:�񐔒l)�D
*
* Return  : �Ȃ�
*
*============================================================================*/
bool CSVWriter::dataSave(const std::string& fileName,int row,int col,int data)
{
	return false;
}

/*=============================================================================
*
* Purpose : �f�[�^�̕ۑ�(fileName:�t�@�C����,row:�s���l,col:�񐔒l)�D
*
* Return  : �Ȃ�
*
*============================================================================*/
bool CSVWriter::dataSave(const std::string& fileName,int row,int col,float data)
{
	return false;
}

/********** End of File ******************************************************/