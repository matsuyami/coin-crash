#include "Coin.h"
#include "TextureLoader.h"
//TextureLoader* T1 = new TextureLoader();
Coin::Coin()
{
    //ctor
    xPos = 0.0;
    yPos = 0.0;
    zPos = 0.0;

    xSize = 1.0;
    ySize = 1.0;

    rotateX = 0.0;
    rotateY = 0.0;
    rotateZ = 0.0;

    width = 1.0;
    height = 1.0;
    //moveObj = false;

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

    xMin = yMin = 0.0;
    xMax = yMax = 1.0;
}

Coin::~Coin()
{
    //dtor
}

void Coin::coinInit()
{
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    //T1->loadTexture(fileName);
    //T1->loadTexture("images/testing.png");
    xMin = 0.0;
    xMax = 1.0;
    yMin = 0.0;
    yMax = 1.0;

}

void Coin::drawCoin()
{
    //T1->binder();
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


    yPos -= 0.0008;   // call coin movements right here
    if(yPos <= -0.9){
    yPos = 0.6;
    xPos = ((rand()% 20)-10.0)/10.0;
    //cout << xPos << endl;
    }

    // Draw bounding box of coin
/*
    glPushMatrix();
        float cwOffset = width / 20;
        float chOffset = height / 20;

        float c_xmin = xPos * 0.65 - cwOffset;
        float c_xmax = xPos * 0.65+ cwOffset;
        float c_ymin = yPos * 0.65- chOffset;
        float c_ymax = yPos * 0.65+ chOffset;

    T1->binder();
        glBegin(GL_QUADS);
        glVertex3f(c_xmax, c_ymin, -1.0);
        glVertex3f(c_xmin, c_ymin, -1.0);
        glVertex3f(c_xmin, c_ymax, -1.0);
        glVertex3f(c_xmax, c_ymax, -1.0);
        glEnd();
    glPopMatrix();
*/
}

void Coin::placeCoins(float x, float y, float z)
{
    xPos = x;
    yPos = y;
    zPos = z;
}

pair<float, float> Coin::gen_rand_pair(){
    pair<float, float> rand_pair;
    float tempX = ((rand()% 20)-10)/10.00;
    float tempY = (rand()% 10)/10.00;
    rand_pair = std::make_pair(tempX, tempY);
    return rand_pair;
}

float Coin::get_xpos()
{
    return xPos;
}

float Coin::get_ypos()
{
    return yPos;
}

// used for collision
float Coin::get_width()
{
    return width / 60;
}

float Coin::get_height()
{
    return height / 60;
}


