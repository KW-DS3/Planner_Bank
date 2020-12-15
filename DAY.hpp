#ifndef __DAY_H__
#define __DAY_H__

#include "RECODE.hpp"
#include <list>

using namespace std;

class DAY {
  public:
    DAY();
    DAY(int input_date);
    int getDate();
    RECODE &getIncomeList();
    RECODE &getExpenseList();

  private:
    int date;
    list<RECODE> incomeList;
    list<RECODE> expenseList;
};

#endif
