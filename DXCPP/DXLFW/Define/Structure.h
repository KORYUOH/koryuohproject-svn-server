/**===File Commentary=======================================*/
/**
 *	@file	Structure.h
 *
 *	@brief	\‘¢‘Ì’è‹`
 *
 *	@author	KORYUOH
 *
 *	@date	2011/12/26
 */
/**===Include Guard========================================*/
#ifndef	__Struct
#define	__Struct
class Ball;
class Circle{
	friend class Ball;
public:
	float x,y,r;
	Circle():x(0),y(0),r(0){};

	Circle(float ax,float ay, float ar):
	x(ax),y(ay),r(ar)
	{};

	Circle(float ax,float ay):
	x(ax),y(ay),r(0.0)
	{};

	bool Collision(const Circle target)const{
		float X = this->x - target.x;
		float Y = this->y - target.y;
		float R = this->r + target.r;
		return (X*X+Y*Y<R*R)? true:false;
	}

};
class Ball:public Circle{
public:
	Ball():Circle(),z(0){};
	Ball(float ax,float ay,float az):Circle(ax,ay),z(az){};
	Ball(float ax,float ay,float az,float ar):Circle(ax,ay,ar),z(az){};
	float z;
	bool Collision(const Ball target)const{
		float X = this->x - target.x;
		float Y = this->y - target.y;
		float Z = this->z - target.z;
		float R = this->r + target.r;
		return (X*X*+Y*Y+Z*Z<R*R)? true:false;

	}
};

struct Rect{
	float x,y,width,height;

	Rect(){};

	Rect(float ax,float ay,float aw,float ah):
	x(ax),y(ay),width(aw),height(ah)
	{};

	Rect(float ax,float ay):
	x(ax),y(ay),width(0.0f),height(0.0f)
	{};


};

#endif