#ifndef _CRITICALSECTION_H_
#define _CRITICALSECTION_H_

/**
 * クリティカルセクションクラス．
 */
class CriticalSection
{
public:

    /**
     * コンストラクタ．
     */
    CriticalSection();

    /**
     * デストラクタ．
     */
    ~CriticalSection();

    /**
     * クリティカルセクション開始．
     */
    void enter();

    /**
     * クリティカルセクション終了．
     */
    void leave();

    /** ロッククラス */
    class Lock
    {
    public:

        /**
         * コンストラクタ．
         *
         * @param cs クリティカルセクション．
         */
        Lock( CriticalSection& cs );

        /**
         * デストラクタ．
         */
        ~Lock();
	private:

		// コピー禁止
		Lock( const Lock& other );
		Lock& operator = ( const Lock& other );

    private:
        /** クリティカルセクション */
        CriticalSection& mCriticalSection;
    };

private:

	/** クリティカルセクションオブジェクト */
	class CriticalSectionBody;

    /** クリティカルセクション */
    CriticalSectionBody* mCriticalSectionBody;
};

#endif
