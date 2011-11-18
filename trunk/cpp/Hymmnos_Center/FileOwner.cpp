#include "FileOwner.h"

using namespace CSV;

FileOwner::FileOwner(){
};

FileOwner::FileOwner(string ReadFileName,string WriteFileName):
m_Reader(ReadFileName),
m_Writer(WriteFileName)
{}

FileOwner::~FileOwner(){
}