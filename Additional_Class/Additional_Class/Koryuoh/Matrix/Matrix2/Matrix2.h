/**===File Commentary=======================================*/
/**
 *	@file	Matrix2.h
 *
 *	@brief	マトリクス
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
	//X成分,Y成分
	float	x,y;
	
public:
	/**
	 *	@note	コンストラクタ
	 *	@author	KORYUOH
	 *	@date	2012/04/18
	 */
	Matrix2(float x,float y){
		this->x = x;
		this->y = y;
	};
	/**
	 *	@note	加算
	 *	@author	KORYUOH
	 *	@date	2012/04/18
	 */
	Matrix2& add(const Matrix2& add);
	/**
	 *	@note	減算
	 *	@author	KORYUOH
	 *	@date	2012/04/18
	 */
	Matrix2& sub(const Matrix2& sub);
	/**
	 *	@note	実数倍
	 *	@author	KORYUOH
	 *	@date	2012/04/18
	 */
	Matrix2& scale(float scale);
	/**
	 *	@note	長さの計算
	 *	@author	KORYUOH
	 *	@date	2012/04/18
	 */
	float length();
	/**
	 *	@note	正規化
	 *	@author	KORYUOH
	 *	@date	2012/04/18
	 */
	void nomalize();
	/**
	 *	@note	内積
	 *	@author	KORYUOH
	 *	@date	2012/04/18
	 */
	float innerProduct(const Matrix2& target);
	/**
	 *	@brief	X成分取得
	 *	@author	KORYUOH
	 *	@date	2012/04/22
	 */
	float getX()const{
		return this->x;
	}
	/**
	 *	@brief	Y成分取得
	 *	@author	KORYUOH
	 *	@date	2012/04/22
	 */
	float getY()const{
		return this->y;
	}
	//_/_/_/_/_/オーバーロード_/_/_/_/_/

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
