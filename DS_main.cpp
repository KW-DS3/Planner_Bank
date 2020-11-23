#include "kbhit.h"
#include <iostream>
#include <stdio.h>

using namespace std;

int main(void) {
    int previous_keystroke = 0;

    printf("\n");
    printf("Type any key to see the return ASCII int of the key pressed.\n");
    printf("The program will start in 1sec. Press <Esc> to quit...\n\n");
    sleep(1);

    while (1) {
        int value = kbhit();

        // key stroke detected
        if (value != -1) {
            // printing of key integer value
            printf("%d\n", value);
        }

        // detection of <Esc> key.    # of integer value set:    1
        //                            integer value:            27
        if ((previous_keystroke == 27) && (value == -1))
            break;
        previous_keystroke = value;

        // printing of '.'s to prove non-blocking of kbhit()
        printf(".");
    }

    printf("\n");
    printf("<Esc> key pressed. Bye bye\n\n");

    return 0;
}
