#ifndef NYOMOGOMB_H
#define NYOMOGOMB_H

#include "graphics.hpp"
#include "Widget.h"
#include "BillentyuMegfigyelo.h"
#include <vector>

using namespace genv;

class NyomoGomb : public Widget
{
protected:
public:
    NyomoGomb();
    NyomoGomb(int x, int y, int szel, int hossz);
    virtual ~NyomoGomb();

    virtual void kezeld_az_esemenyt(event ev);
    virtual bool raklikkeltem(int mouse_x, int mouse_y);
    virtual void rajzol() const;

};

#endif // NYOMOGOMB_H
