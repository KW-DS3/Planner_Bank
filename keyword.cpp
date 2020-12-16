#include "keyword.hpp"
#include "display.hpp"
#include <dirent.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

void Keyword::init() {
    int fd;
    DIR *dir_info;
    struct dirent *dir_entry;
    struct stat fileInfo;
    string pathname = "./";
    dir_info = opendir(pathname.c_str());
    char buf[2];
    int index = 0;
    ssize_t rSize = 0;
    vector<string> keys(2);

    if (NULL != dir_info) {
        while (dir_entry = readdir(dir_info)) {
            stat(dir_entry->d_name, &fileInfo);
            if (S_ISDIR(fileInfo.st_mode) && ('.' != dir_entry->d_name[0])) {
                string compelet =
                    pathname + dir_entry->d_name + "/complete.txt";
                string incompelet =
                    pathname + dir_entry->d_name + "/incomplete.txt";

                fd = open(compelet.c_str(), O_RDONLY);
                if (fd > 0) {
                    do {
                        memset(buf, '\0', 2); // initialize buf '\0'
                        if ((rSize = read(fd, buf, 1)) < 0) {
                            perror("read() error!");
                            exit(-3);
                        }

                        if (strcmp(buf, "#") == 0) {
                            index = 1;
                            keys[index] += "#";
                        } else if (strcmp(buf, "\n") != 0) {
                            keys[index] += buf;
                        } else {
                            if (index == 1) {
                                setkw(keys, dir_entry->d_name);
                            }
                            keys[0] = "";
                            keys[1] = "";
                            index = 0;
                        }
                    } while (rSize > 0);
                    close(fd);
                }

                fd = open(incompelet.c_str(), O_RDONLY);
                if (fd > 0) {
                    do {
                        memset(buf, '\0', 2); // initialize buf '\0'
                        if ((rSize = read(fd, buf, 1)) < 0) {
                            perror("read() error!");
                            exit(-3);
                        }

                        if (strcmp(buf, "#") == 0) {
                            index = 1;
                            keys[index] += "#";
                        } else if (strcmp(buf, "\n") != 0) {
                            keys[index] += buf;
                        } else {
                            if (index == 1) {
                                setkw(keys, dir_entry->d_name);
                            }
                            keys[0] = "";
                            keys[1] = "";
                            index = 0;
                        }
                    } while (rSize > 0);
                    close(fd);
                }
            }
        }
        closedir(dir_info);
    }
}

void Keyword::setkw(vector<string> keyword,
                    string dirname) { // keyword : [0]-todo, [1]-key
    vector<vector<string>> vec;
    vector<string> key;
    vector<string> val = {dirname, keyword[0]}; // {date,todo}
    vector<string>::iterator it;
    int index = 1;
    int bindex = 1;
    string temp;

    while (1) {

        temp = keyword[1][index];
        if (temp == "#") {
            key.push_back(keyword[1].substr(bindex, index - bindex));

            bindex = index + 1;
        }

        index++;
        if (index == keyword[1].length()) {
            key.push_back(keyword[1].substr(bindex, index - bindex + 1));

            break;
        }
    }
    for (it = key.begin(); it != key.end(); it++) { // keywords
        vec = kwMap[*it];
        vec.push_back(val);
        kwMap[*it] = vec;
    }
}

void Keyword::findkw(string keyword) {
    map<string, vector<vector<string>>>::iterator it;

    resetDisplay(97, 7, 32, 5);

    it = kwMap.find(keyword);
    if (it == kwMap.end()) {
        gotoxy(120, 10);
        cout << "no exist" << endl;
        return;
    } else {
        cout << it->second.size();

        for (int i = 0; i < it->second.size(); i++) {
            gotoxy(98, 8 + i);
            cout << it->second[i][0] << "-" << it->second[i][1] << endl;
        }
    }
}

void Keyword::allShow() {
    int y = 8;
    map<string, vector<vector<string>>>::iterator it = kwMap.begin();

    for (int i = 0; it != kwMap.end(); it++, i++) {
        gotoxy(98, y++);
        cout << it->first << endl;
        for (int j = 0; j < it->second.size(); j++) {
            gotoxy(98, y++);
            cout << it->second[j][0] << "-" << it->second[j][1] << endl;
        }
    }
    kbhit();
}
