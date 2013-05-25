/******************************************************************************
* File Name : IFlagManager.h                      Ver : 1.00  Date : 2013-05-09
*
* Description :
*
*		抽象フラグ管理者クラス．
*
******************************************************************************/
#ifndef _I_FLAG_MANAGER_H_
#define _I_FLAG_MANAGER_H_

/*---- ヘッダファイルの読み込み ---------------------------------------------*/

#include"FlagID.h"


/// <summary>
/// 抽象フラグ管理者.
/// </summary>
class IFlagManager
{
public:
	/// <summary>
	/// 仮想デストラクタ.
	/// </summary>
	~IFlagManager() {}
	/// <summary>
	/// フラグを取得する.
	/// </summary>
	/// <param name="id">フラグID</param>
	/// <returns>フラグを返す.</returns>
	virtual bool IsFlag( FlagID id ) const = 0;
	/// <summary>
	/// フラグを有効にする.
	/// </summary>
	/// <param name="id">フラグID</param>
	virtual void FlagEnable( FlagID id ) = 0;
	/// <summary>
	/// フラグを無効にする.
	/// </summary>
	/// <param name="id">フラグID</param>
	virtual void FlagDisable( FlagID id ) = 0;
	/// <summary>
	/// フラグを交換する.
	/// </summary>
	/// <param name="id">フラグID</param>
	virtual void ChangeFlag( FlagID id ) = 0;

};

#endif // !_I_FLAG_MANAGER_H_

/********** End of File ******************************************************/