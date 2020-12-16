#include "bank_function.hpp"
#include "bank.hpp"

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

void addBank(date date) {
    int money;
    char check;
    string category;

    cout << "�ݾ��� �Է����ּ���: ";
    cin >> money;
    cout << "����(i)/����(e)�� �Է����ּ���: ";
    cin >> check;
    cout << "ī�װ��� �Է����ּ���: ";
    cin >> category;

    if (check == 'e')
        money = -money;
    BankRecord newInput(date, money, category);

    int fd = 0;
    string dirname = convert(newInput.getDate().getYear()) +
                     convert(newInput.getDate().getMonth()) +
                     convert(newInput.getDate().getDay());
    string pathname;
    if (newInput.getMoney() >= 0)
        pathname = dirname + "/" + "IncomeList.txt";
    else
        pathname = dirname + "/" + "ExpenseList.txt";

    if (!checkFileExists(dirname)) {
        if (mkdir(dirname.c_str(), PERMS) < 0) {
            perror("mkdir() error!");
        }
    }

    if ((fd = open(pathname.c_str(), O_RDWR | O_CREAT | O_APPEND, PERMS)) < 0) {
        perror("open() error!");
        exit(-1);
    }
    string temp = to_string(newInput.getMoney());
    char const *msgMoney = temp.c_str();
    char const *msgCate = newInput.getCategory().c_str();

    lseek(fd, SEEK_CUR, -1);
    if (write(fd, (char *)msgMoney, strlen(msgMoney)) < 0) {
        perror("write() error!");
        exit(-2);
    }
    if (write(fd, (char *)msgCate, strlen(msgCate)) < 0) {
        perror("write() error!");
        exit(-2);
    }
    if (write(fd, "\n", 1) < 0) {
        perror("write() error!");
        exit(-2);
    }

    close(fd);
}

void delBank(date date) {}

void checkBank(date date) {}
