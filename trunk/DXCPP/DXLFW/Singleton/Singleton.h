/**
	@FileName	Singleton.h
	@note			シングルトンパターン適応物をファザード化
*/
#ifndef _SINGLETON_H_INCLUDED_
#define _SINGLETON_H_INCLUDED_
#include	"../Pad/Pad.h"
#include	"../Key/Key.h"
#include	"../Mouse/Mouce.h"

#include	"../Fps/Fps.h"

#include	"../Container/ImgContainer.h"
namespace SINGLETON{
	namespace INPUT{
		Pad& PadInstance(){
			return Pad::getInstance();
		}
		Key& KeyInstance(){
			return Key::getInstance();
		}
		Mouse& MouseInstance(){
			return Mouse::getInstance();
		}
	};
	namespace SYSTEM{
		FPS_Ctrl& FPSInstance(){
			return FPS_Ctrl::getInstance();
		}
	};
	namespace CONTAINER{
		Image_container& ImgCInstance(){
			return Image_container::getInstance();
		}
	};
};
#endif // _SINGLETON_H_INCLUDED_
