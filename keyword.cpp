#include "keyword.hpp"

void setkw(vector<string> keyword, string dirname){
    vector<vector<string>>vec0;
    vector<string>vec1;     //date(dirname)
    vector<string>vec2;     //todo

    vec1.push_back(dirname);
    vec2.push_back(keyword[0]);
    vec0.push_back(vec1);
    vec0.push_back(vec2);

    for(int i=1;i<keyword.size();i++)
        kwMap.insert(make_pair(keyword[i], vec0));
}

void findkw(string keyword){
    if(kwMap.find(keyword)==kwMap.end()) {
        cout<<"no exist"<<endl;
    } else {
        //
    }
}