#pragma once


#ifndef Management_H
#define Management_H
#include"calendar.h"
#include"window.h"
#include<vector>
#include"Botton.h"
#include<graphics.h>
#include"user.h"
#include<string>
#include<sstream>
#include "Table.h"
#include "group.h"
#include <stdio.h>
#include <time.h>
using namespace std;




class Management
{
	enum choose
	{
		Showcalendar, Schedule, Teamfuntion, Exit,Menu
	};
public:
	Management();//利用初始化来加载图片
	//运行管理类
	void run(user&);

	//选择菜单返回选择值
	int menu();


	//日历功能
	void showcalendar(user&);

	//生成报告 显示最近的日程安排
	void schedule(user&);

	//团队功能
	void teamfuntion(user&);

	//设置背景
	void setbk();

	//退出系统
	void showexit();

	//用于保存vector的用户信息
	void savefile(const string);

	//void registeruser(const string );//用于新用户的注册

	//void userlogin(const string );//用于用户的登录,如果输入正确的话才能开启下面的功能

	int getWeekDay(int ,int ,int);//用于返回今天是周几

	string getnowtime();//返回现在的时间



private :

	ExMessage msg1;

	IMAGE background;

	vector<Botton*>menu_botton;

	string fileheader;//用于保存的文件头

	vector<user>users;

	Table table;
};

//用户注册

#endif
