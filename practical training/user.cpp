#include "user.h"
int commonyear[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };//ƽ��
void user::setuser(string a, string b)//ok
{

	name = a;
	password = b;
	

}

user::user(): time(365, vector<int>(24, 0)),
visible(365, vector<int>(24, 0)),
schedule(vector<schdule>())//�ȳ�ʼ���û���ʱ��Ϳɼ�����//ok
{
    myteam = " ";

}

string user::cout()
{  
	stringstream ss;

       ss << name << '/' << password << '/'; for (int i = 0; i < schedule.size(); i++)
    {
        ss << schedule[i].schdulee << '/';
    }
	return ss.str();



}

void user::setchedule()
{
    string date; // ���� 

    int start, end; // ��ʼʱ��ͽ���ʱ��

    string event; // ��������

    int op;//��ʾ�û���ѡ��,�Ƿ����繫��

    std::cout << "�������ճ̰��ŵ����ڣ���ʽ���� 2000-10-1����" << endl;
    cin >> date;
    std::cout << "�����뿪ʼʱ��(24���ʾ)   ������������������15" << endl;
    cin >> start;
    std::cout << "���������ʱ��" << endl;
    cin >> end;
    std::cout << "�������������ݣ�" << endl;
    cin >> event;
    std::cout << "���ճ̰����Ƿ񹫿�" << endl;

    std::cout << "����1��ʾ����  ����2��ʾ������" << endl;

    cin >> op;

    schdule temp;//����һ����ʱ�ı���Ȼ��push���ҵ�schedule vector
    temp.schdulee = date;
    temp.start = start;
    temp.end = end;
    temp.op = op;
    temp.sname = event;
    schedule.push_back(temp);
  

    int index = returndate(date); // ������ת��Ϊ��ά�����е�������
 
    //for (int i = start; i < end; i++)
    //{ // ����ά�����ж�Ӧ��Ԫ����Ϊ1
    //    time[index][i] = 1;
    //}

    //if (op == 2)
    //{
    //    for (int i = start; i < end; i++)
    //    { // ����ά�����ж�Ӧ��Ԫ����Ϊ1
    //        visible[index][i] = 1;
    //    }

    //} 
    //ifstream fin("resource.txt", ios::in);
    //ofstream fout("temp.txt", ios::out);
    //if (!(fin.is_open() && fout.is_open()))
    //{
    //    std::cout << "����û��ճ̰���ʱ �ļ���ʧ��!" << endl;
    //}
    //else
    //{
    // 
    //    string line;
    //    while (getline(fin, line))
    //    {
    //    
    //        int pos1 = line.find('/');
    //        
    //        int pos2 = line.find('/', pos1 + 1);// �ҵ���һ��\t��λ��

    //        int pos3 = line.find('/', pos2 + 1);
    // 
    //        
    //        string gname = line.substr(0, pos1); // ��ȡ����
    //       
    //        string gpassword = line.substr(pos1 + 1, pos2-pos1-1);//��ȡ����

    //        
    //                             
    //        if ((name == gname && password ==gpassword))
    //        { // �������ƥ��
    //            fout << gname << '/' << gpassword << '/' << myteam << '/'; // д�����������룬��\t�ָ�
    //          
    //            //for (int i = 0; i < time.size(); i++)// д���ճ����ŵĿ���ʱ�䣬��\t�ָ�
    //            //{ 
    //            //    for (vector<int>::iterator it = (time[i].begin()); it != time[i].end(); it++)
    //            //    {

    //            //        fout << *it;
    //            //        if (it != time[i].end() - 1)
    //            //            fout << ",";

    //            //    }
    //            //    if (i != time.size() - 2)
    //            //        fout << ".";
    //            //}
    //            //fout << "/t";

    //          
    //            //for (int i = 0; i < visible.size(); i++)     //д���ճ̰����Ƿ�ɼ�  
    //            //{ 
    //            //    for (vector<int>::iterator it = (visible[i].begin()); it != visible[i].end(); it++)// д���ճ����ţ���\t�ָ�
    //            //    {
    //            //        fout << *it;
    //            //        if (it != visible[i].end() - 1)
    //            //            fout << ",";
    //            //    }
    //            //    if (i != visible.size() - 2)
    //            //        fout << ".";
    //            //}
    //            //fout << "\t";

    //            for (int i = 0; i <schedule.size(); i++)//���û����г̰�����Ϣ��ŵ�schedule�ṹ�� vector(��������ʱ��ľ�������,��ʼʱ��ͽ���ʱ��)
    //            {
    //                fout << schedule[i].schdulee << "," << schedule[i].start << "," << schedule[i].end << "," <<schedule[i].sname<<","<< op;
    //                if (i != schedule.size()-1)
    //                    fout << ".";
    //            }
    //           
    //            fout << endl;
    //        }
    //        else
    //        {
    //            fout << line << endl;
    //        }
    //    }

    //   // fout<< "/t" << x << "," <<y << endl;
    //    fout.close(); // �ر��ļ�
    //    fin.close();
    //    string a = "resource.txt";
    //    remove(a.c_str()); // ɾ��ԭ�����ļ�

    //    rename("temp.txt", a.c_str()); // ��������ʱ�ļ�Ϊԭ�����ļ���
    //    std::cout << "�ճ̰�����ӳɹ�!" << endl;
    //}
   
    savefile();
 
}//ok//ok

//void user::lookforschedule()//��ʱû��
//{
//    string date; // ����
//
//    std::cout << "���������ڣ�yyyy-mm-dd����" << endl;
//    cin >> date;
//
//    int index = returndate(date); // ������ת��Ϊ��ά�����е�������
//    bool flag = true; // ��־λ����ʾ�������Ƿ��п�
//    for (int i = 0; i < 24; i++) { // ������ά�����ж�Ӧ����
//        if (time[index][i] == 1) { // �����һ��Ԫ��Ϊ1���򽫱�־λ��Ϊfalse��������ѭ��
//            flag = false;
//            break;
//        }
//    }
//    if (flag) { // ����������пգ�����п�
//        std::cout << "�������пա�" << endl;
//    }
//    else { // ���������û�пգ����û�п�
//        std::cout << "������û�пա�" << endl;
//    }
//
//  
//}
 
int user::returndate(string date)//�����û��������������������һ��
{
    // ��ȡ���,�·ݻ�������
    int posi1, posi2, posi3;
    posi1 = date.find('-', 0);
    posi2 = date.find('-', posi1 + 1);
  
    int year = stoi(date.substr(0, posi1)); 

    int month = stoi(date.substr(posi1 +1, posi2));
  
    int day = stoi(date.substr(posi2 +1));

    int total = 0; // 
    for (int i = 1; i < month; i++)// �����·��ۼ�����
    { 
        switch (i) 
        {
        case 1: case 3: case 5: case 7: case 8: case 10: case 12:
            total += 31;
            break;
        case 4: case 6: case 9: case 11:
            total += 30;
            break;
        case 2:
            if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
            {
                total += 29;
            }
            else
            {
                total += 28;
            }
            break;
        }
    }
  
    total += day - 1; // ���������ۼ�����
    return total;
   
}

void user::removeschedule()
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
        if (activity == schedule[i].schdulee  &&  start == schedule[i].start && end== schedule[i].end && schedule[i].sname==sname)
        {
            schedule.erase(schedule.begin() + i);//!!erase
            
        }
    }

    //��������txt�ļ��е��ճ̰���
    savefile();

}



void user::showmonthschedule(int year,int month)//����ȷ�����µ��ճ̰���
{
    int flag = 0;
    //����һ���Ƿ����ճ̰����ڱ���
    for (int i = 0; i < schedule.size(); i++)//�ȱ���ÿһ���ճ̰���,�ٸ���������������������
    {
        
        int posi1, posi2, posi3;
        posi1 = schedule[i].schdulee.find('-', 0);
        posi2 = schedule[i].schdulee.find('-', posi1 + 1);

        int syear = stoi(schedule[i].schdulee.substr(0, posi1));//��ȡ��

        int smonth = stoi(schedule[i].schdulee.substr(posi1 + 1, posi2));//��ȡ�·�

        int sday = stoi(schedule[i].schdulee.substr(posi2 + 1));//��ȡ�·�


        int lastday = commonyear[smonth];//��ȡ�����һ���ж�����
        //���ȵ������һ��
        if (syear == year && smonth == month)
        {
            flag = 1;
            std::cout << i << "   ";
            std::cout << schedule[i].schdulee << " " << schedule[i].start << "�㵽" << schedule[i].end << "��";
            std::cout << schedule[i].sname << endl << endl;
        }
    }
    if (flag == 0)
    {
        std::cout << endl;
        std::cout << "�����㲢û���ճ̰���,�����Ƿ��ڱ�����ӹ��ճ̰���!" << endl;
        return;
    }
   
        return;

    //����ſ�ʼ����ճ̰���
    std::cout << "**************************************************" << endl;
    std::cout << "�𾴵��û����,����ճ̰�������:" << endl;
  
    for (int i = 0; i < schedule.size(); i++)//�ȱ���ÿһ���ճ̰���,�ٸ���������������������
    {
        int posi1, posi2, posi3;
        posi1 = schedule[i].schdulee.find('-', 0);
        posi2 = schedule[i].schdulee.find('-', posi1 + 1);

        int syear = stoi(schedule[i].schdulee.substr(0, posi1));//��ȡ��

        int smonth = stoi(schedule[i].schdulee.substr(posi1 + 1, posi2));//��ȡ�·�

        int sday = stoi(schedule[i].schdulee.substr(posi2+1));//��ȡ�·�


        int lastday = commonyear[smonth];//��ȡ�����һ���ж�����
        //���ȵ������һ��
        if (syear == year && smonth == month)
        {
            flag = 1;
            std::cout << i << "   ";
            std::cout << schedule[i].schdulee << " " << schedule[i].start << "�㵽" << schedule[i].end << "��";
            std::cout << schedule[i].sname << endl << endl;
        }
    }
    std::cout << "**************************************************" << endl;

}

void user::getmeg()
{


    fstream ff("resource.txt", ios::in);
    string line;
    if (!ff.is_open())
    {
        std::cout << "����ճ̰���ʱ,�ļ���ʧ��!" << endl;

    }
    else
    {
        //���ȵ��ҵ��������û���Ϣ����һ��

        while (getline(ff, line))
        {
            int pos1 = line.find('/');//ǰ���������

            int pos2 = line.find('/', pos1 + 1);// ǰ���������

            int pos3 = line.find('/', pos2 + 1);//ǰ������Ŷ�����

            int pos4 = line.find('/', pos3 + 1);//ǰ������ճ̰���

            string gname = line.substr(0, pos1); // ��ȡ����

            string gpassword = line.substr(pos1 + 1, pos2-pos1-1);//��ȡ����
           
        
            if (gname == name && gpassword == password)
            {

                myteam = line.substr(pos2 + 1, pos3 - pos2 - 1);//��д����ŶӴ���


                string temp9 = line.substr(pos3 + 1, pos4 - pos3 - 1);

                stringstream ss;
                ss << temp9;
                string temp2;
                while (getline(ss, temp2, '.'))//�����Դ����Ƿ����
                {
                    schdule stemp;//����һ����ʱ�ı���,�ٰѸñ���push��ȥ

                    int pos5 = temp2.find(',');//���ں���Ķ���
                    int pos6 = temp2.find(',', pos5 + 1);
                    int pos7 = temp2.find(',', pos6 + 1);
                    int pos8 = temp2.find(',', pos7 + 1);


                    string time = temp2.substr(0, pos5); // ��ȡ�������
                    string sstart = temp2.substr(pos5 + 1, pos6 - pos5 - 1);//��ȡ��ʼʱ��ͽ�ֹʱ��
                    string eend = temp2.substr(pos6 + 1, pos7 - pos6 - 1);

                    string schdulename = temp2.substr(pos7 + 1, pos8 - pos7 - 1);;// ��ȡ�����
                    string oop = temp2.substr(pos8 + 1);//��ȡ�û���ѡ��

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
    }
}

void user::savefile()
{
    ifstream fin("resource.txt", ios::in);
    ofstream fout("temp.txt", ios::out);
    if (!(fin.is_open() && fout.is_open()))
    {
        std::cout << "�����û���Ϣʱ �ļ���ʧ��!" << endl;
    }
    else
    {

        string line;
        while (getline(fin, line))
        {

            int pos1 = line.find('/');

            int pos2 = line.find('/', pos1 + 1);// �ҵ���һ��/��λ��

            int pos3 = line.find('/', pos2 + 1);


            string gname = line.substr(0, pos1); // ��ȡ����

            string gpassword = line.substr(pos1 + 1, pos2 - pos1 - 1);//��ȡ����



            if ((name == gname && password == gpassword))
            { // �������ƥ��
                fout << gname << '/' << gpassword << '/' << myteam << '/'; // д�����������룬��/�ָ�              

                for (int i = 0; i < schedule.size(); i++)//���û����г̰�����Ϣ��ŵ�schedule�ṹ�� vector(��������ʱ��ľ�������,��ʼʱ��ͽ���ʱ��)
                {
                    fout << schedule[i].schdulee << "," << schedule[i].start << "," << schedule[i].end << "," << schedule[i].sname << "," << schedule[i].op;
                    if (i != schedule.size() - 1)
                        fout << ".";
                }

                fout <<'/'<< endl;
            }
            else
            {
                fout << line << endl;
            }
        }

        // fout<< "/t" << x << "," <<y << endl;
        fout.close(); // �ر��ļ�
        fin.close();
        string a = "resource.txt";
        remove(a.c_str()); // ɾ��ԭ�����ļ�

        rename("temp.txt", a.c_str()); // ��������ʱ�ļ�Ϊԭ�����ļ���

    }



}

void user::creatmonthreport(int year,int month,int day)
{
    std::cout << "���»��������:";


}



void user::creatweekreport(int year, int month, int day)
{
    std::cout << "���ܻ��������:";

}

void user::showschedule()
{
    
    std::cout << endl << "�ճ̰�������,�������ʾ�ճ̰�����Ϣ��ɾ���ճ̰���" << endl;
    for (int i = 0; i < schedule.size(); i++)
    {
        std::cout << i << "   ";
        std::cout << schedule[i].schdulee << " " << schedule[i].start << "�㵽" << schedule[i].end << "��";
        std::cout << schedule[i].sname << endl;
    }
}







