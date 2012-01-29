/**===File Commentary=======================================*/
/**
 *	@file	Fps.h
 *
 *	@brief	FPS����
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
 *	@note	FPS�ݒ�l	60fps
 */
#define FPS_DEFINE 60
/**===Class Definition=======================================*/
class FPS_Ctrl{
private:
	/**
	 *	@note	FPS�v�Z�p
	 */
	int m_fpsCount,m_count0t;
	int m_f[FPS_DEFINE];
	double m_average;

private:
	/**
	 *	@brief	�R���X�g���N�^
	 *	@note	���������s��
	 *	@author	KORYUOH
	 */
	FPS_Ctrl():m_fpsCount(0),m_count0t(0),m_average(0.0f){};
public:
	/**
	 *	@brief	���z�f�X�g���N�^
	 *	@author	KORYUOH
	 */
	virtual ~FPS_Ctrl(){};
	/**
	 *	@brief	���̂𓾂�
	 *	@author	KORYUOH
	 *	@return	����
	 */
	static FPS_Ctrl& getInstance(){
		static FPS_Ctrl Instance;
		return Instance;
	}

public:
	/**
	 *	@brief	fps�ҋ@����
	 *	@note	�����Ɏ��s�����
	 *	@author	KORYUOH
	 */
	void fps_wait();
	/**
	 *	@brief	fps�̒l��`��
	 *	@param[in]	x:x���W
	 *	@param[in]	y:y���W
	 *	@author	KORYUOH
	 */
	void draw_fps(int x,int y);
private:
	/**
	 *	@brief	����fps�̌v�Z����
	 *	@author	KORYUOH
	 */
	void calc_ave();
	int Phase_first(const int t);
	int CreateBase(const int t);
};


#endif	//__Fps_Contorol
