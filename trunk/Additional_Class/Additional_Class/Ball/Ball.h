#ifndef	_BALL_H_INCLUDED_
#define	_BALL_H_INCLUDED_
#include "../Circle/Circle.h"
template<class T>
class Ball :public :Circle{
	T	m_z;
public:
	Ball():m_z(0),Circle(){};
	Ball(T x,T y,T z,T r):Circle(x,y,r),m_z(z){};
	Ball(T x,T y,T z):Circle(x,y),m_z(z){};
	Ball(Circle<T>& Cir, T z):Circle(Cir),m_z(z){};
	virtual ~Ball(){};

	void add_pos(T vx,T vy,T vz);

	bool Collision(const Ball& bal)const;
};
#endif // _BALL_H_INCLUDED_
