#include "window.h"
#include<conio.h>
#include<graphics.h>
#include<string>
ExMessage window:: msg;





window::window(int weight, int height, int flag)
{
	handle=::initgraph(weight, height, flag);
	setbkmode(TRANSPARENT);//�����ֵı�������Ϊ͸��
}

void window::setwindowtitle(string a)
{
	SetWindowText(handle, a.c_str());                
}

