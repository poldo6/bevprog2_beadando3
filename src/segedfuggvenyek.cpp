#include "segedfuggvenyek.h"

using namespace genv;

void torol_szurke(int XX, int YY)
{
    gout << move_to(0,0) << color(127,127,127) << box(XX,YY);
}

void torol_fekete(int XX, int YY)
{
    gout << move_to(0,0) << color(127,127,127) << box(XX,YY);
}

void torol_feher(int XX, int YY)
{
    gout << move_to(0,0) << color(255,255,255) << box(XX,YY);
}

void torol_rgb(int XX, int YY, int r, int g, int b)
{
    gout << move_to(0,0) << color(r,g,b) << box(XX,YY);
}

