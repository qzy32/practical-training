#pragma once
#ifndef WINDOW_H
#define WINDOW_H
using namespace std;
#include<easyx.h>
#include<string>
#include<graphics.h>

class window
{
public:

	window(int weight, int height, int flag);//不懂这个返回值flag
	void setwindowtitle(string title);//给窗口输入名字

	//按键操作和鼠标操作
	static  bool hasmsg() { return	::peekmessage(&msg, EM_MOUSE | EM_KEY); }
	
	static const ExMessage& getmsg() { return msg; }
	

	static ExMessage msg;//鼠标消息和键盘消息

private:
	HWND handle = NULL;//用于接受窗口的位置

};


#endif // !1


