#ifndef __KEYWORD_HPP__
#define __KEYWORD_HPP__

#include <iostream>
#include <map>
#include <set>
#include <unordered_map>
#include <vector>

using namespace std;

class Keyword {
  public:
    void init();
    void setkw(vector<string> keyword, string dirname);
    void findkw();
    void allShow();

  private:
    map<string, vector<vector<string>>> kwMap;
    string keyword;
};

#endif //__KEYWORD_HPP__
