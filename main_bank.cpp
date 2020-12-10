#include <iostream>
#include <Windows.h>
#include "DAY.hpp"
#include "RECODE.hpp"

using namespace std;

void bank_main();       //The first screen of bank function
void bank_management(); //(1) ����/���� ��� ����/����
void bank_print();      //(2) �Ⱓ�� ����/���� �ݾ� ���
void bank_compare();    //(3) �����ް� �̹����� ����/���� ��
void bank_tip();        //(4) ���� ��
void bank_exit();       //(5) ���α׷� ����

int main(void)
{
	while (1)
	{
		bank_main();
	}
	
	return 0;
}

void bank_main()
{
	int user_select = 0;

	cout << "=====================================" << endl;
	cout << "Planner Bank�� ���� ���� ȯ���մϴ�. " << endl;
	cout << "=====================================" << endl;
	cout << "1. ����/���� ��� ����/����" << endl;
	cout << "2. �Ⱓ�� ����/���� �ݾ� ���" << endl;
	cout << "3. �����ް� �̹����� ����/���� ��" << endl;
	cout << "4. ���� ��" << endl;
	cout << "5. ���α׷� ����" << endl;
	cout << "=====================================" << endl;
	cout << "���Ͻô� ����� ������ �ּ���: "; cin >> user_select;

	system("cls");

	switch (user_select)
	{
	case 1:
		bank_management();
		break;
	case 2:
		bank_print();
		break;
	case 3:
		bank_compare();
		break;
	case 4:
		bank_tip();
		break;
	case 5:
		bank_exit();
		break;
	default:
		cout << "�߸��� �Է��Դϴ�. �ٽ� �Է��� �ּ���." << endl;
		cout << "3�� �� ����ȭ������ ���ư��ϴ�..." << endl;
		Sleep(3000); system("cls");
		break;
	}
}

void bank_management()
{
	//code
}

void bank_print()
{
	//code
}

void bank_compare()
{
	//code
}

void bank_exit()
{
	//code
}

void bank_tip()
{
	//code
}