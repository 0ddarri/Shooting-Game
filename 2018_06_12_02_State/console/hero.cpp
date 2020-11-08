#include "include.h"

void HeroInit()
{
	g_mng.g_Hero.x = 60;
	g_mng.g_Hero.y = 25;
	g_mng.g_Hero.attack = 1;
	g_mng.g_Hero.hp = 5;
	g_mng.g_Hero.bColor = BLACK;
	g_mng.g_Hero.fColor = WHITE;
	g_mng.g_Hero.body = 'A';
	g_mng.g_Hero.speed = 1;
}

void Hero_Update()
{
	Hero_Move();

	//붕쉐
	Hero_Clipping();
	Hero_Draw();
}

void Hero_Move()
{
	if (IsKey(VK_LEFT)) // VK : 버추얼 키
	{
		g_mng.g_Hero.x -= g_mng.g_Hero.speed;
	}
	if (IsKey(VK_RIGHT))
	{
		g_mng.g_Hero.x += g_mng.g_Hero.speed;
	}
	if (IsKey(VK_UP))
	{
		g_mng.g_Hero.y -= g_mng.g_Hero.speed;
	}
	if (IsKey(VK_DOWN))
	{
		g_mng.g_Hero.y += g_mng.g_Hero.speed;
	}
}

void Hero_Clipping()
{
	if (g_mng.g_Hero.x >= 119)
	{
		g_mng.g_Hero.x = 119;
	}
	else if (g_mng.g_Hero.x <= 0)
	{
		g_mng.g_Hero.x = 0;
	}
	if (g_mng.g_Hero.y >= 29)
	{
		g_mng.g_Hero.y = 29;
	}
	else if (g_mng.g_Hero.y <= 0)
	{
		g_mng.g_Hero.y = 0;
	}
}

void Hero_Draw()
{
	DrawCharEx3(g_mng.g_Hero.x, g_mng.g_Hero.y, g_mng.g_Hero.body, g_mng.g_Hero.fColor, g_mng.g_Hero.bColor); // 캐릭터 그리기
}

