#ifndef __Key
#define __Key
#include	<../Include/DxLib.h>
/*
class Keystate{
	unsigned int stateKey[256];
public:
	int GetHitKeyStateAll_2();
	int CheckStateKey(unsigned char Handle);
};
*/
class Key{
private:
	/**
	 *	@brief	コンストラクタ
	 *	@author	KORYUOH
	 */
	Key(){};
private:
	/**
	 *	@brief	コピーコンストラクタ
	 *	@brief	代入演算子オーバーロード
	 *	@note	コピーガード
	 *	@author	KORYUOH
	 */
	Key(const Key& rhs);
	Key& operator =(const Key& rhs);
	/**
	 *	@note	キー保持
	 */
	unsigned int stateKey[256];
public:
	/**
	 *	@brief	実体を得る
	 *	@note	シングルトンデザインパターン
	 *	@author	KORYUOH
	 *	@return	キークラスの実体
	 */
	static Key& getInstance(void){
		static Key instance;
		return instance;
	};
	/**
	 *	@brief	全てのキー状態の更新
	 *	@note	毎回行うように記述
	 *	@author	KORYUOH
	 *	@return	成功:0　その他:失敗
	 */
		int GetHitKeyStateAll_2();
	/**
	 *	@brief	入力状態を調べる
	 *	@param[in]	調べるキー
	 *	@note	DIK_つかえる
	 *	@author	KORYUOH
	 *	@return	入っていなければ0
	 */
		int CheckStateKey(unsigned char Handle);

	/**
	 *	@brief	仮想デストラクタ
	 *	@author	KORYUOH
	 */
	virtual ~Key(){};
};

#endif
