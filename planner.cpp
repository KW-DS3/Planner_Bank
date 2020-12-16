#include "planner.hpp"

#include <cstring>
#include <fcntl.h>
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <vector>

#define INCOMPLETE "incomplete.txt"
#define COMPLETE "complete.txt"

using namespace std;

Todo::Todo() {}
Todo::Todo(int year, int month, int date, string title) {
    when.year = year;
    when.month = month;
    when.date = date;
    this->title = title;
}

int Todo::getDate() { return when.date; }
int Todo::getMonth() { return when.month; }
int Todo::getYear() { return when.year; }
string Todo::getTitle() { return title; }
string Todo::getKeyword() { return keyword;}

void Todo::setDate(int year, int month, int date) {
    when.year = year;
    when.month = month;
    when.date = date;
}
void Todo::setTitle(string title) { this->title = title; }
void Todo::setKeyword(string keyword) { this->keyword = keyword; }

string convert(int date) {
    if (date < 10)
        return '0' + to_string(date);
    else
        return to_string(date);
}

void Todo::inputEvent() {

    while (1) {
        resetDisplay(97, 7, 28, 5);

        gotoxy(97, 7);
        printWithBg(WHTE, BLCK, "date: ");
        cin >> when.year >> when.month >> when.date;
        if (when.month < 0 || when.month > 12 || when.date < 0 ||
            when.date > numberOfDays(when.month, when.year)) {
            continue;
        } else
            break;
    }

    gotoxy(97, 9);
    printWithBg(WHTE, BLCK, "title: ");
    cin >> title;

    gotoxy(97, 11);
    printWithBg(WHTE, BLCK, "keyword: ");
    cin >> keyword;

    setDate(when.year, when.month, when.date);
    setTitle(title);
    setKeyword(keyword);
    cin.ignore();
}

void Todo::createEvent() {
    inputEvent();

    int fd;
    string dirname =
        convert(getYear()) + convert(getMonth()) + convert(getDate());

    string pathname = dirname + "/" + INCOMPLETE;

    if (!checkFileExists(dirname)) {
        if (mkdir(dirname.c_str(), PERMS) < 0) {
            perror("mkdir() error!");
        }
    }

    if ((fd = open(pathname.c_str(), O_RDWR | O_CREAT | O_APPEND, PERMS)) < 0) {
        perror("open() error!");
        exit(-1);
    }

    lseek(fd, SEEK_CUR, -1);
    if (write(fd, (char *)getTitle().c_str(), (int)getTitle().length()) < 0) {
        perror("write() error!");
        exit(-2);
    }
    if (write(fd, (char *)getKeyword().c_str(), (int)getKeyword().length()) < 0) {
        perror("write() error!");
        exit(-2);
    }
    if(write(fd, "\n", 1)<0) {
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

string deleteEvent(int year, int month, int date, int index) {

    if (numOfEvents(year, month, date) == 0) {
        gotoxy(103, 16);
        printWithBg(WHTE, BLUE, "nothing to delete");
        sleep(2);
        return NULL;
    }
    int fd, fd1, num = 1;
    int numOfIncomplete = numOfIncompletEvents(year, month, date);

    string dirname = convert(year) + convert(month) + convert(date);
    string pathname;
    string pathname1 = dirname + '/' + "temp.txt";
    ssize_t rSize = 0;
    string eventToDelete = "";
    string todo = "";
    char buf[2];

    if (numOfIncomplete >= index)
        pathname = dirname + '/' + INCOMPLETE;

    else {
        pathname = dirname + '/' + COMPLETE;
        index -= numOfIncomplete;
    }

    if ((fd = open(pathname.c_str(), O_RDWR | O_CREAT, PERMS)) < 0 ||
        (fd1 = open(pathname1.c_str(), O_RDWR | O_CREAT, PERMS)) < 0) {
        perror("open() error!");
        exit(-1);
    }
    do {
        memset(buf, '\0', 2);
        if ((rSize = read(fd, buf, 1)) < 0) {
            perror("read() error!");
            exit(-3);
        }

        if (rSize < 1)
            break;
        if (strcmp(buf, "\n") == 0) {
            if (num++ == index) {
                eventToDelete = todo;
                todo = "";
                continue;
            }
            if ((write(fd1, todo.c_str(), todo.length())) < 0) {
                perror("write() error!");
                exit(-2);
            }
            if (write(fd1, "\n", 1) < 0) {
                perror("write() error!");
                exit(-2);
            }
            todo = "";
        } else {
            todo += buf;
        }

    } while (rSize > 0);

    close(fd);
    close(fd1);

    remove(pathname.c_str());
    rename(pathname1.c_str(), pathname.c_str());

    return eventToDelete;
}

void printList(int year, int month, int date) {
    int fd, y = 14;
    string dirname = convert(year) + convert(month) + convert(date);
    string pathname = dirname + '/' + INCOMPLETE;
    ssize_t rSize = 0;
    struct stat statBuf;
    resetDisplay(93, 7, 35, 27);

    gotoxy(102, y);
    printWithBg(BLUE, BLCK, "[ TO-DO LIST ]");

    if (!checkFileExists(dirname)) {
        gotoxy(103, 16);
        printWithBg(WHTE, BLCK, "nothing to do");
        return;
    }
    char buf[2];

    if ((fd = open(pathname.c_str(), O_RDONLY, PERMS)) < 0) {   //file open
        perror("open() error!");
        exit(-1);
    }
    string todo;
    
    do {
        memset(buf, '\0', 2);                       //initialize buf '\0'
        if ((rSize = read(fd, buf, 1)) < 0) {
            perror("read() error!");
            exit(-3);
        }
        if (rSize < 1)
            break;

        if (strcmp(buf, "\n") != 0) {
            todo += buf;
        } else {
            y += 2;
            gotoxy(95, y);
            printWithBg(WHTE, BLCK, "! ");
            printWithBg(WHTE, BLCK, todo);
            todo = "";
        }
    } while (rSize > 0);

    close(fd);

    pathname = dirname + '/' + COMPLETE;
    if (!checkFileExists(pathname))
        return;

    if ((fd = open(pathname.c_str(), O_RDONLY, PERMS)) < 0) {
        perror("open() error!");
        exit(-1);
    }

    do {
        memset(buf, '\0', 2);
        if ((rSize = read(fd, buf, 1)) < 0) {
            perror("read() error!");
            exit(-3);
        }
        
        if (rSize < 1)
            break;

        if (strcmp(buf, "\n") != 0) {
            todo += buf;

        } else {
            y += 2;
            gotoxy(95, y);
            printWithBg(WHTE, BLCK, "V ");
            printWithBg(WHTE, BLCK, todo);
            todo = "";
        }

    } while (rSize > 0);

    close(fd);
}

void gotoDate(int *year, int *month, int *date) {
    resetDisplay(97, 7, 28, 3);
    int temp = *date;

    gotoxy(97, 7);
    printWithBg(WHTE, BLCK, "date: ");
    cin >> *year >> *month >> *date;

    printCalendar(*year, *month, *date);
    cin.ignore();
}

void markEvent(int year, int month, int date, int index) {
    int originalIn = numOfIncompletEvents(year, month, date);
    int fd;

    string eventToMark = deleteEvent(year, month, date, index);
    string dirname = convert(year) + convert(month) + convert(date);
    string pathname;

    char *buf = (char *)malloc(MAX_BUF_SIZE);

    if (originalIn >= index)
        pathname = dirname + '/' + COMPLETE;
    else {
        pathname = dirname + '/' + INCOMPLETE;
        index = index - originalIn;
    }

    if ((fd = open(pathname.c_str(), O_RDWR | O_CREAT | O_APPEND, PERMS)) < 0) {
        perror("open() error!");
        exit(-1);
    }

    if ((write(fd, eventToMark.c_str(), MAX_BUF_SIZE)) < 0) {
        perror("write() error!");
        exit(-2);
    }
    close(fd);
    resetDisplay(93, 14, 1, 15);
}

void plannerMenuCreate() {
    resetDisplay(97, 7, 32, 5);
    gotoxy(97, 7);
    printWithBg(BLUE, BLCK, "> Create");
    gotoxy(97, 9);
    printWithBg(WHTE, BLCK, "  Go to date");
    gotoxy(112, 7);
    printWithBg(WHTE, BLCK, "  Delete");
    gotoxy(112, 9);
    printWithBg(WHTE, BLCK, "  Previous");
    gotoxy(97, 11);
    printWithBg(WHTE, BLCK, "  Keyword");
}
void plannerMenuGotoDate() {
    resetDisplay(97, 7, 32, 5);
    gotoxy(97, 7);
    printWithBg(WHTE, BLCK, "  Create");
    gotoxy(97, 9);
    printWithBg(BLUE, BLCK, "> Go to date");
    gotoxy(112, 7);
    printWithBg(WHTE, BLCK, "  Delete");
    gotoxy(112, 9);
    printWithBg(WHTE, BLCK, "  Previous");
    gotoxy(97, 11);
    printWithBg(WHTE, BLCK, "  Keyword");
}
void plannerMenuDelete() {
    resetDisplay(97, 7, 32, 5);
    gotoxy(97, 7);
    printWithBg(WHTE, BLCK, "  Create");
    gotoxy(97, 9);
    printWithBg(WHTE, BLCK, "  Go to date");
    gotoxy(112, 7);
    printWithBg(BLUE, BLCK, "> Delete");
    gotoxy(112, 9);
    printWithBg(WHTE, BLCK, "  Previous");
    gotoxy(97, 11);
    printWithBg(WHTE, BLCK, "  Keyword");
}
void plannerMenuPrevious() {
    resetDisplay(97, 7, 32, 5);
    gotoxy(97, 7);
    printWithBg(WHTE, BLCK, "  Create");
    gotoxy(97, 9);
    printWithBg(WHTE, BLCK, "  Go to date");
    gotoxy(112, 7);
    printWithBg(WHTE, BLCK, "  Delete");
    gotoxy(112, 9);
    printWithBg(BLUE, BLCK, "> Previous");
    gotoxy(97, 11);
    printWithBg(WHTE, BLCK, "  Keyword");
}
void plannerMenuKeyword() {
    resetDisplay(97, 7, 32, 5);

    gotoxy(97, 7);
    printWithBg(WHTE, BLCK, "  Create");
    gotoxy(97, 9);
    printWithBg(WHTE, BLCK, "  Go to date");
    gotoxy(112, 7);
    printWithBg(WHTE, BLCK, "  Delete");
    gotoxy(112, 9);
    printWithBg(WHTE, BLCK, "  Previous");
    gotoxy(97, 11);
    printWithBg(BLUE, BLCK, " > Keyword");
}

int numOfEvents(int year, int month, int date) {
    string dirname = convert(year) + convert(month) + convert(date);
    string pathname = dirname + "/" + INCOMPLETE;
    char buf[2];
    int fd;
    ssize_t rSize = 0;
    int num = 0;

    if (!checkFileExists(dirname)) {
        return 0;
    }
    if ((fd = open(pathname.c_str(), O_RDONLY, PERMS)) < 0) {
        perror("open() error!");
        exit(-1);
    }

    do {
        memset(buf, '\0', 2);
        if ((rSize = read(fd, buf, 1)) < 0) {
            perror("read() error!");
            exit(-3);
        }
        if (rSize < 1)
            break;
        if (strcmp(buf, "\n") == 0)
            num++;
    } while (rSize > 0);

    pathname = dirname + "/" + COMPLETE;
    if (!checkFileExists(pathname)) {
        return num;
    }

    if ((fd = open(pathname.c_str(), O_RDONLY, PERMS)) < 0) {
        perror("open() error!");
        exit(-1);
    }

    do {
        memset(buf, '\0', 2);
        if ((rSize = read(fd, buf, 1)) < 0) {
            perror("read() error!");
            exit(-3);
        }
        if (rSize < 1)
            break;
        if (strcmp(buf, "\n") == 0)
            num++;
    } while (rSize > 0);

    return num;
}
int numOfIncompletEvents(int year, int month, int date) {
    string dirname = convert(year) + convert(month) + convert(date);
    string pathname = dirname + "/" + INCOMPLETE;
    char buf[2];
    int fd;
    ssize_t rSize = 0;
    int num = 0;

    if (!checkFileExists(dirname)) {
        return 0;
    }
    if ((fd = open(pathname.c_str(), O_RDONLY, PERMS)) < 0) {
        perror("open() error!");
        exit(-1);
    }

    do {
        memset(buf, '\0', 2);
        if ((rSize = read(fd, buf, 1)) < 0) {
            perror("read() error!");
            exit(-3);
        }
        if (rSize < 1)
            break;
        if (strcmp(buf, "\n") == 0)
            num++;
    } while (rSize > 0);

    return num;
}

bool checkFileExists(std::string filename) {
    if (access(filename.c_str(), F_OK) < 0) {
        return 0;
    }
    return 1;
}
