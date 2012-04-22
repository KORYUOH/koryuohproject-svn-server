/**===File Commentary=======================================*/
/**
 *	@file	Matrix3.h
 *
 *	@brief	３次ベクトル
 *
 *	@author	KORYUOH
 *
 *	@date	2012/04/22
 */
/**===Include Guard========================================*/
#ifndef	_MATRIX3_H_
#define	_MATRIX3_H_
/**===File Include=========================================*/
#include	"../Matrix2/Matrix2.h"
/**===Class Definition=====================================*/
class Matrix3{
public:
	/**
	 *	@brief	コンストラクター
	 *	@param[in]	x成分
	 *	@param[in]	y成分
	 *	@param[in]	z成分
	 *	@author	KORYUOH
	 */
	Matrix3(float x,float y,float z);
	
	/**
	 *	@brief	<要約>
	 *	@param[in]	<[引数名]:[タイプ]>			<概要>
	 *	@note	<メモ書き>
	 *	@author	<作者名>
	 *	@return	<戻り値>
	 */
	Matrix3(const Matrix2& matrix,z);
private:
	/**	メンバー変数*/
	Matrix2 m_matrix;
	float z;
};
/**===End Class Definition=================================*/
#endif	//_MATRIX3_H_
/**===End Of File==========================================*/