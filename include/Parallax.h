#ifndef PARALLAX_H
#define PARALLAX_H

#include <iostream>
#include <windows.h>


using namespace std;


class Parallax
{
    public:
        Parallax();
        virtual ~Parallax();

        void drawSquare(float, float);                  // drawing a square
        void parallaxInit(char*);                       // initialize texture
        void scroll(string, float);               // to scroll the background
        void keyEnv();                                  // move parallax by keys

        float xMin, xMax, yMin, yMax;


    protected:

    private:
};

#endif // PARALLAX_H
