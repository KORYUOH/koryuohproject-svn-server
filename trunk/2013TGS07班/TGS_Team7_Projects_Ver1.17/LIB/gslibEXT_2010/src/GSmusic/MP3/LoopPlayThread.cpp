#include "LoopPlayThread.h"

// コンストラクタ
LoopPlayThread::LoopPlayThread(LoopPlayTarget* target) :
	target_(target), end_(true) {
}

// デストラクタ
LoopPlayThread::~LoopPlayThread() {
	end();
}

// スレッドの開始
void LoopPlayThread::start() {
	// スレッドが動いていれば一度終了する
	if (!end_) {
		end();
	}
	// スレッドを開始する
	end_ = false;
	Thread::start();
}

// ループスレッドを終了する
void LoopPlayThread::end() {
	// スレッドの終了を待つ
	end_ = true;
	join();
}

// スレッドの実行
void LoopPlayThread::run() {
	while (!end_) {
		// ループ処理
		loop();
		// 他のスレッドに制御を渡す
		yield();
	}
}

// ループターゲットの追加
void LoopPlayThread::entry(LoopPlayTarget* target) {
	CriticalSection::Lock guard(lock_);
	target_ = target;
}

// ループ処理
void LoopPlayThread::loop() {
	if (target_ != 0) {
		CriticalSection::Lock guard(lock_);
		if (target_ != 0) {
			// 終了していればリスタートする
			if (target_->isEnd()) {
				target_->restart();
        	}
		}
	}
}

// ループチェックをしているか？
bool LoopPlayThread::isEnd() const {
	return end_;
}
