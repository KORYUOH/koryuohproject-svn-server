#include "Form1.h"
#include <iostream>
#include <string>

bool CClipboard::SetClipboardText(LPCTSTR lpszText)
	{
		CString strText(lpszText);

		// �����񂪋�̏ꍇ�̓R�s�[���Ȃ�
		if( strText.IsEmpty() )
			return FALSE;

		// �N���b�v�{�[�h�̃I�[�v��
		if( !::OpenClipboard(NULL) )
			return FALSE;

		// �q�[�v��Ƀ������̈���m�ۂ��A��������R�s�[
		int iStrLen = strText.GetLength() + 1;
		HGLOBAL hMem = ::GlobalAlloc(GMEM_FIXED, iStrLen);
		LPTSTR pMem = (LPTSTR)hMem;
		::lstrcpy(pMem, (LPCTSTR)strText);

		// �N���b�v�{�[�h�֕�������R�s�[���A�N���[�Y
		::EmptyClipboard();	// �N���b�v�{�[�h�̒��g����ɂ���
		::SetClipboardData(CF_TEXT, hMem);
		::CloseClipboard();

		return TRUE;
	}


void Getifndef(string str){
	string MEMCPY = "#ifndef "+str+"\n#define "+str+"\n\t\n#endif";
	CClipboard Clip;
	Clip
}