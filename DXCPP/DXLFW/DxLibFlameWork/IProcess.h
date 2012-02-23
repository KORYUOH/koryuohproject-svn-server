/**===File Commentary=======================================*/
/**
 *	@file	IProcess.h
 *
 *	@brief	プロセス
 *
 *	@author	KORYUOH
 *
 *	@date	2012/02/20
 */
/**===Include Guard========================================*/
#ifndef	_IPROcESS_H_
#define	_IPROcESS_H_
/**===File Include=========================================*/

/**===Class Definition=====================================*/
class IProcess{
public:
	/**
	 *	@brief	初期化
	 *	@author	KORYUOH
	 */
	virtual void initialize()	=0;
	/**
	 *	@brief	<要約>
	 *	@param[in]	<[引数名]:[タイプ]>			<概要>
	 *	@note	<メモ書き>
	 *	@author	<作者名>
	 *	@return	<戻り値>
	 */
	virtual void update()	=0;
	/**
	 *	@brief	<要約>
	 *	@param[in]	<[引数名]:[タイプ]>			<概要>
	 *	@note	<メモ書き>
	 *	@author	<作者名>
	 *	@return	<戻り値>
	 */
	virtual void draw()	=0;
	/**
	 *	@brief	<要約>
	 *	@param[in]	<[引数名]:[タイプ]>			<概要>
	 *	@note	<メモ書き>
	 *	@author	<作者名>
	 *	@return	<戻り値>
	 */
	virtual void finish()	=0;
};
/**===End Class Definition=================================*/
#endif
/**===End Of File==========================================*/