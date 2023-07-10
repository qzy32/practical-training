#include "calendar.h"
#include<iostream>
#include<string>
#include<iomanip>
using namespace std;



int leap_year[13] = { 0,31,29,31,30,31,30,31,31,30,31,30,31 };//闰年
int common_year[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };//平年

string weekday[8] = { "", "一","二","三","四","五","六","日" };//星期数组


void calendar::PrintStar()//用于界面,打印星星
{
	cout << "**************************************************" << endl;
}

bool calendar::IsLeapyear(curday curday)//判断是否为闰年
{
	
	return  (curday.year % 400 == 0) || (curday.year % 4 == 0 && curday.year % 100 != 0);
}

bool calendar::IsLeapyear(int year)//判断是否为闰年
{

	return  (year % 400 == 0) || (year % 4 == 0 && year % 100 != 0);
}

int calendar::FD_is(curday curday)//判断该月第一天为星期几
{
	int sum = 0;

	for (int i = 1; i < curday.year; i++)//从元年加到上一年一共有多少天
	{
		if (IsLeapyear(i))
		{
			sum += 366;
		}
		if (!IsLeapyear(i))
			sum += 365;

	}

	for (int i = 1; i < curday.month; i++)//加上该年前面月份的
	{
		if (IsLeapyear(curday))
		{
			sum = sum + leap_year[i];
		}
		if (!IsLeapyear(curday))
			sum = sum + common_year[i];
	}

	int tem = sum % 7;



	return tem;

}


void calendar::PrintBegin(curday& curday)//打印表头
{


	//打印开头
	cout << setfill(' ') << setw(28) << "万年历" << endl;

	cout << setw(22) << " " << curday.year << "." << curday.month  << endl;
	PrintStar();

	//打印星期
	for (int i = 1; i <= 7; i++)
		cout << weekday[i] << "\t";
	cout << endl;

}

void calendar::run (user& user,string a)
{


	curday curday1;
	string date;
	date = a;
	int posi1, posi2, posi3;
	posi1 = date.find('-', 0);
	posi2 = date.find('-', posi1 + 1);
	posi3 = date.find('-', posi2 + 1);
	int year, month, day;
	curday1.year = stoi(date.substr(0, posi1));
	year = stoi(date.substr(0, posi1));
	curday1.month = stoi(date.substr(posi1 + 1, posi2));
	month = stoi(date.substr(posi1 + 1, posi2));
	curday1.day= stoi(date.substr(posi2 + 1, posi3));
	day = curday1.day;
	/*day = stoi(date.substr(posi2 + 1, posi3));*/
	//int day = stoi(date.substr(posi2 + 1));

	calendar calendar;

	
	cout << setw(29) << "当前月份" << endl;
	calendar.PrintBegin(curday1);

	calendar.PrintStar();

	calendar.PrintDate(calendar.FD_is(curday1), curday1);

	cout << endl;



	int op;//表示用户的选择
	
	while (true)//一直循环.可以往前往后
	{
		cout << endl;
		cout << "请输入你想要的功能" << endl;
		cout << "输入1 :查询指定月份的日历" << endl;
		cout << "输入2 :查询上一个月的日历" << endl;
		cout << "输入3 :查询下一个月的日历" << endl;
		cout << "输入4 :查询上一年该月份的日历" << endl;
		cout << "输入5 :查询下一年该月份的日历" << endl;
		cout << "输入6 :查看本月的日程安排" << endl;
		cout << "输入7 :打开日程安排功能" << endl;
		cout << "输入8 :退出日历" << endl;

		int flag = 0;
		cin >> op;
		switch (op)
		{
		case 1:
		{
			
		cout << "请输入要查询日历的年,月:" << endl;
		cin >> curday1.year >> curday1.month;
		calendar.PrintBegin(curday1);

		calendar.PrintStar();

		calendar.PrintDate(calendar.FD_is(curday1), curday1);
		break;
		}
		case 2:
			curday1.month -= 1;
			calendar.PrintBegin(curday1);

			calendar.PrintStar();

			calendar.PrintDate(calendar.FD_is(curday1), curday1);
			break;
		case 3:
			curday1.month += 1;
			calendar.PrintBegin(curday1);

			calendar.PrintStar();

			calendar.PrintDate(calendar.FD_is(curday1), curday1);
			break;
		case 4:
			curday1.year -= 1;
			calendar.PrintBegin(curday1);

			calendar.PrintStar();

			calendar.PrintDate(calendar.FD_is(curday1), curday1);
			break;
		case 5:
			curday1.year += 1;
			calendar.PrintBegin(curday1);

			calendar.PrintStar();

			calendar.PrintDate(calendar.FD_is(curday1), curday1);
			break;
		case 6:
		{
			user.showmonthschedule(curday1.year, curday1.month);
		}
		break;
		

	
		case 7:
			flag = 1;
			break;
		case 8:
			exit(123);

			break;

		default:
			break;
		}
		/*calendar.PrintBegin(curday1);

		calendar.PrintStar();

		calendar.PrintDate(calendar.FD_is(curday1), curday1);
		cout << endl;

*/
		if (flag == 1)
			break;




	}

}

int calendar::getweek(int year,int month,int day)
{
	
		int y = year, m = month, d = day;
		if (m == 1 || m == 2) { //把一月和二月看成上一年的十三月和十四月
			m += 12;
			y--;
		}
		int w = (d + 2 * m + 3 * (m + 1) / 5 + y + y / 4 - y / 100 + y / 400 + 1) % 7; //基姆拉尔森计算公式
		return w; //返回星期几（0-6表示周一到周日）
	

}


void calendar::PrintDate(int fd, curday curday)
{
	for (int i = 0; i < fd; i++)
		cout << setfill(' ') << "\t";
	if (IsLeapyear(curday))
		for (int i = 1; i <= leap_year[curday.month]; i++)
		{
			cout << i << "\t";
			if ((i == 7 - fd) || ((i + fd - 7) % 7 == 0))
				cout << endl;

		}

	if (!IsLeapyear(curday))
		for (int i = 1; i <= common_year[curday.month]; i++)
		{
			cout << i << "\t";
			if ((i == 7 - fd) || ((i + fd - 7) % 7 == 0))
				cout << endl;

		}


}

calendar::calendar()
{


}
