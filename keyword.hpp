#ifndef __KEYWORD_H__
#define __KEYWORD_H__

#include <iostream>
#include <map>
#include <set>
#include <unordered_map>
#include <vector>

using namespace std;

class Keyword {
  public:
    void setkw(string title, string keyword);
    void findkw(string title, string keyword);
    void modifykw(string title, string keyword);
    void deletekw(string title, string keyword);
    void printkw(string title, string keyword);

  private:
    string title;
    string kw; // keyword
    map<string, vector<string>> kwMap;
    map<string, vector<string>>::iterator iter;
};

#endif //__KEYWORD_H__
