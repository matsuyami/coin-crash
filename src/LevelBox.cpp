#include "LevelBox.h"

LevelBox::LevelBox()
{
    //ctor
    width = 1.0;
    height = 1.0;

    verticies[0].x = -width / 10.3;
    verticies[0].y = -height / 4.78;
    verticies[0].z = -1.0;

    verticies[1].x = width / 10.3;
    verticies[1].y = -height / 4.78;
    verticies[1].z = -1.0;

    verticies[2].x = width / 10.3;
    verticies[2].y = height / 4.78;
    verticies[2].z = -1.0;

    verticies[3].x = -width / 10.3;
    verticies[3].y = height / 4.78;
    verticies[3].z = -1.0;

    xMin = 0.0;
    yMin = 0.0;
    xMax = 1.0;
    yMax = 1.0;

    xPos = -0.6288; //org -.5
    yPos = 0.314;  //org -.5
    zPos = 0.0;

    xSize = 1.0;
    ySize = 1.0;
    zSize = 1.0;
}

LevelBox::~LevelBox()
{
    //dtor
}
void LevelBox::drawLevelBox()
{
    T->binder();
    glPushMatrix();
        glTranslated(xPos, yPos, zPos);
        glScaled(xSize, ySize, zSize);
        glBegin(GL_QUADS);
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

void LevelBox::levelboxInit(char* filename)
{
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    xMin = 0.0;
    yMin = 0.0;
    xMax = 1.0;
    yMax = 1.0;


}

float LevelBox::get_xpos()
{
    return xPos;
}

float LevelBox::get_ypos()
{
    return yPos;
}

float LevelBox::get_width()
{
    return width / 10.3;
}

float LevelBox::get_height()
{
    return height / 4.78;
}
