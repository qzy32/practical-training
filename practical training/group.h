#pragma once
#include<iostream>
#include<string>
#include<vector>
#include<fstream>
#include"user.h"
using namespace std;
//上一次写到management的 schedule 函数
class group//创立两个文件夹,第一个文件及用来保存用户信息,第二个文件用来存团队的日程安排
{

public:

	string name;//团体的名称

	vector<user>member;//团体成员vector

	vector<schdule>schedule;//团队日程安排

	vector<vector<int>> gtime;//团体的空余时间




	group(string, int);

	group(string);

	group(string, user);


	void addmenmber(user&);//添加新的团队成员

	void removemember(user&);//移除团队成员

	int arrangeactivity();//安排活动


	void show();//把团队中的成员表示出来

	void savefile();//保存文件

	void getmsg();//将文件中的信息传入到团队中

	void setschedule();//手动添加日程安排

	
	void showschedule();//输出日程安排

	void removescheduele();//用于删除日程安排

	
};

