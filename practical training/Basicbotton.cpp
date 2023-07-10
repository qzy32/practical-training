#include "Basicbotton.h"
#include<easyx.h>
#include<graphics.h>
Basicbotton::Basicbotton(int x, int y, int w, int h):x(x),y(y),w(w),h(h)
{
}

int Basicbotton::getweight()
{
    return w;

}

int Basicbotton::getheight()
{
    return h;

}

int Basicbotton::getx()
{
    return x;
}

int Basicbotton::gety()
{
    return y;
}

void Basicbotton::move(int x, int y)
{
    this->x = x;
    this->y = y;
}

void Basicbotton::showbotton()
{
}

void Basicbotton::setsize(int w, int h)
{
    this->w = w;
    this->h = h;
}
