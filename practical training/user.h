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
struct schdule//�����û��ճ̰��ŵ�ʱ�����ʼʱ��
{
	string schdulee;//ʱ��
	string sname;
	int start;
	int end;
	int op;
};

class user
{
public:

	
    void setuser(string, string);
	

	  user();// ��ʼ��ʱ�䰲�ź�ʱ��İ����Ƿ�ɼ�

	string cout();//char���ַ�����string ������
	 
	string myteam;//�ҵ��Ŷ�

	string name;//�û�������

	string password;
	//int x, y;//�û�������
	 

	vector<vector<int>> time; // ÿ���24��Сʱ�Ƿ��а���

	vector<vector<int>> visible; // �����Ƿ�ɼ�

	vector<schdule>schedule;//�ճ̰��ŵľ�������


	void setchedule();//���������Լ����г�


	int returndate(string);  // ������ת��Ϊ��ά�����е�������

	void removeschedule();//ɾ���ճ̰���

	void returnspecificdate();//�����������ؾ��������

	void showmonthschedule(int ,int );//��ʾ���µ��ճ̰���

	void getmeg();//��¼�û�֮��,���ļ��ж�ȡ�û���Ϣ

	void savefile();//�������ݿ��Դ��浽�ڿ���� ���Ű����ݱ��浽txt���ļ�����

	void creatweekreport(int,int,int);//���ɵ��ܱ���

	void creatmonthreport(int, int, int);//���ɵ��±���
   
	void showschedule();//����ɾ���ճ̰���,����ʾ�����ճ̰���
	
	//void updateteammsg();//�����Ŷ��и��˵���Ϣ
};


