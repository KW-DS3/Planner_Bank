#include "ledger.hpp"
#include <string.h>
#include <vector>

using namespace std;

int getLongestLength(vector<string> categories) {
    int max = 0;
    for (int i = 0; i < categories.size(); i++) {
        if (max < categories[i].length()) {
            max = categories[i].length();
        }
    }
    return max;
}

// function for scaling
void setRatio(vector<int> &ratio, const vector<int> money) {
    int max = 0;
    int sum = 0;

    for (int i = 0; i < money.size(); i++) {
        sum += money[i];

        if (max < money[i])
            max = money[i];
    }
    int maxPercentage = max * 100 / sum;

    for (int i = 0; i < money.size(); i++) {
        ratio.push_back(money[i] * 100 / sum);
    }
}

// function for scaling
int getMaxPercentage(const vector<int> ratio) {
    int maxPercentage;

    for (int i = 0; i < ratio.size(); i++) {
        if (maxPercentage < ratio[i])
            maxPercentage = ratio[i];
    }
    return maxPercentage;
}

// print the ratio of money spent in the month
void printRatio(vector<string> categories, vector<int> money) {
    resetDisplay();
    //일단
    categories.push_back("옷");
    categories.push_back("식비");
    categories.push_back("생필품");
    categories.push_back("책");
    categories.push_back("카페");

    money.push_back(10000);
    money.push_back(30000);
    money.push_back(10000);
    money.push_back(5000);
    money.push_back(3000);

    //예시로 담아봄

    int x = 40;
    int y = 10;
    int sum = 0;
    int maxLength = getLongestLength(categories);

    vector<int> ratio;
    setRatio(ratio, money);

    int maxPercentage = getMaxPercentage(ratio);

    for (int i = 0; i < categories.size(); i++) {
        gotoxy(x, y);

        for (int j = 0; j < (maxLength - categories[i].length()) / 3; j++) {
            print(BG, BLCK, "  ");
        }
        printWithBg(WHTE, BLCK, categories[i]);
        printWithBg(WHTE, BLCK, " |  ");

        for (int j = 0; j < ratio[i] * 50 / maxPercentage; j++) {
            print(BG, BLUE, " ");
        }
        gotoxy(x + 61, y);
        printWithBg(WHTE, BLCK, '(' + to_string(ratio[i]) + "%) ");
        y += 2;
    }
}
