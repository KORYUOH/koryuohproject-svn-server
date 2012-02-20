/**===File Commentary=======================================*/
/**
*	@file	Buffer.cpp
*
*	@brief	�o�b�t�@
*
*	@note	DirectX10��
*
*	@author	KORYUOH
*
*	@date	2012/02/20
*/
/**===File Include=========================================*/
#include	<Render/DirectX/Buffer.h>
#include	<memory>
#include	<cassert>
/**===Class Implementation=================================*/

/**========================================================*/
/**
*	@brief	�R���X�g���N�^
*	@param[in]	<����>
*	@author	KORYUOH
*/
/**========================================================*/
Buffer::Buffer(ID3D10Device* device,const BufferDesc& desc,const void* data):
m_desc(desc),
	m_Buffer(NULL)
{
	//�o�b�t�@�쐬
	D3D10_BUFFER_DESC	descBuf;
	descBuf.Usage		= Usage();
	descBuf.ByteWidth	=desc._size;
	descBuf.BindFlags	=bindFlag();
	descBuf.CPUAccessFlags	=cpuAccessFlag();
	descBuf.MiscFlags		=0;
	D3D10_SUBRESOURCE_DATA	initDada;
	initDada.pSysMem	=data;
	device->CreateBuffer(&descBuf,&initDada,&m_Buffer);
	assert(m_Buffer != NULL);
}
/**========================================================*/
/**
 *	@brief	�f�X�g���N�^
 *	@author	KORYUOH
 */
/**========================================================*/
Buffer::~Buffer(){
	m_Buffer->Release();
}

/**========================================================*/
/**
 *	@brief	�f�B�X�N�v���^�擾
 *	@author	KORYUOH
 *	@return	�f�B�X�N�v���^
 */
/**========================================================*/
const BufferDesc& Buffer::desc()const{
	return m_desc;
}

/**========================================================*/
/**
 *	@brief	�o�b�t�@�擾
 *	@author	KORYUOH
 *	@return	�o�b�t�@
 */
/**========================================================*/
ID3D10Buffer * Buffer::buffer() const{
	return m_Buffer;
}

/**========================================================*/
/**
 *	@brief	�f�[�^�ݒ�
 *	@param[in]	�f�[�^
 *	@author	KORYUOH
 */
/**========================================================*/
void Buffer::getData(void* data)const{
	//�f�o�C�X�擾
	ID3D10Device*	device	= NULL;
	m_Buffer->GetDevice(&device);
	D3D10_BUFFER_DESC	descBuf;
	descBuf.Usage		=D3D10_USAGE_STAGING;
	descBuf.ByteWidth		=m_desc._size;
	descBuf.BindFlags		=bindFlag();
	descBuf.CPUAccessFlags		=D3D10_CPU_ACCESS_READ;
	descBuf.MiscFlags		=0;

	ID3D10Buffer*	readBuffer =0;
	device->CreateBuffer(&descBuf,0,&readBuffer);
	device->CopyResource(readBuffer,m_Buffer);

	void*	mapData =0;
	readBuffer->Map(D3D10_MAP_READ,0,&mapData);
	std::memcpy(data,mapData,m_desc._size);
	readBuffer->Unmap();
	//�ǂݍ��݃o�b�t�@�폜
	readBuffer->Release();
	//�f�o�C�X�����[�X
	device->Release();
}
/**========================================================*/
/**
 *	@brief	�o�C���h�t���O�̎擾
 *	@author	KORYUOH
 *	@return	UINT �o�C���h�t���O
 */
/**========================================================*/
UINT Buffer::bindFlag() const{
	static const UINT bindFlags[]={
		D3D10_BIND_VERTEX_BUFFER,	//BUFFER_TYPE_VERTEX	= 0
		D3D10_BIND_INDEX_BUFFER	//BUFFER_TYPE_INDEX	= 1
	};
	return	bindFlags[m_desc._type];
}
/**========================================================*/
/**
 *	@brief	�o�C���h�t���O�擾
 *	@author	KORYUOH
 *	@return	UINT �o�C���h�t���O
 */
/**========================================================*/
D3D10_USAGE	Buffer::Usage()const{
	static const D3D10_USAGE usages[] ={
		D3D10_USAGE_DEFAULT,		//BUFFER_USAGE_DEFAULT		=0
		D3D10_USAGE_IMMUTABLE,	//BUFFER_USAGE_IMMUTABLE	=1
		D3D10_USAGE_DYNAMIC		//BUFFER_USAGE_DYNAMIC		=2
	};
	return usages[m_desc._usage];
}





/**===End Of File==========================================*/