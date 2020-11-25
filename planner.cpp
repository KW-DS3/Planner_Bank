#include "planner.hpp"
#include "display.hpp"

#include <cstring>
#include <fcntl.h>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <vector>

#define PERMS 0666
#define MAX_BUF_SIZE 256

using namespace std;

void createEvent(int year, int month, int date, Todo event) {
    int fd;
    string pathname = to_string(year) + to_string(month) + to_string(date);
    string todo = "";

    char buf[MAX_BUF_SIZE + 1] = {
        '\0',
    };

    if ((fd = open(pathname.c_str(), O_RDWR | O_CREAT | O_APPEND, PERMS)) < 0) {
        perror("open() error!");
        exit(-1);
    }
    memset(buf, '\0', MAX_BUF_SIZE);
    cin >> buf;

    if ((write(fd, buf, MAX_BUF_SIZE)) < 0) {
        perror("write() error!");
        exit(-2);
    }
    close(fd);
}

bool is_stringEmpty(char *buf) {
    for (int i = 0; i < MAX_BUF_SIZE; i++) {
        if (buf[i] == '\0')
            return false;
    }
}

void deleteEvent(int index) {
    int fd, fd1;

    //아이디 디렉토리/날짜.txt
    string pathname = "./temp.txt";
    string pathname1 = "./temp1.txt";
    ssize_t rSize = 0;
    char *buf = (char *)malloc(MAX_BUF_SIZE);

    if ((fd = open(pathname.c_str(), O_RDWR, PERMS)) < 0 ||
        (fd1 = open(pathname1.c_str(), O_RDWR | O_CREAT, PERMS)) < 0) {
        perror("open() error!");
        exit(-1);
    }
    lseek(fd, MAX_BUF_SIZE * (index - 1), SEEK_SET);
    memset(buf, '\0', MAX_BUF_SIZE);

    if ((write(fd, buf, MAX_BUF_SIZE)) < 0) {
        perror("write() error!");
        exit(-2);
    }

    lseek(fd, 0, SEEK_SET);
    do {
        memset(buf, '\0', MAX_BUF_SIZE);
        if ((rSize = read(fd, buf, MAX_BUF_SIZE)) < 0) {
            perror("read() error!");
            exit(-3);
        }

        if (is_stringEmpty(buf) && rSize > 0) {
            continue;
        }

        if ((write(fd1, buf, MAX_BUF_SIZE)) < 0) {
            perror("write() error!");
            exit(-2);
        }

    } while (rSize > 0);
    close(fd);
    close(fd1);
    remove(pathname.c_str());
    rename(pathname1.c_str(), pathname.c_str());
}
void printList(int year, int month, int date) {
    int fd;
    string pathname = to_string(year) + to_string(month) + to_string(date);
    ssize_t rSize = 0;
    int y = 13;
    char *buf = (char *)malloc(MAX_BUF_SIZE);

    if ((fd = open(pathname.c_str(), O_RDONLY, PERMS)) < 0) {
        perror("open() error!");
        exit(-1);
    }
    gotoxy(102, y);
    y += 2;
    printWithBg(blue, blck, "[ TO-DO LIST ]");

    do {
        memset(buf, '\0', MAX_BUF_SIZE);
        if ((rSize = read(fd, buf, MAX_BUF_SIZE)) < 0) {
            perror("read() error!");
            exit(-3);
        }
        if (rSize < 1)
            break;
        gotoxy(95, y);
        y += 2;
        printWithBg(whte, blck, "□  ");
        printWithBg(whte, blck, buf);

    } while (rSize > 0);

    close(fd);
}

void plannerMenu() {
    // resetDisplay();
    gotoxy(94, 7);
    printWithBg(blue, blck, "> 추가");
    gotoxy(104, 7);
    printWithBg(whte, blck, "  삭제");
    gotoxy(114, 7);
    printWithBg(whte, blck, "  완료");
}

bool hasEventsTodo(int year, int month, int date) {
    string pathname = to_string(year) + to_string(month) + to_string(date);

    if (access(pathname.c_str(), F_OK) < 0) {
        return 0;
    }
    return 1;
}

void printNothingToDo() {
    gotoxy(102, 14);
    printWithBg(blue, blck, "[ TO-DO LIST ]");
    gotoxy(103, 16);
    printWithBg(whte, blck, "nothing to do");
}
