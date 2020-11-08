#include "Include.h"

void MonsterRe()
{
	for (int i = 0; i < Max; i++)
	{
		g_Monster[i].x = -1;
		g_Monster[i].y = -1;
		g_Monster[i].hp = 1;
		g_Monster[i].speed = 1;
		g_Monster[i].body = 'W';
		g_Monster[i].live = false;
		g_Monster[i].fColor = RED;
		g_Monster[i].bColor = BLACK;
	}
}

void MonsterInit()
{
	for (int i = 0; i < Max; i++)
	{
		g_Monster[i].x = -1;
		g_Monster[i].y = -1;
		g_Monster[i].hp = 1;
		g_Monster[i].speed = 1;
		g_Monster[i].body = 'W';
		g_Monster[i].live = true;
		g_Monster[i].fColor = RED;
		g_Monster[i].bColor = BLACK;
	}
}

DWORD Timer = GetTickCount();

void MonsterUpdate()
{
	//int random = rand() % 120;
	//for (int i = 0; i < Max; i++)
	//{
	//	if (g_Monster[i].live == true)
	//	{
	//		g_Monster[i].x = rand() % 130;
	//		g_Monster[i].live = false;
	//		break;
	//	}
	//}
	//
	//for (int i = 0; i < Max; i++)
	//{
	//	if (g_Bullet[i].y >= 30)
	//	{
	//		g_Bullet[i].y = -1;
	//		g_Bullet[i].live = true;
	//		break;
	//	}
	//	g_Monster[i].y += g_Monster[i].speed;
	//}

	// 살아있는 애들 검사 후
	// 내려주기 & 일정 수준 이하로 내려가면 죽이게 만들기


	for (int i = 0; i < Max; i++)
	{
		if (g_Monster[i].live == true)
		{
			g_Monster[i].y += g_Monster[i].speed;
			//break;
		}
	}

	for (int i = 0; i < Max; i++)
	{
		if (g_Monster[i].y >= 30 && g_Monster[i].live ==  true)
		{
			g_Monster[i].live = false;
		}
	}

	MonsterRespawn();
}

void MonsterRespawn()
{
	// 죽은 얘들 검사 후
	// 죽은 애들 살려주기

	if (Timer < GetTickCount())
	{
		for (int i = 0; i < Max; i++)
		{
			if (g_Monster[i].live == false)
			{
				g_Monster[i].y = 0;
				g_Monster[i].live = true;
				g_Monster[i].x = rand() % 120;
				Timer = GetTickCount() + 100;
				break;
			}
		}
	}
}

void MonsterDraw()
{
	for (int i = 0; i < Max; i++)
	{
			DrawCharEx3(g_Monster[i].x, g_Monster[i].y, g_Monster[i].body, g_Monster[i].fColor, g_Monster[i].bColor);
	}
}