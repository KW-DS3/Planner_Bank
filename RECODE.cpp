#include "RECODE.hpp"

RECODE::RECODE() {}

RECODE::RECODE(int input_amount, char input_check_ie) {
    amount = input_amount;
    check_ie = input_check_ie;
}

int RECODE::getAmount() { return this->amount; }

char RECODE::getCheck_ie() { return this->check_ie; }
