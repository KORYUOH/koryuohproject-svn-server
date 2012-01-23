/**=================================================*/
/**
 *	@FileName	Mode_Define.h
 *	@brief	モード設定用
 *	@author	KORYUOH
 *	@date	2011/01/23
 */
/**=================================================*/

#ifndef	__MODE_DEFINE_H_
#define	__MODE_DEFINE_H_
/**=============================================*/
/**
 *	XMLの読み込みと書き込みの設定を行う
 *	__USE_XML_IO_:コメント解除で書き込み読み込み両方使用。以下のものは無視される
 *	USE_XML_WRITER:コメント解除で書き込みを使用する。
 *	USE_XML_READER:コメント解除で読み込みを使用する。
 */
/**=============================================*/
//#define	__USE_XML_IO_
#ifndef	__USE_XML_IO_
//#define	USE_XML_WRITER
//#define	USE_XML_READER 
#endif//	__USE_XML_IO_

#endif//	__MODE_DEFINE_H_