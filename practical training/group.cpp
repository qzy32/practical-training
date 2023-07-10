#include "group.h"

group::group(string a,int b)//�����Ŷӵ�ʱ��ʹ��
{
    gtime.resize(365, vector<int>(24, 0));//��ʼ���Ŷ�ʱ��
    name = a;
    fstream ff(name + "user.txt", ios::app);
    fstream fff(name + "schedule.txt", ios::app);
    fff << ',' << ',' << ',' << ',' << '.';

    if (!(ff.is_open()&&fff.is_open()))
    {
        std::cout << "�����Ŷ��û��ļ�ʱ����ʧ��!";
    }
    else
    {
        ff.close();
        fff.close();
    }
}

group::group(string temp)//�û�ֻ������ ���ճ̰��� //�Ѿ���txt�ļ��е������û���Ϣ���浽��group����//��¼��ʱ��ʹ��
{
   
    name = temp;
    gtime.resize(365, vector<int>(24, 0));//��ʼ���Ŷ�ʱ��
   
   

    getmsg();
}


group::group(string a, user user)//���������Ŷ��г�Ա����Ϣ
{
    name = a;
    ifstream fin(name+"user.txt", ios::in);
    ofstream fout("temp.txt", ios::out);
    if (!(fin.is_open() && fout.is_open()))
    {
        std::cout << "�����Ŷӳ�Ա��Ϣʱ �ļ���ʧ��!" << endl;
    }
    else
    {

        string line;
        while (getline(fin, line))
        {

            int pos1 = line.find('/');

            int pos2 = line.find('/', pos1 + 1);

            int pos3 = line.find('/', pos2 + 1);


            string gname = line.substr(0, pos1); // ��ȡ����

            string gpassword = line.substr(pos1 + 1, pos2 - pos1 - 1);//��ȡ����



            if ((user.name == gname && user.password == gpassword))// �������ƥ��
            { 
                fout << gname << '/' << gpassword << '/' ; // д�����������룬��/�ָ�              

                for (int i = 0; i < user.schedule.size(); i++)//���û����г̰�����Ϣ��ŵ�schedule�ṹ�� vector(��������ʱ��ľ�������,��ʼʱ��ͽ���ʱ��)
                {
                    fout << user.schedule[i].schdulee << "," << user.schedule[i].start << "," << user.schedule[i].end << "," << user.schedule[i].sname << "," << user.schedule[i].op;
                    if (i != schedule.size() - 1)
                        fout << ".";
                }

                fout << '/' << endl;
            }
            else
            {
                fout << line << endl;
            }
        }

        // fout<< "/t" << x << "," <<y << endl;
        fout.close(); // �ر��ļ�
        fin.close();
        string a = name + "user.txt";
        std::remove(a.c_str()); // ɾ��ԭ�����ļ�

        std::rename("temp.txt", a.c_str()); // ��������ʱ�ļ�Ϊԭ�����ļ���
        std::cout << "�Ŷ����û�����Ϣ���³ɹ�!" << endl;
    }  
}

void group::addmenmber(user &a)//��ӳ�Ա//ok
{
    a.myteam = name;
    //�Ƚ��Ŷ��еĿ���ʱ�����ú�
    for (int i = 0; i < a.schedule.size(); i++)
    {
        if ( a.schedule[i].op == 1)//����û�����Ϊ�˹��� ,�ͰѶ�Ӧ��ʱ���ɷ�æ
        {
            int dayday = a.returndate(schedule[i].schdulee);

            for (int j = a.schedule[i].start; j < a.schedule[i].end; j++)
            { // ���Ŷ��ж�ά�����ж�Ӧ��Ԫ����Ϊ1
                gtime[dayday][j] = 1;
            }
        }
    }
   
	member.push_back(a);//��a�ȴ��뵽��Ա��
    string b = name + "user.txt";
	fstream fout(b, ios::app);
	if (!fout.is_open())
	{
		std::cout << "�������û�ʱ,�Ŷ��ļ���ʧ��" << endl;
		exit(123);

	}
	else
	{    // ����ļ��򿪳ɹ�
        fout << a.name << '/' << a.password << '/';
            // д�����������룬��\t�ָ�
              
            for (int i = 0; i < schedule.size(); i++)//���û����г̰�����Ϣ��ŵ�schedule�ṹ�� vector(��������ʱ��ľ�������,��ʼʱ��ͽ���ʱ��)
            {
                fout << a.schedule[i].schdulee << "," << a.schedule[i].start << "," << a.schedule[i].end << "," << a.schedule[i].sname << "," << a.schedule[i].op;
                if (i != schedule.size() - 1)
                    fout << ".";
            }

            fout << '/'<<endl;
        
	}
    fout.close();
    a.savefile();
}

void group::removemember(user& a)
{//��ɾ�������û���vector�������Ϣ
    for (int i = 0; i < member.size(); i++) 
    {
        if (member[i].name == a.name&&member[i].password==a.password)//�û���������һ����ʱ�����ɾ��,��Ȼͬ����ʱ�����ɾ��
        {
            member.erase(member.begin() + i);//!!erase
            break;
        }
    }


    // ���ļ���ɾ���û���Ϣ
    ifstream fin(name + ".txt",ios::in); // ���ļ�����ȡģʽ
    ofstream fout("temp.txt",ios::out); // ����ʱ�ļ���д��ģʽ
    if (!(fin.is_open() && fout.is_open()))
    { 
        std::cout << "ɾ���ļ�����Ϣʱ�ļ���ʧ��!" << endl;
    }
    else 
    { // ����ļ����򿪳ɹ�
        string line; // ÿ������
        while (getline(fin, line)) 
        { 
            // ����ÿ������
            int pos1 = line.find('/');
          
            string name = line.substr(0, pos1); // ��ȡ����
       
         
            if (name != a.name) 
            { // ���������ƥ��
                fout << line << endl; // д��ԭ��������
            }
        }
        fin.close(); // �ر��ļ�
        fout.close(); // �ر��ļ�
        std::remove((name + ".txt").c_str()); // ɾ��ԭ�����ļ�
        std::rename("temp.txt", (name + ".txt").c_str()); // ��������ʱ�ļ�Ϊԭ�����ļ���
        std::cout << "��Ա�Ƴ��ɹ���" << endl;
    }
}

int group::arrangeactivity()//�ɹ�
{
    user a;
    string aname;//�����
    int  op=1, activitylong;
    string date;
    int deadline;
    std::cout << "���������ƣ�" << endl;
    cin >> aname;

    std::cout << "������û������Ҫ����һ�죨��ʽ���� 2000-10-1����" << endl;
    cin >> date;

    std::cout << "�û�ܽ��������켸��֮�ڰ��ţ�" << endl;
    cin >> deadline;//��һ���õĵ�

    std::cout << "������������ʱ��(ʱ��Ϊ������Сʱ)" << endl;
    cin >> activitylong;

 
   

    //��ȷ������ÿ����Ա�Ŀ���ʱ��
  
    //for (int i = 0; i < member.size(); i++)//ֻҪ��һ�������Ǹ�ʱ����а���,��ô��û��
    //{
    //    for (int j=0; j < member[i].time.size(); j++)
    //    {
    //       for (int k=0;k<member[i].time[j].size();k++)
    //       {
    //           if (member[i].visible[j][k] != 1)
    //           {
    //               if (member[i].time[j][k] == 1)
    //               {
    //                   gtime[j][k] = 1;
    //               }
    //           }
    //            
    //        }
    //     }
    //    
    //}

    int actdate = a.returndate(date);//��һ��

    int flag = 0;
    int flag2 = 0;//��������ѭ��
   
    for (int k = 0; k <= deadline; k++)//�����������
    {
        
        for (int i = actdate - k; i <= actdate + k; i++)//��һ��ȷ��ʲôʱ����԰���
        {
            for (int j = 6; j < 22; j++)
            {
               
                if (gtime[i][j] == 0)
                {
                    int flag3 = 0;
                    for (int q = 0; q < activitylong; q++)
                    {
                        if (gtime[i][j + q] == 1)
                        {
                            flag3 = 1;
                        }

                    }
                    if (flag3==0)//һ�ҵ����ʵ�ʱ��ξͿ���д���ճ̰���
                    {
                        cout << 11;
                        schdule temp;//����һ����ʱ�ı���Ȼ��push���ҵ�schedule vector
                        temp.schdulee = date;
                        temp.start = j;
                        temp.end = j+activitylong;
                        temp.op = op;
                        temp.sname = aname;
                        cout << 123;
                        schedule.push_back(temp);
                        flag = 1;
                        flag2 = 1;
                        savefile();
                        cout << 345;
                        std::cout << "���Զ�Ϊ���ҵ����ʵ�ʱ��" << endl;
                         std::cout <<"������ŵ�" << temp.schdulee << " " << temp.start << "�㵽" << temp.end << "��";
                        std::cout << temp.sname << endl;
                        for (int q = 0; q < activitylong; q++)
                        {
                            gtime[i][j + q] = 1;
                            

                        }
                    }
                }
                if (flag2 == 1)
                    break;
            }

            if (flag2 == 1)
                break;
        }
        if (flag2 == 1)
            break;
    }
  
    if (flag == 0)
    {
        std::cout << "��Ǹ,û���ʺϵ�ʱ��������Ż" << endl;

    }
           
    return 0;
}

void group::show()
{
    std::cout << "�Ŷ�һ����" << member.size() << "����Ա";
    std::cout << "��Ա��������:" << endl;
    for (int i = 0; i < member.size(); i++)
    {
        std::cout <<i<<"   " << member[i].name << "    ";
    }
}

void group::savefile()
{
    //�����ȱ����Ŷ��û���Ϣ
    ifstream fin(name+"user.txt", ios::in);
    ofstream fout("temp.txt", ios::out);
    if (!(fin.is_open() && fout.is_open()))
    {
        std::cout << "�����Ŷ��û���Ϣʱ �ļ���ʧ��!" << endl;

    }
    else
    {
        for (int i = 0; i < member.size(); i++)
        {
            fout << member[i].name << '/' << member[i].password << '/'; // д�����������룬��\t�ָ�
           

            for (int j = 0; j < member[i].schedule.size(); j++)//���û����г̰�����Ϣ��ŵ�schedule�ṹ�� vector(��������ʱ��ľ�������,��ʼʱ��ͽ���ʱ��)
            {
                fout << member[i].schedule[j].schdulee << "," << member[i].schedule[j].start << "," << member[i].schedule[j].end << "," << member[i].schedule[j].sname << "," << member[i].schedule[j].op;
                if (j != member[i].schedule.size() - 1)
                    fout << ".";
            }

            fout << '/'<<endl;

        }
        fout.close(); // �ر��ļ�
        fin.close();
        string a = name + "user.txt";
        std::remove(a.c_str()); // ɾ��ԭ�����ļ�

        std::rename("temp.txt", a.c_str()); // ��������ʱ�ļ�Ϊԭ�����ļ���
        std::cout << "�Ŷӵ��û���Ϣ����ɹ�" << endl;
    }

    //���ű����Ŷӵ��ճ̰���
    ifstream ffin(name + "schedule.txt", ios::in);
    ofstream ffout("temp.txt", ios::out);
    if (!(ffin.is_open() && ffout.is_open()))
    {
        std::cout << "�����Ŷ��ճ̰���ʱ �ļ���ʧ��!" << endl;
    }
    else
    {
        for (int i = 0; i < schedule.size(); i++)
        {
           
                ffout << schedule[i].schdulee << "," << schedule[i].start << "," << schedule[i].end << "," << schedule[i].sname << "," << schedule[i].op;
                
                    ffout << ".";
                   
        }
       
        ffout.close(); // �ر��ļ�
        ffin.close();
        string b = name + "schedule.txt";
        std::remove(b.c_str()); // ɾ��ԭ�����ļ�

        std::rename("temp.txt", b.c_str()); // ��������ʱ�ļ�Ϊԭ�����ļ���
        std::cout << "�Ŷӵ��ճ̰�����Ϣ����ɹ�" << endl;
    }
}

void group::getmsg()//��txt�ļ�����Ϣ���뵽�ڿ����
{
    //�Ƚ��Ŷ��û�����Ϣ���뵽group�е�vector��
    string a = name + "user.txt";
    ifstream ff(a);
    string line;
    user utemp;
    if (!ff.is_open())
    {
        std::cout << "���Ŷ��û���Ϣ���뵽groupʱ, �ļ���ʧ��!" << endl;

    }
    else
    {
        //���ȵ��ҵ��������û���Ϣ����һ��

        while (getline(ff, line))
        {
            user usertemp;
            int pos1 = line.find('/');//ǰ���������

            int pos2 = line.find('/', pos1 + 1);// ǰ���������


            int pos3 = line.find('/', pos2 + 1);//ǰ������ճ̰���

            string gname = line.substr(0, pos1); // ��ȡ����

            string gpassword = line.substr(pos1 + 1, pos2 - pos1 - 1);//��ȡ����

            string temp9 = line.substr(pos2 + 1, pos3 - pos2 - 1);//��ȡ�ճ̰���

            usertemp.name = gname;

            usertemp.password = gpassword;
            stringstream ss;
            ss << temp9;
            string temp2;
            ss >> temp2;
            if (temp2 > " ")
            {
                std::cout << "123123213";
                while (getline(ss, temp2, '.'))//�����Դ����Ƿ����
                {
                    schdule stemp;//����һ����ʱ�ı���,�ٰѸñ���push��ȥ

                    int pos3 = temp2.find(',');//���ں���Ķ���
                    int pos4 = temp2.find(',', pos3 + 1);
                    int pos5 = temp2.find(',', pos4 + 1);
                    int pos6 = temp2.find(',', pos5 + 1);


                    string time = temp2.substr(0, pos3); // ��ȡ�������
                   
                    string sstart = temp2.substr(pos3 + 1, pos4 - pos3 - 1);//��ȡ��ʼʱ��ͽ�ֹʱ��
                    string eend = temp2.substr(pos4 + 1, pos5 - pos4 - 1);

                    string schdulename = temp2.substr(pos5 + 1, pos6 - pos5 - 1);;// ��ȡ�����
                    string oop = temp2.substr(pos6 + 1);//��ȡ�û���ѡ��

                    int ssstart = stoi(sstart);//������ת����int����
                    int eeend = stoi(eend);
                    int ooop = stoi(oop);


                    //�ȸ��ݽ�ȡ�����ڶ��û��Ŀ���ʱ���
                    stemp.schdulee = time;
                    stemp.start = ssstart;
                    stemp.end = eeend;
                    stemp.op = ooop;
                    stemp.sname = schdulename;
                    usertemp.schedule.push_back(stemp);
                    temp2.clear();
                    
                    if (ooop == 1)//����û�����Ϊ�˹��� ,�ͰѶ�Ӧ��ʱ���ɷ�æ
                    {
                        int dayday = utemp.returndate(time);

                        for (int i = ssstart; i < eeend; i++)
                        { // ����ά�����ж�Ӧ��Ԫ����Ϊ1
                            gtime[dayday][i] = 1;
                        }
                    }

                }
            }
            member.push_back(usertemp);
        

        }
        ff.close();
    }
        //�ٽ��ճ̰��ŵ���
    string b = name + "schedule.txt";
        ifstream fin(b);
        string temp2;
        if (!fin.is_open())
        {
            std::cout << "���Ŷ��ճ̰��ŵ��뵽groupʱ, �ļ���ʧ��!" << endl;

        }
        else
        {
            while(getline(fin,temp2,'.'))
                //�����Դ����Ƿ����
                {
                    schdule stemp;//����һ����ʱ�ı���,�ٰѸñ���push��ȥ

                    int pos3 = temp2.find(',');//���ں���Ķ���
                    int pos4 = temp2.find(',', pos3 + 1);
                    int pos5 = temp2.find(',', pos4 + 1);
                    int pos6 = temp2.find(',', pos5 + 1);

                    
                    string time = temp2.substr(0, pos3); // ��ȡ�������
                    std::cout << "ʧ��ʧ��!" << endl;
                    if (time > " ")
                    {
                        std::cout << "�ɹ��ɹ���!" << endl;
                        string sstart = temp2.substr(pos3 + 1, pos4 - pos3 - 1);//��ȡ��ʼʱ��ͽ�ֹʱ��
                        string eend = temp2.substr(pos4 + 1, pos5 - pos4 - 1);

                        string schdulename = temp2.substr(pos5 + 1, pos6 - pos5 - 1);;// ��ȡ�����
                        string oop = temp2.substr(pos6 + 1);//��ȡ�û���ѡ��

                        int ssstart = stoi(sstart);//������ת����int����
                        int eeend = stoi(eend);
                        int ooop = stoi(oop);


                        //�ȸ��ݽ�ȡ�����ڶ��û��Ŀ���ʱ���
                        stemp.schdulee = time;
                        stemp.start = ssstart;
                        stemp.end = eeend;
                        stemp.op = ooop;
                        stemp.sname = schdulename;
                        schedule.push_back(stemp);
                        temp2.clear();
                    }
                }
         
        }
    
        fin.close();
}

void  group::setschedule()//���������ճ̵�ģʽ һ�����ֶ�����
{
    string date; // ���� 

    int start, end; // ��ʼʱ��ͽ���ʱ��

    string event; // ��������

    int op=1;//��ʾ�û���ѡ��,�Ƿ����繫��

    std::cout << "�������ճ̰��ŵ����ڣ���ʽ���� 2000-10-1����" << endl;
    cin >> date;
    std::cout << "�����뿪ʼʱ��(24���ʾ)   ������������������15" << endl;
    cin >> start;
    std::cout << "���������ʱ��" << endl;
    cin >> end;
    std::cout << "�������������ݣ�" << endl;
    cin >> event;
   


    schdule temp;//����һ����ʱ�ı���Ȼ��push���ҵ�schedule vector
    temp.schdulee = date;
    temp.start = start;
    temp.end = end;
    temp.op = op;
    temp.sname = event;
    schedule.push_back(temp);
    std::cout << "���ڶ��ǳɹ���!";
    savefile();

}

void group::showschedule()
{
    std::cout << "�Ŷӵ��ճ̰�������:" << endl;
    for (int i = 0; i < schedule.size(); i++)
    {
        std::cout << i << "   ";
        std::cout << schedule[i].schdulee << " " << schedule[i].start << "�㵽" << schedule[i].end << "��";
        std::cout << schedule[i].sname << endl;
    }

}

void group::removescheduele()
{
    //�Ȼ�ȡ��Ҫɾ���ճ̵ĸ�����Ϣ
    string activity, sname;
    int start, end;//��ʼʱ��ͽ�ֹʱ��
    std::cout << "����������Ҫɾ�����г̰��ŵ�ʱ��" << endl;
    cin >> activity;
    std::cout << "��������ճ̰��ŵĿ�ʼʱ��:" << endl;
    cin >> start;
    std::cout << "��������ճ̰��ŵĽ���ʱ��:" << endl;
    cin >> end;
    std::cout << "��������ճ̰��ŵ�����:" << endl;
    cin >> sname;



    //ɾ�����������ݳ�Ա�е���Ϣ��
    for (int i = 0; i < schedule.size(); i++)
    {
        if (activity == schedule[i].schdulee && start == schedule[i].start && end == schedule[i].end && schedule[i].sname == sname)
        {
            schedule.erase(schedule.begin() + i);//!!erase

        }
    }

    //��������txt�ļ��е��ճ̰���
    savefile();


}




