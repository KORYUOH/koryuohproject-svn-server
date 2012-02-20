/**===File Commentary=======================================*/
/**
 *	@file	Mouse.cpp
 *
 *	@brief	�}�E�X����
 *
 *	@author	KORYUOH
 *
 *	@date	2011/12/01
 */
/**===File Include=========================================*/
#include	<Mouse/Mouce.h>
/**===Class Implementation=================================*/
/**========================================================*/
/**
 *	@brief	�}�E�X�\���ݒ�
 *	@param[in]	�t���O:true�ŕ\��(�f�t�H���g�͔�\��)
 *	@attention	�f�t�H���g�͔�\��
 *	@author	KORYUOH
 */
/**========================================================*/
void Mouse::setMouseCursolDispFlag(bool flag){
	m_Dispflag = flag;
	SetMouseDispFlag(m_Dispflag);
}
/**========================================================*/
/**
 *	@brief	��`�������ׂ�
 *	@param[in]	��`���
 *	@author	KORYUOH
 *	@return	�����Ă����true
 */
/**========================================================*/
bool Mouse::CheckRect(Rect accept){
	//X
	if(accept.x<= m_pos_x && m_pos_x<accept.x+accept.width)
		//Y
		if(accept.y<=m_pos_y && m_pos_y < accept.y+accept.height)
			return true;

	return false;
}
/**========================================================*/
/**
 *	@brief	�}�E�X�̈ʒu���X�V����
 *	@author	KORYUOH
 */
/**========================================================*/
void Mouse::MousePositionUpdate(){
	GetMousePoint(&m_pos_x,&m_pos_y);
}
//<!-----��蒼��-----!>
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
}
bool Mouse::onClickM(){
	if((GetMouseInput() & MOUSE_INPUT_MIDDLE) != 0){
		GetMousePoint(&m_pos_x,&m_pos_y);
		return true;
	}

	return false;
}
bool Mouse::onClick(Rect accept){
	if(onClick())
		return CheckRect(accept);
	return false;
}

bool Mouse::onClick(Circle accept){
	if(onClick())
		return accept.Collision(Circle((float)m_pos_x,(float)m_pos_y,1.0f) );
	return false;
}

bool Mouse::onClickR(Rect accept){
	if(onClickR())
		return CheckRect(accept);
	return false;
}

bool Mouse::onClickR(Circle accept){
	if(onClickR())
		return accept.Collision(Circle((float)m_pos_x,(float)m_pos_y,1.0f) );
	return false;
}
bool Mouse::onClickM(Rect accept){
	if(onClickM())
		return CheckRect(accept);
	return false;
}

bool Mouse::onClickM(Circle accept){
	if(onClickM())
		return accept.Collision(Circle((float)m_pos_x,(float)m_pos_y,1.0f) );
	return false;
}