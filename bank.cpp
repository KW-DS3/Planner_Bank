#include "bank.hpp"
#include <string>

using namespace std;

date::date() {}

date::date(int year, int month, int day) {
    this->year = year;
    this->month = month;
    this->day = day;
}

int date::getYear() { return this->year; }

int date::getMonth() { return this->month; }

int date::getDay() { return this->day; }

BankRecord::BankRecord() {}

BankRecord::BankRecord(date date, int money, string category) {
    this->when = date;
    this->money = money;
    this->category = category;
}

date BankRecord::getDate() { return this->when; }

int BankRecord::getMoney() { return this->money; }

string BankRecord::getCategory() { return this->category; }
