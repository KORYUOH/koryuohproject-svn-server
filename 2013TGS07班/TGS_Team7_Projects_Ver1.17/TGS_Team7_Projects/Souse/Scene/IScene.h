/******************************************************************************
* File Name : IScene.h                           Ver : 1.00  Date : 2012-12-14
*
* Description :
*
*		シーンインターフェイスクラス．
*
******************************************************************************/
#ifndef		_ISCENE_H_
#define		_ISCENE_H_


/*---- 先行宣言 -------------------------------------------------------------*/

enum Scene;
class World;


/// <summary>
/// シーンインターフェイス.
/// </summary>
class IScene
{
public:
	/// <summary>
	/// デストラクタ.
	/// </summary>
	virtual ~IScene() {}
	/// <summary>
	/// 初期化.
	/// </summary>
	virtual void Initialize() = 0;
	/// <summary>
	/// 更新.
	/// </summary>
	/// <param name="frameTimer">フレームタイマー</param>
	virtual void Update(float frameTimer) = 0;
	/// <summary>
	/// 描画.
	/// </summary>
	virtual void Draw() = 0;
	/// <summary>
	/// シーンの終了判定.
	/// </summary>
	virtual bool IsEnd() const = 0;
	/// <summary>
	/// 次のシーンに移行.
	/// </summary>
	virtual Scene Next() const = 0;
	/// <summary>
	/// 終了.
	/// </summary>
	virtual void Shutdown() = 0;

		/// <summary>
	/// シーンの終了フラグ.
	/// </summary>
	bool	mIsEnd;


}; // IScene end


#endif // _ISCENE_H_ end

/********** End of File ******************************************************/
