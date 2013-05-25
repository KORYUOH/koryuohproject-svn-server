#include "LoopPlayThread.h"

// �R���X�g���N�^
LoopPlayThread::LoopPlayThread(LoopPlayTarget* target) :
	target_(target), end_(true) {
}

// �f�X�g���N�^
LoopPlayThread::~LoopPlayThread() {
	end();
}

// �X���b�h�̊J�n
void LoopPlayThread::start() {
	// �X���b�h�������Ă���Έ�x�I������
	if (!end_) {
		end();
	}
	// �X���b�h���J�n����
	end_ = false;
	Thread::start();
}

// ���[�v�X���b�h���I������
void LoopPlayThread::end() {
	// �X���b�h�̏I����҂�
	end_ = true;
	join();
}

// �X���b�h�̎��s
void LoopPlayThread::run() {
	while (!end_) {
		// ���[�v����
		loop();
		// ���̃X���b�h�ɐ����n��
		yield();
	}
}

// ���[�v�^�[�Q�b�g�̒ǉ�
void LoopPlayThread::entry(LoopPlayTarget* target) {
	CriticalSection::Lock guard(lock_);
	target_ = target;
}

// ���[�v����
void LoopPlayThread::loop() {
	if (target_ != 0) {
		CriticalSection::Lock guard(lock_);
		if (target_ != 0) {
			// �I�����Ă���΃��X�^�[�g����
			if (target_->isEnd()) {
				target_->restart();
        	}
		}
	}
}

// ���[�v�`�F�b�N�����Ă��邩�H
bool LoopPlayThread::isEnd() const {
	return end_;
}
