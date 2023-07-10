#pragma once
class Basicbotton
{
public:
	Basicbotton(int x, int y, int w, int h);
	int getweight();//得到宽度
	int getheight();//得到高度
	int getx();//返回x
	int gety();//返回y
	void move(int x, int y);//移动窗口

	virtual void showbotton() = 0;
	void setsize(int x, int y);//设置按钮的大小


protected:
	int x, y, w, h;//x y坐标 w h宽高

};

