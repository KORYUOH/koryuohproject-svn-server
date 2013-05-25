#ifndef _LOOP_PLAY_THREAD_H_
#define _LOOP_PLAY_THREAD_H_

#include "./Thread/Thread.h"
#include "./Thread/CriticalSection.h"

// ループターゲットインターフェース
class LoopPlayTarget {
public:
	// 仮想デストラクタ
	virtual ~LoopPlayTarget() {}
	// リスタート
	virtual void restart() = 0;
	// 終了しているか？
	virtual bool isEnd() const = 0;
};

// ループ再生スレッド
class LoopPlayThread : public Thread {
public:
	// コンストラクタ
	LoopPlayThread(LoopPlayTarget* target=0);
	// デストラクタ
	~LoopPlayThread();
	// スレッドの開始
	void start();
	// ループターゲットを追加
	void entry(LoopPlayTarget* target);
	// ループチェックの終了
	void end();
	// ループチェックをしているか？
	bool isEnd() const;

private:
	// スレッドの処理
	void run();
	// ループチェック
	void loop();

	// コピー禁止
	LoopPlayThread(const LoopPlayThread& other);
	LoopPlayThread& operator =(const LoopPlayThread& other);

private:
	// ループターゲット
	LoopPlayTarget* target_;
	// 終了フラグ
	bool end_;
	// クリティカルセクション
	CriticalSection lock_;
};

#endif
