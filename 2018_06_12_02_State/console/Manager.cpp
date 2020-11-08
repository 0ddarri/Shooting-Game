#include "Include.h"

void GameInit()
{
	HeroInit(); // 캐릭터 초기화 함수
	BulletInit();
	MonsterInit();
	EffectRe();
}

void GameUpdate()
{
	Hero_Update(); // 계산
	BulletUpdate();
	MonsterUpdate();
	EffectUpdate();
}

void GameDraw()
{
	Hero_Draw(); // 출력
	BulletDraw();
	MonsterDraw();
	EffectDraw();
}

void GameUI()
{
	for (int i = 0; i < 30; i++)
	{
		for (int j = 0; j < 120; j++)
		{
			if (g_mng.nUI[i][j] == 1)
			{
				DrawFillBoxEx3(j, i, 1, 1, WHITE);
			}
		}

	}


	sprintf(g_mng.count, "Kill : %d", g_mng.nCount); //sprintf : 태우함수
	DrawStrEx3(1, 1, g_mng.count, LIGHTRED, BLACK);

	g_mng.PlayTIme = GetTickCount();
	g_mng.NowTime = g_mng.PlayTIme - g_mng.StartTime;
	sprintf(g_mng.cPlayTime, "Play Time : %d", g_mng.NowTime / 1000);
	DrawStrEx3(20, 1, g_mng.cPlayTime, LIGHTRED, BLACK);
}
