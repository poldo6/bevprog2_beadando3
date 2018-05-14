#ifndef JATEK_MESTER_H
#define JATEK_MESTER_H

#include "Kepernyo.h"

// 'Kepernyo' does not name a type|
class Kepernyo;

class JatekMester
{
public:
    JatekMester(int _sor, int _oszlop);
    virtual ~JatekMester();

    void valt();
    void vizsgal(int i, int j);
    void xelt(int i, int j);
    void jatek_indit();

protected:

private:
    int sor, oszlop;
    int soron_kovetkezo=-1;
    bool vege_a_jateknak=false;
    int teli_mezok_szama=0;

    Kepernyo* kepernyo;
};

#endif // JATEK_MESTER_H
