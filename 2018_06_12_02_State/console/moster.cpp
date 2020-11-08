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

	// ����ִ� �ֵ� �˻� ��
	// �����ֱ� & ���� ���� ���Ϸ� �������� ���̰� �����


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
	// ���� ��� �˻� ��
	// ���� �ֵ� ����ֱ�

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