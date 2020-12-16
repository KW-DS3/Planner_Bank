#ifndef __KEYWORD_HPP__
#define __KEYWORD_HPP__

#include <iostream>
#include <map>
#include <set>
#include <unordered_map>
#include <vector>

using namespace std;

string title;
map<string, vector<vector<string>>> kwMap;
map<string, vector<string>>::iterator iter;


void setkw(string keyword, string dirname, string todo);
void findkw(string title);
void deletekw(string title);
void printkw(string title);


#endif //__KEYWORD_HPP__
