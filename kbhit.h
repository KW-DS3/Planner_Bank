#ifndef __KBHIT_H__
#define __KBHIT_H__

#include <stdio.h>
#include <termios.h>
#include <unistd.h>

#define ENTER 10
#define UP 65
#define DOWN 66
#define RIGHT 67
#define LEFT 68

int kbhit(void) {
    struct termios oldt, newt;
    int ch;

    tcgetattr(STDIN_FILENO, &oldt);
    newt = oldt;

    newt.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);

    ch = getchar();

    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);

    return ch;
}

#endif
