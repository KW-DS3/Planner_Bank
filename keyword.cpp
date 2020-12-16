#include "keyword.hpp"
#include "display.hpp"
#include <dirent.h>
#include <sys/stat.h>
#include <sys/types.h> 
#include <unistd.h>
#include <fcntl.h>

Keyword::Keyword() {
    int fd;
    DIR *dir_info;
    DIR *user_dir_info;
    struct dirent *dir_entry;
    struct stat fileInfo;
    string pathname ="./userdata/username/" ;
    string txtfile = "incomplete.txt";
    dir_info=opendir(pathname.c_str());

    if(NULL!=dir_info) {
        while(dir_entry=readdir(dir_info)) {
            stat(dir_entry->d_name, &fileInfo);
            if(S_ISDIR(fileInfo.st_mode)&& ('.'!=dir_entry->d_name[0])) {
                string compelet = pathname + dir_entry->d_name + "complete.txt";
                string incomplet = pathname + dir_entry->d_name + "incomplete.txt";
                int fd1 = open(compelet.c_str(), O_RDWR | O_CREAT, 0755);
            }
        }
        closedir(dir_info);
    }
}

void Keyword::setkw(vector<string> keyword, string dirname)
{
    vector<vector<string>> vec;

    vector<string> val = {dirname,keyword[0]};

    for (int i = 1; i < keyword.size(); i++){ //keywords
        vec = kwMap[keyword[i]];
        vec.push_back(val);
        kwMap[keyword[i]] = vec;
    }
}

void Keyword::findkw(string keyword)
{
    map<string, vector<vector<string>>>::iterator it;

    resetDisplay(97, 7, 32, 5);
    
    it = kwMap.find(keyword);
    if (it == kwMap.end())
    {
        gotoxy(120, 10);
        cout << "no exist" << endl;
        return;
    }
    else
    {
        cout << it->second.size();

        for (int i = 0; i < it->second.size(); i++)
        {
                gotoxy(98, 8 + i);
                cout << it->second[i][0] << "-" <<it->second[i][1] << endl;
        }
    }
}