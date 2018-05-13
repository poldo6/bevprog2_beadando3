#ifndef JATEK_MESTER_H
#define JATEK_MESTER_H
#include "CheckBox.h"
#include <vector>

class JatekMester
{
    public:
        JatekMester(int _sor, int _oszlop);

        virtual ~JatekMester();

        void valt();

        void xelt(int i, int j);

        void esemeny(event ev);

        void jatek_indit();

    protected:
        int sor, oszlop;
        vector<vector<CheckBox>> jatekter;

        const int cb_meret=40;
        const int margo_x=10;
        const int margo_y=100;

        int soron_kovetkezo=-1;

    private:
};

#endif // JATEK_MESTER_H
