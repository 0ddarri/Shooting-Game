#ifndef _INCLUDE_H_
#define _INCLUDE_H_

#include <crtdbg.h>
#include "../ConsoleEx3/ConWrap.h"
#include "mmsystem.h"
#include <stdlib.h>
#include <time.h>

#define Max 30

#include "hero.h" // �ڵ����� ���� ��������� hero.h�� ������ 
#include "bullet.h"
#include "monster.h"
#include "effect.h"

extern stBullet g_Bullet[Max]; // ���ٸ���

extern stHero g_Hero; // ��� ������ ��밡���ϰ� ���س���, hero.h ���� ������ �ν� �ȵ�

extern stMonster g_Monster[Max];

extern stEffect g_Effect[Max];

extern char c_Effect[3][3][3];

extern int isCol;

#endif