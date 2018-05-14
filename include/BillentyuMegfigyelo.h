#ifndef BILLENTYUMEGFIGYELO_H
#define BILLENTYUMEGFIGYELO_H

#include "graphics.hpp"

using namespace genv;
using namespace std;

class BillentyuMegfigyelo
{
public:
    BillentyuMegfigyelo();
    virtual ~BillentyuMegfigyelo();

    void esemenyt_bejelent(event ev);

    char utolso_character();

protected:

private:
    bool shift = 0;
    char character;
};

bool ertelmes_charactere(int keycode);


#endif // BILLENTYUMEGFIGYELO_H
