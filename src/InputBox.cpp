#include "InputBox.h"
#include <iostream>
InputBox::InputBox() : Widget()
{
}

InputBox::~InputBox()
{
    //dtor
}

InputBox::InputBox(int _x, int _y, int _sx, int _sy) : Widget(_x,_y,_sx,_sy,0)
{
}

void InputBox::alapertelmezett_szoveg(string alapertelmezett)
{
    szoveg = alapertelmezett;
}

void InputBox::rajzol() const
{
    // Szovegdoboz kirajzolasa
    szinbeallit_hatter();
    gout << move_to(x,y) << box(sx,sy);

    // Szoveg kirajzolasa
    szinbeallit_szoveg();
    gout << move_to(x+10,y+20) << text(get_szoveg());

    // Ha aktiv akkor a kurzort is jelenitse meg.
    if (aktiv)
    {
        gout << genv::move(1,2) << line(0,-14);
    }
}

void InputBox::kezeld_az_esemenyt(event ev)
{
    if (ev.type!=ev_key)
    {
        return;
    }

    bmegfigyelo.esemenyt_bejelent(ev);

    if (ev.keycode==key_backspace)
    {
        if(szoveg.length()!=0)
        {
            szoveg.erase(szoveg.length()-1,1);
        }
    }

    if (ertelmes_charactere(ev.keycode))
    {
        szoveg.insert(szoveg.length(), 1, bmegfigyelo.utolso_character());
    }
}

string InputBox::get_szoveg() const
{
    return szoveg;
}
