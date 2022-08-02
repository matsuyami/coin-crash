#ifndef TEXTURELOADER_H
#define TEXTURELOADER_H
#include <SOIL.h>
#include <GL/gl.h>
#include <iostream>
using namespace std;

class TextureLoader
{
    public:
        TextureLoader();
        virtual ~TextureLoader();

        void binder();
        void loadTexture(char*);

        unsigned char* image;
        int width, height;

        GLuint tex;

    protected:

    private:
};

#endif // TEXTURELOADER_H
