#pragma once

struct stMonster
{
	int x;
	int y;
	int hp;
	int speed;
	char body;
	boolean live;

	DWORD fColor;
	DWORD bColor;

};

void MonsterRe();

void MonsterInit();
void MonsterUpdate();
void MonsterRespawn();
void MonsterDraw();