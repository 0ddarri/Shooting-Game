#include "Include.h"
void EffectRe()
{
	for (int i = 0; i < Max; i++)
	{
		g_Effect[i].x = -999;
		g_Effect[i].y = -999;
		g_Effect[i].isLive = false;
		g_Effect[i].index = 0;
		g_Effect[i].fcolor = WHITE;
		g_Effect[i].bcolor = BLACK;
		g_Effect[i].Timer = GetTickCount();
	}
}

void EffectInit(int x, int y)
{
	for (int i = 0; i < Max; i++)
	{
		if (!g_Effect[i].isLive)
		{
			g_Effect[i].x = x;
			g_Effect[i].y = y;
			g_Effect[i].isLive = true;
			g_Effect[i].Timer = GetTickCount();

			break;
			//g_Effect[i].index = 0;
			//g_Effect[i].fcolor = WHITE;
			//g_Effect[i].bcolor = BLACK;
		}
	}
}

//총알이랑 몬스터가 충돌하면
//이펙트 출력


void EffectUpdate()
{
	for (int i = 0; i < Max; i++)
	{
		if (g_Effect[i].isLive)
		{
			if (g_Effect[i].Timer < GetTickCount())
			{
				g_Effect[i].index++;
				g_Effect[i].Timer = GetTickCount() + 100;
				if (g_Effect[i].index >= 3)
				{
					g_Effect[i].isLive = false;
					g_Effect[i].index = 0;
					break;
				}
			}
		}
	}

}

void EffectDraw()
{
	for (int i = 0; i < Max; i++)
	{
		if (g_Effect[i].isLive == true)
		{
			for (int j = 0; j < 3; j++)
			{
				for (int k = 0; k < 3; k++)
				{
					DrawCharEx3(g_Effect[i].x + k, g_Effect[i].y + j, c_Effect[g_Effect[i].index][j][k], g_Effect[i].fcolor, g_Effect[i].bcolor);
				}
			}
		}
	}
}