#include "bank.hpp"
#include "bank_function.hpp"
#include "planner.hpp"

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

#define PERMS 0644
#define MAX_NAME_SIZE 32

using namespace std;

string convert(int date) {
	if (date < 10)
		return '0' + to_string(date);
	else
		return to_string(date);
}

bool checkFileExists(std::string filename) {
	if (access(filename.c_str(), F_OK) < 0) {
		return 0;
	}
	return 1;
}

void addBank(date date)
{
	int money; char check; string category;

	cout << "금액을 입력해주세요: "; cin >> money;
	cout << "수입(i)/지출(e)를 입력해주세요: "; cin >> check;
	cout << "카테고리를 입력해주세요: "; cin >> category;

	if (check == 'e') money = -money;
	BankRecord newInput(date, money, category);

	int fd = 0;
	string dirname = convert(newInput.when.getYear()) + convert(newInput.when.getMonth()) + convert(newInput.when.getDay());
	if (newInput.getMoney >= 0) string pathname = dirname + "/" + "IncomeList.txt";
	else string pathname = dirname + "/" + "ExpenseList.txt";

	if (!checkFileExists(dirname)) {
		if (mkdir(dirname.c_str(), PERMS) < 0) {
			perror("mkdir() error!");
		}
	}

	if ((fd = open(pathname.c_str(), O_RDWR | O_CREAT | O_APPEND, PERMS)) < 0) {
		perror("open() error!");
		exit(-1);
	}

	lseek(fd, SEEK_CUR, -1);
	if (write(fd, (char *)getMoney.c_str(), (int)getMoney().length()) < 0) {
		perror("write() error!");
		exit(-2);
	}
	if (write(fd, (char *)getCategory().c_str(), (int)getCategory().length()) < 0) {
		perror("write() error!");
		exit(-2);
	}
	if (write(fd, "\n", 1) < 0) {
		perror("write() error!");
		exit(-2);
	}

	close(fd);

}

void delBank(date date)
{

}

void checkBank(date date)
{

}

