#pragma once
#include<iostream>
#include<string>
#include<vector>
#include<fstream>
#include"user.h"
using namespace std;
//��һ��д��management�� schedule ����
class group//���������ļ���,��һ���ļ������������û���Ϣ,�ڶ����ļ��������Ŷӵ��ճ̰���
{

public:

	string name;//���������

	vector<user>member;//�����Աvector

	vector<schdule>schedule;//�Ŷ��ճ̰���

	vector<vector<int>> gtime;//����Ŀ���ʱ��




	group(string, int);

	group(string);

	group(string, user);


	void addmenmber(user&);//����µ��Ŷӳ�Ա

	void removemember(user&);//�Ƴ��Ŷӳ�Ա

	int arrangeactivity();//���Ż


	void show();//���Ŷ��еĳ�Ա��ʾ����

	void savefile();//�����ļ�

	void getmsg();//���ļ��е���Ϣ���뵽�Ŷ���

	void setschedule();//�ֶ�����ճ̰���

	
	void showschedule();//����ճ̰���

	void removescheduele();//����ɾ���ճ̰���

	
};

