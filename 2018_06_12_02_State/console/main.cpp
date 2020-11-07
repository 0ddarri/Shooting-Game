#include "Include.h"

// 헝가리안 표기법
// int    n이름
// char   c이름
// bool   b이름	
// DWORD  dw이름
// short  s이름
// long   l이름
// 구조체 맴버변수는 
// int m_n이름
// char  m_c이름
// 글로벌 g_?이름
// int nVlaue = 0;
// void Quit();

//int x = 0;
//int y = 0;

stHero g_Hero;
stBullet g_Bullet[Max];

int main()
{
	InitialConsole();//초기화함수
	HeroInit(); // 캐릭터 초기화 함수
	BulletInit();
	SetWindowTitle("Shooting"); // 콘솔의 이름을 Shooting으로 지정

	while (true)
	{
		CheckInput(); // 키보드 입력을 체크하는듯 하다
		ClearScreenEx3(BLACK); // 콘솔 배경색 설정인듯
		
		Hero_Update(); // 계산
		Hero_Draw(); // 출력

		BulletUpdate();
		BulletDraw();

		Flip(); // 더블버퍼링 : 미리 다음 프레임을 그려놓고 전송
		EngineSync(30); // 플레이어 속도?
	}

	ReleaseConsole(); // 콘솔 제거함수라는데
	return 0;
}
