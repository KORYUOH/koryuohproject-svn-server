/**===File Commentary=======================================*/
/**
 *	@file	<�w�b�_�[�t�@�C����>.h
 *
 *	@brief	<�v��>
 *
 *	@attention	<���ӏ���>
 *
 *	@note	<��������>
 *
 *	@author	KORYUOH
 *
 *	@date	2012/02/20
 */
/**===Include Guard========================================*/
#ifndef	_H_
#define	_H_
/**===File Include=========================================*/
#include	<Render/Buffer/BufferDesc.h>
/**===Class Definition=====================================*/
class IBuffer{
public:
	/**
	 *	@brief	�f�X�g���N�^
	 *	@author	KORYUOH
	 */
	virtual	~IBuffer()	{};
	/**
	 *	@brief	�f�B�X�N�v���^�̎擾
	 *	@author	KORYUOH
	 *	@return	BufferDesc
	 */
	virtual const	BufferDesc& desc() const	=0;
	/**
	 *	@brief	�ݒ�
	 *	@param[in]	�f�[�^
	 *	@author	KORYUOH
	 */
	virtual void	setData(const void* data)	=0;
	/**
	 *	@brief	�f�[�^�擾
	 *	@param[in]	�f�[�^
	 *	@author	KORYUOH
	 */
	virtual void	getData(void*	data) const	=0;
};
/**===End Class Definition=================================*/
#endif
/**===End Of File==========================================*/