#include "Circle.h"
namespace KORYUOH{
	template <class T>
	bool Circle<T>::Collision(Circle<T>& tgt){
		T X = this.m_x - tgt.m_x;
		T Y = this.m_x - tgt.m_x;
		T R = this.m_r + tgt.m_r;

		return (X*X+Y*Y<R*R)? true:false;
	}

	template<class T>
	void Circle<T>::add_pos(T vx,T vy){
		m_x += vx;
		m_y += vy;
	}
};