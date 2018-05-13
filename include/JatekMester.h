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
    void xelt(int i, int j);
    void jatek_indit();

protected:
    int sor, oszlop;
    int soron_kovetkezo=-1;

private:
    Kepernyo* kepernyo;
};

#endif // JATEK_MESTER_H
