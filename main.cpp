#include "display.hpp"
//#include "kbhit.h"
#include "planner.hpp"
#include <iostream>
#include <stdio.h>
#include <time.h>
#include <unistd.h>

using namespace std;

int main(void) {
    int previous_keystroke = 0;
    const int LEDGER = 0;
    const int PLANNER = 1;

    // get current date
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    const int DATE = tm.tm_mday;
    const int MONTH = tm.tm_mon + 1;
    const int YEAR = tm.tm_year + 1900;

    int value;

    // printf("\n");
    // printf("Type any key to see the return ASCII int of the key pressed.\n");
    // printf("The program will start in 1sec. Press <Esc> to quit...\n\n");
    sleep(1);

    int menu = chooseMenu();
    printCalendar(YEAR, MONTH);
    if (menu == LEDGER) {

        /* 가계부 */

    } else if (menu == PLANNER) {

        if (hasEventsTodo(YEAR, MONTH, DATE)) {
            printList(YEAR, MONTH, DATE);
        } else {
            printNothingToDo();
        }
        plannerMenu();
    }

    // key stroke detected
    if (value != -1) {
        // printing of key integer value
        // printf("%d\n", value);
    }

    // detection of <Esc> key.    # of integer value set:    1
    //                            integer value:            27
    if ((previous_keystroke == 27) && (value == -1))
        // break;
        previous_keystroke = value;

    // printing of '.'s to prove non-blocking of kbhit()
    // printf(".");

    // printf("\n");
    // printf("<Esc> key pressed. Bye bye\n\n");

    return 0;
}
