#include "Buffer.h"
#include <vector>

template<class T>
T Buffer<T>::push(T foo){
	std::vector<T>::iterator tor = m_Container.begin();
	m_exit = *Itor;
	Itor	=	m_Container.erase(Itor);
	m_Container.push_back(foo);
	return m_exit;
}

template<class T>
void Buffer<T>::resize(const int Size){
	m_Container.resize(Size);
}

template<class T>
int Buffer<T>::size()const{
	return m_Container.size();
}