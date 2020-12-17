#ifndef __DISPLAY_HPP__
#define __DISPLAY_HPP__

#include "kbhit.hpp"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <vector>

const std::string BEGIN = "\033[1;";
const std::string END = "\033[0m";
#define BLCK 30
#define RED 31
#define GREN 32
#define YLLW 33
#define BLUE 34
#define MGNT 35
#define CYAN 36
#define WHTE 37
#define FG 10
#define BG 11

void gotoxy(int x, int y);
void reset();

void print(int location, int color, std::string text);
void printWithBg(int fgColor, int bgColor, std::string text);

void resetDisplay();
void resetDisplay(int x, int y, int width, int height);

int dayNumber(int day, int month, int year);
std::string getMonthName(int monthNumber);
int numberOfDays(int monthNumber, int year);

void printCalendar(int year, int month, int date,
                   int mode); // mode : 0 - ledger, 1 - planner

void loginDisplay();
int chooseLogin();
void CURSOR_SIGNIN();
void CURSOR_SIGNUP();

int chooseMenu();
void firstMenu();
void firstMenuLedger();
void firstMenuPlanner();

int choosePlannerMenu(int year, int month, int date);
int chooseLedgerMenu();

int chooseEvent(int year, int month, int date);
#endif
