#ifndef KEPERNYO_H
#define KEPERNYO_H

#include "graphics.hpp"
#include "CheckBox.h"
#include "JatekMester.h"
#include "TextBox.h"

// 'JatekMester' has not been declared|

class JatekMester;

class Kepernyo
{
public:
    Kepernyo(int _sor, int _oszlop, JatekMester& _jm);
    virtual ~Kepernyo();

    void main();
    void main_regi();
    void klikk_esemeny(genv::event ev);
    void set_jatekmester(JatekMester& _jm);

    void uzend(const string& uzenet);

    int get_tartalma(int i, int j) const;
    void set_tartalma(int i, int j, int _tartalma);

    vector<CheckBox*> mezok_irany_szerint(int i, int j, int irany_i, int irany_j);

protected:
    int sor, oszlop;
    vector<vector<CheckBox>> jatekter;
    TextBox szovegdoboz;

    const int cb_meret=25;
    const int margo_x=10;
    const int margo_y=100;
    const int szovegdoboz_magassag=40;

private:
    int XX;
    int YY;

    // tablazat meretei ( az egyszeruseg kedveert )
    int x,y,sx,sy;

    // referencia a jatekmesterre
    JatekMester &jm;
};

#endif // KEPERNYO_H
