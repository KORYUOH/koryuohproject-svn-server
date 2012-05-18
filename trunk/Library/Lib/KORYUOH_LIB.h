#pragma once
#ifndef	_KORYUOH_LIB_
#define	_KORYUOH_LIB_
#include	"Dice.h"
#include	"CSVLoader.h"
#ifdef _DEBUG
#pragma comment(lib,"Dice_d.lib")
#pragma comment(lib,"CSVLoader_d.lib")
#else
#pragma comment(lib,"Dice_r.lib")
#pragma comment(lib,"CSVLoader_r.lib")
#endif
#endif