#ifndef LITECOIN_H
#define LITECOIN_H
#include "Coin.h"


class Litecoin : public Coin
{
    public:
        Litecoin();
        void coinInit();
        void drawCoin();
        void placeCoins(float, float, float);
        void assignTex(char*);
        bool isAlive = true;
        GLuint coinTex;

        float xPos, yPos, zPos;
        float xSize, ySize;
        float rotateX, rotateY, rotateZ;

        float xMin, yMin;
        float xMax, yMax;
        vec3 verticies[4];
        virtual ~Litecoin()=default;
        float width, height;
        float get_xpos();
        float get_ypos();
        float get_width();
        float get_height();
    protected:

    private:
};

#endif // LITECOIN_H
