/**===File Commentary=======================================*/
/**
 *	@file	GameApplication.cpp
 *
 *	@brief	ゲームアプリケーションクラス実装
 *
 *	@author	<作者名>
 *
 *	@date	2012/04/23
 */
/**===File Include=========================================*/
#include	<GameApplication/Gameapplication.h>
#include	<gslib.h>
#include	<sstream>
/**===Class Implementation=================================*/
/**========================================================*/
/**
 *	@brief	コールバック関数用の静的メンバ変数
 *	@note	<メモ書き>
 *	@author	<作者名>
 */
/**========================================================*/
GameApplication* GameApplication::mInstance = 0;
/**========================================================*/
/**
 *	@brief	コンストラクタ
 *	@param[in]	引数の数
 *	@param[in]	コマンドライン引数
 *	@author	<作者名>
 */
/**========================================================*/
GameApplication::GameApplication(int argc, char* argv[]):
	mWindowTitle("GameWindow"),
	mWindowPositionX( 0 ),
	mWindowPositionY( 0 ),
	mWindowWidth( 640 ),
	mWindowHeight( 480 ),
	mIsFullScreenMode( false ),
	mPerspectiveFov(50.0f),
	mPerspectiveNear(0.5f),
	mPerspectiveFar(100.0f)
{
	//自身のインスタンスを設定
	mInstance = this;
	//GLUT初期化
	glutInit(&argc,argv);
}
/**========================================================*/
/**
 *	@brief	実行
 *	@author	<作者名>
 */
/**========================================================*/
void GameApplication::run(){
	//ウィンドウの設定
	glutInitDisplayMode( GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);
	glutInitWindowPosition(getWindowPositionX(),getWindowPositionY());
	glutInitWindowSize(getWindowWidth(),getWindowHeight());
	//フルスクリーンモードか？
	if(isFullScreenMode()==true){
		std::ostringstream mode;
		//フルスクリーン設定文字列作成
		mode << getWindowWidth() << "x"<<getWindowHeight()<<"@60";
		//フルスクリーンモードに設定
		glutGameModeString(mode.str().c_str());
		glutEnterGameMode();
		//マウスカーソルは消す
		glutSetCursor(GLUT_CURSOR_NONE);
	}else{
		//ウィンドウモード
		glutCreateWindow(getWindowTitle().c_str());
	}
	
	//グラフィックシステム初期化
	gsInitGraphics();
	//サウンドシステム初期化
	gsInitSound((HWND)_glutGetHWND());
	//入力デバイスシステム初期化
	gsInitInput((HWND)_glutGetHWND());
	
	//Vsync有効化
	setSwapInterval(1);
	//乱数初期化
	gsRandamize();
	
	//OpenGL初期化
	initializeGL();
	//アプリケーション初期化
	initialize();

	//終了処理関数設定
	_glutDestroyFunc(destroy);
	//ウィンドウサイズ変更時の関数を設定
	glutReshapeFunc(reshape);
	//表示処理関数を設定
	glutDisplayFunc(display);
	//イベントのないときの関数を設定
	glutIdleFunc(idle);
	//ウィンドウがアクティブになったときの関数を設定
	_glutActivateFunc(activate);

	//フレームタイマーリセット
	gsFrameTimerReset();
	//メインループ
	glutMainLoop();
}
/**========================================================*/
/**
 *	@brief	OpenGL初期化関数
 *	@author	<作者名>
 */
/**========================================================*/
void GameApplication::initializeGL(void){
	//デフォライトパラメータ
	const static float LightAmbient[]	=	{ 0.2f, 0.2f , 0.2f , 1.0f};
	const static float LightDiffuse[]	=	{ 1.0f, 1.0f , 1.0f , 1.0f};
	const static float LightSpeclar[]	=	{ 1.0f, 1.0f , 1.0f , 1.0f};
	const static float LightPosition[]	=	{ 1.0f, 1.0f , 1.0f , 0.0f};

	//画面クリア時のカラー設定
	glClearColor(0.0f, 0.0f,0.0f,1.0f);
	//面カリング処理の有効化
	glEnable(GL_CULL_FACE);
	glCullFace(GL_BACK);
	//デプスバッファを1.0でクリア
	glClearDepth(1.0f);
	//デプステスト有効化
	glEnable(GL_DEPTH_TEST);
	//パースペクティブ補正
	glHint(GL_PERSPECTIVE_CORRECTION_HINT,GL_NICEST);
	//ブレンド有効化
	glEnable(GL_BLEND);
	//デフォブレンド式設定
	glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);
	//デフォ視点変換行列設定
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(
		0.0f, 0.0f ,10.0f,
		0.0f, 0.0f ,0.0f,
		0.0f, 1.0f ,0.0f
		);
	//デフォライト設定
	glLightfv(GL_LIGHT0,	GL_AMBIENT	,LightAmbient);
	glLightfv(GL_LIGHT0,	GL_DIFFUSE	,LightDiffuse);
	glLightfv(GL_LIGHT0,	GL_SPECULAR	,LightSpeclar);
	glLightfv(GL_LIGHT0,	GL_POSITION	,LightPosition);
	glEnable(GL_LIGHT0);
	//ライティング有効化
	glEnable(GL_LIGHTING);
}
/**========================================================*/
/**
 *	@brief	コールバック関数Destroy
 *	@author	<作者名>
 */
/**========================================================*/
void GameApplication::destroy( void ){
	//ゲーム終了処理
	mInstance->finish();

	//入力デバイスシステム終了
	gsFinishInput();
	//サウンドシステム終了
	gsFinishSound();
	//グラフィックシステム終了
	gsFinishGraphics();
}
/**========================================================*/
/**
 *	@brief	ウィンドウサイズ変更時に呼ばれるコールバック関数
 *	@param[in]	幅
 *	@param[in]	高さ
 *	@author	<作者名>
 */
/**========================================================*/
void GameApplication::reshape(int width,int height){
	//高さが0にならないように
	height = (height == 0) ? 1:height;
	//幅が0にならないように
	width = (width == 0) ? 1:width;
	//Viewport設定
	glViewport(0,0,width,height);
	//透視射影変換行列
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(
		mInstance->getPerspectiveFov(),
		(float)width/(float)height,
		mInstance->getPerspectiveNear(),
		mInstance->getPerspectiveFar()
		);
	//モデルビューモードヘ
	glMatrixMode(GL_MODELVIEW);
	//ウィンドウの幅と高さを更新
	mInstance->setWindowWidth(width);
	mInstance->setWindowHeight(height);
}
/**========================================================*/
/**
 *	@brief	何もイベントがないときに呼び出される関数
 *	@author	<作者名>
 */
/**========================================================*/
void GameApplication::idle(void){
	//フレームタイマー更新
	gsFrameTimerUpdate();
	do{
		//入力デバイス読み込み
		gsReadInput();

		//ゲーム更新処理
		mInstance->update(gsFrameTimerGetTime());

		//Escが押された？
		if(GetAsyncKeyState(VK_ESCAPE)!=0){
			if(mInstance->isFullScreenMode())
				glutLeaveGameMode();
			
			else
				//終了処理呼び出し
				mInstance->destroy();

			std::exit(0);
		}
	}while(gsFrameTimerIsSkip() == GS_TRUE);
	//描画処理を呼び出す
	glutPostRedisplay();
}
/**========================================================*/
/**
 *	@brief	描画時コールバック関数
 *	@author	<作者名>
 */
/**========================================================*/
void GameApplication::display(void){
	//画面クリア
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
	
	//ゲーム描画処理
	mInstance->draw();

	//ダブルバッファ切り替え
	glutSwapBuffers();
	//タイマーウェイト
	gsFrameTimerWait();

}
/**========================================================*/
/**
 *	@brief	ウィンドウがアクティブになったときに呼び出されるコールバック
 *	@author	<作者名>
 */
/**========================================================*/
void GameApplication::activate(int state){
	//入力デバイスにアクティヴを伝える
	gsActivateInput(state);
	//サウンドシステムにアクティブを伝える
	gsActivateSound(state);
}
/**========================================================*/
/**
 *	@brief	ダブルバッファ切り替えインターバル
 *	@param[in]	インターバル
 *	@author	<作者名>
 */
/**========================================================*/
void GameApplication::setSwapInterval(int interval){
	//wglSwapIntervalEXT拡張関数ポインタ関数型
	typedef	BOOL	(WINAPI * LPFNWGLSWAPINTERVALEXTPROC)(int interval);
	LPFNWGLSWAPINTERVALEXTPROC	wglSwapIntervalExt = NULL;
	//SwapIntervalEXTの関数ポインタを取得
	wglSwapIntervalExt = (LPFNWGLSWAPINTERVALEXTPROC)
		wglGetProcAddress("wglSwapIntervalEXT");
	//取得できた？
	if(wglSwapIntervalExt != NULL)
		wglSwapIntervalExt(interval);
}
/**========================================================*/
/**
 *	@brief	ウィンドウタイトル取得
 *	@author	<作者名>
 *	@return	ウィンドウタイトル
 */
/**========================================================*/
const std::string& GameApplication::getWindowTitle()const{
	return mWindowTitle;
}
/**========================================================*/
/**
 *	@brief	ウィンドウのX座標取得
 *	@author	<作者名>
 *	@return	x座標
 */
/**========================================================*/
int GameApplication::getWindowPositionX()const{
	return mWindowPositionX;
}
/**========================================================*/
/**
 *	@brief	ウィンドウのY座標取得
 *	@author	<作者名>
 *	@return	Y座標
 */
/**========================================================*/
int GameApplication::getWindowPositionY()const{
	return mWindowPositionY;
}
/**========================================================*/
/**
 *	@brief	ウィンドウの幅取得
 *	@author	<作者名>
 *	@return	幅
 */
/**========================================================*/
int GameApplication::getWindowWidth()const{
	return mWindowWidth;
}
/**========================================================*/
/**
 *	@brief	ウィンドウの高さ取得
 *	@author	<作者名>
 *	@return	高さ
 */
/**========================================================*/
int GameApplication::getWindowHeight()const{
	return mWindowHwight;
}
/**========================================================*/
/**
 *	@brief	視野角取得
 *	@author	<作者名>
 *	@return	視野角
 */
/**========================================================*/
float GameApplication::getPerspectiveFov()const{
	return mPerspectiveFov;
}
/**========================================================*/
/**
 *	@brief	近クリップ面取得
 *	@author	<作者名>
 *	@return	近クリップ面
 */
/**========================================================*/
float GameApplication::getPerspectiveNear()const{
	return mPerspectiveNear;
}
/**========================================================*/
/**
 *	@brief	遠クリップ面取得
 *	@author	<作者名>
 *	@return	遠クリップ面
 */
/**========================================================*/
float GameApplication::getPerspectiveFar()const{
	return mPerspectiveFar;
}








/**===End Of File==========================================*/