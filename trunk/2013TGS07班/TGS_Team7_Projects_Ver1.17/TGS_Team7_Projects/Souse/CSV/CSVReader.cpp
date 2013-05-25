/******************************************************************************
* File Name : CsvReader.h                         Ver : 1.00  Date : 2012-12-14
*
* Description :
*
*		CSV�t�@�C���̓ǂݍ��݃N���X�D
*
******************************************************************************/
#include"CSVReader.h"
//�t�@�C���X�g���[��
#include<fstream>
#include<iostream>
#include<sstream>


/// <summary>
/// �R���X�g���N�^.
/// </summary>
CSVReader::CSVReader()
{
	//�f�[�^�̏���
	mData.clear();
	mDataFloat.clear();
}

/// <summary>
/// �R���X�g���N�^.
/// </summary>
/// <param name="fileName">�t�@�C����</param>
CSVReader::CSVReader(const std::string& fileName)
{
	//�t�@�C���̓ǂݍ���
	Load(fileName);
}

/// <summary>
/// �f�X�g���N�^.
/// </summary>
CSVReader::~CSVReader()
{
}

/// <summary>
/// �f�[�^�̓ǂݍ���.
/// </summary>
/// <param name="fileName">�t�@�C����</param>
bool CSVReader::Load(const std::string& fileName)
{
	//�f�[�^�̏���
	mData.clear();
	mDataFloat.clear();

	//�t�@�C���̓ǂݍ���
	std::fstream file(fileName);

	//�t�@�C���I�[�v���̃G���[�`�F�b�N
	//�t�@�C�����ǂݍ��܂�Ă��Ȃ���
	if( file == 0 )
	{
		//False��Ԃ�
		return false;
	}

	std::string line;

	//getline��1�s��ǂݍ���

	//���ׂĂ̍s��ǂݍ��ނ܂Ń��[�v
	while(std::getline(file,line))
	{
		//�s��ǂݍ���
		std::stringstream stream(line);

		//�f�[�^�ꎞ�ۑ��p�̕ϐ����쐬
		Row row;

		//�ꎞ�ۑ��p�̕�����ϐ�
		std::string val;

		//�J���}��؂��1�s����ǂݍ���
		while( std::getline(stream,val,','))
		{
			//�z��̍Ō���ɒǉ�����
			row.push_back(val);
		}

		//�f�[�^�ۑ��p�z��̍Ō���ɒǉ�����
		mData.push_back(row);
	}

	//�ǂݍ��߂��̂�True��Ԃ�
	return true;
}

/// <summary>
/// �ۑ�.
/// </summary>
/// <returns>�ۑ��ł������^�A�ł��Ȃ���΋U��Ԃ�</returns>
bool CSVReader::Save(const std::string& fileName)
{
	//�t�@�C���̏������ݗp�ɃI�[�v������
	std::ofstream file(fileName);

	//�t�@�C���I�[�v���`�F�b�N
	if( file == 0 )
	{
		return false;
	}

	for( int row = 0 ; row < Rows() ; ++row )
	{
		int col;

		for( col = 0 ; col < Columns() - 1 ; ++col )
		{
			//�f�[�^���������݌�ɃJ���}��t����
			file << Get(row,col) << ",";
		}

		//�Ō�̍s�̂݃J���}��t�������s���s��
		file << Get(row,col) << "\n";

	}

	return true;

}

/// <summary>
/// �s�����擾.
/// </summary>
int CSVReader::Rows()const
{
	return mData.size();
}

/// <summary>
/// �񐔂��擾.
/// </summary>
/// <param name="row">�s��</param>
int CSVReader::Columns(int row)const
{
	if( Rows() == 0 )
	{
		return 0;
	}

	//�w�肵���s�̗񐔂�Ԃ�
	return mData[row].size();
}

/// <summary>
/// �f�[�^�𕶎���Ŏ擾.
/// </summary>
/// <param name="row">�s��</param>
/// <param name="col">��</param>
const std::string& CSVReader::Get(int row,int col) const
{
	return mData[row][col];
}

/// <summary>
/// �f�[�^�𐮐��^�Ŏ擾.
/// </summary>
/// <param name="row">�s��</param>
/// <param name="col">��</param>
/// <returns>�f�[�^</returns>
int CSVReader::Geti(int row,int col) const
{
	//�����^�ɕύX
	return std::atoi(Get(row,col).c_str());
}

/// <summary>
/// �f�[�^�������^�Ŏ擾.
/// </summary>
/// <param name="row">�s��</param>
/// <param name="col">��</param>
/// <returns>�f�[�^</returns>
float CSVReader::Getf(int row,int col) const
{
	//�������ϊ����Ď����^�ŕԂ�
	return (float)Getd(row,col);
}

/// <summary>
/// �f�[�^��{�������^�Ŏ擾.
/// </summary>
/// <param name="row">�s��</param>
/// <param name="col">��</param>
/// <returns>�f�[�^</returns>
double CSVReader::Getd(int row,int col) const
{
	//�������ϊ����Ĕ{���x�����^�ŕԂ�
	return std::atof(Get(row,col).c_str());
}

/// <summary>
/// �f�[�^�̏���.
/// </summary>
void CSVReader::Clear()
{
	mData.clear();
}

/// <summary>
/// �f�[�^���Q�����z����擾.
/// </summary>
std::vector<std::vector<std::string>> CSVReader::GetData()const
{
	return mData;
}

/// <summary>
/// �����f�[�^���擾����.
/// </summary>
const DataFloat& CSVReader::GetFloatData()
{
	// �f�[�^������������.
	mDataFloat.clear();

	for( int row = 0 ; row < Rows() ; ++row )
	{
		RowFloat rowData;
		rowData.clear();

		for( int col = 0 ; col < Columns() ; ++col )
		{
			std::string s = Get( row , col );
			if( s[0] < '0' || s[0] > '9' )
			{
				continue;
			}
			rowData.push_back( Getf(row,col) );
		}

		if( rowData.size() != 0 )
		{
			mDataFloat.push_back( rowData );
		}
	}

	return mDataFloat;
}

/********** End of File ******************************************************/