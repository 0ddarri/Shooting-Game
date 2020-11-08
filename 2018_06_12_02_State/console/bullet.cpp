#include "Include.h"

//stBullet g_Bullet[Max];

void BulletInit()
{
	for (int i = 0; i < Max; i++)
	{
		g_Bullet[i].x = -999;
		g_Bullet[i].y = -99;
		g_Bullet[i].live = false;
		g_Bullet[i].fColor = YELLOW; // 색깔 바꾸기
		g_Bullet[i].speed = 2;
		g_Bullet[i].body = '|';
		g_Bullet[i].bColor = BLACK;
	}
}

DWORD StartTime;
DWORD EndTime = GetTickCount();



void BulletUpdate()
{

 	if (IsKey(VK_A)) // 스페이스바를 눌렀을 때
	{
		StartTime = GetTickCount();
		for (int i = 0; i < Max; i++)
		{

			if (g_Bullet[i].live == false && StartTime - EndTime >= 100)
			{
				g_Bullet[i].x = g_Hero.x; // 플레이어 위치로 설정
				g_Bullet[i].y = g_Hero.y; // 플레이어 위치로 설정
				g_Bullet[i].live = true;
				EndTime = GetTickCount();
				break;
			}
		}
	}
	for (int i = 0; i < Max; i++)
	{
		if (g_Bullet[i].y <= 0)
		{
			g_Bullet[i].live = false;
		}

		g_Bullet[i].y -= g_Bullet[i].speed;
	}
	BulletCollision();
}


void BulletCollision()
{
	for (int i = 0; i < Max; i++)
	{
		for (int j = 0; j < Max; j++)
		{
			if (g_Bullet[j].x == g_Monster[i].x && g_Bullet[j].y <= g_Monster[i].y)
			{
				EffectInit(g_Monster[i].x, g_Monster[i].y);

				g_Bullet[j].live = false;
				g_Bullet[j].x = -9999;
				g_Bullet[j].y = -9999;
				g_Monster[i].live = false;
				g_Monster[i].x = -9999;
				g_Monster[i].y = -9999;
			}
		}
	}
}

void BulletDraw()
{
	for (int i = 0; i < Max; i++)
	{
		if (g_Bullet[i].live == true)
		{
			DrawCharEx3(g_Bullet[i].x, g_Bullet[i].y, g_Bullet[i].body, g_Bullet[i].fColor, g_Bullet[i].bColor);
		}
	}
}