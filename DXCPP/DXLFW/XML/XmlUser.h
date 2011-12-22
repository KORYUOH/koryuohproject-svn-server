#ifndef _XMLUSER_H_INCLUDED_
#define _XMLUSER_H_INCLUDED_
#ifdef	__USE_XML_IO_
#define USE_XML_WRITER
#define	USE_XML_READER 
#endif
#ifdef USE_XML_WRITER
#include	"XmlWriter.h"
#endif
#ifdef USE_XML_READER
#include	"XmlReader.h"
#endif
#endif // _XMLUSER_H_INCLUDED_
