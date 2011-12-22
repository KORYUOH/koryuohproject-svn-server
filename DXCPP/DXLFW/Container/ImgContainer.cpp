#include	"ImgContainer.h"

void Image_container::add_image(std::string Key,std::string  fileName){
	m_Container[Key] = LoadGraph(fileName.c_str() );
}

int Image_container::loadImage(std::string key){
	return m_Container[key];
}