#include "widget.h"

using namespace genv;

Widget::Widget()
{
}

Widget::Widget(int _x, int _y, int _sx, int _sy): x(_x), y(_y), sx(_sx), sy(_sy), id(0)
{
}

Widget::Widget(int _x, int _y, int _sx, int _sy, int _id): x(_x), y(_y), sx(_sx), sy(_sy), id(_id)
{
}

Widget::~Widget()
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
    rajzol();
}

bool Widget::raklikkeltem (int mouse_x, int mouse_y)
{
    aktiv = x <= mouse_x && mouse_x <= x + sx && y <= mouse_y && mouse_y <= y + sy;
    return aktiv;
}

// Szinbeallitasi fuggvenyek.

void Widget::szinbeallit_hatter () const
{
    gout << color(255, 220, 220);
}

void Widget::szinbeallit_hatter_sotetebb () const
{
    gout << color(190, 170, 170);

}

void Widget::szinbeallit_szoveg () const
{
    gout << color(0, 0, 0);
}

void Widget::szinbeallit_szurke () const
{
    gout << color(100, 100, 100);
}

