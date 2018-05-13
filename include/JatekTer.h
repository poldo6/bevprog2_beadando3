#ifndef JATEKTER_H
#define JATEKTER_H
#include "CheckBox.h"
#include <vector>

class JatekTer
{
    public:
        JatekTer(int _sor, int _oszlop);

        virtual ~JatekTer();

    static const int XX = 800;
    static const int YY = 600;

    void valt();

    void xelt(int i, int j);

    void esemeny(event ev);

    protected:
        int sor, oszlop;
        vector<vector<CheckBox>> jatekter;

        const int cb_meret=40;
        const int margo_x=10;
        const int margo_y=100;

        int soron_kovetkezo=-1;

    private:
};

#endif // JATEKTER_H
