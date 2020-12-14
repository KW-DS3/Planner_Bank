#include "keyword.hpp"

void Keyword::setkw(string title, string kw){
    vector<string> kwVector;
    this->title=title;
    this->kw=kw;
    kwVector.push_back(kw);
    kwMap.insert(make_pair(title, kwVector));
}

void Keyword::findkw(string title, string kw){

}

void Keyword::modifykw(string title, string kw){
    
}

void Keyword::deletekw(string title, string kw){
    
}

void Keyword::printkw(string title, string kw){
    if(kwMap.find(title) == kwMap.end())
        cout<<"no exist"<<endl;
    else{
            
    }
    
}