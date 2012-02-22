/**===File Commentary=======================================*/
/**
 *	@file	IEffect.h
 *
 *	@brief	エフェクトインターフェース
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
	 *	@brief	デストラクタ
	 *	@author	KORYUOH
	 */
	virtual ~IEffect(){}
	/**
	 *	@brief	テクニック開始
	 *	@param[in]	テクニック名
	 *	@author	KORYUOH
	 */
	virtual void technique(const char* techniqueName ) =0;
	/**
	 *	@brief	パスを指定
	 *	@param[in]	パス番号:初期値 [0]
	 *	@author	KORYUOH
	 */
	virtual void begin(int passNo = 0) = 0;
	/**
	 *	@brief	パスを終了
	 *	@author	KORYUOH
	 */
	virtual void end() =0;
	/**
	 *	@brief	テクニック名を取得
	 *	@param[in]	番号
	 *	@author	KORYUOH
	 *	@return	テクニック名
	 */
	virtual const char* getTechniqueName(int TechniqueNo ) =0 ;
	/**
	 *	@brief	テクニック数を取得
	 *	@author	KORYUOH
	 *	@return	テクニック数
	 */
	virtual int getNumTechnique() =0;
	/**
	 *	@brief	現在のテクニックのパス数を取得
	 *	@author	KORYUOH
	 *	@return	パス数
	 */
	virtual int getNumPass() =0;
	/**
	 *	@brief	スカラーを設定
	 *	@param[in]	スカラー名
	 *	@param[in]	データ:初期値 [0]
	 *	@author	KORYUOH
	 */
	virtual void setScalar(const char* name , float v=0) =0;
	/**
	 *	@brief	ベクトルを設定
	 *	@param[in]	ベクトル名
	 *	@param[in]	x方向	:初期値 [0]
	 *	@param[in]	y方向	:初期値 [0]
	 *	@param[in]	z方向	:初期値 [0]
	 *	@param[in]	w?		:初期値 [1]
	 *	@author	KORYUOH
	 */
	virtual void setVector(const char * name, float x = 0,float y = 0,float z =0,float w =1) =0;
	/**
	 *	@brief	行列を設定
	 *	@param[in]	行列名
	 *	@param[in]	データ
	 *	@author	KORYUOH
	 */
	virtual void setMatrix(const char* name , float* matrix) = 0;
	/**
	 *	@brief	スカラーの配列を設定
	 *	@param[in]	スカラ行列名
	 *	@param[in]	配列
	 *	@param[in]	カウント
	 *	@author	KORYUOH
	 */
	virtual void setScalarArray(const char* name , float* array,unsigned int count) = 0;
	/**
	 *	@brief	ベクトルの配列を設定
	*	@param[in]	ベクトル名
	*	@param[in]	配列
	*	@param[in]	カウント
	 *	@author	KORYUOH
	 */
	virtual void setVectorArray(const char* name , float* array,unsigned int count) = 0;
	/**
	 *	@brief	行列の配列を設定
	*	@param[in]	行列名
	*	@param[in]	配列
	*	@param[in]	カウント
	 *	@author	KORYUOH
	 */
	virtual void setMatrixArray(const char* name , float* array,unsigned int count) = 0;
	/**
	 *	@brief	テクスチャのパラメータを設定
	*	@param[in]	テクスチャパラメータ名
	*	@param[in]	テクスチャインターフェース
	 *	@author	KORYUOH
	 */
	virtual void setTexture(const char* name, ITexture* texture) =0;
	/**
	 *	@brief	シェーダー入力シグニチャ記述子を取得
	 *	@param[in]	テクニック名
	 *	@param[in]	パス番号:初期値 [0]
	 *	@author	KORYUOH
	 *	@return	シェーダー入力シグニチャ記述子
	 */
	virtual InputSignatureDesc inputSignature(const char* techniqueName, int passNo =0)const =0;

};
/**===End Class Definition=================================*/
#endif
/**===End Of File==========================================*/