#include<iostream>
#include<iomanip>
#include "Management.h"
#include<graphics.h>
#include"window.h"
#include <fstream>
#include <string>
//出现问题 个人添加日程之后 团队中没有更新
//目前存放数据的结构:姓名\t 密码\t   日常安排的具体名称和开始和结束的时间(一个结构体的内容用,分隔  每个事件之间用.来分隔) 名称 是否公开

using namespace std;
void registeruser(string,user&);
bool userlogin(string ,user&);

int main()
{	
	int flag=1;
	int op;
	std::cout << "欢迎来到超级日历!" << endl;
	while (flag != 0)
	{
	

		std::cout << "选择你想要的功能" << endl;
		std::cout << "输入1:登录用户" << endl;
		std::cout << "输入2:注册用户" << endl;
		std::cout << "输入3:退出超级日历" << endl;
		std::cout << endl;
		std::cout << endl;
		std::cout << endl;
		std::cout << endl;
		cin >> op;

		user user;//用来保存用户的信息,便于后面的团队功能
		string a = "resource.txt";
		switch (op)
		{
		case 1:
		{std::cout << "欢迎来到登录系统!" << endl;


		if (userlogin(a, user))
		{
			Management m;

			window window(960, 640, EW_SHOWCONSOLE);
			window.setwindowtitle("超级日历");
			m.run(user);


		}

		}
			break;
		case 2:
			registeruser("resource.txt", user);
			break;
		case 3:
			exit(123);
			break;

		default:
			break;
		}
	}
 
 }
 
void registeruser(string filename,user&user)//注册功能 传入文件路径进行对用户名单的增添//要防止用同名用户的出现
{
	//完成用户信息的创建
	std::cout << "欢迎你注册!" << endl;
	string temp1, temp2;
	std::cout << "请输入你的姓名:" << endl; cin >> temp1;
	std::cout << "请输入你的密码:" << endl; cin >> temp2;
	user.setuser(temp1, temp2);
	//user* newuser = new user(temp1, temp2);

	// 将用户信息保存到文件中
	fstream fout(filename, ios::app); // 打开文件，追加模式

	if (fout.is_open())
	{ // 如果文件打开成功
				fout  << temp1 << '/' << temp2 << '/' <<'/'<<'/'<< endl;// 写入一行数据
		fout.close(); // 关闭文件
		std::cout << "注册成功！" << endl;
		std::cout << "正在为你自动登录" << endl;
		std::cout  << endl;
	
		
		Management m;

		window window(960, 640, EW_SHOWCONSOLE);
		window.setwindowtitle("超级日历");
		m.run(user);

	}
	else { // 如果文件打开失败
		std::cout << "注册失败，无法打开文件！" << endl;
	}

}

bool userlogin(string filename,user & uu)
{
	string temp1, temp2;
	//提示语
	
	std::cout << "输入你的姓名:" << endl;
	cin >> temp1;
	std::cout << "输入你的密码:" << endl;
	cin >> temp2;

	uu.setuser(temp1, temp2);
	// 验证用户信息是否与文件中的匹配
	ifstream fin(filename, ios::in); // 打开文件，读取模式
	if (fin.is_open())
	{ // 如果文件打开成功
		string line; // 每行数据
		while (getline(fin, line)) // 遍历每行数据
		{
			int pos1 = line.find('/'); // 找到第一个\t的位置
			int pos2 = line.find('/', pos1 + 1); // 找到第二个\t的位置
			string name = line.substr(0, pos1); // 截取姓名
			
			string password = line.substr(pos1 + 1, pos2 - pos1-1 ); // 截取密码
		
			if (name == temp1 && password == temp2) // 如果姓名和密码都匹配
			{ 
				
				std::cout << "登录成功！" << endl << endl;
				uu.getmeg();
				
				
				return true;
			}
		}
		fin.close(); // 关闭文件
		std::cout << "登录失败，用户名或密码错误！" << endl;
		std::cout << "请重新进行登录!" << endl;
		std::cout << endl;
		std::cout << endl;
		std::cout << endl;
		return false; 
	}
	else { // 如果文件打开失败
		std::cout << "登录失败，无法打开文件！" << endl;
		//return nullptr; // 返回空指针
		return false;
	}
}



	









