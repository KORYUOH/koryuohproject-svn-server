#ifndef _IMGCONTAINER_H_INCLUDED_
#define _IMGCONTAINER_H_INCLUDED_
#include	"../../Include/DxLib.h"
#include	<map>
#include	<string>
class Image_container{
private:
	Image_container(){};
	Image_container(const Image_container& cntn);
	Image_container& operator=(const Image_container& cntn);

private:
	std::map<std::string,int> m_Container;
public:
	static Image_container& getInstance(){
		static Image_container Instance;
		return Instance;
	}

public:
	void add_image(std::string Key,std::string fileName);
	int loadImage(std::string key);

	int operator[] (std::string Key){
		return getInstance().loadImage(Key);
	}
};
#endif // _IMGCONTAINER_H_INCLUDED_
