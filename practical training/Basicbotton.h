#pragma once
class Basicbotton
{
public:
	Basicbotton(int x, int y, int w, int h);
	int getweight();//�õ����
	int getheight();//�õ��߶�
	int getx();//����x
	int gety();//����y
	void move(int x, int y);//�ƶ�����

	virtual void showbotton() = 0;
	void setsize(int x, int y);//���ð�ť�Ĵ�С


protected:
	int x, y, w, h;//x y���� w h���

};

