#include "objects.h"

//TextureLoader *T1 = new TextureLoader();
Timer *Time2 = new Timer();

Objects::Objects()
{
    //ctor
    xPos=-0.25;
    yPos=1.0;
    zPos-0.5;

    xSize=1;
    ySize=0.5;

    rotateX=0.0;
    rotateY=0.0;
    rotateZ=0.0;

    verticies[0].x =0.0;verticies[0].y =0.0;verticies[0].z =-1.0;
    verticies[1].x =1.0;verticies[1].y =0.0;verticies[1].z =-1.0;
    verticies[2].x =1.0;verticies[2].y =1.0;verticies[2].z =-1.0;
    verticies[3].x =0.0;verticies[3].y =1.0;verticies[3].z =-1.0;
}

Objects::~Objects()
{
    //dtor
}
void Objects::placeObjects(float x, float y, float z)
{
    xPos =x;
    yPos =y;
    zPos =z;
}
void Objects::objectsInit()
{
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);

    //Adding this made my object not be blurry
    glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    //disables bilinear filtering

    //T1->loadTexture(fileName);
    Time2->start();

    xMin=0.0;
    xMax=1.0;

    yMin=0.0;
    yMax=1.0;
}

void Objects::drawObjects(float xSize,float ySize)
{
    //T1->binder();
    glPushMatrix();

    glTranslated(xPos,yPos,zPos);
    glRotated(rotateX,1.0,0.0,0.0);
    glRotated(rotateY,0.0,1.0,0.0);
    glRotated(rotateZ,0.0,0.0,1.0);

    glScaled(xSize,ySize,1.0);

    glBegin(GL_QUADS);
    glScaled(0.5,0.5,0.5);
        glTexCoord2f(xMin,yMax);
        glVertex3f(verticies[0].x,verticies[0].y,verticies[0].z);

        glTexCoord2f(xMax,yMax);
        glVertex3f(verticies[1].x,verticies[1].y,verticies[1].z);

        glTexCoord2f(xMax,yMin);
        glVertex3f(verticies[2].x,verticies[2].y,verticies[2].z);

        glTexCoord2f(xMin,yMin);
        glVertex3f(verticies[3].x,verticies[3].y,verticies[3].z);
    glEnd();

    glPopMatrix();
}
