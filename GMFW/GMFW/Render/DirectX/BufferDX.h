/**===File Commentary=======================================*/
/**
 *	@file	Buffer.h
 *
 *	@brief	�o�b�t�@
 *
 *	@note	DirectX10
 *
 *	@author	KORYUOH
 *
 *	@date	2012/02/20
 */
/**===Include Guard========================================*/
#ifndef	_BUFFER_DX_H_
#define	_BUFFER_DX_H_
/**===File Include=========================================*/
#include	<d3d10.h>
#include	<Render/Buffer/IBuffer.h>
/**===Class Definition=====================================*/
class BufferDX:public IBuffer{
public:
	/**
	 *	@brief	�R���X�g���N�^
	 *	@param[in]	�f�B�X�N
	 *	@param[in]	�f�[�^
	 *	@author	KORYUOH
	 */
	BufferDX(ID3D10Device* devise, const BufferDesc& desc,const void* data=0);
	/**
	 *	@brief	�f�X�g���N�^
	 *	@author	KORYUOH
	 */
	virtual ~BufferDX();
		/**
	 *	@brief	�f�B�X�N�v���^�̎擾
	 *	@author	KORYUOH
	 *	@return	BufferDesc
	 */
	virtual const	BufferDesc& desc() const;
	/**
	 *	@brief	�ݒ�
	 *	@param[in]	�f�[�^
	 *	@author	KORYUOH
	 */
	virtual void	setData(const void* data);
	/**
	 *	@brief	�f�[�^�擾
	 *	@param[in]	�f�[�^
	 *	@author	KORYUOH
	 */
	virtual void	getData(void*	data) const	;
	/**
	 *	@brief	�o�b�t�@�̎擾
	 *	@author	KORYUOH
	 *	@return	�o�b�t�@
	 */
	ID3D10Buffer* buffer() const;
private:

	/**
	 *	@brief	�o�C���h�t���O�擾
	 *	@author	KORYUOH
	 *	@return	�o�C���h�t���O
	 */
	UINT bindFlag()const;
	/**
	 *	@brief	�o�b�t�@�g�p�@�擾
	 *	@author	KORYUOH
	 *	@return	�o�b�t�@�g�p�@
	 */
	D3D10_USAGE	Usage() const;
	/**
	 *	@brief	CPU�A�N�Z�X�t���O�擾
	 *	@author	KORYUOH
	 *	@return	�A�N�Z�X�t���O
	 */
	UINT cpuAccessFlag() const;
	/**
	 *	@brief	�R�s�[�֎~
	 *	@author	KORYUOH
	 */
	BufferDX (const BufferDX& other);
	BufferDX& operator = (const BufferDX& other);


private:
	/**	�f�B�X�N�v���^*/
	BufferDesc	 m_desc;
	/**	�o�b�t�@�N���X*/
	ID3D10Buffer*	m_Buffer;
};
/**===End Class Definition=================================*/
#endif
/**===End Of File==========================================*/