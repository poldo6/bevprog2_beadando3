#include "JatekTer.h"

JatekTer::JatekTer(int _sor, int _oszlop):sor(_sor), oszlop(_oszlop)
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

JatekTer::~JatekTer()
{

}

void JatekTer::valt()
{
    soron_kovetkezo*=-1;
}

void JatekTer::xelt(int i, int j)
{
    if(jatekter[i][j]!=0)
    {
        //ide nem tehetsz!!!!!
    }
    else
    {
        //semmit ne �rjon ki
        jatekter[i][j].set_tartalma(soron_kovetkezo);
    }
}

void JatekTer::esemeny(event ev)
{

}
