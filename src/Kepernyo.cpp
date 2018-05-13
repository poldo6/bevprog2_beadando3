#include "Kepernyo.h"

using namespace genv;

Kepernyo::Kepernyo(int _sor, int _oszlop, JatekMester& _jm) : sor(_sor), oszlop(_oszlop), jm(_jm)
{
    // szukseges kepernyomeret kiszamitasa
    XX = oszlop * cb_meret + 2*margo_x;
    YY = sor * cb_meret + margo_x + margo_y;

    gout.open(XX,YY);

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
    event ev;
    while(gin >> ev && ev.keycode!=key_escape)
    {
        if(ev.type==ev_mouse && ev.button==btn_left)
        {

        }
    }
}

void Kepernyo::set_jatekmester(JatekMester& _jm)
{
    jm = _jm;
}
