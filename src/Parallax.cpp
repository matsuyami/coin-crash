#include "Parallax.h"
#include "TextureLoader.h"

TextureLoader *bTexture = new TextureLoader();

Parallax::Parallax()
{

    xMin = 0.0;
    xMax = 1.0;
    yMin = 0.0;
    yMax = 1.0;
    //ctor
}

Parallax::~Parallax()
{
    //dtor
}

void Parallax::drawSquare(float width, float height)
{
    bTexture->binder();
    glScaled(3.33, 3.33, 1.0);
    glBegin(GL_POLYGON);
        glTexCoord2f(xMin, yMax);
        glVertex3f(-width / height, -1, -8.0);
        glTexCoord2f(xMax, yMax);
        glVertex3f(width / height, -1, -8.0);
        glTexCoord2f(xMax, yMin);
        glVertex3f(width / height, 1, -8.0);
        glTexCoord2f(xMin, yMin);
        glVertex3f(-width / height, 1, -8.0);
    glEnd();
}

void Parallax::parallaxInit(char* filename)
{
    bTexture->loadTexture(filename);
}

void Parallax::scroll(string dir, float speed){
        if(dir == "up")   { yMin -= speed; yMax -= speed; }
        if(dir == "left") { xMin -= speed; xMax -= speed; }
        if(dir == "right"){ xMin += speed; xMax += speed; }
        if(dir == "down") { yMin += speed; yMax += speed; }
}
