/**===File Commentary=======================================*/
/**
 *	@file	Matrix2.h
 *
 *	@brief	�}�g���N�X
 *
 *	@author	KORYUOH
 *
 *	@date	2012/02/20
 */
/**===Include Guard========================================*/
#ifndef	_MATRIX2_H_
#define	_MATRIX2_H_
/**===File Include=========================================*/

/**===Class Definition=====================================*/
class Matrix2{
private:
	//X����,Y����
	float	x,y;
	
public:
	/**
	 *	@note	�R���X�g���N�^
	 *	@author	KORYUOH
	 *	@date	2012/04/18
	 */
	Matrix2(float x,float y){
		this->x = x;
		this->y = y;
	};
	/**
	 *	@note	���Z
	 *	@author	KORYUOH
	 *	@date	2012/04/18
	 */
	Matrix2& add(const Matrix2& add);
	/**
	 *	@note	���Z
	 *	@author	KORYUOH
	 *	@date	2012/04/18
	 */
	Matrix2& sub(const Matrix2& sub);
	/**
	 *	@note	�����{
	 *	@author	KORYUOH
	 *	@date	2012/04/18
	 */
	Matrix2& scale(float scale);
	/**
	 *	@note	�����̌v�Z
	 *	@author	KORYUOH
	 *	@date	2012/04/18
	 */
	float length();
	/**
	 *	@note	���K��
	 *	@author	KORYUOH
	 *	@date	2012/04/18
	 */
	void nomalize();
	/**
	 *	@note	����
	 *	@author	KORYUOH
	 *	@date	2012/04/18
	 */
	float innerProduct(const Matrix2& target);
	/**
	 *	@brief	X�����擾
	 *	@author	KORYUOH
	 *	@date	2012/04/22
	 */
	float getX()const{
		return this->x;
	}
	/**
	 *	@brief	Y�����擾
	 *	@author	KORYUOH
	 *	@date	2012/04/22
	 */
	float getY()const{
		return this->y;
	}
	//_/_/_/_/_/�I�[�o�[���[�h_/_/_/_/_/

	Matrix2 operator +(){
		return *this;
	};
	Matrix2 operator -(){
		Matrix2 Instant(-(this->x),-(this->y));
		return Instant;
	};

	Matrix2& operator +=(const Matrix2& Target){
		this->x+=Target.x;
		this->y+=Target.y;
		return *this;
	};
	Matrix2& operator -=(const Matrix2& Target){
		this->x-=Target.x;
		this->y-=Target.y;
		return *this;
	};
	Matrix2& operator *=(const float s){
		this->scale(s);
		return *this;
	};
	Matrix2& operator /=(const float Target){
		if(Target != 0){
		this->x/=Target;
		this->y/=Target;
		return *this;
		}
		return *this;
	};

	const Matrix2 operator + (const Matrix2& v){
		Matrix2 Instance = *this;
		Instance += v;
		return Instance;
	}

	const Matrix2 operator -(const Matrix2& v){
		Matrix2 Instance = *this;
		Instance -= v;
		return Instance;
	}

	const Matrix2 operator * (float f){
		return Matrix2(*this)*=f;
	}

	const Matrix2 operator / (float f){
		if(f != 0){
			return Matrix2(*this)/=f;
		}
		return *this;
	}

	}
};
/**===End Class Definition=================================*/
#endif // _MATRIX2_H_
/**===End Of File==========================================*/
