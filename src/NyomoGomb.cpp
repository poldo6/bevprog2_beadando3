#include "graphics.hpp"
#include "NyomoGomb.h"
#include "Widget.h"
#include "LegorduloMenu.h"

NyomoGomb::NyomoGomb() : Widget()
{
    //ctor
}

NyomoGomb::~NyomoGomb()
{
    //dtor
}

NyomoGomb::NyomoGomb(int _x, int _y, int _sx, int _sy) : Widget(_x,_y,_sx,_sy,0)
{
}

void NyomoGomb::rajzol() const
{
        szinbeallit_hatter();
        gout << move_to(x, y ) << box(sx, sy);
}

bool NyomoGomb::raklikkeltem (int mouse_x, int mouse_y)
{
        return aktiv;
}

void NyomoGomb::kezeld_az_esemenyt(event ev)
{
}
