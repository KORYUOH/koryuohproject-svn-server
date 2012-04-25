/**===File Commentary=======================================*/
/**
 *	@file	Effect.h
 *
 *	@brief	エフェクトクラス
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
	 *	@brief	コンストラクタ
	 *	@param[in]	ファイル名
	 *	@author	KORYUOH
	 */
	EffectGL ( const char* fileName);
	/**
	 *	@brief	デストラクタ
	 *	@author	KORYUOH
	 */
	virtual ~EffectGL();
	/**
	 *	@brief	テクニック開始
	 *	@param[in]	テクニック名
	 *	@author	KORYUOH
	 */
	virtual void technique(const char* techniqueName ) ;
	/**
	 *	@brief	パスを指定
	 *	@param[in]	パス番号:初期値 [0]
	 *	@author	KORYUOH
	 */
	virtual void begin(int passNo = 0) ;
	/**
	 *	@brief	パスを終了
	 *	@author	KORYUOH
	 */
	virtual void end() ;
	/**
	 *	@brief	テクニック名を取得
	 *	@param[in]	番号
	 *	@author	KORYUOH
	 *	@return	テクニック名
	 */
	virtual const char* getTechniqueName(int TechniqueNo );
	/**
	 *	@brief	テクニック数を取得
	 *	@author	KORYUOH
	 *	@return	テクニック数
	 */
	virtual int getNumTechnique() ;
	/**
	 *	@brief	現在のテクニックのパス数を取得
	 *	@author	KORYUOH
	 *	@return	パス数
	 */
	virtual int getNumPass() ;
	/**
	 *	@brief	スカラーを設定
	 *	@param[in]	スカラー名
	 *	@param[in]	データ:初期値 [0]
	 *	@author	KORYUOH
	 */
	virtual void setScalar(const char* name , float v=0) ;
	/**
	 *	@brief	ベクトルを設定
	 *	@param[in]	ベクトル名
	 *	@param[in]	x方向	:初期値 [0]
	 *	@param[in]	y方向	:初期値 [0]
	 *	@param[in]	z方向	:初期値 [0]
	 *	@param[in]	w?		:初期値 [1]
	 *	@author	KORYUOH
	 */
	virtual void setVector(const char * name, float x = 0,float y = 0,float z =0,float w =1) ;
	/**
	 *	@brief	行列を設定
	 *	@param[in]	行列名
	 *	@param[in]	データ
	 *	@author	KORYUOH
	 */
	virtual void setMatrix(const char* name , float* matrix) ;
	/**
	 *	@brief	スカラーの配列を設定
	 *	@param[in]	スカラ行列名
	 *	@param[in]	配列
	 *	@param[in]	カウント
	 *	@author	KORYUOH
	 */
	virtual void setScalarArray(const char* name , float* array,unsigned int count) ;
	/**
	 *	@brief	ベクトルの配列を設定
	*	@param[in]	ベクトル名
	*	@param[in]	配列
	*	@param[in]	カウント
	 *	@author	KORYUOH
	 */
	virtual void setVectorArray(const char* name , float* array,unsigned int count) ;
	/**
	 *	@brief	行列の配列を設定
	*	@param[in]	行列名
	*	@param[in]	配列
	*	@param[in]	カウント
	 *	@author	KORYUOH
	 */
	virtual void setMatrixArray(const char* name , float* array,unsigned int count) ;
	/**
	 *	@brief	テクスチャのパラメータを設定
	*	@param[in]	テクスチャパラメータ名
	*	@param[in]	テクスチャインターフェース
	 *	@author	KORYUOH
	 */
	virtual void setTexture(const char* name, ITexture* texture) ;
	/**
	 *	@brief	シェーダー入力シグニチャ記述子を取得
	 *	@param[in]	テクニック名
	 *	@param[in]	パス番号:初期値 [0]	
	 *	@author	KORYUOH
	 *	@return	シェーダー入力シグニチャ記述子
	 */
	virtual InputSignatureDesc inputSignature(const char* techniqueName, int passNo =0)const ;


private:
	/**	CGコンテキスト */
	CGcontext	m_context;
	/**	エフェクト */
	CGeffect	m_effect;
	/**	テクニック */
	CGtechnique	m_tecnique;
	/**	パス */
	CGpass	m_pass;

};
/**===End Class Definition=================================*/
#endif
/**===End Of File==========================================*/