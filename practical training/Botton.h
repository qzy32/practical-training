#pragma once
#include "Basicbotton.h"
#include<string>
#include<easyx.h>
using namespace std;
class Botton :
    public  Basicbotton
{
public: Botton(string name);

    void showbotton()override;//override ���麯��������д

    bool isin();//�жϵ�ǰ����Ƿ����ڰ�ť֮��

    bool ispush();//�ж��Ƿ��е�����
    
    void delivermsg(const ExMessage& msg);//��botton����Ϣ���д���



private:
    string name;
    ExMessage msg;//���ڽ�����Ϣ
    COLORREF c1 = RGB(220, 220, 220);//ԭʼ
    COLORREF c2 = RED;
    COLORREF curent = RGB(220, 220, 220);

};

