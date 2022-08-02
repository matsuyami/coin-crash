#include "Sounds.h"

Sounds::Sounds()
{
    //ctor

}

Sounds::~Sounds()
{
    //dtor
    engine->drop(); // delete engine
}

void Sounds::playMusic(char* File)
{
      engine->play2D(File,true);

}

void Sounds::playSound(char* File)
{
     engine->play2D(File,false,false);

}

void Sounds::pauseSound(char* File)
{
    engine->play2D(File, true,false);
}

void Sounds::stopAllSounds()
{
    engine->stopAllSounds();
}


int Sounds::initSounds()
{
     if (!engine)
	{
		cout<<"Could not startup engine\n";
		return 0; // error starting up the engine
	}
	return 1;
}


