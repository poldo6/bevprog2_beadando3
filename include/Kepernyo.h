#ifndef KEPERNYO_H
#define KEPERNYO_H

#include "graphics.hpp"
#include "CheckBox.h"
#include "JatekMester.h"

// 'JatekMester' has not been declared|

class JatekMester;

class Kepernyo
{
public:
    Kepernyo(int _sor, int _oszlop, JatekMester& _jm);
    virtual ~Kepernyo();

    void main();
    void klikk_esemeny(genv::event ev);
    void set_jatekmester(JatekMester& _jm);

    int tartalma(int i, int j) const;

protected:
    int sor, oszlop;
    vector<vector<CheckBox>> jatekter;

    const int cb_meret=25;
    const int margo_x=10;
    const int margo_y=100;

private:
    int XX;
    int YY;

    // tablazat meretei ( az egyszeruseg kedveert )
    int x,y,sx,sy;

    // referencia a jatekmesterre
    JatekMester &jm;
};

#endif // KEPERNYO_H
