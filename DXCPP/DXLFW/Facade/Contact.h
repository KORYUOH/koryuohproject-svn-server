#ifndef	__Contact
#define	__Contact
#include	<Key/Key.h>
#include	<Pad/Pad.h>
#include	<Mouse/Mouce.h>
namespace CONTACT{
	namespace MOUSE{
		enum BUTTON{
			LEFT =0,
			RIGHT,
			MIDDLE
		};
	};


	int inputPad(unsigned int Handle){
		return Pad::getInstance().CheckStatePad(Handle);
	}

	int inputKey(unsigned int Handle){
		return Key::getInstance().CheckStateKey(Handle);
	}

	bool MouseOnClickInRect(Rect rect){
		return Mouse::getInstance().onClickInRect(rect);
	}

	bool MouseOnClickInCircle(Circle c){
		return Mouse::getInstance().onClickInCircle(c);
	}

	bool MouseOnClick(int MOUSEBUTTON){
		switch(MOUSEBUTTON){
			case MOUSE::BUTTON::LEFT:		return Mouse::getInstance().onClick();break;
			case MOUSE::BUTTON::RIGHT:		return Mouse::getInstance().onClickR;break;
			case MOUSE::BUTTON::MIDDLE:	return Mouse::getInstance().onClickM;break;
			default: false;
		}
	}
};


#endif	//__Contact