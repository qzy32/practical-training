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
	Management();//���ó�ʼ��������ͼƬ
	//���й�����
	void run(user&);

	//ѡ��˵�����ѡ��ֵ
	int menu();


	//��������
	void showcalendar(user&);

	//���ɱ��� ��ʾ������ճ̰���
	void schedule(user&);

	//�Ŷӹ���
	void teamfuntion(user&);

	//���ñ���
	void setbk();

	//�˳�ϵͳ
	void showexit();

	//���ڱ���vector���û���Ϣ
	void savefile(const string);

	//void registeruser(const string );//�������û���ע��

	//void userlogin(const string );//�����û��ĵ�¼,���������ȷ�Ļ����ܿ�������Ĺ���

	int getWeekDay(int ,int ,int);//���ڷ��ؽ������ܼ�

	string getnowtime();//�������ڵ�ʱ��



private :

	ExMessage msg1;

	IMAGE background;

	vector<Botton*>menu_botton;

	string fileheader;//���ڱ�����ļ�ͷ

	vector<user>users;

	Table table;
};

//�û�ע��

#endif
