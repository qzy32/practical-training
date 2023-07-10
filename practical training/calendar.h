#pragma once
#include<fstream>
#include"user.h"
#include"group.h"

class Management;
struct curday
	//现在的日期
{
	int year, month, day;
};

class calendar
{


public:
	   void PrintStar();//用于界面,打印星星

		bool IsLeapyear(curday );//判断是否为闰年

		bool IsLeapyear(int );//判断该月第一天为星期几

		int FD_is(curday );//加上该年前面月份的

		void PrintBegin(curday& );//打印表头

		void PrintDate(int d, curday );

		void run(user&,string);

		calendar() ;

		int getweek(int,int,int);//返回是一周的星期几


};

