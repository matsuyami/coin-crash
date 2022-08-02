#include "Spikes.h"

Spikes::Spikes()
{
        //ctor
    xPos = ((rand()% 20)-10.0)/10.0;
    yPos = 0.6;
    zPos = 0.0;

    xSize = 1.0;
    ySize = 1.0;

    width = 1.0;
    height = 1.0;
    //moveObj = false;

    verticies[0].x = -width / 15;
    verticies[0].y = -height / 15;
    verticies[0].z = -1.0;

    verticies[1].x = width / 15;
    verticies[1].y = -height / 15;
    verticies[1].z = -1.0;

    verticies[2].x = width / 15;
    verticies[2].y = height / 15;
    verticies[2].z = -1.0;

    verticies[3].x = -width / 15;
    verticies[3].y = height / 15;
    verticies[3].z = -1.0;

    xMin = yMin = 0.0;
    xMax = yMax = 1.0;
}

Spikes::~Spikes()
{
    //dtor
}

void Spikes::spikeInit(char * fileName)
{
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    T1->loadTexture(fileName);
    xMin = 0.0;
    xMax = 1.0;
    yMin = 0.0;
    yMax = 1.0;
}

void Spikes::drawSpike()
{
    T1->binder();
    glPushMatrix();
        glTranslated(xPos, yPos, zPos);
        //glRotated(rotateX, 1.0, 0.0, 0.0);
        //glRotated(rotateY, 0.0, 1.0, 0.0);
        //glRotated(rotateZ, 0.0, 0.0, 1.0);
        glScaled(xSize, ySize, 1.0);
        glBegin(GL_QUADS);
            glTexCoord2d(xMin, yMax);
            glVertex3f(verticies[0].x, verticies[0].y, verticies[0].z);

            glTexCoord2d(xMax, yMax);
            glVertex3f(verticies[1].x, verticies[1].y, verticies[1].z);

            glTexCoord2d(xMax, yMin);
            glVertex3f(verticies[2].x, verticies[2].y, verticies[2].z);

            glTexCoord2d(xMin, yMin);
            glVertex3f(verticies[3].x, verticies[3].y, verticies[3].z);
        glEnd();
    glPopMatrix();

    yPos -= 0.0005;   // call coin movements right here
    if(yPos <= -0.9){
    yPos = 0.6;
    xPos = ((rand()% 20)-10.0)/10.0;
    }
}
/*
// non moving spike for testing.
void Spikes::drawSpike(bool _)
{
    T1->binder();
    glPushMatrix();
        glTranslated(xPos, yPos, zPos);
        //glRotated(rotateX, 1.0, 0.0, 0.0);
        //glRotated(rotateY, 0.0, 1.0, 0.0);
        //glRotated(rotateZ, 0.0, 0.0, 1.0);
        glScaled(xSize, ySize, 1.0);
        glBegin(GL_QUADS);
            glTexCoord2d(xMin, yMax);
            glVertex3f(verticies[0].x, verticies[0].y, verticies[0].z);

            glTexCoord2d(xMax, yMax);
            glVertex3f(verticies[1].x, verticies[1].y, verticies[1].z);

            glTexCoord2d(xMax, yMin);
            glVertex3f(verticies[2].x, verticies[2].y, verticies[2].z);

            glTexCoord2d(xMin, yMin);
            glVertex3f(verticies[3].x, verticies[3].y, verticies[3].z);
        glEnd();
    glPopMatrix();
}
*/

void Spikes::placeSpike(float x, float y, float z)
{
    xPos = x;
    yPos = y;
    zPos = z;
}

void Spikes::assignTex(char*)
{

}

float Spikes::get_xpos()
{
    return xPos;
}

float Spikes::get_ypos()
{
    return yPos;
}

float Spikes::get_width()
{
    return width / 40;
}

float Spikes::get_height()
{
    return height / 40;
}
