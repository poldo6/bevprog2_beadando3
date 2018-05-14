#ifndef INPUTPASSWORDBOX_H
#define INPUTPASSWORDBOX_H

#include "graphics.hpp"
#include "InputBox.h"

using namespace std;
using namespace genv;

class InputPasswordBox : public InputBox
{
    private:

    protected:

    public:
        InputPasswordBox();
        InputPasswordBox(int x, int y, int szel, int hossz);
        virtual ~InputPasswordBox();

        virtual string get_szoveg();
        virtual string konzolrakiir();

};

#endif // INPUTPASSWORDBOX_H
