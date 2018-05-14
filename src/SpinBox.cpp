#include <iostream>
#include <sstream>

#include "SpinBox.h"

using namespace genv;
using namespace std;

SpinBox::SpinBox () : Widget()
{
}

SpinBox::SpinBox(int _x, int _y, int _sx, int _sy) : Widget(_x,_y,_sx,_sy,0)
{
}

SpinBox::~SpinBox() { }

void SpinBox::alapertelmezett_szam(int alapertelmezett)
{
    szam = alapertelmezett;
}

void SpinBox::novel (int ennyivel)
{
    szam += ennyivel;
}

void SpinBox::rajzol() const
{
    // Alaphatter rajzolasa (ezzel ki is toroljuk az elozo szamot)
    szinbeallit_hatter();
    gout << move_to(x, y) << box(sx, sy);

    // Ket gomb rajzolasa
    szinbeallit_hatter_sotetebb();
    gout << genv::move(-1, -1) << box(-gombszel, -sy / 2 + 2)
        << genv::move(0, -2) << box(gombszel, -sy / 2 + 1);

    // Felso nyil
    szinbeallit_szoveg();
    int nyil_magassag_fele = 3;
    gout << move_to(x + sx - gombszel / 2 - 1, y + sy/4 - nyil_magassag_fele)
        << line_to(x + sx - gombszel + 4, y + sy/4 + nyil_magassag_fele)
        << line_to(x + sx - 5, y + sy/4 + nyil_magassag_fele)
        << line_to(x + sx - gombszel / 2 - 1, y + sy/4 - nyil_magassag_fele);

    // Also nyil
    gout << move_to(x + sx - gombszel / 2 - 1, y + 3*sy/4 + nyil_magassag_fele)
        << line_to(x + sx - gombszel + 4, y + 3*sy/4 - nyil_magassag_fele)
        << line_to(x + sx - 5, y + 3*sy/4 - nyil_magassag_fele)
        << line_to(x + sx - gombszel / 2 - 1, y + 3*sy/4 + nyil_magassag_fele);

    // Szam kirajzolasa
    stringstream ss;
    ss << szam;
    gout << move_to(x + 5, y + sy / 2 + 4) << text(ss.str());
}

void SpinBox::kezeld_az_esemenyt(event ev)
{
    // Ha jobbklikkeles tortent
    if (ev.type == ev_mouse && ev.button == btn_left)
    {
        // ellenorzom, hogy megnyomta-e a felfele nyilat
        if (x + sx - gombszel + 1 <= ev.pos_x && ev.pos_y <= y + sy / 2 - 2)
        {
            novel(1);
        }

        // ellenorzom, hogy megnyomta-e a lefele gombot
        if (x + sx - gombszel + 1 <= ev.pos_x && y + sy / 2 + 2 <= ev.pos_y)
        {
            novel(-1);
        }
    }
}
