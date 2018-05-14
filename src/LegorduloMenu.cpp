#include "LegorduloMenu.h"
#include "graphics.hpp"

#include <iostream>

using namespace std;
using namespace genv;

LegorduloMenu::LegorduloMenu () : Widget()
{
}

LegorduloMenu::~LegorduloMenu()
{
    //dtor
}

LegorduloMenu::LegorduloMenu(int _x, int _y, int _sx, int _sy) : Widget(_x,_y,_sx,_sy)
{
}

void LegorduloMenu::uj_item_hozzaad (string str)
{
    itemek.push_back(str);
}

void LegorduloMenu::rajzol() const
{
    // Kirajzolom a fo reszet
    szinbeallit_hatter();
    gout << move_to(x, y) << box(sx, sy);

    szinbeallit_hatter_sotetebb();
    gout << genv::move(-1, -1) << box(-gombszel, -sy + 2);

    // Nyil rajzolasa
    szinbeallit_szoveg();
    int nyil_magassag_fele = 3;
    gout << move_to(x + sx - gombszel / 2 - 1, y + sy/2 + nyil_magassag_fele)
        << line_to(x + sx - gombszel + 4, y + sy/2 - nyil_magassag_fele)
        << line_to(x + sx - 5, y + sy/2 - nyil_magassag_fele)
        << line_to(x + sx - gombszel / 2 - 1, y + sy/2 + nyil_magassag_fele);

    gout << move_to(x + 5, y + sy / 2 + 4) << text(itemek[aktualisan_kivalasztott]);

    if (aktiv)
    {
        szinbeallit_hatter();
        gout << move_to(x, y + sy) << box(sx, itemek.size() * sormagassag);

        for (int i = 0; i < itemek.size(); i++)
        {
            // halovany elvalaszto vonal rajzolasa
            szinbeallit_szurke();
            gout << move_to(x, y + sy + i * sormagassag) << line(sx, 0);

            szinbeallit_szoveg();
            gout << move_to(x + 5, y + sy + i * sormagassag + sormagassag / 2 + 4) << text(itemek[i]);
        }
    }
}

bool LegorduloMenu::raklikkeltem (int mousex, int mousey)
{
    // Ha eppen aktiv (vagyis le van gordulve), akkor a klikkelesnel azt is kell nezni,
    // hogy legordulo menusorbol valamelyikre raklikkel-e.
    // Widget tenyleges merete tulcsordul a pos_y-on.

    if (aktiv)
    {
        // ha le van gordulve (aktiv)
        aktiv = x <= mousex && mousex <= x + sx && y <= mousey && mousey <= y + sy + itemek.size() * sormagassag;
    }
    else
    {
        // ha nincs legordulve
        aktiv = x <= mousex && mousex <= x + sx && y <= mousey && mousey <= y + sy;
    }

    return aktiv;
}

void LegorduloMenu::kezeld_az_esemenyt (event ev)
{
    // Ellenorzom, hogy raklikkeltem-e a bal klikkel
    if (ev.type == ev_mouse && ev.button == btn_left)
    {
        // ha a legordito gombra kattintottam ra
//        if (x+sx-gombszel+1 <= ev.pos_x && ev.pos_y <= y+sy)
//        {
//            aktiv = !aktiv;
//        }

        if (y + sy < ev.pos_y)
        {
            int index = (ev.pos_y - y - sy) / sormagassag;

            // ellenorzes
            if (0 <= index && index < itemek.size())
            {
                aktualisan_kivalasztott = index;
                aktiv = false;
            }
        }
    }
}


