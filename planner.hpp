#ifndef __PLANNNER_H__
#define __PLANNER_H__

#include <iostream>
#include <string>

#define PERMS 0666
#define MAX_BUF_SIZE 256

typedef struct __todo {
    std::string category;
    std::string todo;
} Todo;

bool is_stringEmpty(char *buf);

void createEvent(int year, int month, int date, Todo event);
void deleteEvent(int index);
void printList(int year, int month, int date);

void plannerMenu();

bool hasEventsTodo(int year, int month, int date);
void printNothingToDo();

#endif
