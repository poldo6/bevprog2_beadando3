#include "Kepernyo.h"

using namespace genv;

Kepernyo::Kepernyo()
{
    // itt kellene az XX-et es az YY-t kiszamitani
}

Kepernyo::~Kepernyo()
{
    //dtor
}

void Kepernyo::main()
{
    gout.open(XX,YY);

    event ev;
    while(gin >> ev && ev.keycode!=key_escape)
    {
        if(ev.type==ev_mouse && ev.button==btn_left)
        {

        }
    }
}
