/**===File Commentary=======================================*/
/**
 *	@file	IEffect.h
 *
 *	@brief	�G�t�F�N�g�C���^�[�t�F�[�X
 *
 *	@author	KORYUOH
 *
 *	@date	2012/02/22
 */
/**===Include Guard========================================*/
#ifndef	_IEFFECT_H_
#define	_IEFFECT_H_
/**===File Include=========================================*/
#include	<Render/Effect/InputSignatureDesc.h>
/**===Class Forward Look At================================*/
class ITexture;
/**===Class Definition=====================================*/
class IEffect{
public:
	/**
	 *	@brief	�f�X�g���N�^
	 *	@author	KORYUOH
	 */
	virtual ~IEffect(){}
	/**
	 *	@brief	�e�N�j�b�N�J�n
	 *	@param[in]	�e�N�j�b�N��
	 *	@author	KORYUOH
	 */
	virtual void technique(const char* techniqueName ) =0;
	/**
	 *	@brief	�p�X���w��
	 *	@param[in]	�p�X�ԍ�:�����l [0]
	 *	@author	KORYUOH
	 */
	virtual void begin(int passNo = 0) = 0;
	/**
	 *	@brief	�p�X���I��
	 *	@author	KORYUOH
	 */
	virtual void end() =0;
	/**
	 *	@brief	�e�N�j�b�N�����擾
	 *	@param[in]	�ԍ�
	 *	@author	KORYUOH
	 *	@return	�e�N�j�b�N��
	 */
	virtual const char* getTechniqueName(int TechniqueNo ) =0 ;
	/**
	 *	@brief	�e�N�j�b�N�����擾
	 *	@author	KORYUOH
	 *	@return	�e�N�j�b�N��
	 */
	virtual int getNumTechnique() =0;
	/**
	 *	@brief	���݂̃e�N�j�b�N�̃p�X�����擾
	 *	@author	KORYUOH
	 *	@return	�p�X��
	 */
	virtual int getNumPass() =0;
	/**
	 *	@brief	�X�J���[��ݒ�
	 *	@param[in]	�X�J���[��
	 *	@param[in]	�f�[�^:�����l [0]
	 *	@author	KORYUOH
	 */
	virtual void setScalar(const char* name , float v=0) =0;
	/**
	 *	@brief	�x�N�g����ݒ�
	 *	@param[in]	�x�N�g����
	 *	@param[in]	x����	:�����l [0]
	 *	@param[in]	y����	:�����l [0]
	 *	@param[in]	z����	:�����l [0]
	 *	@param[in]	w?		:�����l [1]
	 *	@author	KORYUOH
	 */
	virtual void setVector(const char * name, float x = 0,float y = 0,float z =0,float w =1) =0;
	/**
	 *	@brief	�s���ݒ�
	 *	@param[in]	�s��
	 *	@param[in]	�f�[�^
	 *	@author	KORYUOH
	 */
	virtual void setMatrix(const char* name , float* matrix) = 0;
	/**
	 *	@brief	�X�J���[�̔z���ݒ�
	 *	@param[in]	�X�J���s��
	 *	@param[in]	�z��
	 *	@param[in]	�J�E���g
	 *	@author	KORYUOH
	 */
	virtual void setScalarArray(const char* name , float* array,unsigned int count) = 0;
	/**
	 *	@brief	�x�N�g���̔z���ݒ�
	*	@param[in]	�x�N�g����
	*	@param[in]	�z��
	*	@param[in]	�J�E���g
	 *	@author	KORYUOH
	 */
	virtual void setVectorArray(const char* name , float* array,unsigned int count) = 0;
	/**
	 *	@brief	�s��̔z���ݒ�
	*	@param[in]	�s��
	*	@param[in]	�z��
	*	@param[in]	�J�E���g
	 *	@author	KORYUOH
	 */
	virtual void setMatrixArray(const char* name , float* array,unsigned int count) = 0;
	/**
	 *	@brief	�e�N�X�`���̃p�����[�^��ݒ�
	*	@param[in]	�e�N�X�`���p�����[�^��
	*	@param[in]	�e�N�X�`���C���^�[�t�F�[�X
	 *	@author	KORYUOH
	 */
	virtual void setTexture(const char* name, ITexture* texture) =0;
	/**
	 *	@brief	�V�F�[�_�[���̓V�O�j�`���L�q�q���擾
	 *	@param[in]	�e�N�j�b�N��
	 *	@param[in]	�p�X�ԍ�:�����l [0]
	 *	@author	KORYUOH
	 *	@return	�V�F�[�_�[���̓V�O�j�`���L�q�q
	 */
	virtual InputSignatureDesc inputSignature(const char* techniqueName, int passNo =0)const =0;

};
/**===End Class Definition=================================*/
#endif
/**===End Of File==========================================*/