/**===File Commentary=======================================*/
/**
 *	@file	Effect.cpp
 *
 *	@brief	エフェクトクラス実装
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
 *	@brief	<要約>
 *	@param[in]	<引数>
 *	@attention	<注意書き>
 *	@note	<メモ書き>
 *	@author	KORYUOH
 *	@return	<戻り値>
 */
/**========================================================*/
Effect::Effect(const char* fileName)
	:m_context(0)
	,m_effect(0)
	,m_tecnique(0)
	,m_pass(0){
		//コンテキスト作成
		m_context = cgCreateContext();
		assert( m_context !=0 );			//ALEAT!
		//コンテキストをOpenGLに設定
		cgGLRegisterStates(m_context);
		//エフェクト読み込み
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
 *	@brief	<要約>
 *	@param[in]	<引数>
 *	@attention	<注意書き>
 *	@note	<メモ書き>
 *	@author	KORYUOH
 *	@return	<戻り値>
 */
/**========================================================*/
Effect::~Effect(){
	//エフェクト削除
	if( cgIsEffect( m_effect) == CG_TRUE)
		cgDestroyEffect(m_effect);

	//コンテキスト削除
	if( m_context !=0)
		cgDestroyContext(m_context);

}
/**========================================================*/
/**
 *	@brief	<要約>
 *	@param[in]	<引数>
 *	@attention	<注意書き>
 *	@note	<メモ書き>
 *	@author	KORYUOH
 *	@return	<戻り値>
 */
/**========================================================*/
void Effect::technique(const char* techniqueName){
	//テクニック取得
	m_tecnique = cgGetNamedTechnique(m_effect,techniqueName);
}
/**========================================================*/
/**
 *	@brief	<要約>
 *	@param[in]	<引数>
 *	@attention	<注意書き>
 *	@note	<メモ書き>
 *	@author	KORYUOH
 *	@return	<戻り値>
 */
/**========================================================*/
void Effect::begin(int passNo){
	//最初のパス
	m_pass = cgGetFirstPass( m_tecnique);
	for(int n=0;n < passNo ;++n){
		m_pass = cgGetNextPass( m_pass );
	}

	cgSetPassState( m_pass );
}
/**========================================================*/
/**
 *	@brief	<要約>
 *	@param[in]	<引数>
 *	@attention	<注意書き>
 *	@note	<メモ書き>
 *	@author	KORYUOH
 *	@return	<戻り値>
 */
/**========================================================*/
void Effect::end(){
	//リセット
	cgResetPassState( m_pass );
	//無効化
	m_pass = 0;
}
/**========================================================*/
/**
 *	@brief	<要約>
 *	@param[in]	<引数>
 *	@attention	<注意書き>
 *	@note	<メモ書き>
 *	@author	KORYUOH
 *	@return	<戻り値>
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
 *	@brief	<要約>
 *	@param[in]	<引数>
 *	@attention	<注意書き>
 *	@note	<メモ書き>
 *	@author	KORYUOH
 *	@return	<戻り値>
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