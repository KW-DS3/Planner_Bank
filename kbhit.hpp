#ifndef __KBHIT_HPP__
#define __KBHIT_HPP__

#include <stdio.h>
#include <termios.h>
#include <unistd.h>

#define ENTER 10
#define UP 65
#define DOWN 66
#define RIGHT 67
#define LEFT 68

int kbhit(void);

#endif
