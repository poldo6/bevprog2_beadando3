#include "widget.h"

Widget::Widget()
{
}

Widget::Widget(int _x, int _y, int _sx, int _sy, int _id): x(_x), y(_y), sx(_sx), sy(_sy), id(_id)
{
}

void Widget::atmeretez(int _x, int _y, int _sx, int _sy, int _id)
{
    x = _x;
    y = _y;
    sx = _sx;
    sy = _sy;
    id = _id;
}

void Widget::focus(event ev)
{
    if(ev.pos_x >= x && ev.pos_x < x+sx && ev.pos_y >= y && ev.pos_y < y+sy && ev.type == ev_mouse && ev.button == btn_left)
    {

    }

}

void Widget::szinez() const
{
    if(kiemelt)
    {
        gout << color(0,0,255);
    }

    else
    {
        gout << color(255,255,255);
    }
}

void Widget::kiemel(bool _kiemelt)
{
    kiemelt = _kiemelt;
    draw();
}

