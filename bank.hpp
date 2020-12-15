#ifndef __BANK_HPP__
#define __BANK_HPP__

#include <string>

using namespace std;

class date
{
public:
	date();
	date(int year, int month, int day);
	int getYear();
	int getMonth();
	int getDay();

private:
	int year;
	int month;
	int day;
};

class BankRecord
{
public:
	BankRecord();
	BankRecord(date date, int money, string category);
	date getDate();
	int getMoney();
	string getCategory();

private:
	date when; 
	int money; 
	string category; 
};




#endif