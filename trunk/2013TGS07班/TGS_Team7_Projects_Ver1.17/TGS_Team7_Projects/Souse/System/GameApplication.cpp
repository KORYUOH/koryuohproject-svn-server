/******************************************************************************
* File Name : GameApplication.cpp                Ver : 1.00  Date : 2012-12-13
*
* Description :
*
*		ゲームアプリケーション処理．
*
******************************************************************************/
#include"GameApplication.h"
#include<gslib.h>
#include<sstream>

// コールバック関数のための静的メンバ変数.
GameApplication* GameApplication::mInstance = 0;


/// <summary>
/// コンストラクタ.
/// </summary>
/// <param name="argc">コマンドラインオプションの数のポインタ</param>
/// <param name="argv">コマンドラインオプションを表す文字列の配列</param>
GameApplication::GameApplication(int argc,char* argv[] ):
	mWindowTitle("GameWindow"),
	mWindowPositionX(0),
	mWindowPositionY(0),
	mWindowWidth(1024),
	mWindowHeight(768),
	mIsFullScreenMode(false),
	mPerspectiveFov(50.0f),
	mPerspectiveNear(0.0f),
	mPerspectiveFar(100.0f)
{
	// 自分自身のインスタンスを設定.
	mInstance = this;

	// GLUTの初期化.
	glutInit( &argc,argv);

}

/// <summary>
/// アプリケーションの実行.
/// </summary>
void GameApplication::Run()
{
	// ウインドウの設定を行う.
	glutInitDisplayMode( GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH );
	glutInitWindowPosition(GetWindowPositionX(),GetWindowPositionY() );
	glutInitWindowSize( GetWindowWidth(),GetWindowHeight() );

	// フルスクリーンモードか？.
	if(IsFullScreenMode() == true)
	{
		std::ostringstream mode;

		// フルスクリーンモード設定文字列を作成.
		mode << GetWindowWidth() << "X" << GetWindowHeight() << "@60";

		// フルスクリーンモードに設定.
		glutGameModeString( mode.str().c_str() );
		glutEnterGameMode();

		// フルスクリーンの場合はマウスカーソルを消す.
		glutSetCursor( GLUT_CURSOR_NONE );

	}
	else
	{
		// ウインドウモード.
		glutCreateWindow( GetWindowTitle().c_str() );
	}
	// グラフィックシステムの初期化.
	gsInitGraphics();

	// サウンドシステムの初期化.
	gsInitSound( (HWND)_glutGetHWND() );

	// 入力デバイスシステムの初期化.
	gsInitInput( (HWND)_glutGetHWND() );

	// Vsyncを有効にする.
	SetSwapInterval( 1 );

	// 乱数の初期化.
	gsRandamize();

	// OpenGLの初期化.
	InitilaizeGL();

	// アプリケーションの初期化処理.
	Initialize();

	// 終了処理の関数を設定する.
	_glutDestroyFunc( Destroy );

	// ウィンドウサイズ変更時の関数を設定.
	glutReshapeFunc( Reshape );

	// 表示処理の関数を設定.
	glutDisplayFunc( Display );

	// イベントのない時の関数を設定.
	glutIdleFunc( Idle );

	// ウィンドウがアクティブになった時の関数を設定.
	_glutActivateFunc( Activate );

	// フレームタイマのリセット.
	gsFrameTimerReset();

	// メインループ処理を行う.
	glutMainLoop();

}

/// <summary>
/// OpenGLの初期化.
/// </summary>
void GameApplication::InitilaizeGL( void )
{
	// デフォルトのライトパラメータ.
	const static float LightAmbient[] = { 0.2f, 0.2f, 0.2f, 1.0f };
	const static float LightDiffuse[] = { 1.0f, 1.0f, 1.0f, 1.0f };
	const static float LightSpeclar[] = { 1.0f, 1.0f, 1.0f, 1.0f };
	const static float LightPosition[] = { 1.0f, 1.0f, 1.0f, 0.0f };

	// 画面クリア時のカラーの設定.
	glClearColor( 0.0f, 0.0f, 0.0f, 1.0f );

	// 面カリングの処理を有効にする.
	glEnable( GL_CULL_FACE );
	glCullFace( GL_BACK );

	// デプスバッファを1.0でクリアする.
	glClearDepth( 1.0 );

	// テプステストを有効にする.
	glEnable( GL_DEPTH_TEST );

	// パースペクティブ補正を行う.
	glHint( GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST );

	// ブレンドを有効.
	glEnable( GL_BLEND );

	// デフォルトのブレンド式を設定.
	glBlendFunc( GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA );

	// デフォルトの視点変換の変換行列を設定する.
	glMatrixMode( GL_MODELVIEW );
	glLoadIdentity();
	gluLookAt(
		0.0f, 0.0f, 10.0f,
		0.0f, 0.0f, 0.0f,
		0.0f, 1.0f, 0.0f
		);

	// デフォルトのライトの設定.
	glLightfv( GL_LIGHT0, GL_AMBIENT, LightAmbient );
	glLightfv( GL_LIGHT0, GL_DIFFUSE, LightDiffuse );
	glLightfv( GL_LIGHT0, GL_SPECULAR, LightSpeclar );
	glLightfv( GL_LIGHT0, GL_POSITION, LightPosition );
	glEnable( GL_LIGHT0 );

	// ライティングを有効にする.
	glEnable( GL_LIGHTING );

}

/// <summary>
//アプリケーション終了時コールバック関数.
/// </summary>
void GameApplication::Destroy( void )
{

	// ゲーム終了処理.
	mInstance->Finish();

	// 入力デバイスシステムの終了処理.
	gsFinishInput();

	// サウンドシステムの終了処理.
	gsFinishSound();

	// グラフィックスシステムの終了処理.
	gsFinishGraphics();

}

/// <summary>
//ウインドウサイズコールバック関数.
/// </summary>
/// <param name="width">縦幅</param>
/// <param name="height">横幅</param>
void GameApplication::Reshape( int width, int height )
{
	// 高さが０にならないように調整.
	height = ( height == 0 ) ? 1: height;

	// ビューポートの設定.
	glViewport( 0, 0, width, height );

	// 透視射影の変換行列を設定する.
	glMatrixMode( GL_PROJECTION );
	glLoadIdentity();
	gluPerspective(
		mInstance->GetPerspectiveFov(),
		(float)width / (float)height,
		mInstance->GetPerspectiveNear(),
		mInstance->GetPerspectiveFar()
		);

	// モデルビューモードにする.
	glMatrixMode( GL_MODELVIEW );

	// ウィンドウの幅と高さを更新する.
	mInstance->SetWindowWidth( width );
	mInstance->SetWindowHeight( height );

}

/// <summary>
//イベント無し時のコールバック関数.
/// </summary>
void GameApplication::Idle( void )
{
	// フレームタイマの更新.
	gsFrameTimerUpdate();
	do {
		// 入力デバイスの読み込み.
		gsReadInput();

		// ゲーム更新処理.
		mInstance->Update( gsFrameTimerGetTime() );

		// エスケープキーが押されたか？.
		if ( GetAsyncKeyState( VK_ESCAPE ) != 0 ) 
		{
			if ( mInstance->IsFullScreenMode() == true )
			{

				// ゲームモードを終了する.
				glutLeaveGameMode();
			}
			else 
			{

				// 終了処理を呼び出す.
				mInstance->Destroy();
			}

			// 強制終了する.
			std::exit( 0 );
		}
	} while ( gsFrameTimerIsSkip() == GS_TRUE );

	// 描画処理を呼び出す.
	glutPostRedisplay();
}

/// <summary>
/// ウインドウ描画時のコールバック関数.
/// </summary>
void GameApplication::Display( void )
{

	// 画面クリア.
	glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );

	// ゲーム描画処理.
	mInstance->Draw();

	// ダブルバッファの切り替え.
	glutSwapBuffers();

	// タイマウェイトを行う.
	gsFrameTimerWait();

}

/// <summary>
/// ウインドウがアクティブ時のコールバック関数.
/// </summary>
void GameApplication::Activate( int state )
{

	// 入力デバイスシステムにアクティブ状態を伝える.
	gsActivateInput(state);

	// サウンドシステムにアクティブ状態を伝える.
	gsActivateSound(state);

}

/// <summary>
/// ダブルバッファ切替時のインターバルタイマの設定.
/// </summary>
/// <param name="interval">インターバル</param>
void GameApplication::SetSwapInterval( int interval )
{
	// wglSwapIntervalEXT拡張関数のポインタ関数型.
	typedef BOOL (WINAPI * LPFNWGLSWAPINTERVALEXTPROC)( int interval );
	LPFNWGLSWAPINTERVALEXTPROC wglSwapIntervalEXT = NULL;

	// SwapIntervalEXTの関数ポインタを取得.
	wglSwapIntervalEXT = (LPFNWGLSWAPINTERVALEXTPROC)
		wglGetProcAddress( "wglSwapIntervalEXT" );

	// SwapIntervalEXT関数が取得できたか？.
	if ( wglSwapIntervalEXT != NULL )
	{

		// スワップのインターバルを設定.
		wglSwapIntervalEXT( interval );

	}
}

/// <summary>
/// ウインドウタイトル取得.
/// </summary>
/// <returns>ウインドウ文字列</returns>
const std::string& GameApplication::GetWindowTitle() const
{
	return mWindowTitle;
}

/// <summary>
/// ウインドウX座標を取得.
/// </summary>
/// <returns>ウインドウのX座標</returns>
int GameApplication::GetWindowPositionX() const
{
	return mWindowPositionX;
}

/// <summary>
/// ウインドウY座標を取得.
/// </summary>
/// <returns>ウインドウのX座標</returns>
int GameApplication::GetWindowPositionY() const
{
	return mWindowPositionY;
}

/// <summary>
/// ウインドウ幅を取得.
/// </summary>
/// <returns>ウインドウのX座標</returns>
int GameApplication::GetWindowWidth() const
{
	return mWindowWidth;
}

/// <summary>
/// ウインドウ高さを取得.
/// </summary>
/// <returns>ウインドウのX座標</returns>
int GameApplication::GetWindowHeight() const
{
	return mWindowHeight;
}

/// <summary>
/// 視野角を取得.
/// </summary>
/// <returns>視野角値</returns>
float GameApplication::GetPerspectiveFov() const
{
	return mPerspectiveFov;
}

/// <summary>
/// 近クリップ面を取得.
/// </summary>
/// <returns>近クリップ値</returns>
float GameApplication::GetPerspectiveNear() const
{
	return mPerspectiveNear;
}

/// <summary>
/// 遠クリップ面を取得.
/// </summary>
/// <returns>遠クリップ値</returns>
float GameApplication::GetPerspectiveFar() const
{
	return mPerspectiveFar;
}

/// <summary>
/// ウインドウタイトル設定.
/// </summary>
/// <param name="title">ウインドウ文字列</param>
void GameApplication::SetWindowTitle( const std::string& title )
{
	mWindowTitle = title;
}

/// <summary>
/// ウインドウX座標を設定.
/// </summary>
/// <param name="x">X座標</param>
void GameApplication::SetWindowPositionX( int x )
{
	mWindowPositionX = x;
}

/// <summary>
/// ウインドウY座標を設定.
/// </summary>
/// <param name="y">Y座標</param>
void GameApplication::SetWindowPositionY( int y )
{
	mWindowPositionY = y;
}

/// <summary>
/// ウインドウ横幅設定.
/// </summary>
/// <param name="width">横幅</param>
void GameApplication::SetWindowWidth( int width )
{
	mWindowWidth = width;

}

/// <summary>
/// ウインドウ縦幅設定.
/// </summary>
/// <param name="height">縦幅</param>
void GameApplication::SetWindowHeight( int height )
{
	mWindowHeight = height;
}

/// <summary>
/// 視野角設定.
/// </summary>
/// <param name="fov">視野角値</param>
void GameApplication::SetPerspectiveFov( float fov )
{
	mPerspectiveFov = fov;
}

/// <summary>
/// 近クリップ面を設定.
/// </summary>
/// <param name="znear">近クリップ値</param>
void GameApplication::SetPerspectiveNear( float znear )
{
	mPerspectiveNear = znear;
}

/// <summary>
/// 遠クリップ面を設定.
/// </summary>
/// <param name="zfar">遠クリップ値</param>
void GameApplication::SetPerspectiveFar( float zfar )
{
	mPerspectiveFar = zfar;
}

/// <summary>
/// フルスクリーンモード設定.
/// </summary>
/// <param name="mode">モード</param>
void GameApplication::SetFullScreenMode( bool mode )
{
	mIsFullScreenMode = mode;
}

/// <summary>
/// フルスクリーンモードか調べる.
/// </summary>
/// <returns>フルスクリーンの時真、そうでない時偽を返す.</returns>
bool GameApplication::IsFullScreenMode( void )
{
	return mIsFullScreenMode;
}

/********** End of File ******************************************************/
