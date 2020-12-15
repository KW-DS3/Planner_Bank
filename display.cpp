#include "display.hpp"
#include "kbhit.h"
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
    if (location == fg) {
        cout << BEGIN << color << "m";
        cout << text << END;
    } else if (location == bg) {

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

    for (int i = 0; i < 40; i++) {
        for (int j = 0; j < 130; j++) {
            print(bg, blck, " ");
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
            print(bg, blck, " ");
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
    switch (monthNumber) {
    case 1:
        return (31);
        break;
    case 2:
        if (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0))
            return (29);
        else
            return (28);
        break;
    case 3:
        return (31);
        break;
    case 4:
        return (30);
        break;
    case 5:
        return (31);
        break;
    case 6:
        return (30);
        break;
    case 7:
        return (31);
        break;
    case 8:
        return (31);
        break;
    case 9:
        return (30);
        break;
    case 10:
        return (31);
        break;
    case 11:
        return (30);
        break;
    case 12:
        return (31);
        break;
    }
}

// print calendar for that month
void printCalendar(int year, int month, int date) {
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

        if (j < 10) {
            if (date == j) {
                printWithBg(whte, blck, "          ");
                // cout << "\033[4;" << whte << ";" << blck + 10 << "m"
                //      << to_string(j) << end;
                printWithBg(blue, blck, to_string(j));
            } else
                printWithBg(whte, blck, "          " + to_string(j));

        } else {
            if (date == j) {
                printWithBg(whte, blck, "         ");
                printWithBg(blue, blck, to_string(j));

            } else
                printWithBg(whte, blck, "         " + to_string(j));
        }

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
            updown = 0;
            if (menu == 0)
                menu = 4;
            else
                menu--;
            break;
        }
        case RIGHT: {
            updown = 0;
            if (menu == 4)
                menu = 0;
            else
                menu++;
            break;
        }
        case UP: {
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
            printWithBg(whte, blck, ">");
        }

    } while (value != ENTER || updown == 1);

    return menu;
}
int chooseEvent(int year, int month, int date) {
    int value;
    int index = 1;
    int num = numOfEvents(year, month, date);
    do {
        gotoxy(93, 14 + 2 * index);
        printWithBg(whte, blck, ">");
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
