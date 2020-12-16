#ifndef __KEYWORD_HPP__
#define __KEYWORD_HPP__

#include "planner.hpp"
#include <map>
#include <set>
#include <unordered_map>

using namespace std;

map<string, vector<vector<string>>> kwMap;
map<string, vector<string>>::iterator iter;


void setkw(vector<string> keyword, string dirname);
void findkw(string keyword);
void printkw(string title);


#endif //__KEYWORD_HPP__
