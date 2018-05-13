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

    protected:
        int sor, oszlop;
        vector<vector<CheckBox>> jatekter;

        const int cb_meret=10;
        const int margo_x=10;
        const int margo_y=40;



    private:
};

#endif // JATEKTER_H
