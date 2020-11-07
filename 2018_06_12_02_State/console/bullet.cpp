#include "Include.h"

//stBullet g_Bullet[Max];

void BulletInit()
{
	//
	for (int i = 0; i < Max; i++)
	{
		g_Bullet[i].live = false;
		g_Bullet[i].fColor = YELLOW; // 색깔 바꾸기
		g_Bullet[i].speed = 2;
		g_Bullet[i].body = '|';
		g_Bullet[i].bColor = BLACK;
	}
}

DWORD StartTime;
DWORD EndTime = GetTickCount();;

int timee = 0;;

int isFire = 0;

void BulletUpdate()
{

 	if (IsKey(VK_A)) // 스페이스바를 눌렀을 때
	{
		StartTime = GetTickCount();
		for (int i = 0; i < Max; i++)
		{

			if (g_Bullet[i].live == false && StartTime - EndTime >= 1000)
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