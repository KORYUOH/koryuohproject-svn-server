/******************************************************************************
* File Name : GameApplication.h                  Ver : 1.00  Date : 2012-12-13
*
* Description :
*
*		ゲームアプリケーションヘッダファイル．
*
******************************************************************************/
#ifndef	_GAMEAPPLICATION_H_
#define	_GAMEAPPLICATION_H_


/*---- ヘッダファイルの読み込み ---------------------------------------------*/

#include<string>

/// <summary>
/// ゲームアプリケーションクラス.
/// </summary>
class GameApplication
{

public:
	/// <summary>
	/// アプリケーションの実行.
	/// </summary>
	void Run( void );

protected:
	/// <summary>
	/// コンストラクタ.
	/// </summary>
	/// <param name="argc">コマンドラインオプションの数のポインタ</param>
	/// <param name="argv">コマンドラインオプションを表す文字列の配列</param>
	GameApplication( int argc, char* argv[] );
	/// <summary>
	/// バーチャルデストラクタ.
	/// </summary>
	virtual ~GameApplication( void ) {}
	/// <summary>
	/// 初期化.
	/// </summary>
	virtual void Initialize( void ) {}
	/// <summary>
	// 更新.
	/// </summary>
	/// <param name="frameTimer">フレームタイマー</param>
	virtual void Update( float frameTimer ) { (void)frameTimer; }
	/// <summary>
	/// 描画.
	/// </summary>
	virtual void Draw( void ) {}
	/// <summary>
	// 終了.
	/// </summary>
	virtual void Finish( void ) {}

public:
	/// <summary>
	/// ウインドウタイトル取得.
	/// </summary>
	/// <returns>ウインドウ文字列</returns>
	const std::string& GetWindowTitle( void ) const;
	/// <summary>
	/// ウインドウX座標を取得.
	/// </summary>
	/// <returns>ウインドウのX座標</returns>
	int GetWindowPositionX( void ) const;
	/// <summary>
	/// ウインドウY座標を取得.
	/// </summary>
	/// <returns>ウインドウのX座標</returns>
	int GetWindowPositionY( void ) const;
	/// <summary>
	/// ウインドウ幅を取得.
	/// </summary>
	/// <returns>ウインドウのX座標</returns>
	int GetWindowWidth( void ) const;
	/// <summary>
	/// ウインドウ高さを取得.
	/// </summary>
	/// <returns>ウインドウのX座標</returns>
	int GetWindowHeight( void ) const;
	/// <summary>
	/// 視野角を取得.
	/// </summary>
	/// <returns>視野角値</returns>
	float GetPerspectiveFov( void ) const;
	/// <summary>
	/// 近クリップ面を取得.
	/// </summary>
	/// <returns>近クリップ値</returns>
	float GetPerspectiveNear( void ) const;
	/// <summary>
	/// 遠クリップ面を取得.
	/// </summary>
	/// <returns>遠クリップ値</returns>
	float GetPerspectiveFar( void ) const;
	/// <summary>
	/// ウインドウタイトル設定.
	/// </summary>
	/// <param name="title">ウインドウ文字列</param>
	void SetWindowTitle( const std::string& title );
	/// <summary>
	/// ウインドウX座標を設定.
	/// </summary>
	/// <param name="x">X座標</param>
	void SetWindowPositionX( int x );
	/// <summary>
	/// ウインドウY座標を設定.
	/// </summary>
	/// <param name="y">Y座標</param>
	void SetWindowPositionY( int y );
	/// <summary>
	/// ウインドウ横幅設定.
	/// </summary>
	/// <param name="width">横幅</param>
	void SetWindowWidth( int width );
	/// <summary>
	/// ウインドウ縦幅設定.
	/// </summary>
	/// <param name="height">縦幅</param>
	void SetWindowHeight( int height );
	/// <summary>
	/// 視野角設定.
	/// </summary>
	/// <param name="fov">視野角値</param>
	void SetPerspectiveFov( float fov );
	/// <summary>
	/// 近クリップ面を設定.
	/// </summary>
	/// <param name="znear">近クリップ値</param>
	void SetPerspectiveNear( float znear );
	/// <summary>
	/// 遠クリップ面を設定.
	/// </summary>
	/// <param name="zfar">遠クリップ値</param>
	void SetPerspectiveFar( float zfar );
	/// <summary>
	/// フルスクリーンモード設定.
	/// </summary>
	/// <param name="mode">モード</param>
	void SetFullScreenMode( bool mode );
	/// <summary>
	/// フルスクリーンモードか調べる.
	/// </summary>
	/// <returns>フルスクリーンの時真、そうでない時偽を返す.</returns>
	bool IsFullScreenMode( void );

private:
	/// <summary>
	/// OpenGLの初期化.
	/// </summary>
	void InitilaizeGL( void );
	/// <summary>
	/// ダブルバッファ切替時のインターバルタイマの設定.
	/// </summary>
	/// <param name="interval">インターバル</param>
	void SetSwapInterval( int interval );
	/// <summary>
	/// ウインドウがアクティブ時のコールバック関数.
	/// </summary>
	static void Activate( int state );
	/// <summary>
	/// ウインドウ描画時のコールバック関数.
	/// </summary>
	static void Display( void );
	/// <summary>
	//イベント無し時のコールバック関数.
	/// </summary>
	static void Idle( void );
	/// <summary>
	//ウインドウサイズコールバック関数.
	/// </summary>
	/// <param name="width">縦幅</param>
	/// <param name="height">横幅</param>
	static void Reshape( int width, int height );
	/// <summary>
	//アプリケーション終了時コールバック関数.
	/// </summary>
	static void Destroy( void );


#pragma region フィールド変数

private:
	/// <summary>
	/// ウインドウタイトル.
	/// </summary>
	std::string				mWindowTitle;
	/// <summary>
	///	ウインドウのX座標.
	/// </summary>
	int						mWindowPositionX;
	/// <summary>
	/// ウインドウのY座標.
	/// </summary>
	int						mWindowPositionY;
	/// <summary>
	///	ウインドウの横幅.
	/// </summary>
	int						mWindowWidth;
	/// <summary>
	/// ウインドウの縦幅.
	/// </summary>
	int						mWindowHeight;
	/// <summary>
	///	フルスクリーンモード.
	/// </summary>
	bool					mIsFullScreenMode;
	/// <summary>
	/// 視野角値.
	/// </summary>
	float					mPerspectiveFov;
	/// <summary>
	///	近クリップ値.
	/// </summary>
	float					mPerspectiveNear;
	/// <summary>
	///	遠クリップ値.
	/// </summary>
	float					mPerspectiveFar;
	/// <summary>
	///	コールバック関数のための静的メンバ変数.
	/// </summary>
	static GameApplication*	mInstance;

#pragma endregion // フィールド変数 end


}; // class GameApplication end


#endif // !_GAMEAPPLICATION_H_

/********** End of File ******************************************************/
