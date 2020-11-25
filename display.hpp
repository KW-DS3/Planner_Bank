#ifndef __DISPLAY_H__
#define __DISPLAY_H__

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <vector>

#define begin "\033[1;"
#define end "\033[0m"
#define blck 30
#define red 31
#define gren 32
#define yllw 33
#define blue 34
#define mgnt 35
#define cyan 36
#define whte 37
#define fg 10
#define bg 11
#define reset gotoxy(0, 0)

void gotoxy(int x, int y);

void print(int location, int color, std::string text);
void printWithBg(int fgColor, int bgColor, std::string text);

void resetDisplay();

int dayNumber(int day, int month, int year);
std::string getMonthName(int monthNumber);
int numberOfDays(int monthNumber, int year);

void printCalendar(int year, int month);

int chooseMenu();
void firstMenu();
void firstMenuLedger();
void firstMenuPlanner();
void plannerMenu();

void setRatio(std::vector<int> &ratio, const std::vector<int> money);

int getLongestLength(std::vector<std::string> categories);
int getMaxPercentage(const std::vector<int> ratio);

void printRatio(std::vector<std::string> categories, std::vector<int> money);

#endif
