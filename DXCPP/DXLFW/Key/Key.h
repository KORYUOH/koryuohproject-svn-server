#ifndef __Key
#define __Key
#include	<../Include/DxLib.h>
/*
class Keystate{
	unsigned int stateKey[256];
public:
	int GetHitKeyStateAll_2();
	int CheckStateKey(unsigned char Handle);
};
*/
class Key{
private:
	/**
	 *	@brief	�R���X�g���N�^
	 *	@author	KORYUOH
	 */
	Key(){};
private:
	/**
	 *	@brief	�R�s�[�R���X�g���N�^
	 *	@brief	������Z�q�I�[�o�[���[�h
	 *	@note	�R�s�[�K�[�h
	 *	@author	KORYUOH
	 */
	Key(const Key& rhs);
	Key& operator =(const Key& rhs);
	/**
	 *	@note	�L�[�ێ�
	 */
	unsigned int stateKey[256];
public:
	/**
	 *	@brief	���̂𓾂�
	 *	@note	�V���O���g���f�U�C���p�^�[��
	 *	@author	KORYUOH
	 *	@return	�L�[�N���X�̎���
	 */
	static Key& getInstance(void){
		static Key instance;
		return instance;
	};
	/**
	 *	@brief	�S�ẴL�[��Ԃ̍X�V
	 *	@note	����s���悤�ɋL�q
	 *	@author	KORYUOH
	 *	@return	����:0�@���̑�:���s
	 */
		int GetHitKeyStateAll_2();
	/**
	 *	@brief	���͏�Ԃ𒲂ׂ�
	 *	@param[in]	���ׂ�L�[
	 *	@note	DIK_������
	 *	@author	KORYUOH
	 *	@return	�����Ă��Ȃ����0
	 */
		int CheckStateKey(unsigned char Handle);

	/**
	 *	@brief	���z�f�X�g���N�^
	 *	@author	KORYUOH
	 */
	virtual ~Key(){};
};

#endif
