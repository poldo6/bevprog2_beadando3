#include "graphics.hpp"
#include "InputPasswordBox.h"
#include <iostream>


using namespace std;

InputPasswordBox::InputPasswordBox() : InputBox()
{
    //ctor
}

InputPasswordBox::~InputPasswordBox()
{
    //dtor
}

InputPasswordBox::InputPasswordBox(int _x, int _y, int _sx, int _sy) : InputBox(_x,_y,_sx,_sy)
{
}

string InputPasswordBox::get_szoveg()
{
    string csillagok;
    csillagok.insert(0,szoveg.length(),'*');
    return csillagok;
}

string InputPasswordBox::konzolrakiir()
{
    event ev;
    if(ev.type == ev_key && ev_key==key_enter)
    {
        cout << szoveg << endl;
    }
}
