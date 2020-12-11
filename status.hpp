#ifndef __STATUS_H__
#define __STATUS_H__

#include <iostream>
#include <vector>
using namespace std;

typedef struct __list {
    string category;
    int last;
    int pre;
} List;

class Confirm {
public:
    void setCateList(const string category, const int last, const int pre);
    void setCheck();
    void setCnum(int cnum);
    void message();
    int save();
    void setScreen();

private:
    List list;
    vector<List> CateList;
    int cnum;       // number of category
    int mlen;       // length of message
    int check;      // all catetory save/over check
};

#endif