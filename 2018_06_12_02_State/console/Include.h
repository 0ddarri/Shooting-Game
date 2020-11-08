#ifndef _INCLUDE_H_
#define _INCLUDE_H_

#include <crtdbg.h>
#include "../ConsoleEx3/ConWrap.h"
#include "mmsystem.h"
#include <stdlib.h>
#include <time.h>

#define Max 30

#include "hero.h" // 자동으로 위의 헤더파일이 hero.h에 속해짐 
#include "bullet.h"
#include "monster.h"
#include "effect.h"
#include "Manager.h"

extern GameMng g_mng;

#endif