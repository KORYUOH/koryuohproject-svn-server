#include	"Mouce.h"

void Mouse::setMouseCursolDispFlag(bool flag){
	m_Dispflag = flag;
	SetMouseDispFlag(m_Dispflag);
}
bool Mouse::CheckRect(Rect accept){
	//X
	if(accept.x<= m_pos_x && m_pos_x<accept.x+accept.width)
		//Y
		if(accept.y<=m_pos_y && m_pos_y < accept.y+accept.height)
			return true;

	return false;
}
void Mouse::MousePositionUpdate(){
	GetMousePoint(&m_pos_x,&m_pos_y);
}

bool Mouse::onClick(){
	if((GetMouseInput() & MOUSE_INPUT_LEFT) != 0){
		GetMousePoint(&m_pos_x,&m_pos_y);
		return true;
	}

	return false;
}
bool Mouse::onClickR(){
	if((GetMouseInput() & MOUSE_INPUT_RIGHT) != 0){
		GetMousePoint(&m_pos_x,&m_pos_y);
		return true;
	}

	return false;
}bool Mouse::onClickM(){
	if((GetMouseInput() & MOUSE_INPUT_MIDDLE) != 0){
		GetMousePoint(&m_pos_x,&m_pos_y);
		return true;
	}

	return false;
}
bool Mouse::onClickInRect(Rect accept){
	if(onClick())
		return CheckRect(accept);
	return false;
}

bool Mouse::onClickInCircle(Circle accept){
	if(onClick())
		return accept.Collision(Circle((float)m_pos_x,(float)m_pos_y,1.0f) );
	return false;
}