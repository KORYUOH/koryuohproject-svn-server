#ifndef	__Circle_h_
#define	__Circle_h_
namespace KORYUOH{
	template <class T>
	class Circle{
	protected:
		T m_x,m_y,m_r;
	public:
		Circle():m_x(0),m_y(0),m_r(0){}
		Circle(T x,T y):m_x(x),m_y(y),m_r(0){}
		Circle(T x,T y, T r):m_x(x),m_y(y),m_r(r){};
		virtual ~Circle(){};

		void add_pos(T vx,T vy);
		bool Collision(Circle<T>& tgt);
	};

	typedef	 Circle<int>			CrcleI;
	typedef	 Circle<float>		CrcleF;
	typedef	 Circle<double>		CrcleD;
};
#endif