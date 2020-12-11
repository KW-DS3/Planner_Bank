#include <cstring>
#include <fcntl.h>
#include <iostream>
#include <pwd.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <unistd.h>

#define PERMS 0755

using namespace std;

struct userdata {
    string id;
    string pw;
    string checkid;
    string checkpw;
    string cwd;
};

int main(void) {
    userdata user;
    int menu = 0;

    cout << "1. SIGNIN" << endl;
    cout << "2. LOGIN" << endl;
    cin >> menu;

    if (menu == 1) {
        while (1) {
            cout << "ID : ";
            cin >> user.id;

            if (mkdir("userdata", PERMS) == -1) {
                chdir("userdata");
            } else {
                mkdir("userdata", PERMS);
                chdir("userdata");
            }

            if (access(user.id.c_str(), F_OK) == -1) {
                mkdir(user.id.c_str(), PERMS);
                chdir(user.id.c_str());
                cout << "You can use this ID!" << endl;
                cout << "PW : ";
                cin >> user.pw;
                int fd = open(user.pw.c_str(), O_CREAT | O_WRONLY, PERMS);
                close(fd);
                cout << "signin clear!";
                chdir("..");
                chdir("..");
                break;
            } else {
                cout << "ID is already" << endl;
                chdir("..");
            }
        }
    } else if (menu == 2) {
        while (1) {
            cout << "ID : ";
            cin >> user.checkid;
            cout << "PW : ";
            cin >> user.checkpw;
            chdir("userdata");
            if (access(user.checkid.c_str(), F_OK) == 0) {
                chdir(user.checkid.c_str());
                if (access(user.checkpw.c_str(), F_OK) == 0) {
                    cout << "LOGIN SUCCESS!!" << endl;
                    chdir("..");
                    chdir("..");
                    break;
                } else {
                    cout << "LOGIN FAILED!" << endl;
                    chdir("..");
                }
            } else {
                cout << "LOGIN FAILED!" << endl;
            }
        }
    }
}
