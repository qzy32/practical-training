#pragma once
#include "Basicbotton.h"
#include<string>
using namespace std;
class Table:public Basicbotton
{
public:
	Table();
	void setrowamount(int );//赋值表格行的数量
	void setcolamount(int );//赋值表格宽的数量

	void setheader(const string);

	void showbotton();
private:
	int row;//行
	int col;//列
};

