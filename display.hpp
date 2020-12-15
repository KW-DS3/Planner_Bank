#ifndef __DISPLAY_H__
#define __DISPLAY_H__

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <vector>

const std::string BEGIN = "\033[1;";
const std::string END = "\033[0m";
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

void gotoxy(int x, int y);
void reset();

void print(int location, int color, std::string text);
void printWithBg(int fgColor, int bgColor, std::string text);

void resetDisplay();
void resetDisplay(int x, int y, int width, int height);

int dayNumber(int day, int month, int year);
std::string getMonthName(int monthNumber);
int numberOfDays(int monthNumber, int year);

void printCalendar(int year, int month, int date);

int chooseMenu();
void firstMenu();
void firstMenuLedger();
void firstMenuPlanner();

int choosePlannerMenu(int year, int month, int date);

int chooseEvent(int year, int month, int date);
#endif
