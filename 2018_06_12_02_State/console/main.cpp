#include "Include.h"

// �밡���� ǥ���
// int    n�̸�
// char   c�̸�
// bool   b�̸�	
// DWORD  dw�̸�
// short  s�̸�
// long   l�̸�
// ����ü �ɹ������� 
// int m_n�̸�
// char  m_c�̸�
// �۷ι� g_?�̸�
// int nVlaue = 0;
// void Quit();

//int x = 0;
//int y = 0;

stHero g_Hero;
stBullet g_Bullet[Max];
stMonster g_Monster[Max];
stEffect g_Effect[Max];

char c_Effect[3][3][3] = {
	{
		{' ',' ',' '},
		{' ','*',' '},
		{' ',' ',' '}
	},
	{
		{' ','*',' '},
		{'*','*','*'},
		{' ','*',' '}
	},
	{
		{'*',' ','*'},
		{' ','*',' '},
		{'*',' ','*'}
	}
};

int main()
{

	InitialConsole();//�ʱ�ȭ�Լ�
	HeroInit(); // ĳ���� �ʱ�ȭ �Լ�
	BulletInit();
	MonsterInit();
	MonsterRe();
	EffectRe();
	SetWindowTitle("Shooting"); // �ܼ��� �̸��� Shooting���� ����
	srand(time(NULL));
	while (true)
	{

		CheckInput(); // Ű���� �Է��� üũ�ϴµ� �ϴ�
		ClearScreenEx3(BLACK); // �ܼ� ���� �����ε�
		
		Hero_Update(); // ���
		Hero_Draw(); // ���

		BulletUpdate();
		BulletDraw();

		MonsterUpdate();
		MonsterDraw();

		EffectUpdate();
		EffectDraw();


		Flip(); // ������۸� : �̸� ���� �������� �׷����� ����
		EngineSync(30); // �÷��̾� �ӵ�?
	}

	ReleaseConsole(); // �ܼ� �����Լ���µ�
	return 0;
}
