#ifndef SPINBOX_H
#define SPINBOX_H

#include <sstream>
#include "Widget.h"

using namespace std;

class SpinBox : public Widget
{
private:
    int szam=0;
    int gombszel=21;

protected:

public:
    SpinBox();
    SpinBox(int x, int y, int szel, int hossz);
    virtual ~SpinBox();

    void alapertelmezett_szam(int alapertelmezett);
    void novel(int ennyivel);

    virtual void rajzol() const;
    virtual void kezeld_az_esemenyt(genv::event ev);
};

#endif // SPINBOX_H
