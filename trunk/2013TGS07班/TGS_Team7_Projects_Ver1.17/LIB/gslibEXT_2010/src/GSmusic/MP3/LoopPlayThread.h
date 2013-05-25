#ifndef _LOOP_PLAY_THREAD_H_
#define _LOOP_PLAY_THREAD_H_

#include "./Thread/Thread.h"
#include "./Thread/CriticalSection.h"

// ���[�v�^�[�Q�b�g�C���^�[�t�F�[�X
class LoopPlayTarget {
public:
	// ���z�f�X�g���N�^
	virtual ~LoopPlayTarget() {}
	// ���X�^�[�g
	virtual void restart() = 0;
	// �I�����Ă��邩�H
	virtual bool isEnd() const = 0;
};

// ���[�v�Đ��X���b�h
class LoopPlayThread : public Thread {
public:
	// �R���X�g���N�^
	LoopPlayThread(LoopPlayTarget* target=0);
	// �f�X�g���N�^
	~LoopPlayThread();
	// �X���b�h�̊J�n
	void start();
	// ���[�v�^�[�Q�b�g��ǉ�
	void entry(LoopPlayTarget* target);
	// ���[�v�`�F�b�N�̏I��
	void end();
	// ���[�v�`�F�b�N�����Ă��邩�H
	bool isEnd() const;

private:
	// �X���b�h�̏���
	void run();
	// ���[�v�`�F�b�N
	void loop();

	// �R�s�[�֎~
	LoopPlayThread(const LoopPlayThread& other);
	LoopPlayThread& operator =(const LoopPlayThread& other);

private:
	// ���[�v�^�[�Q�b�g
	LoopPlayTarget* target_;
	// �I���t���O
	bool end_;
	// �N���e�B�J���Z�N�V����
	CriticalSection lock_;
};

#endif
