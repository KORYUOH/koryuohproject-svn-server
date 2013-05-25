#include "CriticalSection.h"
#include <windows.h>

/** �N���e�B�J���Z�N�V�����I�u�W�F�N�g�\���� */
class CriticalSection::CriticalSectionBody
{
public:
	/** �N���e�B�J���Z�N�V�����I�u�W�F�N�g*/
	CRITICAL_SECTION mCriticalSection;
};

/**
 * �R���X�g���N�^�D
 */
CriticalSection::CriticalSection() :
	mCriticalSectionBody( new CriticalSectionBody )
{
	::InitializeCriticalSection( &mCriticalSectionBody->mCriticalSection );
}

/**
 * �f�X�g���N�^�D
 */
CriticalSection::~CriticalSection()
{
	::DeleteCriticalSection( &mCriticalSectionBody->mCriticalSection );
	
	delete mCriticalSectionBody;
}

/**
 * �N���e�B�J���Z�N�V�����J�n�D
 */
void CriticalSection::enter()
{
	::EnterCriticalSection( &mCriticalSectionBody->mCriticalSection );
}

/**
 * �N���e�B�J���Z�N�V�����I���D
 */
void CriticalSection::leave()
{
	::LeaveCriticalSection( &mCriticalSectionBody->mCriticalSection );
}

/**
 * �R���X�g���N�^�D
 *
 * @param cs �N���e�B�J���Z�N�V����
 */
CriticalSection::Lock::Lock( CriticalSection& cs ) :
	mCriticalSection( cs )
{
	mCriticalSection.enter();
}

/**
 * �f�X�g���N�^�D
 */
CriticalSection::Lock::~Lock()
{
	mCriticalSection.leave();
}
