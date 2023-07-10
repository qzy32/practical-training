#include "calendar.h"
#include<iostream>
#include<string>
#include<iomanip>
using namespace std;



int leap_year[13] = { 0,31,29,31,30,31,30,31,31,30,31,30,31 };//����
int common_year[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };//ƽ��

string weekday[8] = { "", "һ","��","��","��","��","��","��" };//��������


void calendar::PrintStar()//���ڽ���,��ӡ����
{
	cout << "**************************************************" << endl;
}

bool calendar::IsLeapyear(curday curday)//�ж��Ƿ�Ϊ����
{
	
	return  (curday.year % 400 == 0) || (curday.year % 4 == 0 && curday.year % 100 != 0);
}

bool calendar::IsLeapyear(int year)//�ж��Ƿ�Ϊ����
{

	return  (year % 400 == 0) || (year % 4 == 0 && year % 100 != 0);
}

int calendar::FD_is(curday curday)//�жϸ��µ�һ��Ϊ���ڼ�
{
	int sum = 0;

	for (int i = 1; i < curday.year; i++)//��Ԫ��ӵ���һ��һ���ж�����
	{
		if (IsLeapyear(i))
		{
			sum += 366;
		}
		if (!IsLeapyear(i))
			sum += 365;

	}

	for (int i = 1; i < curday.month; i++)//���ϸ���ǰ���·ݵ�
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


void calendar::PrintBegin(curday& curday)//��ӡ��ͷ
{


	//��ӡ��ͷ
	cout << setfill(' ') << setw(28) << "������" << endl;

	cout << setw(22) << " " << curday.year << "." << curday.month  << endl;
	PrintStar();

	//��ӡ����
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

	
	cout << setw(29) << "��ǰ�·�" << endl;
	calendar.PrintBegin(curday1);

	calendar.PrintStar();

	calendar.PrintDate(calendar.FD_is(curday1), curday1);

	cout << endl;



	int op;//��ʾ�û���ѡ��
	
	while (true)//һֱѭ��.������ǰ����
	{
		cout << endl;
		cout << "����������Ҫ�Ĺ���" << endl;
		cout << "����1 :��ѯָ���·ݵ�����" << endl;
		cout << "����2 :��ѯ��һ���µ�����" << endl;
		cout << "����3 :��ѯ��һ���µ�����" << endl;
		cout << "����4 :��ѯ��һ����·ݵ�����" << endl;
		cout << "����5 :��ѯ��һ����·ݵ�����" << endl;
		cout << "����6 :�鿴���µ��ճ̰���" << endl;
		cout << "����7 :���ճ̰��Ź���" << endl;
		cout << "����8 :�˳�����" << endl;

		int flag = 0;
		cin >> op;
		switch (op)
		{
		case 1:
		{
			
		cout << "������Ҫ��ѯ��������,��:" << endl;
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
		if (m == 1 || m == 2) { //��һ�ºͶ��¿�����һ���ʮ���º�ʮ����
			m += 12;
			y--;
		}
		int w = (d + 2 * m + 3 * (m + 1) / 5 + y + y / 4 - y / 100 + y / 400 + 1) % 7; //��ķ����ɭ���㹫ʽ
		return w; //�������ڼ���0-6��ʾ��һ�����գ�
	

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
