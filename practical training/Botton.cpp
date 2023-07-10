#include "Botton.h"
#include<iostream>
using namespace std;
Botton::Botton(string name):Basicbotton(0,0,100,30)//父类的构造函数
{
	this->name = name;
}

void Botton::showbotton()
{
	setfillcolor(curent);//设置按钮的填充颜色
	fillroundrect(x, y, x + w, y + h,10,10);//绘制按钮形状

	settextcolor(BLUE);//设置文字颜色




	//让按钮文字的位置居中
	int tx = x+(w - textwidth(name.c_str())) / 2;
	int ty = y+(h - textheight(name.c_str())) / 2;
	outtextxy(tx, ty, name.c_str());
}

bool Botton::isin()
{
	if (msg.x >= x && msg.x <= x + w && msg.y >= y && msg.y <= y + h)
	{
		
		return true;
	}
	else
	{
		
		return false;
	}
		
}

bool Botton::ispush()
{
	if (isin())
	{
		if (msg.message == WM_LBUTTONDOWN)
			return true;
	}
	else return false;
}

void Botton::delivermsg(const ExMessage &msg)
{
	this->msg = msg;
	if (!isin())
	{
		curent = c1;
	}
	else
		curent = c2;
	
}


