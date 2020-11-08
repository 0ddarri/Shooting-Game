#include "Include.h"

//stBullet g_mng.g_Bullet[Max];

void BulletInit()
{
	for (int i = 0; i < Max; i++)
	{
		g_mng.g_Bullet[i].x = -999;
		g_mng.g_Bullet[i].y = -99;
		g_mng.g_Bullet[i].live = false;
		g_mng.g_Bullet[i].fColor = YELLOW; // ���� �ٲٱ�
		g_mng.g_Bullet[i].speed = 2;
		g_mng.g_Bullet[i].body = '|';
		g_mng.g_Bullet[i].bColor = BLACK;
	}
}

	DWORD StartTime;
	DWORD EndTime = GetTickCount();



void BulletUpdate()
{

 	if (IsKey(VK_A)) // �����̽��ٸ� ������ ��
	{
		StartTime = GetTickCount();
		for (int i = 0; i < Max; i++)
		{

			if (g_mng.g_Bullet[i].live == false && StartTime - EndTime >= 100)
			{
				g_mng.g_Bullet[i].x = g_mng.g_Hero.x; // �÷��̾� ��ġ�� ����
				g_mng.g_Bullet[i].y = g_mng.g_Hero.y; // �÷��̾� ��ġ�� ����
				g_mng.g_Bullet[i].live = true;
				EndTime = GetTickCount();
				break;
			}
		}
	}
	for (int i = 0; i < Max; i++)
	{
		if (g_mng.g_Bullet[i].y <= 4)
		{
			g_mng.g_Bullet[i].live = false;
			g_mng.g_Bullet[i].x = -99999;
		}

		g_mng.g_Bullet[i].y -= g_mng.g_Bullet[i].speed;
	}
	BulletCollision();
}


void BulletCollision()
{
	for (int i = 0; i < Max; i++)
	{
		for (int j = 0; j < Max; j++)
		{
			if (g_mng.g_Bullet[j].x == g_mng.g_Monster[i].x && g_mng.g_Bullet[j].y <= g_mng.g_Monster[i].y)
			{
				EffectInit(g_mng.g_Monster[i].x, g_mng.g_Monster[i].y);

				g_mng.g_Bullet[j].live = false;
				g_mng.g_Bullet[j].x = -9999;
				g_mng.g_Bullet[j].y = -9999;
				g_mng.g_Monster[i].live = false;
				g_mng.g_Monster[i].x = -9999;
				g_mng.g_Monster[i].y = -9999;

				g_mng.nCount += 1;
			}
		}
	}
}

void BulletDraw()
{
	for (int i = 0; i < Max; i++)
	{
		if (g_mng.g_Bullet[i].live == true)
		{
			DrawCharEx3(g_mng.g_Bullet[i].x, g_mng.g_Bullet[i].y, g_mng.g_Bullet[i].body, g_mng.g_Bullet[i].fColor, g_mng.g_Bullet[i].bColor);
		}
	}
}