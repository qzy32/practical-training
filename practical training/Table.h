#pragma once
#include "Basicbotton.h"
#include<string>
using namespace std;
class Table:public Basicbotton
{
public:
	Table();
	void setrowamount(int );//��ֵ����е�����
	void setcolamount(int );//��ֵ���������

	void setheader(const string);

	void showbotton();
private:
	int row;//��
	int col;//��
};

