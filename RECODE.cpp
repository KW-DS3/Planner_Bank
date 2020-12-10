#include "RECODE.hpp"

class RECODE
{
public:
	RECODE();
	RECODE(int input_amount, char input_check_ie);
	int getAmount();
	char getCheck_ie();

private:
	int amount;
	char check_ie;
};

RECODE::RECODE()
{
	
}

RECODE::RECODE(int input_amount, char input_check_ie)
{
	amount = input_amount;
	check_ie = input_check_ie;
}

int RECODE::getAmount()
{
	return this->amount;
}

char RECODE::getCheck_ie()
{
	return this->check_ie;
}