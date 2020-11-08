#pragma once

struct stEffect
{
	int index;

	int x;
	int y;

	bool isLive;

	DWORD Timer;

	DWORD fcolor;
	DWORD bcolor;
};

void EffectRe();
void EffectInit(int x, int y);
void EffectUpdate();
void EffectDraw();