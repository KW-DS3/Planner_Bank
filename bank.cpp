#include "bank.hpp"
#include "display.hpp"
#include <string>
using namespace std;

Date::Date() {}

Date::Date(int year, int month, int day) {
    this->year = year;
    this->month = month;
    this->day = day;
}

int Date::getYear() { return this->year; }

int Date::getMonth() { return this->month; }

int Date::getDay() { return this->day; }

void Date::setDate(int *year, int *month, int *day) {
    resetDisplay(97, 7, 28, 5);

    gotoxy(97, 7);
    printWithBg(WHTE, BLCK, "date: ");
    cin >> *year >> *month >> *day;
    this->year = *year;
    this->month = *month;
    this->day = *day;

    printCalendar(*year, *month, *day, 0);
    cin.ignore();
}

BankRecord::BankRecord() {}

BankRecord::BankRecord(Date date, int money, string category) {
    this->when = date;
    this->money = money;
    this->category = category;
}

Date BankRecord::getDate() { return this->when; }

int BankRecord::getMoney() { return this->money; }

string BankRecord::getCategory() { return this->category; }

void ledgerMenuAdd() {
    resetDisplay(97, 7, 32, 5);
    gotoxy(97, 7);
    printWithBg(BLUE, BLCK, "> Add");
    gotoxy(97, 9);
    printWithBg(WHTE, BLCK, "  Check");
    gotoxy(112, 7);
    printWithBg(WHTE, BLCK, "  Delete");
    gotoxy(112, 9);
    printWithBg(WHTE, BLCK, "  Go to date");
    gotoxy(97, 11);
    printWithBg(WHTE, BLCK, "  Previous");
}
void ledgerMenuGotoDate() {
    resetDisplay(97, 7, 32, 5);
    gotoxy(97, 7);
    printWithBg(WHTE, BLCK, "  Add");
    gotoxy(97, 9);
    printWithBg(WHTE, BLCK, "  Check");
    gotoxy(112, 7);
    printWithBg(WHTE, BLCK, "  Delete");
    gotoxy(112, 9);
    printWithBg(BLUE, BLCK, "> Go to date");
    gotoxy(97, 11);
    printWithBg(WHTE, BLCK, "  Previous");
}
void ledgerMenuDelete() {
    resetDisplay(97, 7, 32, 5);
    gotoxy(97, 7);
    printWithBg(WHTE, BLCK, "  Add");
    gotoxy(97, 9);
    printWithBg(WHTE, BLCK, "  Check");
    gotoxy(112, 7);
    printWithBg(BLUE, BLCK, "> Delete");
    gotoxy(112, 9);
    printWithBg(WHTE, BLCK, "  Go to date");
    gotoxy(97, 11);
    printWithBg(WHTE, BLCK, "  Previous");
}
void ledgerMenuPrevious() {
    resetDisplay(97, 7, 32, 5);
    gotoxy(97, 7);
    printWithBg(WHTE, BLCK, "  Add");
    gotoxy(97, 9);
    printWithBg(WHTE, BLCK, "  Check");
    gotoxy(112, 7);
    printWithBg(WHTE, BLCK, "  Delete");
    gotoxy(112, 9);
    printWithBg(WHTE, BLCK, "  Go to date");
    gotoxy(97, 11);
    printWithBg(BLUE, BLCK, "> Previous");
}
void ledgerMenuCheck() {
    resetDisplay(97, 7, 32, 5);
    gotoxy(97, 7);
    printWithBg(WHTE, BLCK, "  Add");
    gotoxy(97, 9);
    printWithBg(BLUE, BLCK, "> Check");
    gotoxy(112, 7);
    printWithBg(WHTE, BLCK, "  Delete");
    gotoxy(112, 9);
    printWithBg(WHTE, BLCK, "  Go to date");
    gotoxy(97, 11);
    printWithBg(WHTE, BLCK, "  Previous");
}
