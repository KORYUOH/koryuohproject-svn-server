/**===File Commentary=======================================*/
/**
 *	@file	Effect.h
 *
 *	@brief	�G�t�F�N�g�N���X
 *
 *	@note	OpenGL
 *
 *	@author	KORYUOH
 *
 *	@date	2012/02/23
 */
/**===Include Guard========================================*/
#ifndef	_EFFECT_GL_H_
#define	_EFFECT_GL_H_
/**===File Include=========================================*/
#include	<Render/Effect/IEffect.h>
#include	<GLee/GLee.h>
#include	<Render/OpenGL/CgInc.h>
/**===Class Definition=====================================*/
class EffectGL:public IEffect{
public:
	/**
	 *	@brief	�R���X�g���N�^
	 *	@param[in]	�t�@�C����
	 *	@author	KORYUOH
	 */
	EffectGL ( const char* fileName);
	/**
	 *	@brief	�f�X�g���N�^
	 *	@author	KORYUOH
	 */
	virtual ~EffectGL();
	/**
	 *	@brief	�e�N�j�b�N�J�n
	 *	@param[in]	�e�N�j�b�N��
	 *	@author	KORYUOH
	 */
	virtual void technique(const char* techniqueName ) ;
	/**
	 *	@brief	�p�X���w��
	 *	@param[in]	�p�X�ԍ�:�����l [0]
	 *	@author	KORYUOH
	 */
	virtual void begin(int passNo = 0) ;
	/**
	 *	@brief	�p�X���I��
	 *	@author	KORYUOH
	 */
	virtual void end() ;
	/**
	 *	@brief	�e�N�j�b�N�����擾
	 *	@param[in]	�ԍ�
	 *	@author	KORYUOH
	 *	@return	�e�N�j�b�N��
	 */
	virtual const char* getTechniqueName(int TechniqueNo );
	/**
	 *	@brief	�e�N�j�b�N�����擾
	 *	@author	KORYUOH
	 *	@return	�e�N�j�b�N��
	 */
	virtual int getNumTechnique() ;
	/**
	 *	@brief	���݂̃e�N�j�b�N�̃p�X�����擾
	 *	@author	KORYUOH
	 *	@return	�p�X��
	 */
	virtual int getNumPass() ;
	/**
	 *	@brief	�X�J���[��ݒ�
	 *	@param[in]	�X�J���[��
	 *	@param[in]	�f�[�^:�����l [0]
	 *	@author	KORYUOH
	 */
	virtual void setScalar(const char* name , float v=0) ;
	/**
	 *	@brief	�x�N�g����ݒ�
	 *	@param[in]	�x�N�g����
	 *	@param[in]	x����	:�����l [0]
	 *	@param[in]	y����	:�����l [0]
	 *	@param[in]	z����	:�����l [0]
	 *	@param[in]	w?		:�����l [1]
	 *	@author	KORYUOH
	 */
	virtual void setVector(const char * name, float x = 0,float y = 0,float z =0,float w =1) ;
	/**
	 *	@brief	�s���ݒ�
	 *	@param[in]	�s��
	 *	@param[in]	�f�[�^
	 *	@author	KORYUOH
	 */
	virtual void setMatrix(const char* name , float* matrix) ;
	/**
	 *	@brief	�X�J���[�̔z���ݒ�
	 *	@param[in]	�X�J���s��
	 *	@param[in]	�z��
	 *	@param[in]	�J�E���g
	 *	@author	KORYUOH
	 */
	virtual void setScalarArray(const char* name , float* array,unsigned int count) ;
	/**
	 *	@brief	�x�N�g���̔z���ݒ�
	*	@param[in]	�x�N�g����
	*	@param[in]	�z��
	*	@param[in]	�J�E���g
	 *	@author	KORYUOH
	 */
	virtual void setVectorArray(const char* name , float* array,unsigned int count) ;
	/**
	 *	@brief	�s��̔z���ݒ�
	*	@param[in]	�s��
	*	@param[in]	�z��
	*	@param[in]	�J�E���g
	 *	@author	KORYUOH
	 */
	virtual void setMatrixArray(const char* name , float* array,unsigned int count) ;
	/**
	 *	@brief	�e�N�X�`���̃p�����[�^��ݒ�
	*	@param[in]	�e�N�X�`���p�����[�^��
	*	@param[in]	�e�N�X�`���C���^�[�t�F�[�X
	 *	@author	KORYUOH
	 */
	virtual void setTexture(const char* name, ITexture* texture) ;
	/**
	 *	@brief	�V�F�[�_�[���̓V�O�j�`���L�q�q���擾
	 *	@param[in]	�e�N�j�b�N��
	 *	@param[in]	�p�X�ԍ�:�����l [0]	
	 *	@author	KORYUOH
	 *	@return	�V�F�[�_�[���̓V�O�j�`���L�q�q
	 */
	virtual InputSignatureDesc inputSignature(const char* techniqueName, int passNo =0)const ;


private:
	/**	CG�R���e�L�X�g */
	CGcontext	m_context;
	/**	�G�t�F�N�g */
	CGeffect	m_effect;
	/**	�e�N�j�b�N */
	CGtechnique	m_tecnique;
	/**	�p�X */
	CGpass	m_pass;

};
/**===End Class Definition=================================*/
#endif
/**===End Of File==========================================*/