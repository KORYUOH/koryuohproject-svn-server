/******************************************************************************
* File Name : WorldUnit.h                        Ver : 1.00  Date : 2012-12-14
*
* Description :
*
*		ワールドアクタークラス．
*
******************************************************************************/
#ifndef _WORLD_UNIT_H_
#define _WORLD_UNIT_H_

/*---- ヘッダファイルの読み込み ---------------------------------------------*/

#include	"../Unit/UnitPtr.h"
#include	"../Collider/ColliderPairManager.h"
#include	<map>
#include	<memory>
#include	<functional>

/*---- 先行宣言 -------------------------------------------------------------*/

/// <summary>ユニットマネージャー</summary>
class UnitManager;
class IRenderer;
/// <summary>アクターID</summary>
enum UnitID;




/// <summary>
/// ワールドアクタークラス.
/// </summary>
class WorldUnit
{
public:
	/// <summary>
	/// コンストラクタ.
	/// </summary>
	WorldUnit();
	/// <summary>
	/// デストラクタ.
	/// </summary>
	~WorldUnit();

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
	/// <param name="id">アクターマネージャID</param>
	/// <param name="actor">追加するアクター</param>
	void Add( UnitID id, UnitPtr unit );
	/// <summary>
	/// 消去.
	/// </summary>
	void Clear();

private:
	/// <summary>
	/// マネージャーの追加.
	/// </summary>
	/// <param name="id">追加するアクターマネージャID</param>
	void AddManager( UnitID id );

#pragma region "アクセスの禁止"

private:
	/// <summary>
	/// コピーコンストラクタ(外部からは禁止).
	/// </summary>
	WorldUnit( const WorldUnit& other );
	/// <summary>
	/// 代入演算子オーバロード禁止.
	/// </summary>
	WorldUnit& operator = ( const WorldUnit& other );

#pragma endregion


private:
	/*アクターマネージャシェアドポインタ*/
	typedef std::shared_ptr<UnitManager> UnitManagerPtr;
	/*アクターマネージャコンテナ*/
	typedef std::map<UnitID,UnitManagerPtr> UnitManagerContainer;

	/*アクターマネージャー*/
	typedef std::pair<UnitID,UnitManagerPtr> UnitManagerPair;
	/*Function宣言*/
	typedef std::function<void (UnitManagerPtr)> UnitManagerFunction;

	/// <summary>
	/// foreachの省略宣言.
	/// </summary>
	void each(UnitManagerFunction f);

	/// <summary>
	/// マネージャー管理者.
	/// </summary>
	UnitManagerContainer mManagers;
	/// <summary>
	/// 衝突管理者.
	/// </summary>
	ColliderPairManager	mColliderManager;

};

#endif

/********** End of File ******************************************************/
