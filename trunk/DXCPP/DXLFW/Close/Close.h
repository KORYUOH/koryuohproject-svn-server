/**===File Commentary=======================================*/
/**
 *	@file	Close.h
 *
 *	@brief	�I���t�@�C��
 *
 *	@note	���u�ŏI��������̂Ɏg��
 *
 *	@author	KORYUOH
 *
 *	@date	2012/08/07
 */
/**===Include Guard========================================*/
#ifndef	_CLOSE_H_
#define	_CLOSE_H_
/**===File Include=========================================*/
/**===Class Definition=====================================*/
class Close{
	Close():flag(false){};
	Close(const Close& other);
public:
	/**
	 *	@brief	<�v��>
	 *	@param[in]	<[������]:[�^�C�v]>			<�T�v>
	 *	@note	<��������>
	 *	@author	KORYUOH
	 *	@return	<�߂�l>
	 */
	static Close& getInstance(){
		static Close Instance;
		return Instance;
	}
	/**
	 *	@brief	�I���`�F�b�N
	 *	@return	�I���Ȃ�true
	 */
	bool isClose()const;
	/**
	 *	@brief	�I��������
	 */
	void close();
private:
	/**	�����o�[�ϐ�*/
	bool flag;
};
/**===End Class Definition=================================*/
#endif
/**===End Of File==========================================*/