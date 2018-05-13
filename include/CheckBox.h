#ifndef CHECKBOX_H
#define CHECKBOX_H
#include "Widget.h"

using namespace std;
using namespace genv;

class CheckBox : public Widget
{
    public:
        CheckBox(int _x, int _y, int _sx, int _sy, int _id);
        virtual ~CheckBox();

        virtual void draw() const;
        virtual void action(event ev);

    protected:
        int tartalma=0;


    private:
};

#endif // CHECKBOX_H
