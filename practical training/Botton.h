#pragma once
#include "Basicbotton.h"
#include<string>
#include<easyx.h>
using namespace std;
class Botton :
    public  Basicbotton
{
public: Botton(string name);

    void showbotton()override;//override 对虚函数进行重写

    bool isin();//判断当前鼠标是否是在按钮之上

    bool ispush();//判断是否有点击鼠标
    
    void delivermsg(const ExMessage& msg);//给botton的信息进行传递



private:
    string name;
    ExMessage msg;//用于接受信息
    COLORREF c1 = RGB(220, 220, 220);//原始
    COLORREF c2 = RED;
    COLORREF curent = RGB(220, 220, 220);

};

