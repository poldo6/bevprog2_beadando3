#include "CheckBox.h"
#include <iostream>

CheckBox::CheckBox(int _x, int _y, int _sx, int _sy, int _id) : Widget(_x, _y, _sx, _sy, _id)
{
    //ctor
}

CheckBox::~CheckBox()
{
    //dtor
}

void CheckBox::draw() const
{
    if(kiemelt)
    {
        szin_kiemelt();
    }

    else
    {
        szin_normal();
    }

    gout << move_to(x,y) << box(sx,sy);
    gout << color(0,0,0) << move_to(x+1,y+1) << box(sx-2,sy-2);
//    cout << "Belepett:" << x << "  " << y << " " << endl;
//    cout << "S-es belepett:" << sx << "  " << sy << " " << endl;
}

void CheckBox::action(event ev)
{

}

void CheckBox::szin_normal() const
{
    gout << color(255,255,255);
}

void CheckBox::szin_kiemelt() const
{
    gout << color(0,0,255);
}

bool CheckBox::ures() const
{
    return tartalma == 0;
}

void CheckBox::set_tartalma(int _tartalma)
{
    tartalma=_tartalma;
}

int CheckBox::get_tartalma() const
{
    return tartalma;
}
