#include "login.hpp"

using namespace std;

void signup() {
    string id;
    string pw;
    int value;
    while (1) {
        loginDisplay();
        gotoxy(51, 30);
        cin >> id;

        if (mkdir("userdata", PERMS) == -1) {
            chdir("userdata");
        } else {
            mkdir("userdata", PERMS);
            chdir("userdata");
        }

        if (access(id.c_str(), F_OK) == -1) {
            mkdir(id.c_str(), PERMS);
            chdir(id.c_str());
            gotoxy(47, 34);
            printWithBg(WHTE, BLCK, "You can use this ID!");
            gotoxy(51, 32);
            cin >> pw;
            int fd = open(pw.c_str(), O_CREAT | O_WRONLY, PERMS);
            close(fd);
            // mkdir(pw.c_str(), PERMS);
            gotoxy(47, 34);
            printWithBg(WHTE, BLCK, "signin clear! (for next ENTER)");
            kbhit();
            while (kbhit() != ENTER)
                ;
            chdir("..");
            chdir("..");
            break;
        } else {
            gotoxy(47, 34);
            printWithBg(WHTE, BLCK, "ID is already (for next ENTER)");
            kbhit();
            while (kbhit() != ENTER)
                ;
            chdir("..");
        }
    }
}
void signin() {
    string checkid;
    string checkpw;
    while (1) {
        loginDisplay();
        gotoxy(51, 30);
        cin >> checkid;
        gotoxy(51, 32);
        cin >> checkpw;
        chdir("userdata");
        if (access(checkid.c_str(), F_OK) == 0) {
            chdir(checkid.c_str());
            if (access(checkpw.c_str(), F_OK) == 0) {
                gotoxy(47, 34);
                printWithBg(WHTE, BLCK, "LOGIN SUCCESS!! (for next ENTER)");
                kbhit();
                while (kbhit() != ENTER)
                    ;
                // chdir("..");
                // chdir("..");
                break;
            } else {
                gotoxy(47, 34);
                printWithBg(WHTE, BLCK, "LOGIN FAILED! (for next ENTER)");
                kbhit();
                while (kbhit() != ENTER)
                    ;
                chdir("..");
            }
        } else {
            gotoxy(47, 34);
            printWithBg(WHTE, BLCK, "LOGIN FAILED! (for next ENTER)");
            kbhit();
            while (kbhit() != ENTER)
                ;
        }
    }
}
