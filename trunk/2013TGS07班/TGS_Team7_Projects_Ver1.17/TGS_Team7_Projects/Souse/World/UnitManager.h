/******************************************************************************
* File Name : UnitManager.h                       Ver : 1.00  Date : 2013-04-25
*
* Description :
*
*		ユニットマネージャークラス．
*
* Author : Shouta Takemura.
*
******************************************************************************/
#ifndef _UNIT_MANAGER_H_
#define _UNIT_MANAGER_H_

/*---- ヘッダファイルの読み込み ---------------------------------------------*/

#include	"../Unit/UnitPtr.h"
#include	"../Collider/ColliderPairManager.h"
#include	<list>
#include	<functional>


/// <summary>
/// アクターマネージャー.
/// </summary>
class UnitManager
{

public:
	/*ファンクション定義*/
	typedef std::function<void (UnitPtr)> ActorFunction;

public:
	/// <summary>
	/// コンストラクタ.
	/// </summary>
	/// <param name="collder">衝突管理者/param>
	UnitManager( ColliderPairManager& collder );
	/// <summary>
	/// デストラクタ.
	/// </summary>
	~UnitManager();

public:
	/// <summary>
	/// 更新.
	/// </summary>
	/// <param name="frameTimer">フレームタイマー</param>
	void Update( float frameTimer );
	/// <summary>
	/// 生産処理.
	/// </summary>
	/// <param name="frameTimer">フレームタイマー</param>
	void Production( float frameTimer );
	/// <summary>
	/// 維持コスト支払い処理.
	/// </summary>
	/// <param name="frameTimer">フレームタイマー</param>
	void Maintenance( float frameTimer );
	/// <summary>
	/// 描画.
	/// </summary>
	void Draw();	
	/// <summary>
	/// UIの描画.
	/// </summary>
	void DrawUI();
	/// <summary>
	/// アクターの追加.
	/// </summary>
	/// <param name="actor">追加するアクター</param>
	void Add( UnitPtr unit );
	/// <summary>
	/// 消去.
	/// </summary>
	void Clear();
	/// <summary>
	/// 死亡しているアクターの削除.
	/// </summary>
	void Remove();
	/// <summary>
	/// アクター間の衝突判定.
	/// </summary>
	/// <param name="other">相手アクター</param>
	void Collide( Unit& other );
	/// <summary>
	/// 他のマネージャーを衝突判定.
	/// </summary>
	/// <param name="other">相手マネージャー</param>
	void Collide( UnitManager& other );
	/*foreachを省略する関数*/
	void each(ActorFunction f);

#pragma region "アクセスの禁止"

private:
	/*コピー禁止処理*/
	UnitManager( const UnitManager& other );
	/*代入演算子オーバロードの禁止*/
	UnitManager& operator = ( const UnitManager& other );

#pragma endregion

private:
	/*型の置き換えアクターコンテナ(アクターシェアドポインタリスト)*/
	typedef std::list<UnitPtr> UnitContainer;
	/// <summary>
	/// 衝突管理者.
	/// </summary>
	ColliderPairManager&	mColliderManager;
	/// <summary>
	/// ユニットリスト.
	/// </summary>
	UnitContainer			mUnits;
};

#endif

/********** End of File ******************************************************/
