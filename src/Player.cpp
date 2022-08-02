#include "Player.h"
#include <Timer.h>

Player::Player()
{
    //ctor
    width = 1.0;
    height = 1.0;

    verticies[0].x = -width / 20;
    verticies[0].y = -height / 20;
    verticies[0].z = -1.0;

    verticies[1].x = width / 20;
    verticies[1].y = -height / 20;
    verticies[1].z = -1.0;

    verticies[2].x = width / 20;
    verticies[2].y = height / 20;
    verticies[2].z = -1.0;

    verticies[3].x = -width / 20;
    verticies[3].y = height / 20;
    verticies[3].z = -1.0;

    xMin = 0.0;
    yMin = 0.0;
    xMax = 1.0;
    yMax = 1.0;

    xPos = 0.0; //org -.5
    yPos = 0.0;  //org -.5
    zPos = 0.0;

    xSize = 1.0;
    ySize = 1.0;
    zSize = 1.0;
}

Player::~Player()
{
    //dtor
}
void Player::drawPlayer()
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

void Player::playerInit(char * fileName)
{
glEnable(GL_BLEND);
glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);
T->loadTexture(fileName);
Time->start();
xMin = 0.0;
xMax = 1.0/4.0; //0.25;  /////reverse the xmin and xmax and ymin and ymax if you want the sprite image to be inversed

yMin = 0.5;
yMax = 3.0/4.0;//.25;
}

void Player::playerActions()
{
    if(actionTrigger == "Stand"){
        xMin = xMin;//0.0;
        xMax = xMax;//1.0/4.0; //0.25;  /////reverse the xmin and xmax and ymin and ymax if you want the sprite image to be inversed

        yMin = yMin;//0.0;
        yMax = yMax;//1.0/4.0;//.25;
        //yPos = -0.6;

    }
    if(actionTrigger == "Right"){
        //yPos = -0.6;
        yMin = 0.0;
        yMax = 1.0/4.0;
        if(Time->getTicks() > 65){
        xMin += (1.0/4.0);//+= 0.16;
        xMax += (1.0/4.0);//0.16;
        xPos += .06;
//cout << "xPos is: " << xPos << "and yPos is: " << yPos << endl;
        if(xPos >= 1.0){
            xPos = -1.0;
        }

        Time->reset();
        }

    }

    if(actionTrigger == "Left"){
        yMin = 1.0/4.0;
        yMax = 2.0/4.0;
        if(Time->getTicks() > 65){
        xMin += (1.0/4.0);//+= 0.16;
        xMax += (1.0/4.0);//0.16;
        xPos -= .06;
        //cout << "xPos is: " << xPos << "and yPos is: " << yPos << endl;
        if(xPos <= -1.0){
            xPos = 1.0;
        }
        Time->reset();
        }

    }

    if(actionTrigger == "Up"){
    yMin = 2.0/4.0;
    yMax = 3.0/4.0;
    if(Time->getTicks() > 65){
        xMin += (1.0/4.0);//+= 0.16;
        xMax += (1.0/4.0);//0.16;
        yPos += .06;
        //cout << "xPos is: " << xPos << "and yPos is: " << yPos << endl;
        //cout << yPos << " ";
        if(yPos >= .55){
            yPos = -0.68;
        }

        Time->reset();
    }
    }

    if(actionTrigger == "Down"){
    yMin = 3.0/4.0;
    yMax = 4.0/4.0;
    if(Time->getTicks() > 65){
        xMin += (1.0/4.0);//+= 0.16;
        xMax += (1.0/4.0);//0.16;
        yPos += -.06;
        if(yPos <= -.60){
            yPos = 0.55;
        }
        Time->reset();
    }
    }

    if(actionTrigger == "Slant"){
    yMin = 2.0/4.0;
    yMax = 3.0/4.0;
    if(Time->getTicks() > 65){
        xMin += (1.0/4.0);//+= 0.16;
        xMax += (1.0/4.0);//0.16;
        yPos += .2;
        xPos += .2;
        //cout << "xPos is: " << xPos << "and yPos is: " << yPos << endl;
        //cout << yPos << " ";
        if(yPos >= .55){
            yPos = -0.68;
        }

        Time->reset();
    }
    }
}

float Player::get_xpos(){
    return xPos;
}

float Player::get_ypos(){
    return yPos;
}

// used for collision
float Player::get_width(){
    return width / 25;
}

float Player::get_height(){
    return height / 25;
}
