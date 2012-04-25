/**===File Commentary=======================================*/
/**
 *	@file	Effect.cpp
 *
 *	@brief	�G�t�F�N�g�N���X����
 *
 *	@note	OpenGL
 *
 *	@author	KORYUOH
 *
 *	@date	2012/02/23
 */
/**===File Include=========================================*/
#include	<Render/OpenGL/EffectGL.h>
#include	<Render/OpenGL/TextureGL.h>
#include	<cassert>
#include	<iostream>
/**===Class Implementation=================================*/

/**========================================================*/
/**
 *	@brief	�R���X�g���N�^
 *	@param[in]	�t�@�C����
 *	@author	KORYUOH
 */
/**========================================================*/
EffectGL::EffectGL(const char* fileName)
	:m_context(0)
	,m_effect(0)
	,m_tecnique(0)
	,m_pass(0){
		//�R���e�L�X�g�쐬
		m_context = cgCreateContext();
		assert( m_context !=0 );			//ALEAT!
		//�R���e�L�X�g��OpenGL�ɐݒ�
		cgGLRegisterStates(m_context);
		//�G�t�F�N�g�ǂݍ���
		m_effect = cgCreateEffectFromFile(m_context,fileName,NULL);
		if( m_effect == 0){
			const char* listing = cgGetLastListing(m_context);
			if( listing != 0)
				std::cout << listing;
		}
		assert( m_effect != 0);
}
/**========================================================*/
/**
 *	@brief	�f�X�g���N�^
 *	@author	KORYUOH
 */
/**========================================================*/
EffectGL::~EffectGL(){
	//�G�t�F�N�g�폜
	if( cgIsEffect( m_effect) == CG_TRUE)
		cgDestroyEffect(m_effect);

	//�R���e�L�X�g�폜
	if( m_context !=0)
		cgDestroyContext(m_context);

}
/**========================================================*/
/**
 *	@brief	�e�N�j�b�N�J�n
 *	@param[in]	�e�N�j�b�N��
 *	@note	<��������>
 *	@author	KORYUOH
 */
/**========================================================*/
void EffectGL::technique(const char* techniqueName){
	//�e�N�j�b�N�擾
	m_tecnique = cgGetNamedTechnique(m_effect,techniqueName);
}
/**========================================================*/
/**
 *	@brief	�p�X���J�n
 *	@param[in]	�p�X�ԍ�
 *	@author	KORYUOH
 */
/**========================================================*/
void EffectGL::begin(int passNo){
	//�ŏ��̃p�X
	m_pass = cgGetFirstPass( m_tecnique);
	for(int n=0;n < passNo ;++n){
		m_pass = cgGetNextPass( m_pass );
	}

	cgSetPassState( m_pass );
}
/**========================================================*/
/**
 *	@brief	�p�X���I��
 *	@author	KORYUOH
 */
/**========================================================*/
void EffectGL::end(){
	//���Z�b�g
	cgResetPassState( m_pass );
	//������
	m_pass = 0;
}
/**========================================================*/
/**
 *	@brief	�e�N�j�b�N�����擾
 *	@param[in]	�e�N�j�b�N�ԍ�
 *	@author	KORYUOH
 *	@return	�e�N�j�b�N��
 */
/**========================================================*/
const char* EffectGL::getTechniqueName(int techniqueNo ){
	CGtechnique t = cgGetFirstTechnique(m_effect);
	for(int n =0;n < techniqueNo;++n){
		t = cgGetNextTechnique( t );
	}
	return cgGetTechniqueName(t);
}
/**========================================================*/
/**
 *	@brief	�e�N�j�b�N�ԍ��擾
 *	@author	KORYUOH
 *	@return	�e�N�j�b�N�ԍ�
 */
/**========================================================*/
int EffectGL::getNumTechnique(){
	int numTechnique = 0;
	for(CGpass p = cgGetFirstPass(m_tecnique);cgIsPass(p);p=cgGetNextPass(p)){
		numTechnique++;
	}
	return numTechnique;
}
/**========================================================*/
/**
 *	@brief	�p�X�ԍ��擾
 *	@author	KORYUOH
 */
/**========================================================*/
int EffectGL::getNumPass(){
	int numPass =0;
	for(CGpass p = cgGetFirstPass(m_tecnique); cgIsPass(p);p = cgGetNextPass(p)){
		numPass++;
	}
	return numPass;
}
/**========================================================*/
/**
 *	@brief	�X�J���[�ݒ�
 *	@param[in]	���O
 *	@param[in]	�X�J���[
 *	@author	KORYUOH
 */
/**========================================================*/
void EffectGL::setScalar(const char* name,float v){
	CGparameter param = cgGetNamedEffectParameter(m_effect,name);
	cgSetParameter1f(param,v);
}
/**========================================================*/
/**
 *	@brief	�x�N�g���ݒ�
 *	@param[in]	���O
 *	@param[in]	�x�N�g��X
 *	@param[in]	�x�N�g��Y
 *	@param[in]	�x�N�g��Z
 *	@param[in]	�x�N�g��W
 *	@author	KORYUOH
 */
/**========================================================*/
void EffectGL::setVector(const char* name,float x,float y, float z,float w){
	CGparameter param= cgGetNamedEffectParameter(m_effect,name);
	float v[4] = {x,y,z,w};
	cgSetParameterValuefc(param,cgGetParameterColumns(param),v);
}
/**========================================================*/
/**
 *	@brief	�s��ݒ�
 *	@param[in]	���O
 *	@param[in]	�s��
 *	@author	KORYUOH
 */
/**========================================================*/
void EffectGL::setMatrix(const char* name,float* matrix){
	CGparameter param = cgGetNamedEffectParameter(m_effect,name);
	cgSetMatrixParameterfr(param,matrix);
}
/**========================================================*/
/**
 *	@brief	�X�J���[�̔z���ݒ�
 *	@param[in]	���O
 *	@param[in]	�z��
 *	@param[in]	�J�E���g
 *	@author	KORYUOH
 */
/**========================================================*/
void EffectGL::setScalarArray(const char* name, float* array,unsigned int count){
	CGparameter param = cgGetNamedEffectParameter(m_effect,name);
	cgSetParameterValuefc(param,count,array);
}
/**========================================================*/
/**
 *	@brief	�x�N�g���̔z���ݒ�
 *	@param[in]	���O
 *	@param[in]	�z��
 *	@param[in]	�J�E���g
 *	@author	KORYUOH
 */
/**========================================================*/
void EffectGL::setVectorArray(const char* name, float* array,unsigned int count){
	CGparameter param = cgGetNamedEffectParameter(m_effect,name);
	cgSetParameterValuefc(param,cgGetParameterColumns(param)+count,array);
}
/**========================================================*/
/**
 *	@brief	�s��̔z���ݒ�
 *	@param[in]	���O
 *	@param[in]	�z��
 *	@param[in]	�J�E���g
 *	@author	KORYUOH
 */
/**========================================================*/
void EffectGL::setMatrixArray(const char* name,float* array,unsigned int count){
	CGparameter param = cgGetNamedEffectParameter(m_effect,name);
	cgSetParameterValuefr(param,cgGetParameterColumns(param)*cgGetParameterRows(param),array);
}
/**========================================================*/
/**
 *	@brief	�e�N�X�`���ݒ�
 *	@param[in]	���O
 *	@param[in]	�e�N�X�`��
 *	@author	KORYUOH
 */
/**========================================================*/
void EffectGL::setTexture(const char* name,ITexture* texture){
	CGparameter param = cgGetNamedEffectParameter(m_effect,name);
	cgGLSetupSampler(param,static_cast<TextureGL*>(texture)->texture() );
}
/**========================================================*/
/**
 *	@brief	�V�F�[�_�[���̓V�O�j�`���L�q�q�擾
 *	@param[in]	�e�N�j�b�N��
 *	@param[in]	�p�X�ԍ�
 *	@author	KORYUOH
 *	@return	�V�F�[�_�[���͋L�q�q
 */
/**========================================================*/
InputSignatureDesc EffectGL::inputSignature(const char* techniqueName,int passNo)const{
	(void)techniqueName;
	(void)passNo;
	//DirectX10�Ƃ̌݊�����������_�~�[
	InputSignatureDesc descSignature = {0,0};
	return descSignature;
}


/**===End Of File==========================================*/