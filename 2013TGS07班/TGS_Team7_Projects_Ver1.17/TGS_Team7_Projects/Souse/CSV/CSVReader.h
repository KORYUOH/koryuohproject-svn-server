/******************************************************************************
* File Name : CSVReader.h                        Ver : 1.00  Date : 2012-12-14
*
* Description :
*
*		CSV���[�_�[�N���X�D
*
* Author : Shouta Takemura.
*
******************************************************************************/
#ifndef _CSV_READER_H_
#define _CSV_READER_H_

/*---- �w�b�_�t�@�C���̓ǂݍ��� ---------------------------------------------*/

#include<string>
#include<vector>

/*---- ��s�錾 -------------------------------------------------------------*/

/// <summary>
/// �s��������p�z��錾.
/// </summary>
typedef std::vector<std::string>	Row;
/// <summary>
/// ������f�[�^�^.
/// </summary>
typedef std::vector<Row>			Data;
/// <summary>
/// �s�������p�z��錾.
/// </summary>
typedef std::vector<float>			RowFloat;
/// <summary>
/// �����f�[�^�^.
/// </summary>
typedef	std::vector<RowFloat>		DataFloat;
/// <summary>
/// �s�������p�z��錾.
/// </summary>
typedef std::vector<int>			RowInt;
/// <summary>
/// �����f�[�^�^.
/// </summary>
typedef	std::vector<RowInt>			DataInt;

/*---- �N���X�̎��� ---------------------------------------------------------*/

/// <summary>
/// CSV�ǂݎ��N���X.
/// </summary>
class CSVReader
{

public:

public:
	/// <summary>
	/// �R���X�g���N�^.
	/// </summary>
	CSVReader();
	/// <summary>
	/// �R���X�g���N�^.
	/// </summary>
	/// <param name="fileName">�t�@�C����</param>
	CSVReader(const std::string& fileName);
	/// <summary>
	/// �f�X�g���N�^.
	/// </summary>
	~CSVReader();
	/// <summary>
	/// �f�[�^�̓ǂݍ���.
	/// </summary>
	/// <param name="fileName">�t�@�C����</param>
	bool Load(const std::string& fileName);
	/// <summary>
	/// �s�����擾.
	/// </summary>
	int Rows()const;
	/// <summary>
	/// �񐔂��擾.
	/// </summary>
	/// <param name="row">�s��</param>
	int Columns(int row = 0)const;
	/// <summary>
	/// �f�[�^�𕶎���Ŏ擾.
	/// </summary>
	/// <param name="row">�s��</param>
	/// <param name="col">��</param>
	const std::string& Get(int row,int col) const;
	/// <summary>
	/// �f�[�^�𐮐��^�Ŏ擾.
	/// </summary>
	/// <param name="row">�s��</param>
	/// <param name="col">��</param>
	/// <returns>�f�[�^</returns>
	int Geti(int row,int col) const;
	/// <summary>
	/// �f�[�^�������^�Ŏ擾.
	/// </summary>
	/// <param name="row">�s��</param>
	/// <param name="col">��</param>
	/// <returns>�f�[�^</returns>
	float Getf(int row,int col) const;
	/// <summary>
	/// �f�[�^��{�������^�Ŏ擾.
	/// </summary>
	/// <param name="row">�s��</param>
	/// <param name="col">��</param>
	/// <returns>�f�[�^</returns>
	double Getd(int row,int col) const;
	/// <summary>
	/// �����f�[�^���擾����.
	/// </summary>
	/// <returns>�����f�[�^</returns>
	const DataFloat& GetFloatData();

	/// <summary>
	/// �ۑ�.
	/// </summary>
	/// <returns>�ۑ��ł������^�A�ł��Ȃ���΋U��Ԃ�</returns>
	bool Save(const std::string& fileName);
	/// <summary>
	/// �f�[�^���Q�����z����擾.
	/// </summary>
	std::vector<std::vector<std::string>> GetData()const;

private:
	/// <summary>
	/// �f�[�^�̏���.
	/// </summary>
	void Clear();

public:
	/// <summary>
	//�f�[�^�ۑ��p
	/// </summary>
	Data		mData;
	/// <summary>
	/// �����f�[�^�ۑ��p.
	/// </summary>
	DataFloat	mDataFloat;
};


#endif

/********** End of File ******************************************************/
