#include "display.hpp"
#include "kbhit.h"
#include <cstring>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <vector>

using namespace std;

// move (x, y);
void gotoxy(int x, int y) { printf("%c[%d;%df", 0x1B, y, x); }

void print(int location, int color, string text) {
    if (location == fg) {
        cout << begin << color << "m";
        cout << text << end;
    } else if (location == bg) {

        cout << begin << color + 10 << "m";
        cout << text << end;
    }
}

// print fgColored text with bgcolor
void printWithBg(int fgColor, int bgColor, string text) {
    cout << begin << fgColor << ";" << bgColor + 10 << "m" << text << end;
}

// clear the terminal and print 40*130 colored screen
void resetDisplay() {
    system("clear");

    for (int i = 0; i < 40; i++) {
        for (int j = 0; j < 130; j++) {
            print(bg, blck, " ");
        }
        cout << endl;
    }
    reset;
}

int dayNumber(int day, int month, int year) {
    static int t[] = {0, 3, 2, 5, 0, 3, 5, 1, 4, 6, 2, 4};
    year -= month < 3;
    return (year + year / 4 - year / 100 + year / 400 + t[month - 1] + day) % 7;
}

// return monthName
string getMonthName(int monthNumber) {
    string months[] = {"January",   "February", "March",    "April",
                       "May",       "June",     "July",     "August",
                       "September", "October",  "November", "December"};
    return (months[monthNumber]);
}

// return how many days are there in the month of year
int numberOfDays(int monthNumber, int year) {
    switch (monthNumber) {
    case 0:
    case 2:
    case 4:
    case 6:
    case 7:
    case 9:
    case 11:
        return (31);
        break;
    case 1:
        if (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0))
            return (29);
        else
            return (28);
        break;
    case 3:
    case 5:
    case 8:
    case 10:
        return (30);
        break;
    }
}

// print calendar for that month
void printCalendar(int year, int month) {
    resetDisplay();

    int days, k;
    int current = dayNumber(1, month, year);
    string monthAndYear = getMonthName(month - 1) + ' ' + to_string(year);

    days = numberOfDays(month - 1, year);

    gotoxy(38, 3);
    printWithBg(whte, blck, "[ " + monthAndYear + " ]");
    reset;
    gotoxy(11, 6);
    printWithBg(red, blck, "S");
    printWithBg(
        whte, blck,
        "          M          T          W          T          F          S");
    gotoxy(9, 7);
    printWithBg(whte, blck,
                "──────────────────────────────────────────────────────────────"
                "─────────"
                "───────\n");

    for (k = 0; k < current; k++)
        print(bg, blck, "           ");

    for (int j = 1; j <= days; j++) {
        if (j < 10)
            printWithBg(whte, blck, "          " + to_string(j));
        else
            printWithBg(whte, blck, "         " + to_string(j));

        if (++k > 6) {
            k = 0;
            cout << endl << endl << endl << endl << endl;

            printWithBg(whte, blck,
                        "        "
                        "─────────────────────────────────────────────────────"
                        "───────────────"
                        "──────────\n");
        }
    }
    if (k)
        cout << endl << endl << endl << endl << endl;
    printWithBg(whte, blck,
                "        "
                "──────────────────────────────────────────────────────"
                "───────────────"
                "─────────\n");
    current = k;
    reset;
    return;
}
int chooseMenu() {
    const int LEDGER = 0;
    const int PLANNER = 1;
    int menu = 0;
    int value;

    firstMenu();

    do {
        value = kbhit();

        switch (value) {
        case LEFT: {
            firstMenuLedger();
            menu = LEDGER;
            break;
        }
        case RIGHT: {
            firstMenuPlanner();
            menu = PLANNER;
            break;
        }
        }
    } while (value != ENTER);

    return menu;
}

// print PLANNER BANC
void firstMenu() {
    resetDisplay();
    gotoxy(25, 11);
    printWithBg(whte, blck,
                "╔════════╗ ╥          ╔════════╗ ╔════════╗ ╔════════╗ "
                "╔═════════ ╔════════╗");
    gotoxy(25, 12);
    printWithBg(whte, blck,
                "║        ║ ║          ║        ║ ║        ║ ║        ║ ║      "
                "    ║        ║");
    gotoxy(25, 13);
    printWithBg(whte, blck,
                "║        ║ ║          ║        ║ ║        ║ ║        ║ ║      "
                "    ║        ║");
    gotoxy(25, 14);
    printWithBg(whte, blck,
                "╠════════╝ ║          ╠════════╣ ║        ║ ║        ║ "
                "╠════════╣ ╠════════╗");
    gotoxy(25, 15);
    printWithBg(whte, blck,
                "║          ║          ║        ║ ║        ║ ║        ║ ║      "
                "    ║        ║");
    gotoxy(25, 16);
    printWithBg(whte, blck,
                "║          ║          ║        ║ ║        ║ ║        ║ ║      "
                "    ║        ║");
    gotoxy(25, 17);
    printWithBg(whte, blck,
                "╨          ╚════════  ╨        ╨ ╨        ╨ ╨        ╨ "
                "╚═════════ ╨        ╨");

    gotoxy(58, 18);
    printWithBg(whte, blck, "╔════════╗ ╔════════╗ ╔════════╗ ╔═════════");
    gotoxy(58, 19);
    printWithBg(whte, blck, "║        ║ ║        ║ ║        ║ ║");
    gotoxy(58, 20);
    printWithBg(whte, blck, "║        ║ ║        ║ ║        ║ ║");
    gotoxy(58, 21);
    printWithBg(whte, blck, "╠════════╝ ╠════════╣ ║        ║ ║");
    gotoxy(58, 22);
    printWithBg(whte, blck, "║        ║ ║        ║ ║        ║ ║");
    gotoxy(58, 23);
    printWithBg(whte, blck, "║        ║ ║        ║ ║        ║ ║");
    gotoxy(58, 24);
    printWithBg(whte, blck, "╚════════╝ ╨        ╨ ╨        ╨ ╚═════════");
    gotoxy(45, 30);

    firstMenuLedger();
    reset;
}
void firstMenuLedger(void) {
    gotoxy(45, 30);
    print(bg, blck, "                             ");
    gotoxy(49, 30);
    printWithBg(blue, blck, ">  LEDGER");
    gotoxy(71, 30);
    printWithBg(whte, blck, " PLANNER");

    reset;
}

void firstMenuPlanner(void) {
    gotoxy(45, 30);
    print(bg, blck, "                             ");
    gotoxy(51, 30);
    printWithBg(whte, blck, " LEDGER");
    gotoxy(70, 30);
    printWithBg(blue, blck, "> PLANNER");
    reset;
}

int getLongestLength(vector<string> categories) {
    int max = 0;
    for (int i = 0; i < categories.size(); i++) {
        if (max < categories[i].length()) {
            max = categories[i].length();
        }
    }
    return max;
}

// function for scaling
void setRatio(vector<int> &ratio, const vector<int> money) {
    int max = 0;
    int sum = 0;

    for (int i = 0; i < money.size(); i++) {
        sum += money[i];

        if (max < money[i])
            max = money[i];
    }
    int maxPercentage = max * 100 / sum;

    for (int i = 0; i < money.size(); i++) {
        ratio.push_back(money[i] * 100 / sum);
    }
}

// function for scaling
int getMaxPercentage(const vector<int> ratio) {
    int maxPercentage;

    for (int i = 0; i < ratio.size(); i++) {
        if (maxPercentage < ratio[i])
            maxPercentage = ratio[i];
    }
    return maxPercentage;
}

// print the ratio of money spent in the month
void printRatio(vector<string> categories, vector<int> money) {
    resetDisplay();
    //일단
    categories.push_back("옷");
    categories.push_back("식비");
    categories.push_back("생필품");
    categories.push_back("책");
    categories.push_back("카페");

    money.push_back(10000);
    money.push_back(30000);
    money.push_back(10000);
    money.push_back(5000);
    money.push_back(3000);

    //예시로 담아봄

    int x = 40;
    int y = 10;
    int sum = 0;
    int maxLength = getLongestLength(categories);

    vector<int> ratio;
    setRatio(ratio, money);

    int maxPercentage = getMaxPercentage(ratio);

    for (int i = 0; i < categories.size(); i++) {
        gotoxy(x, y);

        for (int j = 0; j < (maxLength - categories[i].length()) / 3; j++) {
            print(bg, blck, "  ");
        }
        printWithBg(whte, blck, categories[i]);
        printWithBg(whte, blck, " |  ");

        for (int j = 0; j < ratio[i] * 50 / maxPercentage; j++) {
            print(bg, blue, " ");
        }
        gotoxy(x + 61, y);
        printWithBg(whte, blck, '(' + to_string(ratio[i]) + "%) ");
        y += 2;
    }
}
