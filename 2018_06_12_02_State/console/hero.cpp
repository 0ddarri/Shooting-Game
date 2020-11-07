#include "include.h"

void HeroInit()
{
	g_Hero.x = 0;
	g_Hero.y = 0;
	g_Hero.attack = 1;
	g_Hero.hp = 5;
	g_Hero.bColor = BLACK;
	g_Hero.fColor = WHITE;
	g_Hero.body = 'A';
	g_Hero.speed = 1;
}

void Hero_Update()
{
	Hero_Move();

	//붕쉐
	Hero_Clipping();
}

void Hero_Move()
{
	if (IsKey(VK_LEFT)) // VK : 버추얼 키
	{
		g_Hero.x -= g_Hero.speed;
	}
	if (IsKey(VK_RIGHT))
	{
		g_Hero.x += g_Hero.speed;
	}
	if (IsKey(VK_UP))
	{
		g_Hero.y -= g_Hero.speed;
	}
	if (IsKey(VK_DOWN))
	{
		g_Hero.y += g_Hero.speed;
	}
}

void Hero_Clipping()
{
	if (g_Hero.x >= 119)
	{
		g_Hero.x = 119;
	}
	else if (g_Hero.x <= 0)
	{
		g_Hero.x = 0;
	}
	if (g_Hero.y >= 29)
	{
		g_Hero.y = 29;
	}
	else if (g_Hero.y <= 0)
	{
		g_Hero.y = 0;
	}
}

void Hero_Draw()
{
	DrawCharEx3(g_Hero.x, g_Hero.y, g_Hero.body, g_Hero.fColor, g_Hero.bColor); // 캐릭터 그리기
}

