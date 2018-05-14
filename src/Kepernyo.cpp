#include "Kepernyo.h"
#include <iostream>

using namespace std;
using namespace genv;

Kepernyo::Kepernyo(int _sor, int _oszlop, JatekMester& _jm) : sor(_sor), oszlop(_oszlop), jm(_jm)
{
    // tablazat meretei
    x = margo_x;
    y = margo_y;
    sx = oszlop * cb_meret;
    sy = sor * cb_meret;

    // szukseges kepernyomeret kiszamitasa
    XX = sx + 2*margo_x;
    YY = sy + margo_x + margo_y;

    gout.open(XX,YY);

    szovegdoboz.atmeretez(margo_x,margo_x,XX-2*margo_x,szovegdoboz_magassag,0);
    uzend("Kezdodhet a jatek, a kor kezd!");

    jatekter.resize(sor);
    for(int i=0; i<sor; i++)
    {
        for(int j=0; j<oszlop; j++)
        {
            CheckBox cb(margo_x+cb_meret*j,margo_y+cb_meret*i,cb_meret,cb_meret,i*sor+j);
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
            klikk_esemeny(ev);
        }
    }
}

void Kepernyo::klikk_esemeny(event ev)
{
    if(ev.pos_x >= x && ev.pos_x < x+sx && ev.pos_y >= y && ev.pos_y < y+sy && ev.type == ev_mouse && ev.button == btn_left)
    {
        int i = (ev.pos_y - y) / cb_meret;
        int j = (ev.pos_x - x) / cb_meret;

        // cout << i << " " << j << endl;

        jm.xelt(i,j);
        gout << refresh;
    }
}

vector<CheckBox*> Kepernyo::mezok_irany_szerint(int i, int j, int irany_i, int irany_j)
{
    vector<CheckBox*> ret;
    for (int k = -4; k <= 4; k++)
    {
        int ii = i + k*irany_i;
        int jj = j + k*irany_j;
        if (0 <= ii && ii < sor && 0 <= jj && jj <= oszlop)
        {
            ret.push_back(&jatekter[ii][jj]);
        }
    }
    return ret;
}

void Kepernyo::uzend(const string& uzenet)
{
    szovegdoboz.set_szoveg(uzenet);
    szovegdoboz.draw();
}

int Kepernyo::get_tartalma(int i, int j) const
{
    return jatekter[i][j].get_tartalma();
}

void Kepernyo::set_tartalma(int i, int j, int _tartalma)
{
    jatekter[i][j].set_tartalma(_tartalma);
}

void Kepernyo::set_jatekmester(JatekMester& _jm)
{
    jm = _jm;
}
