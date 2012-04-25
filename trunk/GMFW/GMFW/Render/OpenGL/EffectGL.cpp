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
#include	<Render/OpenGL/EffectGL.h>
#include	<Render/OpenGL/TextureGL.h>
#include	<cassert>
#include	<iostream>
/**===Class Implementation=================================*/

/**========================================================*/
/**
 *	@brief	コンストラクタ
 *	@param[in]	ファイル名
 *	@author	KORYUOH
 */
/**========================================================*/
EffectGL::EffectGL(const char* fileName)
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
 *	@brief	デストラクタ
 *	@author	KORYUOH
 */
/**========================================================*/
EffectGL::~EffectGL(){
	//エフェクト削除
	if( cgIsEffect( m_effect) == CG_TRUE)
		cgDestroyEffect(m_effect);

	//コンテキスト削除
	if( m_context !=0)
		cgDestroyContext(m_context);

}
/**========================================================*/
/**
 *	@brief	テクニック開始
 *	@param[in]	テクニック名
 *	@note	<メモ書き>
 *	@author	KORYUOH
 */
/**========================================================*/
void EffectGL::technique(const char* techniqueName){
	//テクニック取得
	m_tecnique = cgGetNamedTechnique(m_effect,techniqueName);
}
/**========================================================*/
/**
 *	@brief	パスを開始
 *	@param[in]	パス番号
 *	@author	KORYUOH
 */
/**========================================================*/
void EffectGL::begin(int passNo){
	//最初のパス
	m_pass = cgGetFirstPass( m_tecnique);
	for(int n=0;n < passNo ;++n){
		m_pass = cgGetNextPass( m_pass );
	}

	cgSetPassState( m_pass );
}
/**========================================================*/
/**
 *	@brief	パスを終了
 *	@author	KORYUOH
 */
/**========================================================*/
void EffectGL::end(){
	//リセット
	cgResetPassState( m_pass );
	//無効化
	m_pass = 0;
}
/**========================================================*/
/**
 *	@brief	テクニック名を取得
 *	@param[in]	テクニック番号
 *	@author	KORYUOH
 *	@return	テクニック名
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
 *	@brief	テクニック番号取得
 *	@author	KORYUOH
 *	@return	テクニック番号
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
 *	@brief	パス番号取得
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
 *	@brief	スカラー設定
 *	@param[in]	名前
 *	@param[in]	スカラー
 *	@author	KORYUOH
 */
/**========================================================*/
void EffectGL::setScalar(const char* name,float v){
	CGparameter param = cgGetNamedEffectParameter(m_effect,name);
	cgSetParameter1f(param,v);
}
/**========================================================*/
/**
 *	@brief	ベクトル設定
 *	@param[in]	名前
 *	@param[in]	ベクトルX
 *	@param[in]	ベクトルY
 *	@param[in]	ベクトルZ
 *	@param[in]	ベクトルW
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
 *	@brief	行列設定
 *	@param[in]	名前
 *	@param[in]	行列
 *	@author	KORYUOH
 */
/**========================================================*/
void EffectGL::setMatrix(const char* name,float* matrix){
	CGparameter param = cgGetNamedEffectParameter(m_effect,name);
	cgSetMatrixParameterfr(param,matrix);
}
/**========================================================*/
/**
 *	@brief	スカラーの配列を設定
 *	@param[in]	名前
 *	@param[in]	配列
 *	@param[in]	カウント
 *	@author	KORYUOH
 */
/**========================================================*/
void EffectGL::setScalarArray(const char* name, float* array,unsigned int count){
	CGparameter param = cgGetNamedEffectParameter(m_effect,name);
	cgSetParameterValuefc(param,count,array);
}
/**========================================================*/
/**
 *	@brief	ベクトルの配列を設定
 *	@param[in]	名前
 *	@param[in]	配列
 *	@param[in]	カウント
 *	@author	KORYUOH
 */
/**========================================================*/
void EffectGL::setVectorArray(const char* name, float* array,unsigned int count){
	CGparameter param = cgGetNamedEffectParameter(m_effect,name);
	cgSetParameterValuefc(param,cgGetParameterColumns(param)+count,array);
}
/**========================================================*/
/**
 *	@brief	行列の配列を設定
 *	@param[in]	名前
 *	@param[in]	配列
 *	@param[in]	カウント
 *	@author	KORYUOH
 */
/**========================================================*/
void EffectGL::setMatrixArray(const char* name,float* array,unsigned int count){
	CGparameter param = cgGetNamedEffectParameter(m_effect,name);
	cgSetParameterValuefr(param,cgGetParameterColumns(param)*cgGetParameterRows(param),array);
}
/**========================================================*/
/**
 *	@brief	テクスチャ設定
 *	@param[in]	名前
 *	@param[in]	テクスチャ
 *	@author	KORYUOH
 */
/**========================================================*/
void EffectGL::setTexture(const char* name,ITexture* texture){
	CGparameter param = cgGetNamedEffectParameter(m_effect,name);
	cgGLSetupSampler(param,static_cast<TextureGL*>(texture)->texture() );
}
/**========================================================*/
/**
 *	@brief	シェーダー入力シグニチャ記述子取得
 *	@param[in]	テクニック名
 *	@param[in]	パス番号
 *	@author	KORYUOH
 *	@return	シェーダー入力記述子
 */
/**========================================================*/
InputSignatureDesc EffectGL::inputSignature(const char* techniqueName,int passNo)const{
	(void)techniqueName;
	(void)passNo;
	//DirectX10との互換を持たせるダミー
	InputSignatureDesc descSignature = {0,0};
	return descSignature;
}


/**===End Of File==========================================*/