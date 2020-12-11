#include "status.hpp"
#include "display.hpp"

void Confirm::setCateList(const string category,const int last, const int pre) {
    list.category = category;
    list.last = last;
    list.pre = pre;
    CateList.push_back(list);
}
void Confirm::setCheck(){check = 0;}
void Confirm::setCnum(int cnum) {this->cnum = cnum;}

int Confirm::save() {
    int num = 0;
    for(int i = 0; i <cnum; i++) {
        num += CateList[i].last - CateList[i].pre;
        if(CateList[i].last < CateList[i].pre) check ++;
        else if(CateList[i].last > CateList[i].pre) check--;
    }
    return num;
}
void Confirm::message() {
    setCheck();

    string str,overCate,saveCate;
    int mostOver, mostSave;
 
    for(int i = 0; i < cnum; i++) {
        if((CateList[i].pre - CateList[i].last) <0) {
            if((CateList[i].pre - CateList[i].last)>mostSave) {
                mostSave = abs(CateList[i].last - CateList[i].pre);
                saveCate = CateList[i].category;
            }
        }
        else{
            if((CateList[i].pre - CateList[i].last)<mostOver) {
                mostOver = abs(CateList[i].last - CateList[i].pre);
                overCate = CateList[i].category;
            }
        }
    }

    if((save() >30000)&&(check == cnum)) str = "모든 부분에서 절약이 있었습니다. 특히 "+saveCate+"에 "+to_string(mostSave)+"원 절약했습니다. 정말 훌륭해요!!";
    else if(300000<save()) str = overCate+"에 "+to_string(mostOver)+"원 과소비했지만 총 "+to_string(save())+"원 절약, 특히 "+saveCate+"에 "+to_string(mostSave)+"원 절약을 했습니다. 좋아요!";
    else if(0<save()<=30000) str = overCate+"에 "+to_string(mostOver)+"원 과소비했지만 총 "+to_string(save())+"원 절약, 특히 "+saveCate+"에 "+to_string(mostSave)+"원 절약을 했습니다. 괜찮네요!";
    else if(-30000<=save()<0) str = saveCate+"에 "+to_string(mostSave)+"원 절약했지만 총 "+to_string(save())+"원 과소비, 특히 "+overCate+"에 "+to_string(mostOver)+"원 과소비 했습니다. 노력해요!";
    else if(save()<-30000) str = saveCate+"에 "+to_string(mostSave)+"원 절약했지만 총 "+to_string(save())+"원 과소비, 특히 "+overCate+"에 "+to_string(mostOver)+"원 과소비 했습니다. 조심해요!";
    else if((save() < 30000)&&(-check ==cnum)) str = "절약된 부문이 없습니다. 특히 "+overCate+"에 "+to_string(mostOver)+"원 과소비 했습니다. 정신차려야겠네요...";
    else if(save() == 0) str = "저번 달과 총금액 차이가 없네요! 신기합니다!";

    printWithBg(whte,blck, str);
    mlen = str.length();
}


void Confirm::setScreen() {
    int x=0,y=0;
    resetDisplay();
    setCnum(3);
    setCateList("food", 10000, 40000); setCateList("face", 50000, 30000); setCateList("study", 50000, 20000);     //IMSEE
    gotoxy(59, 3); printWithBg(whte, blck,"[ MY STATUS ]");
    gotoxy(32, 5); printWithBg(whte, blck, "[ Last Month ]                              [ This Month ]");
    gotoxy(10, 6); printWithBg(whte, blck, "╔═════════════════════════════════════════════════════════════════════════════════════════════════════════════╗");
    for(int i = 0; i <25; i++) {
        gotoxy(10, 7+i); printWithBg(whte, blck, "║");
        gotoxy(60, 7+i); printWithBg(whte, blck, "║");
        gotoxy(120, 7+i); printWithBg(whte, blck, "║");
        gotoxy(20, 7+i); printWithBg(whte, blck, "|");
        gotoxy(105, 7+i); printWithBg(whte,blck, "|");
    }
    gotoxy(10, 31); printWithBg(whte, blck, "╚═════════════════════════════════════════════════════════════════════════════════════════════════════════════╝");
    gotoxy(12,8); printWithBg(whte, blck, "EARNING");
    for(int i = 0; i < cnum; i++) {
        gotoxy(22, 8+i); printWithBg(whte, blck, CateList[i].category+" : "+to_string(CateList[i].last));
    }
    gotoxy(12, 18); printWithBg(whte, blck, "SPENDING");
    for(int i = 0; i < cnum; i++) {
        gotoxy(62, 8+i); printWithBg(whte, blck, CateList[i].category+" : "+to_string(CateList[i].pre));
    }
    gotoxy(10, 33); printWithBg(whte, blck, "[ ONE-LINE EVALUATION ]");
    gotoxy(12, 35); message();
    gotoxy(11, 35); printWithBg(whte, blck, "╭");for(int i = 0; i < mlen; i++) {gotoxy(12+i,35); printWithBg(whte,blck,"─");x=13+i;}gotoxy(x,35);printWithBg(whte,blck,"╮");
    gotoxy(13, 35); printWithBg(whte, blck, "^");gotoxy(11,36); printWithBg(whte,blck,"│"); gotoxy(x,36); printWithBg(whte,blck,"│");
    gotoxy(11, 37); printWithBg(whte, blck, "╰");for(int i = 0; i < mlen; i++) {gotoxy(12+i,37); printWithBg(whte,blck,"─");x=13+i;}gotoxy(x,37);printWithBg(whte,blck,"╯");
    gotoxy(13, 36); message();
    gotoxy(130,40);
}