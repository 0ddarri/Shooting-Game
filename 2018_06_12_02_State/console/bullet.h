#pragma once

struct stBullet
{
	int x, y;
	char body;
	int speed;
	boolean live;

	DWORD fColor;
	DWORD bColor;
};

void BulletInit();
void BulletUpdate();
void BulletDraw();