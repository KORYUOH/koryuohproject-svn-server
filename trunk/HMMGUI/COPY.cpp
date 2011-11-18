#include "Form1.h"
#include <iostream>
#include <string>

bool CClipboard::SetClipboardText(LPCTSTR lpszText)
	{
		CString strText(lpszText);

		// 文字列が空の場合はコピーしない
		if( strText.IsEmpty() )
			return FALSE;

		// クリップボードのオープン
		if( !::OpenClipboard(NULL) )
			return FALSE;

		// ヒープ上にメモリ領域を確保し、文字列をコピー
		int iStrLen = strText.GetLength() + 1;
		HGLOBAL hMem = ::GlobalAlloc(GMEM_FIXED, iStrLen);
		LPTSTR pMem = (LPTSTR)hMem;
		::lstrcpy(pMem, (LPCTSTR)strText);

		// クリップボードへ文字列をコピーし、クローズ
		::EmptyClipboard();	// クリップボードの中身を空にする
		::SetClipboardData(CF_TEXT, hMem);
		::CloseClipboard();

		return TRUE;
	}


void Getifndef(string str){
	string MEMCPY = "#ifndef "+str+"\n#define "+str+"\n\t\n#endif";
	CClipboard Clip;
	Clip
}