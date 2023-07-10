#include "Management.h"
#include <iostream>
#include<fstream>
#include<conio.h>

using namespace std;

//void Management::registeruser( string filename)//注册功能 传入文件路径进行对用户名单的增添
//{
//	//完成用户信息的创建
//	cout << "欢迎你注册!" << endl;
//	string temp1, temp2;
//	cout << "请输入你的姓名:" << endl; cin >> temp1;
//	cout << "请输入你的密码:" << endl; cin >> temp2;
//
//	user* newuser = new user(temp1, temp2);
//
//	// 将用户信息保存到文件中
//	fstream fout(filename, ios::app); // 打开文件，追加模式
//
//	if (fout.is_open()) { // 如果文件打开成功
//		fout << temp1 << "\t" << temp2 << "\t" << endl;// 写入一行数据
//		fout.close(); // 关闭文件
//		cout << "注册成功！" << endl;
//	}
//	else { // 如果文件打开失败
//		cout << "注册失败，无法打开文件！" << endl;
//	}
//
//}
// 
// 
//void  Management::userlogin(string filename)
//{
//	string temp1, temp2;
//	//提示语
//	cout << "欢迎来到登录系统!" << endl;
//	cout << "输入你的姓名" << endl;
//	cin >> temp1;
//	cout << "输入你的密码" << endl;
//	cin >> temp2;
//
//
//	// 验证用户信息是否与文件中的匹配
//	ifstream fin(filename,ios::in); // 打开文件，读取模式
//	if (fin.is_open()) 
//	{ // 如果文件打开成功
//		string line; // 每行数据
//		while (getline(fin, line)) // 遍历每行数据
//		{ 
//			int pos1 = line.find("\t"); // 找到第一个逗号的位置
//			int pos2 = line.find("\t", pos1 + 1); // 找到第二个逗号的位置
//			string name = line.substr(0, pos1); // 截取姓名
//
//			string password = line.substr(pos1 + 1, pos2 - pos1 - 1); // 截取密码
//
//			string schedule = line.substr(pos2 + 1); // 截取日常安排
//			if (name == temp1 && password == temp2) { // 如果姓名和密码都匹配
//				//fin.close(); // 关闭文件
//				cout << "登录成功！" << endl;
//				cout << "你的日常安排是：" << endl;
//				cout << schedule << endl; // 显示日常安排
//				//return new User(name, password, schedule); // 返回用户对象
//				return true;
//			}
//		}
//		fin.close(); // 关闭文件
//		cout << "登录失败，用户名或密码错误！" << endl;
//		return ; // 返回空指针
//	}
//	else { // 如果文件打开失败
//		cout << "登录失败，无法打开文件！" << endl;
//		//return nullptr; // 返回空指针
//		return false;
//	}
//}

//void update(string, user);




void Management::setbk()
{
	putimage(0, 0, &background);
}

void Management::showexit()
{
	exit(1);
}

Management::Management()
{
	//readfile("D:/vs/practical training/practical training/resource.txt");//读取用户文件


	loadimage(&background,"D:/vs/practical training/practical training/piture1.jpg", 960, 640);
	menu_botton.push_back(new Botton("查看日历"));
	menu_botton.push_back(new Botton("日程安排"));
	menu_botton.push_back(new Botton("团队功能"));
	menu_botton.push_back(new Botton("退出系统"));

	for (int i = 0; i < menu_botton.size(); i++)
	{
		menu_botton[i]->setsize(250, 50);
		
		int y = i * menu_botton[i]->getheight();
		int by = (640 - menu_botton.size() * 50) / 2;
		menu_botton[i]->move((960 - 250) / 2,by+y );
  }


}

void Management::run(user&user)
{
	calendar calendar;

	

	//通过用户的选择来返回值 以此选择功能
	int op=Menu;
	
	while (true)
	{
		setbk();
		::BeginBatchDraw();
		if (window::hasmsg())//如果按了esc 返回主菜单
		{
			msg1 = window::getmsg();
			switch (msg1.message)
			{
			case WM_KEYDOWN:
				if (msg1.vkcode == VK_ESCAPE)
				{
				
					op = Menu;
				}
				break;
			default:
				break;
			}
		}
	
		//if (_kbhit())//如果按了esc 返回主菜单
		//{
		//	if (_getch() == 27)
		//		op = Menu;
		//}
	switch (op)
	{
	case Showcalendar:
		showcalendar(user);
		break;
	case Schedule:
	      schedule(user);
		
		break;
	case Teamfuntion:
	{teamfuntion(user);
	     op = Menu;
	}
		break;

	case Exit:
		showexit();
		break;
	case Menu:
		op = menu();
		break;
	default:
		break;
	}
	::cleardevice();

	}
	::EndBatchDraw();


}

int Management::menu()
{
	for (int i=0;i<menu_botton.size();i++)
	{
		menu_botton[i]->delivermsg(window::getmsg());
		
		menu_botton[i]->showbotton();
		if (menu_botton[i]->isin())
		{
		
	
		}
	
		if (menu_botton[i]->ispush())
		{
			return i;
		}
	}
	FlushBatchDraw();

	return Menu ;
}

void Management::showcalendar(user&user)
{
	calendar calendar;
	calendar.run(user,getnowtime());
	cout << endl;
	schedule(user);
	
	outtextxy(0, 0, "showcalendar");
	::FlushBatchDraw();

}

void Management::schedule(user&user)
{
	
	int op=100;
	std::cout << "请选择功能!" << endl;
	std::cout << "输入1:添加日程安排" << endl;
	std::cout << "输入2:移除日程安排" << endl;//先将所有的日程安排先显示到屏幕上
	std::cout << "输入3:查看日历" << endl;
	std::cout << "输入4:退出系统" << endl;
	cin >> op;
	
	switch (op)
	{
	case 1:
	{
		int oop = 1;
		while (oop == 1)
		{
			int temp;
			user.setchedule();
			cout << endl;
			std::cout << "是否要继续添加日程安排?" << endl;
			std::cout << "输入1:继续添加日程安排" << endl;
			std::cout << "输入2:返回上一级菜单" << endl;
			cin >> temp;
			if (temp == 2)
				oop = 0;
		}

	}
		break;
	case 2:
	{
		int oop = 1;
		while (oop == 1)
		{
			int temp;
			user.showschedule();
			user.removeschedule();
			std::cout << endl;
			std::cout << "是否要继续删除日程安排?" << endl;
			std::cout << "输入1:继续删除日程安排" << endl;
			std::cout << "输入2:返回上一级菜单" << endl;
			cin >> temp;
			if (temp == 2)
				oop = 0;
		}

	}
		break;
	case 3:
		showcalendar(user);
		break;
	case 4:
		exit(123);
		break;
	default:
		break;
	}
	schedule(user);
	outtextxy(0, 0, "createreport");
	::FlushBatchDraw();

}

void Management::teamfuntion(user& user)
{
	cout << "欢迎来到团队功能!" << endl;
	while (true)
	{
		int flag = 0;
		cout << "请输入你想要的功能" << endl;
		cout << "输入1 :查看个人团队" << endl;
		cout << "输入2 :加入团队" << endl;
		cout << "输入3 :注册团队" << endl;
		cout << "输入4 :退出团队功能" << endl;
		cout << "输入5 :退出系统" << endl;
		int op;
		cin >> op;
		switch (op)
		{
		case 1:
		{
			cout << user.myteam << endl;
			if (user.myteam > " ")
			{
				group gp(user.myteam);
				while (true)
				{
					int flag = 0;
					cout << "请输入你想要使用的功能" << endl;
					cout << "输入1 :查看团队成员" << endl;
					cout << "输入2 :查看团队日程" << endl;
					cout << "输入3 :添加团队日程" << endl;
					cout << "输入4 :删除团队日程" << endl;
					cout << "输入5 :返回上一级菜单" << endl;
					int oop = 0;
					cin >> oop;

					switch (oop)
					{
					case 1:
						gp.show();
						break;
					case 2:
						gp.showschedule();
						break;
					case 3:

					  {
						
						while (true)
						{
							cout << "请输入你想要使用的功能" << endl;
							cout << "输入1 :手动添加日程安排" << endl;
							cout << "输入2 :系统自动添加日程安排" << endl;
							cout << "输入3 :返回上一级菜单" << endl;
							int oooop = 0;
							cin >> oooop;
							switch (oooop)
							{
							case 1:
							 {
								int flag1 = 0;
								int op1 = 0;
								while (true)
								{

									gp.setschedule();
									cout << endl;
									cout << "输入1 :继续添加日程安排" << endl;

									cout << "输入2 :返回上一级菜单" << endl;
									cin >> op1;
									if (op1 == 2)
										break;

								}
								break;
							 }
							case 2:
							 {
								int flag1 = 0;
								int op1 = 0;
								while (true)
								{

									gp.arrangeactivity();
									cout << endl;
									cout << "输入1 :继续添加日程安排" << endl;

									cout << "输入2 :返回上一级菜单" << endl;
									cin >> op1;
									if (op1 == 2)
										break;

								}
								break;
							 }
							case 3:
								oooop = 1;
								break;
							default:
								break;
							}
							if (oooop == 1)
								break;
							

						}
					  }
					case 4:
						break;
					case 5:
						oop = 1;
						break;

					default:
						break;
					}
					if (oop == 1)
						break;
					
					
				}
				
			}
			else
			{
				cout << "你尚未加入团队,无法查看个人团队!" << endl;
				break;
			}

		}
		case 2:

		{
			if (user.myteam > " ")
			{
				cout << "你已经加入了团队,无法重复加入新的团队!" << endl;
				break;
			}
			else
			{
				string tempname, teampassword;
				cout << "请输入你要加入的团队:" << endl;
				cin >> tempname;
				group gp(tempname);
				gp.addmenmber(user);
				
				cout << "团队加入成功!" << endl;
				cout << endl;
				break;
			}
		}


		case 3:
		{cout << "请输入你想要创建的团队名称:";
		string name;
		cin >> name;
	
		
		user.myteam = name;
		
		group gp(name, 1);//创建团队的txt文件	
		//同时保存创建人的信息
		gp.addmenmber(user);
		
		cout << "创建团队成功!";
		cout << endl;
		break; }
		case 4:
		{
			flag = 1;
			break;
		}
		case 5:
		{
			cout << "程序退出成功!" << endl;
			exit(123);
		}
		default:
			break;

		}
		if (flag == 1)
			break;
	}
	::FlushBatchDraw();

	
}

//void Management::readfile(const string filename)//用来读取文件
//{
//	fstream fin(filename,ios::in);
//	if (!fin.is_open())
//	{
//		cout << "文件打开失败";
//		return;
//	}
//	//读取表头
//	char buf[2000] = { 0 };//
//	fin.getline(buf, 2000);//流对象有个getline,重点理解一下
//	cout << buf << endl;
//	fileheader = buf;
//	//读取数据
//	while (!fin.eof())//一直读到文件尾
//	{
//		char data[2000] = { 0 };
//		fin.getline(data, 2000);
//
//		if (strlen(data) == 0)//防止读到最后一个空行
//			break;
//		stringstream ss(data);
//
//		user temp;//临时的用户变量来储存数据
//		ss >> temp.name >> temp.password >> temp.schedule;
//		users.push_back(temp);
//		cout << temp.name <<"\t" << temp.password <<"\t" << temp.schedule;
//
//	}
//
//
//}

void Management::savefile(const string filestring)
{
	fstream write(filestring, ios::out | ios::trunc);
	if (!write.is_open())//防止文件没有成功被打开
	{
		cerr << "文件打开失败" << endl;
		return;
	}

	write.write(fileheader.c_str(), fileheader.size());
	for (auto& userr : users)
	{
		string temp = userr.cout();//必须创造一个临时的变量,不然不能用返回值内的东西
		write.write(temp.c_str(), temp.size());//注意拼接之后读入数据也要用string的str来写入
	}
}

int Management::getWeekDay(int year,int month,int day)
{
	
		int y = year, m = month, d = day;
		if (m == 1 || m == 2) { //把一月和二月看成上一年的十三月和十四月
			m += 12;
			y--;
		}
		int w = (d + 2 * m + 3 * (m + 1) / 5 + y + y / 4 - y / 100 + y / 400 + 1) % 7; //基姆拉尔森计算公式
		return w; //返回星期几（0-6表示周一到周日）


}

string Management::getnowtime()//返回系统当前的时间
{
	
		time_t t = time(NULL); //获取当前时间戳

		struct tm tm; //定义一个struct tm变量

		localtime_s(&tm, &t); //转换为本地时间结构体

		std::string date; //定义一个字符串对象

		date = std::to_string(tm.tm_year + 1900) + "-" + std::to_string(tm.tm_mon + 1) + "-" + std::to_string(tm.tm_mday); //拼接年月日字符串

		return date; //返回字符串对象
	
}



//void updateuser(string a, user user)
//{
//	group gp(a, user);
//}