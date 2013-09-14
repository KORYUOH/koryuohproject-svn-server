/**===File Commentary=======================================*/
/**
 *	@file	GameApplication.cpp
 *
 *	@brief	ゲームアプリケーションクラス実装
 *
 *	@author	KORYUOH
 *
 *	@date	2012/04/23
 */
/**===File Include=========================================*/
#include	<GameApplication/Gameapplication.h>
#include	<Define/Define.h>
#include	<gslib.h>
#include	<sstream>
/**===Class Implementation=================================*/
/**========================================================*/
/**
 *	@brief	コールバック関数用の静的メンバ変数
 *	@note	<メモ書き>
 *	@author	KORYUOH
 */
/**========================================================*/
GameApplication* GameApplication::mInstance = 0;
/**========================================================*/
/**
 *	@brief	コンストラクタ
 *	@param[in]	引数の数
 *	@param[in]	コマンドライン引数
 *	@author	KORYUOH
 */
/**========================================================*/
GameApplication::GameApplication(int argc, char* argv[]):
	mWindowTitle(APPLICATION_TITLE),
	mParam(Rect(
		WINDOW_CREATE_POSITION_X,
		WINDOW_CREATE_POSITION_Y,
		WINDOW_SIZE_X,
		WINDOW_SIZE_Y
		),
		Perspective(
		50.0f,
		0.5f,
		100.0f))
	mIsFullScreenMode( SCREENMODE ),
{
	//自身のインスタンスを設定
	mInstance = this;
	//GLUT初期化
	glutInit(&argc,argv);
}
/**========================================================*/
/**
 *	@brief	実行
 *	@author	KORYUOH
 */
/**========================================================*/
void GameApplication::run(){
	//ウィンドウの設定
	glutInitDisplayMode( GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);
	glutInitWindowPosition(getWindowPositionX(),getWindowPositionY());
	glutInitWindowSize(getWindowWidth(),getWindowHeight());
	//フルスクリーンモードか？
	FullScreenCheck();
	gsSystemInitialize();
	//Vsync有効化
	setSwapInterval(1);
	//乱数初期化
	gsRandamize();
	
	//OpenGL初期化
	initializeGL();
	//アプリケーション初期化
	initialize();

	setCallBacks();

	//フレームタイマーリセット
	gsFrameTimerReset();
	//メインループ
	glutMainLoop();
}
/**========================================================*/
/**
 *	@brief	OpenGL初期化関数
 *	@author	KORYUOH
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
 *	@author	KORYUOH
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
 *	@author	KORYUOH
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
 *	@author	KORYUOH
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
			
			mInstance->finishCheck();

			std::exit(0);
		}
	}while(gsFrameTimerIsSkip() == GS_TRUE);
	//描画処理を呼び出す
	glutPostRedisplay();
}
/**========================================================*/
/**
 *	@brief	描画時コールバック関数
 *	@author	KORYUOH
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
 *	@author	KORYUOH
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
 *	@author	KORYUOH
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
 *	@author	KORYUOH
 *	@return	ウィンドウタイトル
 */
/**========================================================*/
const std::string& GameApplication::getWindowTitle()const{
	return mWindowTitle;
}
/**========================================================*/
/**
 *	@brief	ウィンドウのX座標取得
 *	@author	KORYUOH
 *	@return	x座標
 */
/**========================================================*/
int GameApplication::getWindowPositionX()const{
	return (int)mParam.mWindow.mPos.x_;
}
/**========================================================*/
/**
 *	@brief	ウィンドウのY座標取得
 *	@author	KORYUOH
 *	@return	Y座標
 */
/**========================================================*/
int GameApplication::getWindowPositionY()const{
	return (int)mParam.mWindow.mPos.y_;
}
/**========================================================*/
/**
 *	@brief	ウィンドウの幅取得
 *	@author	KORYUOH
 *	@return	幅
 */
/**========================================================*/
int GameApplication::getWindowWidth()const{
	return (int)mParam.mWindow.mSize.x_;
}
/**========================================================*/
/**
 *	@brief	ウィンドウの高さ取得
 *	@author	KORYUOH
 *	@return	高さ
 */
/**========================================================*/
int GameApplication::getWindowHeight()const{
	return (int)mParam.mWindow.mSize.y_;
}
/**========================================================*/
/**
 *	@brief	視野角取得
 *	@author	KORYUOH
 *	@return	視野角
 */
/**========================================================*/
float GameApplication::getPerspectiveFov()const{
	return mParam.mPerspective.fov_;
}
/**========================================================*/
/**
 *	@brief	近クリップ面取得
 *	@author	KORYUOH
 *	@return	近クリップ面
 */
/**========================================================*/
float GameApplication::getPerspectiveNear()const{
	return mParam.mPerspective.near_;
}
/**========================================================*/
/**
 *	@brief	遠クリップ面取得
 *	@author	KORYUOH
 *	@return	遠クリップ面
 */
/**========================================================*/
float GameApplication::getPerspectiveFar()const{
	return mParam.mPerspective.far_;
}
/**========================================================*/
/**
 *	@brief	ウィンドウタイトル設定
 *	@param[in]	タイトル
 *	@author	KORYUOH
 */
/**========================================================*/
void GameApplication::setWindowTitle(const std::string& title){
	mWindowTitle = title;
}
/**========================================================*/
/**
 *	@brief	X座標設定
 *	@param[in]	X座標
 *	@author	KORYUOH
 */
/**========================================================*/
void GameApplication::setWindowPositionX(int x){
	mParam.mWindow.mPos.x_ = (float)x;
}
/**========================================================*/
/**
 *	@brief	Y座標設定
 *	@param[in]	Y座標
 *	@author	KORYUOH
 */
/**========================================================*/
void GameApplication::setWindowPositionY(int y){
	mParam.mWindow.mPos.y_ = (float)y;
}
/**========================================================*/
/**
 *	@brief	幅設定
 *	@param[in]	幅
 *	@author	KORYUOH
 */
/**========================================================*/
void GameApplication::setWindowWidth(int width){
	mParam.mWindow.mSize.x_ = (float)width;
}
/**========================================================*/
/**
 *	@brief	高さ設定
 *	@param[in]	高さ
 *	@author	KORYUOH
 */
/**========================================================*/
void GameApplication::setWindowHeight(int height){
	mParam.mWindow.mSize.y_ = (float)height;
}
/**========================================================*/
/**
 *	@brief	視野角設定
 *	@param[in]	視野角
 *	@author	KORYUOH
 */
/**========================================================*/
void GameApplication::setPerspectiveFov(float fov){
	mParam.mPerspective.fov_ = fov;
}
/**========================================================*/
/**
 *	@brief	近クリップ面設定
 *	@param[in]	近クリップ面
 *	@author	KORYUOH
 */
/**========================================================*/
void GameApplication::setPerspectiveNear(float znear){
	mParam.mPerspective.near_ = znear;
}
/**========================================================*/
/**
 *	@brief	遠クリップ面設定
 *	@param[in]	遠クリップ面
 *	@author	KORYUOH
 */
/**========================================================*/
void GameApplication::setPerspectiveFar(float zfar){
	mParam.mPerspective.far_ = zfar;
}
/**========================================================*/
/**
 *	@brief	フルスクリーンモード設定設定
 *	@param[in]	モード
 *	@author	KORYUOH
 */
/**========================================================*/
void GameApplication::setFullScreenMode(bool mode){
	mIsFullScreenMode = mode;
}
/**========================================================*/
/**
 *	@brief	フルスクリーンモードか調べる
 *	@author	KORYUOH
 *	@return	FullScreenMode
 */
/**========================================================*/
bool GameApplication::isFullScreenMode()const{
	return mIsFullScreenMode;
}
/**========================================================*/
/**
 *	@brief	終了処理動作チェック
 *	@author	KORYUOH
 */
/**========================================================*/

void GameApplication::finishCheck(){
	if(mInstance->isFullScreenMode())
		glutLeaveGameMode();

	else
		//終了処理呼び出し
		mInstance->destroy();
}
/**========================================================*/
/**
 *	@brief	フルスクリーン起動チェック
 *	@author	KORYUOH
 */
/**========================================================*/
void GameApplication::FullScreenCheck(){
	if(!isFullScreenMode()){
		//ウィンドウモード
		glutCreateWindow(getWindowTitle().c_str());
		return;
	}
	std::ostringstream mode;
	//フルスクリーン設定文字列作成
	mode << getWindowWidth() << "x"<<getWindowHeight()<<"@60";
	//フルスクリーンモードに設定
	glutGameModeString(mode.str().c_str());
	glutEnterGameMode();
	//マウスカーソルは消す
	glutSetCursor(GLUT_CURSOR_NONE);
}
/**========================================================*/
/**
 *	@brief	gsシステム初期化
 */
/**========================================================*/
void GameApplication::gsSystemInitialize(){
	//グラフィックシステム初期化
	gsInitGraphics();
	//サウンドシステム初期化
	gsInitSound((HWND)_glutGetHWND());
	//入力デバイスシステム初期化
	gsInitInput((HWND)_glutGetHWND());
}
/**========================================================*/
/**
 *	@brief	コールバック関数の設定
 */
/**========================================================*/
void GameApplication::setCallBacks(){
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
}




/**===End Of File==========================================*/