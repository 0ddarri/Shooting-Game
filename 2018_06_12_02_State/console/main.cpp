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

GameMng g_mng;


int main()
{
	GameInit();
	InitialConsole();//�ʱ�ȭ�Լ�

	SetWindowTitle("Shooting"); // �ܼ��� �̸��� Shooting���� ����
	srand(time(NULL));
	while (true)
	{
		CheckInput(); // Ű���� �Է��� üũ�ϴµ� �ϴ�
		ClearScreenEx3(BLACK); // �ܼ� ���� �����ε�


		GameUpdate();
		GameDraw();
		GameUI();

		Flip(); // ������۸� : �̸� ���� �������� �׷����� ����
		EngineSync(30); // �÷��̾� �ӵ�?
	}

	ReleaseConsole(); // �ܼ� �����Լ���µ�
	return 0;
}