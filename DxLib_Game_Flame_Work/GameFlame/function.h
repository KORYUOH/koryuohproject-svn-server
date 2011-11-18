//key.cpp
	//現在のキー入力処理を行う
	GLOBAL int GetHitKeyStateAll_2();
	//受け取ったキー番号の現在の入力状態を返す
	GLOBAL int CheckStateKey(unsigned char Handle);

	//現在のパッド入力処理を行う関数
	GLOBAL void GetHitPadStateAll();
	//受け取ったパッド番号の現在の入力状態を返す
//	GLOBAL int CheckStatePad(unsigned int Handle);
		// if文法	if(CheckStatePad(unsigned int Handle)>0)
		//				TRUE
//	GLOBAL int CheckStateTrigger(unsigned int Handle);
		// if文法	if(CheckStateTrigger(unsigned int Handle)>0)
		//				TRUE
//	GLOBAL int CheckStateToggle(unsigned int Handle);
		// if文法	if(CheckStateToggle(unsigned int Handle)>0)
		//				TRUE

	GLOBAL int CheckHitState(unsigned int Handle,int PadMode=PUSH);
				// Handle configpad.any			PadMode PUSH TRIGGER TOGGLE
//ini.cpp
//	GLOBAL void key_init();
//	GLOBAL void other_Init();
	GLOBAL void Init_main();


//out.cpp
	GLOBAL int HitCheck_R2R(double ax,double ay,double ar,double bx,double by,double br);
	GLOBAL int HitCheck_B2B(int x1,int y1,unsigned int h1,unsigned int w1,int x2,int y2,unsigned int h2,unsigned int w2);
	GLOBAL int HitCheck_B2R(double x,double y,double width,double height,double angle,double rx,double ry,double Range,double HF);

//game.cpp
	GLOBAL void game_Init();
	GLOBAL void game_Main();
	GLOBAL void game_Draw();
	GLOBAL void game_End();

//fps.cpp
	GLOBAL void fps_wait();
	GLOBAL void draw_fps(int x, int y);