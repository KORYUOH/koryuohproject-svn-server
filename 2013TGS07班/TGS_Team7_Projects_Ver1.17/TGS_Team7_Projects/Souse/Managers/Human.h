/******************************************************************************
* File Name : Human.h                            Ver : 1.00  Date : 2013-05-09
*
* Description :
*
*		人材クラス．
*
******************************************************************************/
#ifndef _HUMAN_H_
#define _HUMAN_H_

/*---- ヘッダファイルの読み込み ---------------------------------------------*/

#include<map>

/*---- 先行宣言 -------------------------------------------------------------*/


/// <summary>
/// 人材管理者.
/// </summary>
class Human
{
public:
	/// <summary>
	/// コンストラクタ.
	/// </summary>
	Human();
	/// <summary>
	/// 初期化.
	/// </summary>
	void Initialize();
	/// <summary>
	/// 人材の最大値を設定する.
	/// </summary>
	/// <param name="humanMax">人材の最大値</param>
	void SetHumanMax( float humanMax );
	/// <summary>
	/// 人材の取得する.
	/// </summary>
	/// <returns>人材を返す.</returns>
	float GetHuman() const;
	/// <summary>
	/// 人材の最大値を取得する.
	/// </summary>
	/// <returns>人材を返す.</returns>
	float GetHumanMax() const;
	/// <summary>
	/// 人材がゼロ人判定.
	/// </summary>
	/// <returns>人材がいるか判定.</returns>
	bool IsHumanZero() const;
	/// <summary>
	/// 人材が定員か判定.
	/// </summary>
	/// <returns>定員の時真、そうでなければ偽を返す.</returns>
	bool IsHumanCapacity() const;
	/// <summary>
	/// 移動先に人事異動できるか判定する.
	/// </summary>
	/// <param name="target">移動先</param>
	/// <param name="human">増減量</param>
	/// <returns>移動できれば真、そうでなければ偽を返す.</returns>
	bool IsPersonnelChange( const Human& target, float human ) const;
	/// <summary>
	/// 人事異動できるか判定する.
	/// </summary>
	/// <param name="unit">ユニット</param>
	/// <param name="human">増減量</param>
	/// <returns>増減できる時真、そうでなければ偽を返す.</returns>
	bool IsPersonnelChange( float human ) const;
	/// <summary>
	/// 人材を増減させる.
	/// </summary>
	/// <param name="human">増減量</param>
	/// <returns>移動できれば真、できなければ偽を返す.</returns>
	void PersonnelChange( float human );
	/// <summary>
	/// 自身から対象に人材を移動させる.
	/// </summary>
	/// <param name="target">移動先ユニット</param>
	/// <param name="human">増減量</param>
	/// <returns>移動できれば真、できなければ偽を返す.</returns>
	void PersonnelChange( Human& target, float human );

private:
	/// <summary>
	/// 人材の最大量.
	/// </summary>
	float	mHumanMax;
	/// <summary>
	/// 人材の数.
	/// </summary>
	float	mHuman;

};


#endif // !_HUMAN_MANAGER_H_

/********** End of File ******************************************************/