/**===File Commentary=======================================*/
/**
 *	@file	Factory.h
 *
 *	@brief	�t�@�N�g���[�N���X
 *
 *	@author	<��Җ�>
 *
 *	@date	2012/04/30
 */
/**===Include Guard========================================*/
#ifndef	_FACTORY_H_
#define	_FACTORY_H_
/**===File Include=========================================*/
#include	<string>
#include	<algorithm>
#include	<map>
/**===Class Definition=====================================*/
template<class Ty>
class Factory{
public:
	/**
	 *	@brief	<�v��>
	 *	@param[in]	<[������]:[�^�C�v]>			<�T�v>
	 *	@note	<��������>
	 *	@author	<��Җ�>
	 *	@return	<�߂�l>
	 */
	~Factory(){
		std::for_each(mTypeContainer.begin(),mTypeContainer.end(),[&](Ty* pt){delete pt;});
	}
	void add(const std::string& name,Ty* ptr){
		mTypeContainer[name] = ptr;
	}

	std::shared_ptr<Ty> clone(const std::string& name){
		return std::shared_ptr<Ty>(new mTypeContainer[name]);
	}
private:
	/**	�����o�[�ϐ�*/
	typedef std::map<std::string,Ty*> TypeContainer;
	
	TypeContainer mTypeContainer;

};
/**===End Class Definition=================================*/
#endif
/**===End Of File==========================================*/