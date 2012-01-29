#ifndef __Pad
#define __Pad
#include	<Define/Define.h>
#include	<Define/Structure.h>
#include	<../Include/DxLib.h>
#include	<Key/Key.h>
struct PS2{
	int left,up,right,down,circle,triangle,square,cross,l1,l2,r1,r2,start,select;
	
	PS2():
	left(1),up(3),right(2),down(0),
	circle(5),triangle(6),square(7),cross(4),
	l1(10),l2(8),r1(11),r2(9),start(13),select(14){};
	
	/*
	configpad.down			=0;
	configpad.left				=1;
	configpad.right			=2;
	configpad.up				=3;
	configpad.cross			=4;
	configpad.circle			=5;
	configpad.triangle		=6;
	configpad.square		=7;
	configpad.l2				=8;
	configpad.r2				=9;
	configpad.l1				=10;
	configpad.r1				=11;
	configpad.start			=13;
	configpad.select			=14;
	*/
};
class Pad{
private:
	/**
	 *	@brief	�R���X�g���N�^
	 *	@author	KORYUOH
	 */
	Pad():configpad(){};
	/**
	 *	@brief	�R�s�[�R���X�g���N�^
	 *	@brief	������Z�q�I�[�o�[���[�h
	 *	@author	KORYUOH
	 */
	Pad(const Pad& p);
	Pad& operator = (const Pad& pad);
private:
	/**
	 *	@note	�L�[������
	 */
	int Key[PAD_MAX];
	/**
	 *	PS2�p�b�h�R���g���[���\����
	 */
	PS2 configpad;
	/**
	 *	@brief	�傫���ق���Ԃ�
	 *	@param[in]	*p:�p�b�h
	 *	@param[in]	k:�L�[
	 *	@note	�����Ŏg�p
	 *	@author	KORYUOH
	 */
	void input_pad_or_key(int *p, int k){
		*p = *p>k ? *p : k;
	}
	/**
	 *	@brief	�L�[�̏�����
	 *	@note	PS2�悤�ɃR���o�[�g
	 *	@author	KORYUOH
	 */
	void KeyInit();
public:
	/**
	 *	@brief	���̂��擾
	 *	@author	KORYUOH
	 *	@return	����
	 */
	static Pad& getInstance(void){
		static Pad Instance;
		return Instance;
	}
	/**
	 *	@brief	�S�Ẵp�b�h�̓��͏�Ԃ̎擾
	 *	@author	KORYUOH
	 */
	void	GetHitPadStateAll();
	/**
	 *	@brief	�p�b�h�̓��͏�Ԃ��擾
	 *	@param[in]	�~����Padkey
	 *	@author	KORYUOH
	 *	@return	�����ĂȂ����0
	 */
	int CheckStatePad(unsigned int Handle);
		/**
	 *	@brief	�p�b�h�̃g���K�[���͏�Ԃ��擾
	 *	@param[in]	�~����Padkey
	 *	@author	KORYUOH
	 *	@return	�����ꂽ�Ƃ���1
	 */
	int CheckStateTrigger(unsigned int Handle);
		/**
	 *	@brief	�p�b�h�̃g�O�����͏�Ԃ��擾
	 *	@param[in]	�~����Padkey
	 *	@author	KORYUOH
	 *	@return	�����ĂȂ����0
	 */
	int CheckStateToggle(unsigned int Handle);
private:
	bool TriggerHandle[PAD_MAX];
	bool ToggleHandle[PAD_MAX];
};
#endif