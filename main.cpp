#include "graphics.hpp"
#include "JatekTer.h"

#include <vector>
#include <iostream>

using namespace genv;
using namespace std;

int main()
{
    gout.open(JatekTer::XX,JatekTer::YY);

    JatekTer jt(20,15);
    event ev;
    while(gin >> ev && ev.keycode!=key_escape)
    {
        if(ev.type==ev_mouse && ev.button==btn_left)
        {

        }
    }

    return 0;
}
