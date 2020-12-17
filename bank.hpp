#ifndef __BANK_HPP__
#define __BANK_HPP__

#include <string>

using namespace std;

class Date {
  public:
    Date();
    Date(int year, int month, int day);
    int getYear();
    int getMonth();
    int getDay();
    void setDate(int *year, int *month, int *day);

  private:
    int year;
    int month;
    int day;
};

class BankRecord {
  public:
    BankRecord();
    BankRecord(Date date, int money, string category);
    Date getDate();
    int getMoney();
    string getCategory();

  private:
    Date when;
    int money;
    string category;
};

enum ledgerMenu {
    ADD,
    DEL,
    CHECK,
    DATE,
    PRE,
    KEY,
};
void ledgerMenuPrevious();
void ledgerMenuCheck();
void ledgerMenuDelete();
void ledgerMenuGotoDate();
void ledgerMenuAdd();
#endif
