#include "JatekMester.h"

#include <vector>

JatekMester::JatekMester(int _sor, int _oszlop) : sor(_sor), oszlop(_oszlop)
{
    kepernyo = new Kepernyo(_sor,_oszlop,*this);
}

JatekMester::~JatekMester()
{
    delete kepernyo;
}

void JatekMester::jatek_indit()
{
    kepernyo->main();
}

void JatekMester::valt()
{
    soron_kovetkezo*=-1;

    if (soron_kovetkezo > 0)
    {
        kepernyo->uzend("Az X kovetkezik.");
    }
    else
    {
        kepernyo->uzend("A kor kovetkezik.");
    }
}

void JatekMester::vizsgal(int i, int j)
{
    vector<int> irany_i = { 1, 1, 0, -1 };
    vector<int> irany_j = { 0, 1, 1, 1 };

    for (int k=0; k < irany_i.size(); k++)
    {
        vector<CheckBox*> sor = kepernyo->mezok_irany_szerint(i,j,irany_i[k],irany_j[k]);

        int egymas_utan = 0;
        int index = -1;
        for (int l=0; l < sor.size(); l++)
        {
            if (sor[l]->get_tartalma() == soron_kovetkezo)
            {
                egymas_utan++;

                if (egymas_utan == 5)
                {
                    index = l;
                }
            }

            else
            {
                egymas_utan = 0;
            }
        }

        if (index >=4)
        {
            vege_a_jateknak = true;
            for (int l=index-4; l<=index; l++)
            {
                sor[l]->kiemel(true);
            }
        }
    }

    if (teli_mezok_szama == sor*oszlop)
    {
        vege_a_jateknak = true;
        kepernyo->uzend("Betelt az osszes mezo: dontetlen!");
    }

    else if (!vege_a_jateknak)
    {
        valt();
    }

    else
    {
        if (soron_kovetkezo > 0)
        {
            kepernyo->uzend("Az X nyert!");
        }
        else
        {
            kepernyo->uzend("A kor nyert!");
        }
    }
}

void JatekMester::xelt(int i, int j)
{
    if (vege_a_jateknak)
    {
        kepernyo->uzend("A jatek veget ert!");
    }

    else if(kepernyo->get_tartalma(i,j) != 0)
    {
        kepernyo->uzend("Az a mezo mar foglalt!");
    }

    else
    {
        kepernyo->set_tartalma(i,j,soron_kovetkezo);
        teli_mezok_szama++;
        vizsgal(i,j);
    }
}
