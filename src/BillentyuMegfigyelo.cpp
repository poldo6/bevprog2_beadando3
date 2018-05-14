#include "BillentyuMegfigyelo.h"

BillentyuMegfigyelo::BillentyuMegfigyelo()
{
    //ctor
}

BillentyuMegfigyelo::~BillentyuMegfigyelo()
{
    //dtor
}

void BillentyuMegfigyelo::esemenyt_bejelent(event ev)
{
    if (ev.type != ev_key)
    {
        return;
    }

    if (ev.keycode == key_lshift || ev.keycode == key_rshift)
    {
        shift = true;
    }

    if (ev.keycode == -key_lshift || ev.keycode == -key_rshift)
    {
        shift = false;
    }

    if (ertelmes_charactere(ev.keycode))
    {
        character = ev.keycode;
    }
    else
    {
        character = 0;
    }
}

char BillentyuMegfigyelo::utolso_character()
{
    return character;
}

bool ertelmes_charactere(int keycode)
{
    return 32 <= keycode && keycode <= 126;
}

