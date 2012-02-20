/**===File Commentary=======================================*/
/**
 *	@file	BufferDesc.h
 *
 *	@brief	�p�����[�^�i�[
 *
 *	@author	KORYUOH
 *
 *	@date	2012/02/20
 */
/**===Include Guard========================================*/
#ifndef	_BUFFER_DESC_H_
#define	_BUFFER_DESC_H_
/**===File Include=========================================*/

/**===eNum Definition=====================================*/
enum BufferUsage{
	BUFFER_USAGE_DEFAULT		=0,	// �f�t�H���g
	BUFFER_USAGE_IMMUTABLE	=1,	// �쐬���̂�
	BUFFER_USAGE_DYNAMIC		=2	// �p�ɂɏ�������
};
/**===eNum Definition=====================================*/
enum BufferType{
	BUFFER_TYPE_VERTEX	=0,	// ���_�o�b�t�@
	BUFFER_TYPE_INDEX	=1	// �C���f�b�N�X�o�b�t�@
};
/**===Struct Definition=====================================*/
struct BufferDesc{
	//�o�b�t�@�^�C�v
	BufferType	_type;
	//�g�p�@
	BufferUsage	_usage;
	//�f�[�^�̃o�C�g��
	unsigned int	_size;
	//�R���X�g���N�^
	BufferDesc():
			_type(BUFFER_TYPE_VERTEX),
			_usage(BUFFER_USAGE_IMMUTABLE),
			_size(0)
		{}
};
/**===End Class Definition=================================*/
#endif
/**===End Of File==========================================*/