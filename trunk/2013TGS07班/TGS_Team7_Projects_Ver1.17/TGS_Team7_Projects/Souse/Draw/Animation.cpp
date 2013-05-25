/******************************************************************************
* File Name : Animation.cpp                       Ver : 1.00  Date : 2012-12-16
*
* Description :
*
*		�A�j���[�V�����N���X�̎����D
*
* Author : Shouta Takemura.
*
******************************************************************************/
#include"Animation.h"
#include"AnimationTimer.h"

#include"../Draw\Renderer.h"
#include"../Draw\TextureID.h"
#include<algorithm>
#include"../Utility\ToString.h"


/// <summary>
/// �R���X�g���N�^.
/// </summary>
/// <param name="id">�A�j���[�V����������e�N�X�`��ID</param>
Animation::Animation( TextureID id ):
	mCurrentCell(""),
	mPreviousCell(""),
	mCellNo( 0 ),
	mAnimationTimer(),
	mID(id),
	mIsBlink( false )
{
	mCells.clear();
}


/// <summary>
/// ������.
/// </summary>
void Animation::Initialize()
{
	//�ŏ��̘A�z�z��̃L�[�����݂̃L�[�ɕύX
	mCurrentCell =  mCells.begin()->first;
	//�A�j���[�V�����^�C�}�[�̏�����
	mAnimationTimer.Initialize();
	//�Z���ԍ�������
	mCellNo = 0;
	//�Ō�̃L�[�ɋ�̒Z�`��ǉ�����
	mCells["EndKey"] = GSrect(0,0,0,0);
	//�_�ł𖳌��ɐݒ�
	mIsBlink = false;
}

/// <summary>
/// �e�N�X�`��ID�̐ݒ�.
/// </summary>
/// <param name="id">�A�j���[�V����������e�N�X�`��ID</param>
void Animation::SetTextureID( TextureID id )
{
	mID = id;
}

/// <summary>
/// �X�V.
/// </summary>
/// <param name="frameTimer">�t���[�����[�g</param>
/// <param name="initial">�A�j���[�V����������\��������</param>
void Animation::Update( float frameTimer, std::string initial )
{
	// �A�j���[�V�����^�C�}�[���X�V.
	mAnimationTimer.Update( frameTimer );

	// ���݂̃Z����1�t���[���O�̂���Ƃ��đ��.
	mPreviousCell = mCurrentCell;

	// �Z���L�[���쐬.
	CreateCurrentCellCell(initial,mCellNo);

	// �쐬�����L�[���}�b�v�ɓo�^����Ă��Ȃ���.
	if( mCurrentCell != mPreviousCell )
	{
		// ���Z�b�g.
		Reset(initial);
	}

	// �A�j���[�V�����^�C�}�[���[���łȂ���.
	if( !mAnimationTimer.IsZero() )
	{
		// �����I��.
		return;
	}

	// �\��������Z���̗�ԍ����C���N�������g.
	mCellNo++;

	// �󂯎�����������ŃL�[���쐬���Č��݂̃Z���Ƃ��Đݒ�.
	CreateCurrentCellCell(initial,mCellNo);

	// �쐬�����L�[���}�b�v�ɓo�^����Ă��Ȃ����.
	if( mCells.find(mCurrentCell) == mCells.end() /*&& currentCell != cells.end()->first*/ )
	{
		// ���Z�b�g����.
		Reset(initial);
	}

	// �A�j���[�V�����^�C�}�[�����Z�b�g.
	mAnimationTimer.Reset();
	// �_�ł��X�V.
	BlinkUpdate();
}

/// <summary>
/// �A�j���[�V�����摜�̐؂�o�����(�Z�`)��o�^.
/// </summary>
/// <param name="initial">�A�j���[�V����������\��������</param>
/// <param name="line">���s�ڂ̉摜</param>
/// <param name="peace">���摜����</param>
/// <param name="width">1���摜������̉���</param>
/// <param name="height">1���摜������̏c��</param>
void Animation::AddCell( std::string initial, int line, int peace, int width, int height)
{
	//1�Z�������W�ԍ���o�^
	for( int i = 0 ; i < peace ; ++i)
	{
		//�}�b�v�L�[�ɓ������̔ԍ���U���ĊǗ�
		std::string key = initial + IntToString(i);

		//�Z�`����ݒ�
		GSrect rect(i*width,(line-1)*height, width, height);
		rect.right = rect.left + width;
		rect.bottom = rect.top + height;

		//�ԍ��̒Z�`��o�^
		mCells[key] = rect;
	}
}

/// <summary>
/// �Z���L�[���쐬�u��:D0,D1....�v.
/// </summary>
/// <param name="initial">�ǉ����铪����</param>
/// <param name="number">�Z���̗�ԍ�</param>
void Animation::CreateCurrentCellCell( std::string initial, int number )
{
	mCurrentCell = initial + IntToString(number);
}

/// <summary>
/// ���Z�b�g.
/// </summary>
/// <param name="centor">���������铪����</param>
void Animation::Reset(std::string initial)
{
	// �Z���̗�ԍ���������.
	mCellNo = 0;
	// �Z���L�[���쐬.
	CreateCurrentCellCell( initial,mCellNo );
	// �A�j���[�V�����^�C�}�[�����Z�b�g.
	mAnimationTimer.Reset();
}


/// <summary>
/// �`��.
/// </summary>
/// <param name="position">�`��ʒu</param>
/// <param name="centor">�摜�̒��S</param>
void Animation::Draw( const GSvector2& position, const GSvector2& centor ) const
{
	// �A�j���[�V�����摜���Ȃ���.
	if( mCells.size() == 0 )
	{
		// �`����s��Ȃ�.
		return;
	}

	// �摜��؂�o���ĕ`��
	Renderer::GetInstance()->DrawRectTexture( mID, position, mCells.find(mCurrentCell)->second, centor );
}

/// <summary>
/// �`��.
/// </summary>
/// <param name="position">�`��ʒu</param>
/// <param name="centor">�摜�̒��S</param>
/// <param name="rotate">��]��</param>
void Animation::Draw( const GSvector2& position, const GSvector2& centor, float rotate ) const
{
	// �A�j���[�V�����摜���Ȃ���.
	if( mCells.size() == 0 )
	{
		// �`����s��Ȃ�.
		return;
	}

	// �摜��؂�o���ĕ`��
	Renderer::GetInstance()->DrawRectTexture( mID, position, mCells.find(mCurrentCell)->second, centor, rotate );
}

/// <summary>
/// �A�j���[�V�����_�ŏ���.
/// </summary>
/// <param name="position">�`��ʒu</param>
/// <param name="centor">�摜�̒��S</param>
void Animation::DrawBlink( const GSvector2& position, const GSvector2& centor ) const
{
	// �K�[�h��
	// �_�Ńt���O���L���̎��͑����I��
	if( mIsBlink )
	{
		return;
	}

	// �摜��؂�o���ĕ`��.
	Draw( position, centor );
}

/// <summary>
/// �A�j���[�V�����_�ŏ���.
/// </summary>
/// <param name="position">�`��ʒu</param>
/// <param name="centor">�摜�̒��S</param>
/// <param name="rotate">��]��</param>
void Animation::DrawBlink( const GSvector2& position, const GSvector2& centor, float rotate ) const
{
	// �K�[�h��
	// �_�Ńt���O���L���̎��͑����I��
	if( mIsBlink )
	{
		return;
	}

	// �摜��؂�o���ĕ`��.
	Draw( position, centor, rotate );
}

/// <summary>
/// �_�Ńt���O�X�V.
/// </summary>
void Animation::BlinkUpdate()
{
	//�t���O�𔽓]������.
	mIsBlink = (mIsBlink) ? (false) : (true);
}

/********** End of File ******************************************************/