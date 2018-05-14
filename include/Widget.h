#ifndef WIDGET_HPP_INCLUDED
#define WIDGET_HPP_INCLUDED

#include "graphics.hpp"
#include <vector>

class Widget
{
protected:
    int x,y;
    int sx,sy;
    int id;

    bool kiemelt=false;

public:
    Widget();
    Widget(int _x, int _y, int _sx, int _sy, int _id);

    void atmeretez(int _x, int _y, int _sx, int _sy, int _id);

    void szinez() const;
    void kiemel(bool _kiemel);

    virtual void draw() const = 0;
    virtual void action(genv::event ev) = 0;
};

#endif // WIDGET_HPP_INCLUDED
