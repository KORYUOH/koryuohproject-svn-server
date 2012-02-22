/**===File Commentary=======================================*/
/**
 *	@file	Mouse.h
 *
 *	@brief	�}�E�X����
 *
 *	@author	KORYUOH
 *
 *	@date	2012/01/13
 */
/**===Include Guard========================================*/
#ifndef _MOUCE_H_INCLUDED_
#define _MOUCE_H_INCLUDED_
/**===File Include=========================================*/
#include	<../Include/DxLib.h>
#include	<Define/DefineManager.h>
/**===Class Definition=====================================*/
class Mouse{
private:
	Mouse():m_Dispflag(false),m_pos_x(0),m_pos_y(0){};
	Mouse(const Mouse& it);
	Mouse&  operator = (const Mouse& are);
public:
	/**
	 *	@brief	���z�f�X�g���N�^
	 *	@author	KORYUOH
	 */
	virtual ~Mouse(){};
private:
	bool m_Dispflag;
	int m_pos_x,m_pos_y;
public:
	/**
	 *	@brief	���̂𓾂�
	 *	@author	KORYUOH
	 *	@return	����
	 */
	static Mouse& getInstance(){
		static Mouse Instance;
		return Instance;
	}

public:
	/**
	 *	@brief	�J�[�\���\�����[�h�̕ύX
	 *	@param[in]	flag:bool	�\����true
	 *	@author	KORYUOH
	 */
	void setMouseCursolDispFlag(bool flag);
	/**
	 *	@brief	�}�E�X�̈ʒu�̍X�V
	 *	@author	KORYUOH
	 */
	void MousePositionUpdate();
	/**
	 *	@brief	�N���b�N���ꂽ���̃`�F�b�N
	 *	@author	KORYUOH
	 *	@return	�N���b�N���ꂽ�Ƃ�true
	 */
	bool onClick();
	/**
	 *	@brief	�E�N���b�N���ꂽ���̃`�F�b�N
	 *	@author	KORYUOH
	 *	@return	�N���b�N���ꂽ�Ƃ�true
	 */
	bool onClickR();
	/**
	 *	@brief	�z�C�[���N���b�N���ꂽ���̃`�F�b�N
	 *	@author	KORYUOH
	 *	@return	�N���b�N���ꂽ�Ƃ�true
	 */
	bool onClickM();
	/**
	 *	@brief	��`���ɓ����Ă��邩
	 *	@param[in]	accept:Rect	��`���
	 *	@author	KORYUOH
	 *	@return	�����Ă����true
	 */
	bool onClick(Rect accept);
	/**
	 *	@brief	�~���ɓ����Ă��邩
	 *	@param[in]	accept:Circle	�~���
	 *	@author	KORYUOH
	 *	@return	�����Ă����true
	 */
	bool onClick(Circle accept);
	/**
	 *	@brief	��`���ɓ����Ă��邩
	 *	@param[in]	accept:Rect	��`���
	 *	@author	KORYUOH
	 *	@return	�����Ă����true
	 */
	bool onClickR(Rect accept);
	/**
	 *	@brief	�~���ɓ����Ă��邩
	 *	@param[in]	accept:Circle	�~���
	 *	@author	KORYUOH
	 *	@return	�����Ă����true
	 */
	bool onClickR(Circle accept);
	/**
	 *	@brief	��`���ɓ����Ă��邩
	 *	@param[in]	accept:Rect	��`���
	 *	@author	KORYUOH
	 *	@return	�����Ă����true
	 */
	bool onClickM(Rect accept);
	/**
	 *	@brief	�~���ɓ����Ă��邩
	 *	@param[in]	accept:Circle	�~���
	 *	@author	KORYUOH
	 *	@return	�����Ă����true
	 */
	bool onClickM(Circle accept);
private:
	/**
	 *	@brief	��`�`�F�b�N
	 *	@param[in]	accept:Rect	��`���
	 *	@author	KORYUOH
	 *	@return	�������Ȃ�true
	 */
	bool CheckRect(Rect accept);
};
#endif // _MOUCE_H_INCLUDED_