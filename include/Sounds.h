#ifndef SOUNDS_H
#define SOUNDS_H

#include <SNDS/irrKlang.h>

#include <stdlib.h>
#include <iostream>

#include <conio.h>
#pragma comment(lib, "irrKlang.lib") // link with irrKlang.dll
using namespace irrklang;


using namespace std;

class Sounds
{
    public:
        Sounds();
        virtual ~Sounds();
        void playMusic(char *);
        void playSound(char *);
        void pauseSound(char *);
        void stopAllSounds();
        int initSounds();
        ISoundEngine* engine = createIrrKlangDevice();
    protected:

    private:
};



#endif // SOUNDS_H
