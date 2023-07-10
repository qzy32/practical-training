#include "group.h"

group::group(string a,int b)//创立团队的时候使用
{
    gtime.resize(365, vector<int>(24, 0));//初始化团队时间
    name = a;
    fstream ff(name + "user.txt", ios::app);
    fstream fff(name + "schedule.txt", ios::app);
    fff << ',' << ',' << ',' << ',' << '.';

    if (!(ff.is_open()&&fff.is_open()))
    {
        std::cout << "创建团队用户文件时创建失败!";
    }
    else
    {
        ff.close();
        fff.close();
    }
}

group::group(string temp)//用户只有姓名 和日程安排 //已经把txt文件中的所有用户信息储存到了group里面//登录的时候使用
{
   
    name = temp;
    gtime.resize(365, vector<int>(24, 0));//初始化团队时间
   
   

    getmsg();
}


group::group(string a, user user)//用来更新团队中成员的信息
{
    name = a;
    ifstream fin(name+"user.txt", ios::in);
    ofstream fout("temp.txt", ios::out);
    if (!(fin.is_open() && fout.is_open()))
    {
        std::cout << "耿欣团队成员信息时 文件打开失败!" << endl;
    }
    else
    {

        string line;
        while (getline(fin, line))
        {

            int pos1 = line.find('/');

            int pos2 = line.find('/', pos1 + 1);

            int pos3 = line.find('/', pos2 + 1);


            string gname = line.substr(0, pos1); // 截取姓名

            string gpassword = line.substr(pos1 + 1, pos2 - pos1 - 1);//截取密码



            if ((user.name == gname && user.password == gpassword))// 如果姓名匹配
            { 
                fout << gname << '/' << gpassword << '/' ; // 写入姓名和密码，用/分隔              

                for (int i = 0; i < user.schedule.size(); i++)//把用户的行程安排信息存放到schedule结构体 vector(包括空余时间的具体名字,开始时间和结束时间)
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
        fout.close(); // 关闭文件
        fin.close();
        string a = name + "user.txt";
        std::remove(a.c_str()); // 删除原来的文件

        std::rename("temp.txt", a.c_str()); // 重命名临时文件为原来的文件名
        std::cout << "团队中用户的信息更新成功!" << endl;
    }  
}

void group::addmenmber(user &a)//添加成员//ok
{
    a.myteam = name;
    //先将团队中的空余时间设置好
    for (int i = 0; i < a.schedule.size(); i++)
    {
        if ( a.schedule[i].op == 1)//如果用户设置为了公开 ,就把对应的时间变成繁忙
        {
            int dayday = a.returndate(schedule[i].schdulee);

            for (int j = a.schedule[i].start; j < a.schedule[i].end; j++)
            { // 将团队中二维向量中对应的元素设为1
                gtime[dayday][j] = 1;
            }
        }
    }
   
	member.push_back(a);//把a先存入到成员中
    string b = name + "user.txt";
	fstream fout(b, ios::app);
	if (!fout.is_open())
	{
		std::cout << "保存新用户时,团队文件打开失败" << endl;
		exit(123);

	}
	else
	{    // 如果文件打开成功
        fout << a.name << '/' << a.password << '/';
            // 写入姓名和密码，用\t分隔
              
            for (int i = 0; i < schedule.size(); i++)//把用户的行程安排信息存放到schedule结构体 vector(包括空余时间的具体名字,开始时间和结束时间)
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
{//先删除掉该用户在vector里面的信息
    for (int i = 0; i < member.size(); i++) 
    {
        if (member[i].name == a.name&&member[i].password==a.password)//用户名和密码一样的时候才能删除,不然同名的时候会误删除
        {
            member.erase(member.begin() + i);//!!erase
            break;
        }
    }


    // 从文件中删除用户信息
    ifstream fin(name + ".txt",ios::in); // 打开文件，读取模式
    ofstream fout("temp.txt",ios::out); // 打开临时文件，写入模式
    if (!(fin.is_open() && fout.is_open()))
    { 
        std::cout << "删除文件中信息时文件打开失败!" << endl;
    }
    else 
    { // 如果文件都打开成功
        string line; // 每行数据
        while (getline(fin, line)) 
        { 
            // 遍历每行数据
            int pos1 = line.find('/');
          
            string name = line.substr(0, pos1); // 截取姓名
       
         
            if (name != a.name) 
            { // 如果姓名不匹配
                fout << line << endl; // 写入原来的数据
            }
        }
        fin.close(); // 关闭文件
        fout.close(); // 关闭文件
        std::remove((name + ".txt").c_str()); // 删除原来的文件
        std::rename("temp.txt", (name + ".txt").c_str()); // 重命名临时文件为原来的文件名
        std::cout << "成员移除成功！" << endl;
    }
}

int group::arrangeactivity()//成功
{
    user a;
    string aname;//活动名称
    int  op=1, activitylong;
    string date;
    int deadline;
    std::cout << "请输入活动名称：" << endl;
    cin >> aname;

    std::cout << "请输入该活动大致需要在哪一天（格式如下 2000-10-1）：" << endl;
    cin >> date;

    std::cout << "该活动能接受在那天几天之内安排：" << endl;
    cin >> deadline;//不一定用的到

    std::cout << "请输入活动持续的时间(时间为整数个小时)" << endl;
    cin >> activitylong;

 
   

    //先确立团体每个成员的空余时间
  
    //for (int i = 0; i < member.size(); i++)//只要有一个人在那个时间点有安排,那么就没空
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

    int actdate = a.returndate(date);//那一天

    int flag = 0;
    int flag2 = 0;//用于跳出循环
   
    for (int k = 0; k <= deadline; k++)//这里出了问题
    {
        
        for (int i = actdate - k; i <= actdate + k; i++)//进一步确定什么时间可以安排
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
                    if (flag3==0)//一找到合适的时间段就可以写入日程安排
                    {
                        cout << 11;
                        schdule temp;//创建一个临时的变量然后push进我的schedule vector
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
                        std::cout << "已自动为你找到合适的时间" << endl;
                         std::cout <<"活动被安排到" << temp.schdulee << " " << temp.start << "点到" << temp.end << "点";
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
        std::cout << "抱歉,没有适合的时间段来安排活动" << endl;

    }
           
    return 0;
}

void group::show()
{
    std::cout << "团队一共有" << member.size() << "个成员";
    std::cout << "成员名单如下:" << endl;
    for (int i = 0; i < member.size(); i++)
    {
        std::cout <<i<<"   " << member[i].name << "    ";
    }
}

void group::savefile()
{
    //首先先保存团队用户信息
    ifstream fin(name+"user.txt", ios::in);
    ofstream fout("temp.txt", ios::out);
    if (!(fin.is_open() && fout.is_open()))
    {
        std::cout << "保存团队用户信息时 文件打开失败!" << endl;

    }
    else
    {
        for (int i = 0; i < member.size(); i++)
        {
            fout << member[i].name << '/' << member[i].password << '/'; // 写入姓名和密码，用\t分隔
           

            for (int j = 0; j < member[i].schedule.size(); j++)//把用户的行程安排信息存放到schedule结构体 vector(包括空余时间的具体名字,开始时间和结束时间)
            {
                fout << member[i].schedule[j].schdulee << "," << member[i].schedule[j].start << "," << member[i].schedule[j].end << "," << member[i].schedule[j].sname << "," << member[i].schedule[j].op;
                if (j != member[i].schedule.size() - 1)
                    fout << ".";
            }

            fout << '/'<<endl;

        }
        fout.close(); // 关闭文件
        fin.close();
        string a = name + "user.txt";
        std::remove(a.c_str()); // 删除原来的文件

        std::rename("temp.txt", a.c_str()); // 重命名临时文件为原来的文件名
        std::cout << "团队的用户信息保存成功" << endl;
    }

    //接着保存团队的日程安排
    ifstream ffin(name + "schedule.txt", ios::in);
    ofstream ffout("temp.txt", ios::out);
    if (!(ffin.is_open() && ffout.is_open()))
    {
        std::cout << "保存团队日程安排时 文件打开失败!" << endl;
    }
    else
    {
        for (int i = 0; i < schedule.size(); i++)
        {
           
                ffout << schedule[i].schdulee << "," << schedule[i].start << "," << schedule[i].end << "," << schedule[i].sname << "," << schedule[i].op;
                
                    ffout << ".";
                   
        }
       
        ffout.close(); // 关闭文件
        ffin.close();
        string b = name + "schedule.txt";
        std::remove(b.c_str()); // 删除原来的文件

        std::rename("temp.txt", b.c_str()); // 重命名临时文件为原来的文件名
        std::cout << "团队的日程安排信息保存成功" << endl;
    }
}

void group::getmsg()//将txt文件的信息传入到黑框框中
{
    //先将团队用户的信息传入到group中的vector中
    string a = name + "user.txt";
    ifstream ff(a);
    string line;
    user utemp;
    if (!ff.is_open())
    {
        std::cout << "将团队用户信息导入到group时, 文件打开失败!" << endl;

    }
    else
    {
        //首先得找到包含该用户信息的哪一行

        while (getline(ff, line))
        {
            user usertemp;
            int pos1 = line.find('/');//前面的是姓名

            int pos2 = line.find('/', pos1 + 1);// 前面的是密码


            int pos3 = line.find('/', pos2 + 1);//前面的是日程安排

            string gname = line.substr(0, pos1); // 截取姓名

            string gpassword = line.substr(pos1 + 1, pos2 - pos1 - 1);//截取密码

            string temp9 = line.substr(pos2 + 1, pos3 - pos2 - 1);//截取日程安排

            usertemp.name = gname;

            usertemp.password = gpassword;
            stringstream ss;
            ss << temp9;
            string temp2;
            ss >> temp2;
            if (temp2 > " ")
            {
                std::cout << "123123213";
                while (getline(ss, temp2, '.'))//代测试代码是否可行
                {
                    schdule stemp;//创建一个临时的变量,再把该变量push进去

                    int pos3 = temp2.find(',');//日期后面的逗号
                    int pos4 = temp2.find(',', pos3 + 1);
                    int pos5 = temp2.find(',', pos4 + 1);
                    int pos6 = temp2.find(',', pos5 + 1);


                    string time = temp2.substr(0, pos3); // 截取活动的日期
                   
                    string sstart = temp2.substr(pos3 + 1, pos4 - pos3 - 1);//截取开始时间和截止时间
                    string eend = temp2.substr(pos4 + 1, pos5 - pos4 - 1);

                    string schdulename = temp2.substr(pos5 + 1, pos6 - pos5 - 1);;// 截取活动名称
                    string oop = temp2.substr(pos6 + 1);//截取用户的选择

                    int ssstart = stoi(sstart);//将它们转换成int类型
                    int eeend = stoi(eend);
                    int ooop = stoi(oop);


                    //先根据截取的日期对用户的空余时间和
                    stemp.schdulee = time;
                    stemp.start = ssstart;
                    stemp.end = eeend;
                    stemp.op = ooop;
                    stemp.sname = schdulename;
                    usertemp.schedule.push_back(stemp);
                    temp2.clear();
                    
                    if (ooop == 1)//如果用户设置为了公开 ,就把对应的时间变成繁忙
                    {
                        int dayday = utemp.returndate(time);

                        for (int i = ssstart; i < eeend; i++)
                        { // 将二维向量中对应的元素设为1
                            gtime[dayday][i] = 1;
                        }
                    }

                }
            }
            member.push_back(usertemp);
        

        }
        ff.close();
    }
        //再将日程安排导入
    string b = name + "schedule.txt";
        ifstream fin(b);
        string temp2;
        if (!fin.is_open())
        {
            std::cout << "将团队日程安排导入到group时, 文件打开失败!" << endl;

        }
        else
        {
            while(getline(fin,temp2,'.'))
                //代测试代码是否可行
                {
                    schdule stemp;//创建一个临时的变量,再把该变量push进去

                    int pos3 = temp2.find(',');//日期后面的逗号
                    int pos4 = temp2.find(',', pos3 + 1);
                    int pos5 = temp2.find(',', pos4 + 1);
                    int pos6 = temp2.find(',', pos5 + 1);

                    
                    string time = temp2.substr(0, pos3); // 截取活动的日期
                    std::cout << "失败失败!" << endl;
                    if (time > " ")
                    {
                        std::cout << "成功成功成!" << endl;
                        string sstart = temp2.substr(pos3 + 1, pos4 - pos3 - 1);//截取开始时间和截止时间
                        string eend = temp2.substr(pos4 + 1, pos5 - pos4 - 1);

                        string schdulename = temp2.substr(pos5 + 1, pos6 - pos5 - 1);;// 截取活动名称
                        string oop = temp2.substr(pos6 + 1);//截取用户的选择

                        int ssstart = stoi(sstart);//将它们转换成int类型
                        int eeend = stoi(eend);
                        int ooop = stoi(oop);


                        //先根据截取的日期对用户的空余时间和
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

void  group::setschedule()//两种设置日程的模式 一种是手动输入
{
    string date; // 日期 

    int start, end; // 开始时间和结束时间

    string event; // 事情内容

    int op=1;//表示用户的选择,是否对外界公开

    std::cout << "请输入日程安排的日期（格式如下 2000-10-1）：" << endl;
    cin >> date;
    std::cout << "请输入开始时间(24点表示)   例如下午三点则输入15" << endl;
    cin >> start;
    std::cout << "请输入结束时间" << endl;
    cin >> end;
    std::cout << "请输入事情内容：" << endl;
    cin >> event;
   


    schdule temp;//创建一个临时的变量然后push进我的schedule vector
    temp.schdulee = date;
    temp.start = start;
    temp.end = end;
    temp.op = op;
    temp.sname = event;
    schedule.push_back(temp);
    std::cout << "现在都是成功的!";
    savefile();

}

void group::showschedule()
{
    std::cout << "团队的日程安排如下:" << endl;
    for (int i = 0; i < schedule.size(); i++)
    {
        std::cout << i << "   ";
        std::cout << schedule[i].schdulee << " " << schedule[i].start << "点到" << schedule[i].end << "点";
        std::cout << schedule[i].sname << endl;
    }

}

void group::removescheduele()
{
    //先获取所要删除日程的各种信息
    string activity, sname;
    int start, end;//开始时间和截止时间
    std::cout << "请输入你想要删除的行程安排的时间" << endl;
    cin >> activity;
    std::cout << "请输入该日程安排的开始时间:" << endl;
    cin >> start;
    std::cout << "请输入该日程安排的结束时间:" << endl;
    cin >> end;
    std::cout << "请输入该日程安排的名称:" << endl;
    cin >> sname;



    //删除程序中数据成员中的信息先
    for (int i = 0; i < schedule.size(); i++)
    {
        if (activity == schedule[i].schdulee && start == schedule[i].start && end == schedule[i].end && schedule[i].sname == sname)
        {
            schedule.erase(schedule.begin() + i);//!!erase

        }
    }

    //保存起来txt文件中的日程安排
    savefile();


}




