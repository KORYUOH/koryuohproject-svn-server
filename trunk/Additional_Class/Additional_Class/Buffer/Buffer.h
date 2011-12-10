#ifndef _BUFFER_H_INCLUDED_
#define _BUFFER_H_INCLUDED_
#include <vector>
template<class T>
class Buffer{
private:
	std::vector<T>		m_Container;
	T	m_exit;
	Buffer():{};
	Buffer( const Buffer& foo);
	Buffer& operator =(const Buffer& foo);

public:

	Buffer(const int BufferSize):m_exit(0),m_Container(BufferSize){
		//m_Container.reserve(BufferSize);
	};

	T push(T foo);

	void resize(const int Size);

	int size()const;
};
#endif // _BUFFER_H_INCLUDED_
