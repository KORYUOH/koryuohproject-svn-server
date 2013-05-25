/******************************************************************************
* File Name : FlagManager.h                      Ver : 1.00  Date : 2013-05-09
*
* Description :
*
*		フラグ管理者クラス．
*
******************************************************************************/
#ifndef _FLAG_MANAGER_H_
#define _FLAG_MANAGER_H_

/*---- ヘッダファイルの読み込み ---------------------------------------------*/

#include<map>
#include"FlagID.h"
#include"IFlagManager.h"

typedef std::map<FlagID, bool>	FlagContainer;

/// <summary>
/// フラグ管理者.
/// </summary>
class FlagManager : public IFlagManager
{
public:
	/// <summary>
	/// コンストラクタ.
	/// </summary>
	FlagManager();
	/// <summary>
	/// 初期化.
	/// </summary>
	void Initialize();
	/// <summary>
	/// フラグの追加.
	/// </summary>
	/// <param name="id">フラグID</param>
	void Add( FlagID id );
	/// <summary>
	/// フラグを取得する.
	/// </summary>
	/// <param name="id">フラグID</param>
	/// <returns>フラグを返す.</returns>
	virtual bool IsFlag( FlagID id ) const;
	/// <summary>
	/// フラグを有効にする.
	/// </summary>
	/// <param name="id">フラグID</param>
	virtual void FlagEnable( FlagID id );
	/// <summary>
	/// フラグを無効にする.
	/// </summary>
	/// <param name="id">フラグID</param>
	virtual void FlagDisable( FlagID id );
	/// <summary>
	/// フラグを交換する.
	/// </summary>
	/// <param name="id">フラグID</param>
	virtual void ChangeFlag( FlagID id );
	/// <summary>
	/// 消去.
	/// </summary>
	void Clear();
private:
	/// <summary>
	/// フラグコンテナ.
	/// </summary>
	FlagContainer	mFlagContainer;

};


#endif // !_FLAG_MANAGER_H_

/********** End of File ******************************************************/