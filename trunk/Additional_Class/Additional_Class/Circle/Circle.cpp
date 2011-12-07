#include "Circle.h"

template <class T>
bool Circle<T>::Collision(Circle<T>& tgt){
	T X = this.m_x - tgt.m_x;
	T Y = this.m_x - tgt.m_x;
	T R = this.m_r + tgt.m_r;
	
	return (X*X+Y*Y<R*R)? true:false;
}