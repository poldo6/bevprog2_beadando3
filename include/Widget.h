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

    // Azt mondja meg, hogy az utolso klikkeleskor beleklikkeltem-e?
    bool aktiv = false;

public:
    Widget();
    Widget(int _x, int _y, int _sx, int _sy);
    Widget(int _x, int _y, int _sx, int _sy, int _id);
    virtual ~Widget();

    // Atmeretezi a widgetet.
    void atmeretez(int _x, int _y, int _sx, int _sy, int _id);

    void kiemel(bool _kiemel);

    // Ezeket a fuggvenyeket az oroklo osztalyok ujra fogjak definialni.
    virtual bool raklikkeltem(int mouse_x, int mouse_y);
    virtual void rajzol() const = 0;
    virtual void kezeld_az_esemenyt(genv::event ev) = 0;

    void szinez() const;
    void szinbeallit_hatter() const;
    void szinbeallit_hatter_sotetebb() const;
    void szinbeallit_szoveg() const;
    void szinbeallit_szurke() const;
};

#endif // WIDGET_HPP_INCLUDED
