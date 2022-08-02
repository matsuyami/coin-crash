#ifndef COIN_H
#define COIN_H

#include<GL/gl.h>
#include <TextureLoader.h>
#include <Timer.h>
#include <utility>

typedef struct {
    float x, y, z;
}vec3;

class Coin
{
    public:
        Coin();
        ~Coin();

        virtual void coinInit();
        virtual void drawCoin();
        virtual void placeCoins(float, float, float);
        void assignTex(char*);

        bool isAlive = true;
        GLuint coinTex;

        float xPos, yPos, zPos;
        float xSize, ySize;
        float rotateX, rotateY, rotateZ;

        float xMin, yMin;
        float xMax, yMax;
        vec3 verticies[4];
        float width, height;
        float get_xpos();
        float get_ypos();
        float get_width();
        float get_height();
        pair<float, float> gen_rand_pair();
    protected:

    private:
};

#endif // COIN_H
