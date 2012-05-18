#pragma once
#ifndef	_DICE_LIB_
#define	_DICE_LIB_
#include	"Dice.h"
#ifdef _DEBUG
#pragma comment(lib,"Dice_d.lib")
#else
#pragma comment(lib,"Dice_r.lib")
#endif
#endif