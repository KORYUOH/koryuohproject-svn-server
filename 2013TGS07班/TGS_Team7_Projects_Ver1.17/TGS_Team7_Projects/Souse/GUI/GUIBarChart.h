/******************************************************************************
* File Name : GUIBarChart.h                       Ver : 1.00  Date : 2013-05-06
*
* Description :
*
*		�_�O���tGUI�N���X�D
*
* Author : Shouta Takemura.
*
******************************************************************************/
#ifndef _GUI_BAR_CHART_H_
#define _GUI_BAR_CHART_H_

/*---- �w�b�_�t�@�C���̓ǂݍ��� ---------------------------------------------*/

#include"GUI.h"

/*---- ��s�錾 -------------------------------------------------------------*/

class IFlagManager;


/// <summary>
/// �_�O���tGUI.
/// </summary>
class GUIBarChart : public GUI
{
public:
	/// <summary>
	/// �R���X�g���N�^.
	/// </summary>
	/// <param name="collider">�Փˏ��</param>
	/// <param name="flagManager">�t���O�Ǘ���</param>
	/// <param name="maxValue">�l�ւ̃p�X</param>
	/// <param name="angle">�p�x</param>
	/// <param name="color">�F</param>
	GUIBarChart( Collider& collider, IFlagManager& flagManager, float* value, float angle, const GScolor& color );
	/// <summary>
	/// �X�V.
	/// </summary>
	/// <param name="frameTimer">�t���[�����[�g</param>
	virtual void Update( float frameTimer );
	/// <summary>
	/// �`��.
	/// </summary>
	/// <param name="position">�t���[���̈ʒu</param>
	/// <param name="angle">�p�x</param>
	virtual void Draw( const GSvector2& position, float angle ) const;
private:
	/// <summary>
	/// �l�ւ̃p�X.
	/// </summary>
	float*		mValue;
	/// <summary>
	/// �p�x.
	/// </summary>
	float		mAngle;
	/// <summary>
	/// �_�O���t�̕`��F.
	/// </summary>
	GScolor		mColor;
	/// <summary>
	/// �X�P�[���{��.
	/// </summary>
	static const float SCALE_RATE;

}; // class GUIBarChart end


#endif // _GUI_BAR_CHART_H_ end

/********** End of File ******************************************************/
