#include "bank.hpp"
#include "bank_function.hpp"
#include "display.hpp"
#include "login.hpp"
#include "planner.hpp"

#include <iostream>
#include <stdio.h>
#include <time.h>
#include <unistd.h>

using namespace std;

int main(void) {
    int previous_keystroke = 0, menu, log_sign, index = 0;
    const int LEDGER = 0;
    const int PLANNER = 1;
    const int SIGNIN = 0;
    const int SIGNUP = 1;

    // get current date
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    int day = tm.tm_mday;
    int month = tm.tm_mon + 1;
    int year = tm.tm_year + 1900;
    Todo todo;
    Keyword keyword;
    Date date(year, month, day);
    int value;

    while (1) {
        log_sign = chooseLogin();
        if (log_sign == SIGNIN) {
            signin();

            while (1) {
                menu = chooseMenu();
                if (menu == LEDGER) {
                    if (mkdir("LEDGER", PERMS) == -1) {
                        chdir("LEDGER");
                    } else {
                        mkdir("LEDGER", PERMS);
                        chdir("LEDGER");
                    }
                    /* LEDGER */
                    keyword.init();
                    while (1) {
                        printCalendar(year, month, day, 0);
                        menu = chooseLedgerMenu();
                        switch (menu) {
                        case ADD:
                            addBank(date);
                            break;
                        case DEL:
                            delBank(date);
                            break;
                        case CHECK:
                            checkBank(date);
                            cin.ignore();
                            while (kbhit() != ENTER)
                                ;
                            break;
                        case DATE:
                            date.setDate(&year, &month, &day);
                            break;
                        case PRE:
                            chdir("..");
                            goto END1;
                            break;
                        case KEY:
                            break;
                        }
                    }
                END1:;
                } else if (menu == PLANNER) {
                    if (mkdir("PLANNER", PERMS) == -1) {
                        chdir("PLANNER");
                    } else {
                        mkdir("PLANNER", PERMS);
                        chdir("PLANNER");
                    }
                    keyword.init();
                    while (1) {
                        printCalendar(year, month, day, 1);
                        printList(year, month, day);
                        menu = choosePlannerMenu(year, month, day);
                        switch (menu) {
                        case CREATE:
                            todo.createEvent(keyword);
                            break;
                        case DELETE:
                            index = chooseEvent(year, month, day);
                            deleteEvent(year, month, day, index);
                            break;
                        case GOTODATE:
                            gotoDate(&year, &month, &day);
                            break;
                        case PREVIOUS:
                            chdir("..");
                            goto END2;
                            break;
                        case KEYWORD:
                            keyword.findkw();
                            break;
                        }
                    }
                END2:;
                }
            }
        } else if (log_sign == SIGNUP) {
            signup();
        }
    }

    return 0;
}
