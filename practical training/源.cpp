#include<iostream>
#include<iomanip>
#include "Management.h"
#include<graphics.h>
#include"window.h"
#include <fstream>
#include <string>
//�������� ��������ճ�֮�� �Ŷ���û�и���
//Ŀǰ������ݵĽṹ:����\t ����\t   �ճ����ŵľ������ƺͿ�ʼ�ͽ�����ʱ��(һ���ṹ���������,�ָ�  ÿ���¼�֮����.���ָ�) ���� �Ƿ񹫿�

using namespace std;
void registeruser(string,user&);
bool userlogin(string ,user&);

int main()
{	
	int flag=1;
	int op;
	std::cout << "��ӭ������������!" << endl;
	while (flag != 0)
	{
	

		std::cout << "ѡ������Ҫ�Ĺ���" << endl;
		std::cout << "����1:��¼�û�" << endl;
		std::cout << "����2:ע���û�" << endl;
		std::cout << "����3:�˳���������" << endl;
		std::cout << endl;
		std::cout << endl;
		std::cout << endl;
		std::cout << endl;
		cin >> op;

		user user;//���������û�����Ϣ,���ں�����Ŷӹ���
		string a = "resource.txt";
		switch (op)
		{
		case 1:
		{std::cout << "��ӭ������¼ϵͳ!" << endl;


		if (userlogin(a, user))
		{
			Management m;

			window window(960, 640, EW_SHOWCONSOLE);
			window.setwindowtitle("��������");
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
 
void registeruser(string filename,user&user)//ע�Ṧ�� �����ļ�·�����ж��û�����������//Ҫ��ֹ��ͬ���û��ĳ���
{
	//����û���Ϣ�Ĵ���
	std::cout << "��ӭ��ע��!" << endl;
	string temp1, temp2;
	std::cout << "�������������:" << endl; cin >> temp1;
	std::cout << "�������������:" << endl; cin >> temp2;
	user.setuser(temp1, temp2);
	//user* newuser = new user(temp1, temp2);

	// ���û���Ϣ���浽�ļ���
	fstream fout(filename, ios::app); // ���ļ���׷��ģʽ

	if (fout.is_open())
	{ // ����ļ��򿪳ɹ�
				fout  << temp1 << '/' << temp2 << '/' <<'/'<<'/'<< endl;// д��һ������
		fout.close(); // �ر��ļ�
		std::cout << "ע��ɹ���" << endl;
		std::cout << "����Ϊ���Զ���¼" << endl;
		std::cout  << endl;
	
		
		Management m;

		window window(960, 640, EW_SHOWCONSOLE);
		window.setwindowtitle("��������");
		m.run(user);

	}
	else { // ����ļ���ʧ��
		std::cout << "ע��ʧ�ܣ��޷����ļ���" << endl;
	}

}

bool userlogin(string filename,user & uu)
{
	string temp1, temp2;
	//��ʾ��
	
	std::cout << "�����������:" << endl;
	cin >> temp1;
	std::cout << "�����������:" << endl;
	cin >> temp2;

	uu.setuser(temp1, temp2);
	// ��֤�û���Ϣ�Ƿ����ļ��е�ƥ��
	ifstream fin(filename, ios::in); // ���ļ�����ȡģʽ
	if (fin.is_open())
	{ // ����ļ��򿪳ɹ�
		string line; // ÿ������
		while (getline(fin, line)) // ����ÿ������
		{
			int pos1 = line.find('/'); // �ҵ���һ��\t��λ��
			int pos2 = line.find('/', pos1 + 1); // �ҵ��ڶ���\t��λ��
			string name = line.substr(0, pos1); // ��ȡ����
			
			string password = line.substr(pos1 + 1, pos2 - pos1-1 ); // ��ȡ����
		
			if (name == temp1 && password == temp2) // ������������붼ƥ��
			{ 
				
				std::cout << "��¼�ɹ���" << endl << endl;
				uu.getmeg();
				
				
				return true;
			}
		}
		fin.close(); // �ر��ļ�
		std::cout << "��¼ʧ�ܣ��û������������" << endl;
		std::cout << "�����½��е�¼!" << endl;
		std::cout << endl;
		std::cout << endl;
		std::cout << endl;
		return false; 
	}
	else { // ����ļ���ʧ��
		std::cout << "��¼ʧ�ܣ��޷����ļ���" << endl;
		//return nullptr; // ���ؿ�ָ��
		return false;
	}
}



	









