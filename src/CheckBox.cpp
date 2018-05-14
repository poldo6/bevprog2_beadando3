#include "CheckBox.h"
#include <iostream>
#include <cmath>

using namespace genv;

CheckBox::CheckBox(int _x, int _y, int _sx, int _sy, int _id) : Widget(_x, _y, _sx, _sy, _id)
{
    //ctor
}

CheckBox::~CheckBox()
{
    //dtor
}

void CheckBox::rajzol() const
{
    szinez();
    gout << move_to(x,y) << box(sx,sy);
    gout << color(0,0,0) << move_to(x+1,y+1) << box(sx-2,sy-2);

    szinez();
    if (tartalma>0)
    {
        // x-et rajzol
        gout << move_to(x+sx/3,y+sy/3) << line(sx-2*(sx/3)+1,sy-2*(sy/3)+1);
        gout << move_to(x+sx/3,y+sy-sy/3) << line(sx-2*(sx/3)+1,-sy+2*(sy/3)-1);
    }

    if (tartalma < 0)
    {
        // kort rajzol
        float dalpha = 3.1415/36.0;
        float r = sx/3.5;
        for (float alpha=0; alpha < 2*3.1415; alpha+=dalpha)
        {
            int xkiind = r*cos(alpha) + x + sx/2 + 1;
            int ykiind = r*sin(alpha) + y + sy/2 + 1;
            int xveg = r*cos(alpha+dalpha) + x + sx/2 + 1;
            int yveg = r*sin(alpha+dalpha) + y + sy/2 + 1;
            gout << move_to(xkiind,ykiind) << line_to(xveg,yveg);
        }
    }
}

void CheckBox::kezeld_az_esemenyt(event ev)
{

}

bool CheckBox::ures() const
{
    return tartalma == 0;
}

void CheckBox::set_tartalma(int _tartalma)
{
    tartalma=_tartalma;
    rajzol();
}

int CheckBox::get_tartalma() const
{
    return tartalma;
}
