#include "../include/DxLib.h"
#include "SET_MODE.h"
#include "define.h"

#ifdef GLOBAL_INSTANCE
#define GLOBAL
#else
#define GLOBAL extern 
#endif
#ifdef DEVELOP_MODE
#define DEVELOP TRUE
#else
#define DEVELOP FALSE
#endif
#ifdef FPS_DRAW
#define FPS_SHOW TRUE
#else
#define FPS_SHOW FALSE
#endif
#ifndef	SYSTEM_LOG_OUTPUT
#define	SYSTEM_LOG	TRUE
#else
#define	SYSTEM_LOG	FALSE
#endif
#include "Valiable.h"
#include "function.h"
#include "DevUsrCtrl.h"