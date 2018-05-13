#ifndef KEPERNYO_H
#define KEPERNYO_H

#include "graphics.hpp"
#include "CheckBox.h"
#include "JatekMester.h"

class JatekMester;

class Kepernyo
{
public:
    Kepernyo(int _sor, int _oszlop, JatekMester& _jm);
    virtual ~Kepernyo();

    void main();

    void esemeny(genv::event ev);

    void set_jatekmester(JatekMester& _jm);

protected:
    int sor, oszlop;
    vector<vector<CheckBox>> jatekter;

    const int cb_meret=40;
    const int margo_x=10;
    const int margo_y=100;
private:
    int XX;
    int YY;

    // referencia a jatekmesterre
    JatekMester &jm;
};

#endif // KEPERNYO_H
