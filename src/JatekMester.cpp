#include "JatekMester.h"

JatekMester::JatekMester(int _sor, int _oszlop) : sor(_sor), oszlop(_oszlop)
{
    kepernyo = new Kepernyo(_sor,_oszlop,*this);
}

JatekMester::~JatekMester()
{
    delete kepernyo;
}

void JatekMester::valt()
{
    soron_kovetkezo*=-1;
}

void JatekMester::xelt(int i, int j)
{
//    if(tartalma != 0)
//    {
//
//        //ide nem tehetsz!!!!!
//    }
//    else
//    {
//        //semmit ne írjon ki
//        jatekter[i][j].set_tartalma(soron_kovetkezo);
//    }
}


void JatekMester::jatek_indit()
{
    kepernyo->main();
}
