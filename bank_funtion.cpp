#include "bank.hpp"
#include "bank_function.hpp"

#include <cstring>
#include <fcntl.h>
#include <iostream>
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

using namespace std;

void addBank(date date)
{
	int money; char check; string category;

	cout << "금액을 입력해주세요: "; cin >> money;
	cout << "수입(i)/지출(e)를 입력해주세요: "; cin >> check;
	cout << "카테고리를 입력해주세요: "; cin >> category;

	if (check == 'e') money = -money;
	BankRecord newBankRecord(date, money, category);
	
	//파일 생성 후 기록
}

void delBank(date date)
{

}

void checkBank(date date)
{

}

