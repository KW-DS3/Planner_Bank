#include <list>
#include "RECODE.hpp"
#include "DAY.hpp"

using namespace std;

class DAY
{
public:
	DAY();
	DAY(int input_date);
	int getDate();
	RECODE& getIncomeList();
	RECODE& getExpenseList();

private:
	int date;
	list<RECODE> incomeList;
	list<RECODE> expenseList;
};

DAY:: DAY()
{

}

DAY::DAY(int input_date)
{
	date = input_date;
}

int DAY::getDate()
{
	return this->date;
}

RECODE& DAY::getIncomeList()
{
	return incomeList.front();
}

RECODE& DAY::getExpenseList()
{
	return expenseList.front();
}