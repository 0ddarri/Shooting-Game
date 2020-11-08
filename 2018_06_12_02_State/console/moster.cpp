#include "Include.h"

void MonsterInit()
{
	for (int i = 0; i < Max; i++)
	{
		g_mng.g_Monster[i].x = -1;
		g_mng.g_Monster[i].y = -1;
		g_mng.g_Monster[i].hp = 1;
		g_mng.g_Monster[i].speed = 1;
		g_mng.g_Monster[i].body = 'W';
		g_mng.g_Monster[i].live = false;
		g_mng.g_Monster[i].fColor = RED;
		g_mng.g_Monster[i].bColor = BLACK;
	}
}

DWORD Timer = GetTickCount();

void MonsterUpdate()
{
	//int random = rand() % 120;
	//for (int i = 0; i < Max; i++)
	//{
	//	if (g_mng.g_Monster[i].live == true)
	//	{
	//		g_mng.g_Monster[i].x = rand() % 130;
	//		g_mng.g_Monster[i].live = false;
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
	//	g_mng.g_Monster[i].y += g_mng.g_Monster[i].speed;
	//}

	// ����ִ� �ֵ� �˻� ��
	// �����ֱ� & ���� ���� ���Ϸ� �������� ���̰� �����


	for (int i = 0; i < Max; i++)
	{
		if (g_mng.g_Monster[i].live == true)
		{
			g_mng.g_Monster[i].y += g_mng.g_Monster[i].speed;
			//break;
		}
	}

	for (int i = 0; i < Max; i++)
	{
		if (g_mng.g_Monster[i].y >= 30 && g_mng.g_Monster[i].live ==  true)
		{
			g_mng.g_Monster[i].live = false;
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
			if (g_mng.g_Monster[i].live == false)
			{
				g_mng.g_Monster[i].y = -3;
				g_mng.g_Monster[i].live = true;
				g_mng.g_Monster[i].x = rand() % 120;
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
			DrawCharEx3(g_mng.g_Monster[i].x, g_mng.g_Monster[i].y, g_mng.g_Monster[i].body, g_mng.g_Monster[i].fColor, g_mng.g_Monster[i].bColor);
	}
}