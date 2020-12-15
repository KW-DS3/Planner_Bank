#ifndef __LEDGER_HPP__
#define __LEDGER_HPP__

#include "display.hpp"
#include <string>
#include <vector>

using namespace std;

int getLongestLength(vector<string> categories);

// function for scaling
void setRatio(vector<int> &ratio, const vector<int> money);

// function for scaling
int getMaxPercentage(const vector<int> ratio);

// print the ratio of money spent in the month
void printRatio(vector<string> categories, vector<int> money);
#endif
