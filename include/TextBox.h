#ifndef TEXTBOX_H
#define TEXTBOX_H

#include <string>

#include "Widget.h"

using namespace std;

class TextBox : public Widget
{
public:
    TextBox();
    TextBox(int _x, int _y, int _sx, int _sy);
    virtual ~TextBox();

    void set_szoveg(const string& _szoveg);

    virtual void draw() const;
    virtual void action(genv::event ev);

protected:
    string szoveg;

private:
    const int szoveg_magassag = 5;
    const int bekezdes = 10;
};

#endif // TEXTBOX_H
