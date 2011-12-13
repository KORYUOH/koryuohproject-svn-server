#ifndef	__Struct
#define	__Struct
struct Circle{
	float x,y,r;
	Circle(){};
	
	Circle(float ax,float ay, float ar):
	x(ax),y(ay),r(ar)
	{};

	Circle(float ax,float ay):
	x(ax),y(ay),r(0.0)
	{};
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