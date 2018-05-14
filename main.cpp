#include "JatekMester.h"

/*

Feladatkiiras:

Klasszikus zártpályás (minimum 15x15, max 30x30) amőba, ahol 5 egyformát kell kirakni egy sorba.

Kétszemélyes játék, hol az egyik játékos lép, hol a másik. [OK]

Gépi játékos írásáért extra pontokat lehet kapni.
A programnak kezelnie kell minden lehetséges esetet, azt is, ha betelik a pálya. [KEZELI]

Extra pont lehetőségek: gépi játékos. [NINCS]

*/

int main()
{
    JatekMester jm(15,30);
    jm.jatek_indit();
    return 0;
}
