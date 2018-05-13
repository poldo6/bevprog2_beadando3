#ifndef KEPERNYO_H
#define KEPERNYO_H

#include "graphics.hpp"
#include "CheckBox.h"

class Kepernyo
{
public:
    Kepernyo(int _sor, int _oszlop);
    virtual ~Kepernyo();

    void main();

    void esemeny(genv::event ev);

protected:
    int sor, oszlop;
    vector<vector<CheckBox>> jatekter;

    const int cb_meret=40;
    const int margo_x=10;
    const int margo_y=100;

private:
    int XX;
    int YY;
};

#endif // KEPERNYO_H
