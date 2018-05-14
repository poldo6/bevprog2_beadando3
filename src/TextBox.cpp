#include "TextBox.h"

using namespace genv;

TextBox::TextBox() : Widget()
{
}

TextBox::TextBox(int _x, int _y, int _sx, int _sy) : Widget(_x,_y,_sx,_sy,0)
{
}

TextBox::~TextBox()
{
}

void TextBox::set_szoveg(const string& _szoveg)
{
    szoveg = _szoveg;
}

void TextBox::rajzol() const
{
    szinez();
    gout << move_to(x,y) << box(sx,sy);

    gout << color(0,0,0) << move_to(x+1,y+1) << box(sx-2,sy-2);

    szinez();
    gout << move_to(x + bekezdes, y + sy/2 + 1 + szoveg_magassag) << text(szoveg);
}

void TextBox::kezeld_az_esemenyt(event ev)
{
}
