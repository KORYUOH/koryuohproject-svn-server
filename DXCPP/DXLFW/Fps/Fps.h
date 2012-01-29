/**===File Commentary=======================================*/
/**
 *	@file	Fps.h
 *
 *	@brief	FPS調整
 *
 *	@author	KORYUOH
 *
 *	@date	2012/01/01
 */
/**===Include Guard========================================*/
#ifndef	__Fps_Contorol
#define	__Fps_Contorol
/**===File Include=========================================*/
/*
 *	@note	FPS設定値	60fps
 */
#define FPS_DEFINE 60
/**===Class Definition=======================================*/
class FPS_Ctrl{
private:
	/**
	 *	@note	FPS計算用
	 */
	int m_fpsCount,m_count0t;
	int m_f[FPS_DEFINE];
	double m_average;

private:
	/**
	 *	@brief	コンストラクタ
	 *	@note	初期化を行う
	 *	@author	KORYUOH
	 */
	FPS_Ctrl():m_fpsCount(0),m_count0t(0),m_average(0.0f){};
public:
	/**
	 *	@brief	仮想デストラクタ
	 *	@author	KORYUOH
	 */
	virtual ~FPS_Ctrl(){};
	/**
	 *	@brief	実体を得る
	 *	@author	KORYUOH
	 *	@return	実体
	 */
	static FPS_Ctrl& getInstance(){
		static FPS_Ctrl Instance;
		return Instance;
	}

public:
	/**
	 *	@brief	fps待機処理
	 *	@note	自動に実行される
	 *	@author	KORYUOH
	 */
	void fps_wait();
	/**
	 *	@brief	fpsの値を描画
	 *	@param[in]	x:x座標
	 *	@param[in]	y:y座標
	 *	@author	KORYUOH
	 */
	void draw_fps(int x,int y);
private:
	/**
	 *	@brief	平均fpsの計算処理
	 *	@author	KORYUOH
	 */
	void calc_ave();
	int Phase_first(const int t);
	int CreateBase(const int t);
};


#endif	//__Fps_Contorol
