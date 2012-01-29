#ifndef __Pad
#define __Pad
#include	<Define/Define.h>
#include	<Define/Structure.h>
#include	<../Include/DxLib.h>
#include	<Key/Key.h>
struct PS2{
	int left,up,right,down,circle,triangle,square,cross,l1,l2,r1,r2,start,select;
	
	PS2():
	left(1),up(3),right(2),down(0),
	circle(5),triangle(6),square(7),cross(4),
	l1(10),l2(8),r1(11),r2(9),start(13),select(14){};
	
	/*
	configpad.down			=0;
	configpad.left				=1;
	configpad.right			=2;
	configpad.up				=3;
	configpad.cross			=4;
	configpad.circle			=5;
	configpad.triangle		=6;
	configpad.square		=7;
	configpad.l2				=8;
	configpad.r2				=9;
	configpad.l1				=10;
	configpad.r1				=11;
	configpad.start			=13;
	configpad.select			=14;
	*/
};
class Pad{
private:
	/**
	 *	@brief	コンストラクタ
	 *	@author	KORYUOH
	 */
	Pad():configpad(){};
	/**
	 *	@brief	コピーコンストラクタ
	 *	@brief	代入演算子オーバーロード
	 *	@author	KORYUOH
	 */
	Pad(const Pad& p);
	Pad& operator = (const Pad& pad);
private:
	/**
	 *	@note	キー分だけ
	 */
	int Key[PAD_MAX];
	/**
	 *	PS2パッドコントローラ構造体
	 */
	PS2 configpad;
	/**
	 *	@brief	大きいほうを返す
	 *	@param[in]	*p:パッド
	 *	@param[in]	k:キー
	 *	@note	内部で使用
	 *	@author	KORYUOH
	 */
	void input_pad_or_key(int *p, int k){
		*p = *p>k ? *p : k;
	}
	/**
	 *	@brief	キーの初期化
	 *	@note	PS2ようにコンバート
	 *	@author	KORYUOH
	 */
	void KeyInit();
public:
	/**
	 *	@brief	実体を取得
	 *	@author	KORYUOH
	 *	@return	実体
	 */
	static Pad& getInstance(void){
		static Pad Instance;
		return Instance;
	}
	/**
	 *	@brief	全てのパッドの入力状態の取得
	 *	@author	KORYUOH
	 */
	void	GetHitPadStateAll();
	/**
	 *	@brief	パッドの入力状態を取得
	 *	@param[in]	欲しいPadkey
	 *	@author	KORYUOH
	 *	@return	入ってなければ0
	 */
	int CheckStatePad(unsigned int Handle);
		/**
	 *	@brief	パッドのトリガー入力状態を取得
	 *	@param[in]	欲しいPadkey
	 *	@author	KORYUOH
	 *	@return	離されたときに1
	 */
	int CheckStateTrigger(unsigned int Handle);
		/**
	 *	@brief	パッドのトグル入力状態を取得
	 *	@param[in]	欲しいPadkey
	 *	@author	KORYUOH
	 *	@return	入ってなければ0
	 */
	int CheckStateToggle(unsigned int Handle);
private:
	bool TriggerHandle[PAD_MAX];
	bool ToggleHandle[PAD_MAX];
};
#endif