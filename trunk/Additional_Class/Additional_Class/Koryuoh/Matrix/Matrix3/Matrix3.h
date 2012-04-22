/**===File Commentary=======================================*/
/**
 *	@file	Matrix3.h
 *
 *	@brief	�R���x�N�g��
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
	 *	@brief	�R���X�g���N�^�[
	 *	@param[in]	x����
	 *	@param[in]	y����
	 *	@param[in]	z����
	 *	@author	KORYUOH
	 */
	Matrix3(float x,float y,float z);
	
	/**
	 *	@brief	<�v��>
	 *	@param[in]	<[������]:[�^�C�v]>			<�T�v>
	 *	@note	<��������>
	 *	@author	<��Җ�>
	 *	@return	<�߂�l>
	 */
	Matrix3(const Matrix2& matrix,z);
private:
	/**	�����o�[�ϐ�*/
	Matrix2 m_matrix;
	float z;
};
/**===End Class Definition=================================*/
#endif	//_MATRIX3_H_
/**===End Of File==========================================*/