/**===File Commentary=======================================*/
/**
 *	@file	Application.h
 *
 *	@brief	アプリケーションメインクラス
 *
 *	@author	KORYUOH
 *
 *	@date	2013/04/28
 */
/**===Include Guard========================================*/
#ifndef	_APPLICATOIN_H_
#define	_APPLICATOIN_H_
/**===File Include=========================================*/
#include	<Application/AppParam/AppParam.h>
/**===Class Definition=====================================*/
class Application{
public:
	/**
	 *	@brief	コンストラクタ
	 *	@param[in]	引数の数
	 *	@param[in]	引数の文字列
	 */
	Application(int argc,char* argv[]);
	/**
	 *	@brief	実行
	 */
	void run();
private:
	/**
	 *	@brief	<要約>
	 *	@param[in]	<[引数名]:[タイプ]>			<概要>
	 *	@note	<メモ書き>
	 *	@author	KORYUOH
	 *	@return	<戻り値>
	 */
	void initialize();
	/**
	 *	@brief	<要約>
	 *	@param[in]	<[引数名]:[タイプ]>			<概要>
	 *	@note	<メモ書き>
	 *	@author	KORYUOH
	 *	@return	<戻り値>
	 */
	void update(float f);
	/**
	 *	@brief	<要約>
	 *	@param[in]	<[引数名]:[タイプ]>			<概要>
	 *	@note	<メモ書き>
	 *	@author	KORYUOH
	 *	@return	<戻り値>
	 */
	void draw();
/**
	 *	@brief	<要約>
	 *	@param[in]	<[引数名]:[タイプ]>			<概要>
	 *	@note	<メモ書き>
	 *	@author	KORYUOH
	 *	@return	<戻り値>
	 */
	void finish();

private:
	/**	メンバー変数*/
	static Application* mInstance;
private:
	AppParam param;
};
/**===End Class Definition=================================*/
#endif
/**===End Of File==========================================*/