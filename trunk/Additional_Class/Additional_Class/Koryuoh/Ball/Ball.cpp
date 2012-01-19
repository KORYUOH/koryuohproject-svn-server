#include "Ball.h"
#include "../Circle/Circle.h"
namespace KORYUOH{
	template<class T>
	bool Ball<T>::Collision(const Ball<T>& bal)const{

		T X = m_x - bal.m_x;
		T Y = m_y - bal.m_y;
		T Z = m_z - bal.m_z;
		T R = m_r + bal.m_r;

		return (X*X+Y*Y+Z*Z<R*R)? true:false;
	};

	template<class T>
	void Ball<T>::add_pos(T vx,T vy,T vz){
		m_x	+=	vx;
		m_x	+=	vy;
		m_z	+=	vz;
	}
};