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

	cout << "�ݾ��� �Է����ּ���: "; cin >> money;
	cout << "����(i)/����(e)�� �Է����ּ���: "; cin >> check;
	cout << "ī�װ��� �Է����ּ���: "; cin >> category;

	if (check == 'e') money = -money;
	BankRecord newBankRecord(date, money, category);
	
	//���� ���� �� ���
}

void delBank(date date)
{

}

void checkBank(date date)
{

}

