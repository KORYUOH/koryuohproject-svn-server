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
#include	<Render/OpenGL/Effect.h>
#include	<Render/OpenGL/Texture.h>
#include	<cassert>
#include	<iostream>
/**===Class Implementation=================================*/

/**========================================================*/
/**
 *	@brief	<�v��>
 *	@param[in]	<����>
 *	@attention	<���ӏ���>
 *	@note	<��������>
 *	@author	KORYUOH
 *	@return	<�߂�l>
 */
/**========================================================*/
Effect::Effect(const char* fileName)
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
 *	@brief	<�v��>
 *	@param[in]	<����>
 *	@attention	<���ӏ���>
 *	@note	<��������>
 *	@author	KORYUOH
 *	@return	<�߂�l>
 */
/**========================================================*/
Effect::~Effect(){
	//�G�t�F�N�g�폜
	if( cgIsEffect( m_effect) == CG_TRUE)
		cgDestroyEffect(m_effect);

	//�R���e�L�X�g�폜
	if( m_context !=0)
		cgDestroyContext(m_context);

}
/**========================================================*/
/**
 *	@brief	<�v��>
 *	@param[in]	<����>
 *	@attention	<���ӏ���>
 *	@note	<��������>
 *	@author	KORYUOH
 *	@return	<�߂�l>
 */
/**========================================================*/
void Effect::technique(const char* techniqueName){
	//�e�N�j�b�N�擾
	m_tecnique = cgGetNamedTechnique(m_effect,techniqueName);
}
/**========================================================*/
/**
 *	@brief	<�v��>
 *	@param[in]	<����>
 *	@attention	<���ӏ���>
 *	@note	<��������>
 *	@author	KORYUOH
 *	@return	<�߂�l>
 */
/**========================================================*/
void Effect::begin(int passNo){
	//�ŏ��̃p�X
	m_pass = cgGetFirstPass( m_tecnique);
	for(int n=0;n < passNo ;++n){
		m_pass = cgGetNextPass( m_pass );
	}

	cgSetPassState( m_pass );
}
/**========================================================*/
/**
 *	@brief	<�v��>
 *	@param[in]	<����>
 *	@attention	<���ӏ���>
 *	@note	<��������>
 *	@author	KORYUOH
 *	@return	<�߂�l>
 */
/**========================================================*/
void Effect::end(){
	//���Z�b�g
	cgResetPassState( m_pass );
	//������
	m_pass = 0;
}
/**========================================================*/
/**
 *	@brief	<�v��>
 *	@param[in]	<����>
 *	@attention	<���ӏ���>
 *	@note	<��������>
 *	@author	KORYUOH
 *	@return	<�߂�l>
 */
/**========================================================*/
const char* Effect::getTechniqueName(int techniqueNo ){
	CGtechnique t = cgGetFirstTechnique(m_effect);
	for(int n =0;n < techniqueNo;++n){
		t = cgGetNextTechnique( t );
	}
	return cgGetTechniqueName(t);
}
/**========================================================*/
/**
 *	@brief	<�v��>
 *	@param[in]	<����>
 *	@attention	<���ӏ���>
 *	@note	<��������>
 *	@author	KORYUOH
 *	@return	<�߂�l>
 */
/**========================================================*/
int Effect::getNumTechnique(){
	int numTechnique = 0;
	for(CGpass p = cgGetFirstPass(m_tecnique);cgIsPass(p);p=cgGetNextPass(p)){
		numTechnique++;
	}
	return numTechnique;
}


/**===End Of File==========================================*/