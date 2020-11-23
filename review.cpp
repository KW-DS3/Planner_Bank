#include <iostream>
using namespace std;

template <class C>
//C: category's C

//gap: last month - this month
void review(const C Cname, const int gap) {
    switch(Cname) {
        case 'a':
            if (gap < 0) cout << "Wow great" << endl;
            if else(0<gap<=10000) cout << "try a little more" << endl;
            if else(10000 < gap <= 30000) cout << "Oops!" << endl;
            else cout << "Oh my god....."<< endl;
        case 'b':
        case 'c':
        case 'd':
        case 'e':
        default:
            cout << "Invalid category name entered review()." << endl;
            return -1;
    }
}