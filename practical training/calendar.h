#pragma once
#include<fstream>
#include"user.h"
#include"group.h"

class Management;
struct curday
	//���ڵ�����
{
	int year, month, day;
};

class calendar
{


public:
	   void PrintStar();//���ڽ���,��ӡ����

		bool IsLeapyear(curday );//�ж��Ƿ�Ϊ����

		bool IsLeapyear(int );//�жϸ��µ�һ��Ϊ���ڼ�

		int FD_is(curday );//���ϸ���ǰ���·ݵ�

		void PrintBegin(curday& );//��ӡ��ͷ

		void PrintDate(int d, curday );

		void run(user&,string);

		calendar() ;

		int getweek(int,int,int);//������һ�ܵ����ڼ�


};

