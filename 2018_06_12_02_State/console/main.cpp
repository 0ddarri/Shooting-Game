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

int main()
{
	InitialConsole();//�ʱ�ȭ�Լ�
	HeroInit(); // ĳ���� �ʱ�ȭ �Լ�
	BulletInit();
	SetWindowTitle("Shooting"); // �ܼ��� �̸��� Shooting���� ����

	while (true)
	{
		CheckInput(); // Ű���� �Է��� üũ�ϴµ� �ϴ�
		ClearScreenEx3(BLACK); // �ܼ� ���� �����ε�
		
		Hero_Update(); // ���
		Hero_Draw(); // ���

		BulletUpdate();
		BulletDraw();

		Flip(); // ������۸� : �̸� ���� �������� �׷����� ����
		EngineSync(30); // �÷��̾� �ӵ�?
	}

	ReleaseConsole(); // �ܼ� �����Լ���µ�
	return 0;
}
