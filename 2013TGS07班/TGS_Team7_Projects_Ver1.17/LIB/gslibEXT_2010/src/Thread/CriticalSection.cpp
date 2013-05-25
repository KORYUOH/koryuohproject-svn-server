#include "CriticalSection.h"
#include <windows.h>

/** クリティカルセクションオブジェクト構造体 */
class CriticalSection::CriticalSectionBody
{
public:
	/** クリティカルセクションオブジェクト*/
	CRITICAL_SECTION mCriticalSection;
};

/**
 * コンストラクタ．
 */
CriticalSection::CriticalSection() :
	mCriticalSectionBody( new CriticalSectionBody )
{
	::InitializeCriticalSection( &mCriticalSectionBody->mCriticalSection );
}

/**
 * デストラクタ．
 */
CriticalSection::~CriticalSection()
{
	::DeleteCriticalSection( &mCriticalSectionBody->mCriticalSection );
	
	delete mCriticalSectionBody;
}

/**
 * クリティカルセクション開始．
 */
void CriticalSection::enter()
{
	::EnterCriticalSection( &mCriticalSectionBody->mCriticalSection );
}

/**
 * クリティカルセクション終了．
 */
void CriticalSection::leave()
{
	::LeaveCriticalSection( &mCriticalSectionBody->mCriticalSection );
}

/**
 * コンストラクタ．
 *
 * @param cs クリティカルセクション
 */
CriticalSection::Lock::Lock( CriticalSection& cs ) :
	mCriticalSection( cs )
{
	mCriticalSection.enter();
}

/**
 * デストラクタ．
 */
CriticalSection::Lock::~Lock()
{
	mCriticalSection.leave();
}
