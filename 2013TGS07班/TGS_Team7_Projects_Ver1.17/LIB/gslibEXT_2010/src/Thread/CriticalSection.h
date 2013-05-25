#ifndef _CRITICALSECTION_H_
#define _CRITICALSECTION_H_

/**
 * �N���e�B�J���Z�N�V�����N���X�D
 */
class CriticalSection
{
public:

    /**
     * �R���X�g���N�^�D
     */
    CriticalSection();

    /**
     * �f�X�g���N�^�D
     */
    ~CriticalSection();

    /**
     * �N���e�B�J���Z�N�V�����J�n�D
     */
    void enter();

    /**
     * �N���e�B�J���Z�N�V�����I���D
     */
    void leave();

    /** ���b�N�N���X */
    class Lock
    {
    public:

        /**
         * �R���X�g���N�^�D
         *
         * @param cs �N���e�B�J���Z�N�V�����D
         */
        Lock( CriticalSection& cs );

        /**
         * �f�X�g���N�^�D
         */
        ~Lock();
	private:

		// �R�s�[�֎~
		Lock( const Lock& other );
		Lock& operator = ( const Lock& other );

    private:
        /** �N���e�B�J���Z�N�V���� */
        CriticalSection& mCriticalSection;
    };

private:

	/** �N���e�B�J���Z�N�V�����I�u�W�F�N�g */
	class CriticalSectionBody;

    /** �N���e�B�J���Z�N�V���� */
    CriticalSectionBody* mCriticalSectionBody;
};

#endif
