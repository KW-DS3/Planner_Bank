#include "display.hpp"
#include "planner.hpp"

#include <cstring>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <vector>

using namespace std;

// move (x, y);
void gotoxy(int x, int y) { printf("%c[%d;%df", 0x1B, y, x); }

void reset() { gotoxy(0, 0); }

void print(int location, int color, string text) {
    if (location == FG) {
        cout << BEGIN << color << "m";
        cout << text << END;
    } else if (location == BG) {

        cout << BEGIN << color + 10 << "m";
        cout << text << END;
    }
}

// print fgColored text with bgcolored background
void printWithBg(int fgColor, int bgColor, string text) {
    cout << BEGIN << fgColor << ";" << bgColor + 10 << "m" << text << END;
}

// clear the terminal and print 40*130 colored screen
void resetDisplay() {
    gotoxy(0, 0);
    system("clear");

    for (int i = 0; i < 45; i++) {
        for (int j = 0; j < 130; j++) {
            print(BG, BLCK, " ");
        }
        cout << endl;
    }
    reset;
}
void resetDisplay(int x, int y, int width, int height) {
    gotoxy(0, 0);
    for (int i = 0; i < height; i++) {
        gotoxy(x, y++);
        for (int j = 0; j < width; j++)
            print(BG, BLCK, " ");
    }
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

// return how many days there are in the month of year
int numberOfDays(int monthNumber, int year) {
    switch (monthNumber - 1) {
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
void printCalendar(int year, int month, int date) {
    resetDisplay();

    int days, k;
    int current = dayNumber(1, month, year);
    string monthAndYear = getMonthName(month - 1) + ' ' + to_string(year);

    days = numberOfDays(month, year);

    gotoxy(38, 3);
    printWithBg(WHTE, BLCK, "[ " + monthAndYear + " ]");
    reset;
    gotoxy(11, 6);
    printWithBg(RED, BLCK, "S");
    printWithBg(
        WHTE, BLCK,
        "          M          T          W          T          F          S");
    gotoxy(9, 7);
    printWithBg(WHTE, BLCK,
                "──────────────────────────────────────────────────────────────"
                "─────────"
                "───────\n");

    for (k = 0; k < current; k++)
        print(BG, BLCK, "           ");

    for (int j = 1; j <= days; j++) {

        if (j < 10) {
            if (date == j) {
                printWithBg(WHTE, BLCK, "          ");
                printWithBg(BLUE, BLCK, to_string(j));
            } else
                printWithBg(WHTE, BLCK, "          " + to_string(j));

        } else {
            if (date == j) {
                printWithBg(WHTE, BLCK, "         ");
                printWithBg(BLUE, BLCK, to_string(j));

            } else
                printWithBg(WHTE, BLCK, "         " + to_string(j));
        }

        if (++k > 6) {
            k = 0;
            cout << endl << endl << endl << endl << endl;

            printWithBg(WHTE, BLCK,
                        "        "
                        "─────────────────────────────────────────────────────"
                        "───────────────"
                        "──────────\n");
        }
    }
    if (k)
        cout << endl << endl << endl << endl << endl;
    printWithBg(WHTE, BLCK,
                "        "
                "──────────────────────────────────────────────────────"
                "───────────────"
                "─────────\n");
    current = k;
    reset;
    return;
}

// print PLANNER BANC
void firstMenu() {
    resetDisplay();
    gotoxy(25, 11);
    printWithBg(WHTE, BLCK,
                "╔════════╗ ╥          ╔════════╗ ╔════════╗ ╔════════╗ "
                "╔═════════ ╔════════╗");
    gotoxy(25, 12);
    printWithBg(WHTE, BLCK,
                "║        ║ ║          ║        ║ ║        ║ ║        ║ ║      "
                "    ║        ║");
    gotoxy(25, 13);
    printWithBg(WHTE, BLCK,
                "║        ║ ║          ║        ║ ║        ║ ║        ║ ║      "
                "    ║        ║");
    gotoxy(25, 14);
    printWithBg(WHTE, BLCK,
                "╠════════╝ ║          ╠════════╣ ║        ║ ║        ║ "
                "╠════════╣ ╠════════╗");
    gotoxy(25, 15);
    printWithBg(WHTE, BLCK,
                "║          ║          ║        ║ ║        ║ ║        ║ ║      "
                "    ║        ║");
    gotoxy(25, 16);
    printWithBg(WHTE, BLCK,
                "║          ║          ║        ║ ║        ║ ║        ║ ║      "
                "    ║        ║");
    gotoxy(25, 17);
    printWithBg(WHTE, BLCK,
                "╨          ╚════════  ╨        ╨ ╨        ╨ ╨        ╨ "
                "╚═════════ ╨        ╨");

    gotoxy(58, 18);
    printWithBg(WHTE, BLCK, "╔════════╗ ╔════════╗ ╔════════╗ ╔═════════");
    gotoxy(58, 19);
    printWithBg(WHTE, BLCK, "║        ║ ║        ║ ║        ║ ║");
    gotoxy(58, 20);
    printWithBg(WHTE, BLCK, "║        ║ ║        ║ ║        ║ ║");
    gotoxy(58, 21);
    printWithBg(WHTE, BLCK, "╠════════╝ ╠════════╣ ║        ║ ║");
    gotoxy(58, 22);
    printWithBg(WHTE, BLCK, "║        ║ ║        ║ ║        ║ ║");
    gotoxy(58, 23);
    printWithBg(WHTE, BLCK, "║        ║ ║        ║ ║        ║ ║");
    gotoxy(58, 24);
    printWithBg(WHTE, BLCK, "╚════════╝ ╨        ╨ ╨        ╨ ╚═════════");
    gotoxy(45, 30);

    reset;
}
void loginDisplay() {
    firstMenu();
    gotoxy(42, 27);
    printWithBg(WHTE, BLCK, "┌────────────────────────────────────────┐");
    gotoxy(42, 35);
    printWithBg(WHTE, BLCK, "└────────────────────────────────────────┘");

    gotoxy(47, 30);
    printWithBg(WHTE, BLCK, "ID:");
    gotoxy(47, 32);
    printWithBg(WHTE, BLCK, "PW: ");
}
int chooseLogin() {
    const int SIGNIN = 0;
    const int SIGNUP = 1;
    int menu = 0;
    int value;

    firstMenu();
    CURSOR_SIGNIN();
    do {
        value = kbhit();

        switch (value) {
        case LEFT: {
            CURSOR_SIGNIN();
            menu = SIGNIN;
            break;
        }
        case RIGHT: {
            CURSOR_SIGNUP();
            menu = SIGNUP;
            break;
        }
        }
    } while (value != ENTER);

    return menu;
}

void CURSOR_SIGNIN(void) {
    gotoxy(45, 30);
    print(BG, BLCK, "                             ");
    gotoxy(49, 30);
    printWithBg(BLUE, BLCK, ">  SIGN IN");
    gotoxy(71, 30);
    printWithBg(WHTE, BLCK, " SIGN UP");

    reset;
}

void CURSOR_SIGNUP(void) {
    gotoxy(45, 30);
    print(BG, BLCK, "                             ");
    gotoxy(51, 30);
    printWithBg(WHTE, BLCK, " SIGN IN");
    gotoxy(70, 30);
    printWithBg(BLUE, BLCK, "> SIGN UP");

    reset;
}

int chooseMenu() {
    const int LEDGER = 0;
    const int PLANNER = 1;
    int menu = 0;
    int value;

    firstMenu();
    firstMenuLedger();

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

void firstMenuLedger(void) {
    gotoxy(45, 30);
    print(BG, BLCK, "                             ");
    gotoxy(49, 30);
    printWithBg(BLUE, BLCK, ">  LEDGER");
    gotoxy(71, 30);
    printWithBg(WHTE, BLCK, " PLANNER");

    reset;
}

void firstMenuPlanner(void) {
    gotoxy(45, 30);
    print(BG, BLCK, "                             ");
    gotoxy(51, 30);
    printWithBg(WHTE, BLCK, " LEDGER");
    gotoxy(70, 30);
    printWithBg(BLUE, BLCK, "> PLANNER");
    reset;
}

int choosePlannerMenu(int year, int month, int date) {

    int menu = 0, value, index = 0;
    int updown = 0;
    int num = numOfEvents(year, month, date);

    plannerMenuCreate();
    do {
        value = kbhit();

        if (value == ENTER && updown == 1) {
            markEvent(year, month, date, index);
            printList(year, month, date);
        }

        switch (value) {
        case LEFT: {
            resetDisplay(93, 14, 1, 15);

            updown = 0;
            if (menu == 0)
                menu = 4;
            else
                menu--;
            break;
        }
        case RIGHT: {
            resetDisplay(93, 14, 1, 15);

            updown = 0;
            if (menu == 4)
                menu = 0;
            else
                menu++;
            break;
        }
        case UP: {
            updown = 1;
            if (index == 1)
                index = num;
            else
                index--;

            break;
        }
        case DOWN: {
            updown = 1;
            if (index == num)
                index = 1;
            else
                index++;
            break;
        }
        } // switch (value)
        switch (menu) {
        case CREATE:
            plannerMenuCreate();
            break;
        case DELETE:
            plannerMenuDelete();
            break;
        case GOTODATE:
            plannerMenuGotoDate();
            break;
        case PREVIOUS:
            plannerMenuPrevious();
            break;
        case KEYWORD:
            plannerMenuKeyword();
            break;
        } // switch (menu)

        if (updown == 1) {
            resetDisplay(93, 14, 1, (num + 1) * 2);
            gotoxy(93, 14 + 2 * index);
            printWithBg(WHTE, BLCK, ">");
        }

    } while (value != ENTER || updown == 1);

    return menu;
}
//삭제할 이벤트 커서로 고르기
int chooseEvent(int year, int month, int date) {
    int value;
    int index = 1;
    int num = numOfEvents(year, month, date);

    do {
        gotoxy(93, 14 + 2 * index);
        printWithBg(WHTE, BLCK, ">");

        value = kbhit();

        switch (value) {
        case UP: {
            if (index == 1)
                index = num;
            else
                index--;

            break;
        }
        case DOWN: {
            if (index == num)
                index = 1;
            else
                index++;
            break;
        }
        }
        resetDisplay(93, 14, 1, (num + 1) * 2);

    } while (value != ENTER);

    return index;
}
