/**===File Commentary=======================================*/
/**
 *	@file	Close.h
 *
 *	@brief	終了ファイル
 *
 *	@note	遠隔で終了させるのに使う
 *
 *	@author	KORYUOH
 *
 *	@date	2012/08/07
 */
/**===Include Guard========================================*/
#ifndef	_CLOSE_H_
#define	_CLOSE_H_
/**===File Include=========================================*/
/**===Class Definition=====================================*/
class Close{
	Close():flag(false){};
	Close(const Close& other);
public:
	/**
	 *	@brief	<要約>
	 *	@param[in]	<[引数名]:[タイプ]>			<概要>
	 *	@note	<メモ書き>
	 *	@author	KORYUOH
	 *	@return	<戻り値>
	 */
	static Close& getInstance(){
		static Close Instance;
		return Instance;
	}
	/**
	 *	@brief	終了チェック
	 *	@return	終了ならtrue
	 */
	bool isClose()const;
	/**
	 *	@brief	終了させる
	 */
	void close();
private:
	/**	メンバー変数*/
	bool flag;
};
/**===End Class Definition=================================*/
#endif
/**===End Of File==========================================*/