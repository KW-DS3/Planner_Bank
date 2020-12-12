#ifndef __RECODE_H__
#define __RECODE_H__

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

#endif


