#ifndef _INCLUDE_H_
#define _INCLUDE_H_

#include <crtdbg.h>
#include "../ConsoleEx3/ConWrap.h"
#include "mmsystem.h"

#define Max 20

#include "hero.h" // �ڵ����� ���� ��������� hero.h�� ������ 
#include "bullet.h"

extern stBullet g_Bullet[Max]; // ���ٸ���

extern stHero g_Hero; // ��� ������ ��밡���ϰ� ���س���, hero.h ���� ������ �ν� �ȵ�

#endif