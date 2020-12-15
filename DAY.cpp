#include "DAY.hpp"
#include "RECODE.hpp"
#include <list>

using namespace std;

DAY::DAY() {}

DAY::DAY(int input_date) { date = input_date; }

int DAY::getDate() { return this->date; }

RECODE &DAY::getIncomeList() { return incomeList.front(); }

RECODE &DAY::getExpenseList() { return expenseList.front(); }
