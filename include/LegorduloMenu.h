#ifndef LEGORDULO_MENU_HPP
#define LEGORDULO_MENU_HPP

#include "Widget.h"

#include <string>
#include <vector>

using namespace std;

class LegorduloMenu : public Widget
{
    protected:
        vector<string> itemek = vector<string>(1,"<default>");

        int aktualisan_kivalasztott = 0;
        int sormagassag = 30;
        int gombszel=21;

    public:
        LegorduloMenu ();
        LegorduloMenu(int x, int y, int szel, int hossz);
        virtual ~LegorduloMenu();

        void uj_item_hozzaad (string str);

        // Widget-bol orokolt metodusok feluldefinialasa
        virtual bool raklikkeltem (int mouse_x, int mouse_y);
        virtual void rajzol() const;
        virtual void kezeld_az_esemenyt(genv::event ev);
        // uj irat 2018 04 19

};

#endif /* LEGORDULO_MENU_HPP */

