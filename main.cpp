#include "graphics.hpp"
#include "JatekTer.h"

#include <vector>
#include <iostream>

using namespace genv;
using namespace std;

int main()
{
    gout.open(JatekTer::XX,JatekTer::YY);

    event ev;
    while(gin >> ev && ev.keycode!=key_escape)
    {

    }

    return 0;
}
