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

	window(int weight, int height, int flag);//�����������ֵflag
	void setwindowtitle(string title);//��������������

	//����������������
	static  bool hasmsg() { return	::peekmessage(&msg, EM_MOUSE | EM_KEY); }
	
	static const ExMessage& getmsg() { return msg; }
	

	static ExMessage msg;//�����Ϣ�ͼ�����Ϣ

private:
	HWND handle = NULL;//���ڽ��ܴ��ڵ�λ��

};


#endif // !1


