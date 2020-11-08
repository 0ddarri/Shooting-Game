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

extern stBullet g_Bullet[Max]; // 접근만됨

extern stHero g_Hero; // 모든 곳에서 사용가능하게 해준나더, hero.h 위에 있으면 인식 안됨

extern stMonster g_Monster[Max];

extern stEffect g_Effect[Max];

extern char c_Effect[3][3][3];

extern int isCol;

#endif