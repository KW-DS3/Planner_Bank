#include "keyword.hpp"

void setkw(string keyword, string dirname, string todo){
    vector<vector<string>>vec0;
    vector<string>vec1;     //date(dirname)
    vector<string>vec2;     //todo

    vec1.push_back(dirname);
    vec2.push_back(todo);
    vec0.push_back(vec1);
    vec0.push_back(vec2);

    kwMap.insert(make_pair(keyword, vec0));
}

void findkw(string pathname){

}

void deletekw(string pathname){
    
}

void printkw(string pathname){
    if(kwMap.find(title) == kwMap.end())
        cout<<"no exist"<<endl;
    else{
            
    }
    
}