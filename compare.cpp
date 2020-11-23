#include <iostream>
#include <string>
using namespace std;

// Compare profit
void profitCompare(const int lastAll, const int thisAll) {
    // output positioning
    cout << lastAll<<endl;
    // output positioning
    cout << thisAll<<endl;
    // ouput positioning
    if(lastAll < thisAll) cout << "지난 달보다 수입이" << thisAll-lastAll << "원 늘었습니다."<< endl;
    else cout << "지난 달보다 수입이 " << lastAll-thisAll << "원 줄었습니다."<<endl;
}

int main(void) {
    int lastAll = 10000;
    int thisAll = 20050;
    profitCompare(lastAll, thisAll);
    return 0;
}