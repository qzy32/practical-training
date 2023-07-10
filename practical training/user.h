#pragma once
#include<string>
#include<sstream>
#include<vector>
#include<iostream>
#include<map>
#include<fstream>
#include<sstream>

class group;
using namespace std;

class calendar;
struct schdule//储存用户日程安排的时间和起始时间
{
	string schdulee;//时间
	string sname;
	int start;
	int end;
	int op;
};

class user
{
public:

	
    void setuser(string, string);
	

	  user();// 初始化时间安排和时间的安排是否可见

	string cout();//char的字符串用string 来接收
	 
	string myteam;//我的团队

	string name;//用户的姓名

	string password;
	//int x, y;//用户的坐标
	 

	vector<vector<int>> time; // 每天的24个小时是否有安排

	vector<vector<int>> visible; // 安排是否可见

	vector<schdule>schedule;//日程安排的具体内容


	void setchedule();//用于输入自己的行程


	int returndate(string);  // 将日期转换为二维向量中的行索引

	void removeschedule();//删除日程安排

	void returnspecificdate();//根据天数返回具体的日期

	void showmonthschedule(int ,int );//显示该月的日程安排

	void getmeg();//登录用户之后,从文件中读取用户信息

	void savefile();//其他数据可以储存到黑框框中 最后才把内容保存到txt的文件当中

	void creatweekreport(int,int,int);//生成当周报告

	void creatmonthreport(int, int, int);//生成当月报告
   
	void showschedule();//用于删除日程安排,先显示出来日程安排
	
	//void updateteammsg();//更新团队中个人的信息
};


