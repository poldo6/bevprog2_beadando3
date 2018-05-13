#include "Kepernyo.h"

using namespace genv;

Kepernyo::Kepernyo(int _sor, int _oszlop) : sor(_sor), oszlop(_oszlop)
{

    jatekter.resize(sor);
    for(int i=0; i<sor; i++)
    {
        for(int j=0; j<oszlop; j++)
        {
            CheckBox cb(margo_x+cb_meret*j,margo_y+cb_meret*i,cb_meret,cb_meret,i);
            jatekter[i].push_back(cb);
            cb.draw();
        }
    }
    gout << refresh;
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
