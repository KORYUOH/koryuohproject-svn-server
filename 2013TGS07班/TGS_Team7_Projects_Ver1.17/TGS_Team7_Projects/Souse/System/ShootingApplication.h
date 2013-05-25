/******************************************************************************
* File Name : ShootingApplication.h              Ver : 1.00  Date : 2012-12-14
*
* Description :
*
*		ゲームアプリケーションクラス
*
******************************************************************************/
#ifndef _OIKAKEAPPLICATION_H_
#define _OIKAKEAPPLICATION_H_

/*---- ヘッダファイルの読み込み ---------------------------------------------*/

#include	"GameApplication.h"
#include	"../Scene\SceneManager.h"

/*---- 先行宣言 -------------------------------------------------------------*/


/*---- クラスの宣言 ---------------------------------------------------------*/

/// <summary>
/// シューティングアプリケーション.
/// </summary>
class ShootingApplication : public GameApplication
{

	//メンバ関数
public:
	/// <summary>
	/// コンストラクタ.
	/// </summary>
	/// <param name="argc">コマンドラインオプションの数のポインタ</param>
	/// <param name="argv">コマンドラインオプションを表す文字列の配列</param>
	ShootingApplication(int argc,char *argv[]); 

public:
	/// <summary>
	/// 初期化.
	/// </summary>
	virtual void Initialize( void );
	/// <summary>
	// 更新.
	/// </summary>
	/// <param name="frameTimer">フレームタイマー</param>
	virtual void Update( float frameTimer );
	/// <summary>
	/// 描画.
	/// </summary>
	virtual void Draw( void );
	/// <summary>
	// 終了.
	/// </summary>
	virtual void Finish( void );

	//メンバ変数
private:
	/// <summary>
	/// シーン管理者.
	/// </summary>
	SceneManager mSceneManager;

};

#endif



/********** End of File ******************************************************/