#include "user.h"
int commonyear[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };//平年
void user::setuser(string a, string b)//ok
{

	name = a;
	password = b;
	

}

user::user(): time(365, vector<int>(24, 0)),
visible(365, vector<int>(24, 0)),
schedule(vector<schdule>())//先初始化用户的时间和可见数组//ok
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
    string date; // 日期 

    int start, end; // 开始时间和结束时间

    string event; // 事情内容

    int op;//表示用户的选择,是否对外界公开

    std::cout << "请输入日程安排的日期（格式如下 2000-10-1）：" << endl;
    cin >> date;
    std::cout << "请输入开始时间(24点表示)   例如下午三点则输入15" << endl;
    cin >> start;
    std::cout << "请输入结束时间" << endl;
    cin >> end;
    std::cout << "请输入事情内容：" << endl;
    cin >> event;
    std::cout << "该日程安排是否公开" << endl;

    std::cout << "输入1表示公开  输入2表示不公开" << endl;

    cin >> op;

    schdule temp;//创建一个临时的变量然后push进我的schedule vector
    temp.schdulee = date;
    temp.start = start;
    temp.end = end;
    temp.op = op;
    temp.sname = event;
    schedule.push_back(temp);
  

    int index = returndate(date); // 将日期转换为二维向量中的行索引
 
    //for (int i = start; i < end; i++)
    //{ // 将二维向量中对应的元素设为1
    //    time[index][i] = 1;
    //}

    //if (op == 2)
    //{
    //    for (int i = start; i < end; i++)
    //    { // 将二维向量中对应的元素设为1
    //        visible[index][i] = 1;
    //    }

    //} 
    //ifstream fin("resource.txt", ios::in);
    //ofstream fout("temp.txt", ios::out);
    //if (!(fin.is_open() && fout.is_open()))
    //{
    //    std::cout << "添加用户日程安排时 文件打开失败!" << endl;
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
    //        int pos2 = line.find('/', pos1 + 1);// 找到第一个\t的位置

    //        int pos3 = line.find('/', pos2 + 1);
    // 
    //        
    //        string gname = line.substr(0, pos1); // 截取姓名
    //       
    //        string gpassword = line.substr(pos1 + 1, pos2-pos1-1);//截取密码

    //        
    //                             
    //        if ((name == gname && password ==gpassword))
    //        { // 如果姓名匹配
    //            fout << gname << '/' << gpassword << '/' << myteam << '/'; // 写入姓名和密码，用\t分隔
    //          
    //            //for (int i = 0; i < time.size(); i++)// 写入日常安排的空余时间，用\t分隔
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
    //            //for (int i = 0; i < visible.size(); i++)     //写入日程安排是否可见  
    //            //{ 
    //            //    for (vector<int>::iterator it = (visible[i].begin()); it != visible[i].end(); it++)// 写入日常安排，用\t分隔
    //            //    {
    //            //        fout << *it;
    //            //        if (it != visible[i].end() - 1)
    //            //            fout << ",";
    //            //    }
    //            //    if (i != visible.size() - 2)
    //            //        fout << ".";
    //            //}
    //            //fout << "\t";

    //            for (int i = 0; i <schedule.size(); i++)//把用户的行程安排信息存放到schedule结构体 vector(包括空余时间的具体名字,开始时间和结束时间)
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
    //    fout.close(); // 关闭文件
    //    fin.close();
    //    string a = "resource.txt";
    //    remove(a.c_str()); // 删除原来的文件

    //    rename("temp.txt", a.c_str()); // 重命名临时文件为原来的文件名
    //    std::cout << "日程安排添加成功!" << endl;
    //}
   
    savefile();
 
}//ok//ok

//void user::lookforschedule()//暂时没用
//{
//    string date; // 日期
//
//    std::cout << "请输入日期（yyyy-mm-dd）：" << endl;
//    cin >> date;
//
//    int index = returndate(date); // 将日期转换为二维向量中的行索引
//    bool flag = true; // 标志位，表示该日期是否有空
//    for (int i = 0; i < 24; i++) { // 遍历二维向量中对应的行
//        if (time[index][i] == 1) { // 如果有一个元素为1，则将标志位设为false，并跳出循环
//            flag = false;
//            break;
//        }
//    }
//    if (flag) { // 如果该日期有空，输出有空
//        std::cout << "该日期有空。" << endl;
//    }
//    else { // 如果该日期没有空，输出没有空
//        std::cout << "该日期没有空。" << endl;
//    }
//
//  
//}
 
int user::returndate(string date)//根据用户输入的日期来返回是哪一天
{
    // 截取年份,月份还有日期
    int posi1, posi2, posi3;
    posi1 = date.find('-', 0);
    posi2 = date.find('-', posi1 + 1);
  
    int year = stoi(date.substr(0, posi1)); 

    int month = stoi(date.substr(posi1 +1, posi2));
  
    int day = stoi(date.substr(posi2 +1));

    int total = 0; // 
    for (int i = 1; i < month; i++)// 根据月份累加天数
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
  
    total += day - 1; // 根据日期累加天数
    return total;
   
}

void user::removeschedule()
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
        if (activity == schedule[i].schdulee  &&  start == schedule[i].start && end== schedule[i].end && schedule[i].sname==sname)
        {
            schedule.erase(schedule.begin() + i);//!!erase
            
        }
    }

    //保存起来txt文件中的日程安排
    savefile();

}



void user::showmonthschedule(int year,int month)//用来确定该月的日程安排
{
    int flag = 0;
    //先找一下是否有日程安排在本月
    for (int i = 0; i < schedule.size(); i++)//先遍历每一个日程安排,再根据满足的条件来进行输出
    {
        
        int posi1, posi2, posi3;
        posi1 = schedule[i].schdulee.find('-', 0);
        posi2 = schedule[i].schdulee.find('-', posi1 + 1);

        int syear = stoi(schedule[i].schdulee.substr(0, posi1));//截取年

        int smonth = stoi(schedule[i].schdulee.substr(posi1 + 1, posi2));//截取月份

        int sday = stoi(schedule[i].schdulee.substr(posi2 + 1));//截取月份


        int lastday = commonyear[smonth];//获取这个月一共有多少天
        //首先得年和月一样
        if (syear == year && smonth == month)
        {
            flag = 1;
            std::cout << i << "   ";
            std::cout << schedule[i].schdulee << " " << schedule[i].start << "点到" << schedule[i].end << "点";
            std::cout << schedule[i].sname << endl << endl;
        }
    }
    if (flag == 0)
    {
        std::cout << endl;
        std::cout << "本月你并没有日程安排,请检查是否在本月添加过日程安排!" << endl;
        return;
    }
   
        return;

    //后面才开始输出日程安排
    std::cout << "**************************************************" << endl;
    std::cout << "尊敬的用户你好,你的日程安排如下:" << endl;
  
    for (int i = 0; i < schedule.size(); i++)//先遍历每一个日程安排,再根据满足的条件来进行输出
    {
        int posi1, posi2, posi3;
        posi1 = schedule[i].schdulee.find('-', 0);
        posi2 = schedule[i].schdulee.find('-', posi1 + 1);

        int syear = stoi(schedule[i].schdulee.substr(0, posi1));//截取年

        int smonth = stoi(schedule[i].schdulee.substr(posi1 + 1, posi2));//截取月份

        int sday = stoi(schedule[i].schdulee.substr(posi2+1));//截取月份


        int lastday = commonyear[smonth];//获取这个月一共有多少天
        //首先得年和月一样
        if (syear == year && smonth == month)
        {
            flag = 1;
            std::cout << i << "   ";
            std::cout << schedule[i].schdulee << " " << schedule[i].start << "点到" << schedule[i].end << "点";
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
        std::cout << "输出日程安排时,文件打开失败!" << endl;

    }
    else
    {
        //首先得找到包含该用户信息的哪一行

        while (getline(ff, line))
        {
            int pos1 = line.find('/');//前面的是姓名

            int pos2 = line.find('/', pos1 + 1);// 前面的是密码

            int pos3 = line.find('/', pos2 + 1);//前面的是团队名称

            int pos4 = line.find('/', pos3 + 1);//前面的是日程安排

            string gname = line.substr(0, pos1); // 截取姓名

            string gpassword = line.substr(pos1 + 1, pos2-pos1-1);//截取密码
           
        
            if (gname == name && gpassword == password)
            {

                myteam = line.substr(pos2 + 1, pos3 - pos2 - 1);//把写入的团队传入


                string temp9 = line.substr(pos3 + 1, pos4 - pos3 - 1);

                stringstream ss;
                ss << temp9;
                string temp2;
                while (getline(ss, temp2, '.'))//代测试代码是否可行
                {
                    schdule stemp;//创建一个临时的变量,再把该变量push进去

                    int pos5 = temp2.find(',');//日期后面的逗号
                    int pos6 = temp2.find(',', pos5 + 1);
                    int pos7 = temp2.find(',', pos6 + 1);
                    int pos8 = temp2.find(',', pos7 + 1);


                    string time = temp2.substr(0, pos5); // 截取活动的日期
                    string sstart = temp2.substr(pos5 + 1, pos6 - pos5 - 1);//截取开始时间和截止时间
                    string eend = temp2.substr(pos6 + 1, pos7 - pos6 - 1);

                    string schdulename = temp2.substr(pos7 + 1, pos8 - pos7 - 1);;// 截取活动名称
                    string oop = temp2.substr(pos8 + 1);//截取用户的选择

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
    }
}

void user::savefile()
{
    ifstream fin("resource.txt", ios::in);
    ofstream fout("temp.txt", ios::out);
    if (!(fin.is_open() && fout.is_open()))
    {
        std::cout << "保存用户信息时 文件打开失败!" << endl;
    }
    else
    {

        string line;
        while (getline(fin, line))
        {

            int pos1 = line.find('/');

            int pos2 = line.find('/', pos1 + 1);// 找到第一个/的位置

            int pos3 = line.find('/', pos2 + 1);


            string gname = line.substr(0, pos1); // 截取姓名

            string gpassword = line.substr(pos1 + 1, pos2 - pos1 - 1);//截取密码



            if ((name == gname && password == gpassword))
            { // 如果姓名匹配
                fout << gname << '/' << gpassword << '/' << myteam << '/'; // 写入姓名和密码，用/分隔              

                for (int i = 0; i < schedule.size(); i++)//把用户的行程安排信息存放到schedule结构体 vector(包括空余时间的具体名字,开始时间和结束时间)
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
        fout.close(); // 关闭文件
        fin.close();
        string a = "resource.txt";
        remove(a.c_str()); // 删除原来的文件

        rename("temp.txt", a.c_str()); // 重命名临时文件为原来的文件名

    }



}

void user::creatmonthreport(int year,int month,int day)
{
    std::cout << "本月活动报告如下:";


}



void user::creatweekreport(int year, int month, int day)
{
    std::cout << "本周活动报告如下:";

}

void user::showschedule()
{
    
    std::cout << endl << "日程安排如下,请根据显示日程安排信息来删除日程安排" << endl;
    for (int i = 0; i < schedule.size(); i++)
    {
        std::cout << i << "   ";
        std::cout << schedule[i].schdulee << " " << schedule[i].start << "点到" << schedule[i].end << "点";
        std::cout << schedule[i].sname << endl;
    }
}







