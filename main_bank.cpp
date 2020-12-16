#include "bank.hpp"
#include "bank_function.hpp"
#include <iostream>
#include <string>

using namespace std;

int main(int argc, char *argv[]) {
    int userSelect = 0;
    int year, month, day;

    cout << "Please select the function you want." << endl;
    cout << "1. Add Income/Expense" << endl;
    cout << "2. Delete Income/Expense" << endl;
    cout << "3. Check Income/Expense" << endl;
    cout << "Your Choice: ";
    cin >> userSelect;

    cout << "Please enter a date to select(ex. 2020 12 16): ";
    cin >> year >> month >> day;
    date newDate(year, month, day);

    switch (userSelect) {
    case 1:
        addBank(newDate);
        break;
    case 2:
        delBank(newDate);
        break;
    case 3:
        checkBank(newDate);
        break;
    default:
        cout << "Wrong number! please try again." << endl;
        break;
    }

    return 0;
}
