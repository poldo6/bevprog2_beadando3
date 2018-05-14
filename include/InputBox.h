#ifndef INPUTBOX_H
#define INPUTBOX_H

#include "graphics.hpp"
#include "Widget.h"
#include "BillentyuMegfigyelo.h"

using namespace std;
using namespace genv;

class InputBox : public Widget
{
protected:
    string szoveg;
    BillentyuMegfigyelo bmegfigyelo;

public:
    InputBox();
    InputBox(int x, int y, int szel, int hossz);
    virtual ~InputBox();

    void alapertelmezett_szoveg(string alapertelmezett);

    // Ezt orokli a Widget-bol, de feluldefinialja (kotelezo, mivel ott nincs definialva)
    virtual void rajzol() const;
    virtual void kezeld_az_esemenyt(event ev);

    // Ezt az InputPasswordBox felul fogja irni es csak csillagokat fog visszaadni.
    virtual string get_szoveg() const;
};

#endif // INPUTBOX_H
