#pragma once

struct stHero
{
	int x, y;
	char body;
	int speed;
	int attack;
	int hp;

	DWORD fColor;
	DWORD bColor;
};

void HeroInit();
void Hero_Update();
void Hero_Draw();