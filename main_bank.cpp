#include <iostream>
#include <Windows.h>
#include "DAY.hpp"
#include "RECODE.hpp"

using namespace std;

void bank_main();       //The first screen of bank function
void bank_management(); //(1) 수입/지출 목록 관리/열람
void bank_print();      //(2) 기간별 수입/지출 금액 출력
void bank_compare();    //(3) 지난달과 이번달의 수입/지출 비교
void bank_tip();        //(4) 한줄 평가
void bank_exit();       //(5) 프로그램 종료

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
	cout << "Planner Bank에 오신 것을 환영합니다. " << endl;
	cout << "=====================================" << endl;
	cout << "1. 수입/지출 목록 관리/열람" << endl;
	cout << "2. 기간별 수입/지출 금액 출력" << endl;
	cout << "3. 지난달과 이번달의 수입/지출 비교" << endl;
	cout << "4. 한줄 평가" << endl;
	cout << "5. 프로그램 종료" << endl;
	cout << "=====================================" << endl;
	cout << "원하시는 기능을 선택해 주세요: "; cin >> user_select;

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
		cout << "잘못된 입력입니다. 다시 입력해 주세요." << endl;
		cout << "3초 후 메인화면으로 돌아갑니다..." << endl;
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