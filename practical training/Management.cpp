#include "Management.h"
#include <iostream>
#include<fstream>
#include<conio.h>

using namespace std;

//void Management::registeruser( string filename)//ע�Ṧ�� �����ļ�·�����ж��û�����������
//{
//	//����û���Ϣ�Ĵ���
//	cout << "��ӭ��ע��!" << endl;
//	string temp1, temp2;
//	cout << "�������������:" << endl; cin >> temp1;
//	cout << "�������������:" << endl; cin >> temp2;
//
//	user* newuser = new user(temp1, temp2);
//
//	// ���û���Ϣ���浽�ļ���
//	fstream fout(filename, ios::app); // ���ļ���׷��ģʽ
//
//	if (fout.is_open()) { // ����ļ��򿪳ɹ�
//		fout << temp1 << "\t" << temp2 << "\t" << endl;// д��һ������
//		fout.close(); // �ر��ļ�
//		cout << "ע��ɹ���" << endl;
//	}
//	else { // ����ļ���ʧ��
//		cout << "ע��ʧ�ܣ��޷����ļ���" << endl;
//	}
//
//}
// 
// 
//void  Management::userlogin(string filename)
//{
//	string temp1, temp2;
//	//��ʾ��
//	cout << "��ӭ������¼ϵͳ!" << endl;
//	cout << "�����������" << endl;
//	cin >> temp1;
//	cout << "�����������" << endl;
//	cin >> temp2;
//
//
//	// ��֤�û���Ϣ�Ƿ����ļ��е�ƥ��
//	ifstream fin(filename,ios::in); // ���ļ�����ȡģʽ
//	if (fin.is_open()) 
//	{ // ����ļ��򿪳ɹ�
//		string line; // ÿ������
//		while (getline(fin, line)) // ����ÿ������
//		{ 
//			int pos1 = line.find("\t"); // �ҵ���һ�����ŵ�λ��
//			int pos2 = line.find("\t", pos1 + 1); // �ҵ��ڶ������ŵ�λ��
//			string name = line.substr(0, pos1); // ��ȡ����
//
//			string password = line.substr(pos1 + 1, pos2 - pos1 - 1); // ��ȡ����
//
//			string schedule = line.substr(pos2 + 1); // ��ȡ�ճ�����
//			if (name == temp1 && password == temp2) { // ������������붼ƥ��
//				//fin.close(); // �ر��ļ�
//				cout << "��¼�ɹ���" << endl;
//				cout << "����ճ������ǣ�" << endl;
//				cout << schedule << endl; // ��ʾ�ճ�����
//				//return new User(name, password, schedule); // �����û�����
//				return true;
//			}
//		}
//		fin.close(); // �ر��ļ�
//		cout << "��¼ʧ�ܣ��û������������" << endl;
//		return ; // ���ؿ�ָ��
//	}
//	else { // ����ļ���ʧ��
//		cout << "��¼ʧ�ܣ��޷����ļ���" << endl;
//		//return nullptr; // ���ؿ�ָ��
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
	//readfile("D:/vs/practical training/practical training/resource.txt");//��ȡ�û��ļ�


	loadimage(&background,"D:/vs/practical training/practical training/piture1.jpg", 960, 640);
	menu_botton.push_back(new Botton("�鿴����"));
	menu_botton.push_back(new Botton("�ճ̰���"));
	menu_botton.push_back(new Botton("�Ŷӹ���"));
	menu_botton.push_back(new Botton("�˳�ϵͳ"));

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

	

	//ͨ���û���ѡ��������ֵ �Դ�ѡ����
	int op=Menu;
	
	while (true)
	{
		setbk();
		::BeginBatchDraw();
		if (window::hasmsg())//�������esc �������˵�
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
	
		//if (_kbhit())//�������esc �������˵�
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
	std::cout << "��ѡ����!" << endl;
	std::cout << "����1:����ճ̰���" << endl;
	std::cout << "����2:�Ƴ��ճ̰���" << endl;//�Ƚ����е��ճ̰�������ʾ����Ļ��
	std::cout << "����3:�鿴����" << endl;
	std::cout << "����4:�˳�ϵͳ" << endl;
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
			std::cout << "�Ƿ�Ҫ��������ճ̰���?" << endl;
			std::cout << "����1:��������ճ̰���" << endl;
			std::cout << "����2:������һ���˵�" << endl;
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
			std::cout << "�Ƿ�Ҫ����ɾ���ճ̰���?" << endl;
			std::cout << "����1:����ɾ���ճ̰���" << endl;
			std::cout << "����2:������һ���˵�" << endl;
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
	cout << "��ӭ�����Ŷӹ���!" << endl;
	while (true)
	{
		int flag = 0;
		cout << "����������Ҫ�Ĺ���" << endl;
		cout << "����1 :�鿴�����Ŷ�" << endl;
		cout << "����2 :�����Ŷ�" << endl;
		cout << "����3 :ע���Ŷ�" << endl;
		cout << "����4 :�˳��Ŷӹ���" << endl;
		cout << "����5 :�˳�ϵͳ" << endl;
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
					cout << "����������Ҫʹ�õĹ���" << endl;
					cout << "����1 :�鿴�Ŷӳ�Ա" << endl;
					cout << "����2 :�鿴�Ŷ��ճ�" << endl;
					cout << "����3 :����Ŷ��ճ�" << endl;
					cout << "����4 :ɾ���Ŷ��ճ�" << endl;
					cout << "����5 :������һ���˵�" << endl;
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
							cout << "����������Ҫʹ�õĹ���" << endl;
							cout << "����1 :�ֶ�����ճ̰���" << endl;
							cout << "����2 :ϵͳ�Զ�����ճ̰���" << endl;
							cout << "����3 :������һ���˵�" << endl;
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
									cout << "����1 :��������ճ̰���" << endl;

									cout << "����2 :������һ���˵�" << endl;
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
									cout << "����1 :��������ճ̰���" << endl;

									cout << "����2 :������һ���˵�" << endl;
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
				cout << "����δ�����Ŷ�,�޷��鿴�����Ŷ�!" << endl;
				break;
			}

		}
		case 2:

		{
			if (user.myteam > " ")
			{
				cout << "���Ѿ��������Ŷ�,�޷��ظ������µ��Ŷ�!" << endl;
				break;
			}
			else
			{
				string tempname, teampassword;
				cout << "��������Ҫ������Ŷ�:" << endl;
				cin >> tempname;
				group gp(tempname);
				gp.addmenmber(user);
				
				cout << "�ŶӼ���ɹ�!" << endl;
				cout << endl;
				break;
			}
		}


		case 3:
		{cout << "����������Ҫ�������Ŷ�����:";
		string name;
		cin >> name;
	
		
		user.myteam = name;
		
		group gp(name, 1);//�����Ŷӵ�txt�ļ�	
		//ͬʱ���洴���˵���Ϣ
		gp.addmenmber(user);
		
		cout << "�����Ŷӳɹ�!";
		cout << endl;
		break; }
		case 4:
		{
			flag = 1;
			break;
		}
		case 5:
		{
			cout << "�����˳��ɹ�!" << endl;
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

//void Management::readfile(const string filename)//������ȡ�ļ�
//{
//	fstream fin(filename,ios::in);
//	if (!fin.is_open())
//	{
//		cout << "�ļ���ʧ��";
//		return;
//	}
//	//��ȡ��ͷ
//	char buf[2000] = { 0 };//
//	fin.getline(buf, 2000);//�������и�getline,�ص����һ��
//	cout << buf << endl;
//	fileheader = buf;
//	//��ȡ����
//	while (!fin.eof())//һֱ�����ļ�β
//	{
//		char data[2000] = { 0 };
//		fin.getline(data, 2000);
//
//		if (strlen(data) == 0)//��ֹ�������һ������
//			break;
//		stringstream ss(data);
//
//		user temp;//��ʱ���û���������������
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
	if (!write.is_open())//��ֹ�ļ�û�гɹ�����
	{
		cerr << "�ļ���ʧ��" << endl;
		return;
	}

	write.write(fileheader.c_str(), fileheader.size());
	for (auto& userr : users)
	{
		string temp = userr.cout();//���봴��һ����ʱ�ı���,��Ȼ�����÷���ֵ�ڵĶ���
		write.write(temp.c_str(), temp.size());//ע��ƴ��֮���������ҲҪ��string��str��д��
	}
}

int Management::getWeekDay(int year,int month,int day)
{
	
		int y = year, m = month, d = day;
		if (m == 1 || m == 2) { //��һ�ºͶ��¿�����һ���ʮ���º�ʮ����
			m += 12;
			y--;
		}
		int w = (d + 2 * m + 3 * (m + 1) / 5 + y + y / 4 - y / 100 + y / 400 + 1) % 7; //��ķ����ɭ���㹫ʽ
		return w; //�������ڼ���0-6��ʾ��һ�����գ�


}

string Management::getnowtime()//����ϵͳ��ǰ��ʱ��
{
	
		time_t t = time(NULL); //��ȡ��ǰʱ���

		struct tm tm; //����һ��struct tm����

		localtime_s(&tm, &t); //ת��Ϊ����ʱ��ṹ��

		std::string date; //����һ���ַ�������

		date = std::to_string(tm.tm_year + 1900) + "-" + std::to_string(tm.tm_mon + 1) + "-" + std::to_string(tm.tm_mday); //ƴ���������ַ���

		return date; //�����ַ�������
	
}



//void updateuser(string a, user user)
//{
//	group gp(a, user);
//}