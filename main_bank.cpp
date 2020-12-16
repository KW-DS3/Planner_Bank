#include "bank.hpp"
#include "bank_function.hpp"
#include <iostream>
#include <string>

using namespace std;

int main(int argc, char *argv[]) {
    date newDate(2020, 12, 26); //for test
    addBank(newDate);

    return 0;
}
