#ifndef INPUTS_H
#define INPUTS_H
#include<windows.h>
#include<Model.h>
#include<Parallax.h>
#include<Player.h>
#include <Sounds.h>

class Inputs
{
    public:
        Inputs();
        virtual ~Inputs();

        void keyPressed(Model *);
        void keyUp();
        void keyEnv(Parallax *,float);      ///**************************************move parallax by keys
        void mouseEventDown(Model *, double, double);
        void mouseEventUp();
        void mouseEventWheel(Model *, double);
        void mouseEventMove(Model *,double, double);
        void playerAction(Player *);
        void playerAction2(Player *);
        double prev_mouse_X;
        double prev_mouse_Y;

        bool mouse_Translate;
        bool mouse_Rotate;
        void keySounds(Sounds*);


        WPARAM wParam;

    protected:

    private:
};

#endif // INPUTS_H
