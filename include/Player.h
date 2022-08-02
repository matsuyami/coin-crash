#ifndef PLAYER_H
#define PLAYER_H

#include<GL/gl.h>
#include<TextureLoader.h>
#include <Timer.h>

typedef struct {

    float x;
    float y;
    float z;
}vec;


class Player
{
    public:
        Player();
        virtual ~Player();

        void drawPlayer();
        void playerInit(char *);
        void playerActions();
        string actionTrigger;
        vec verticies[4];

        static Player* player;
        float get_xpos();
        float get_ypos();
        float get_width();
        float get_height();
        float xMin,yMin,xMax,yMax;
        TextureLoader * T = new TextureLoader();
        Timer *Time = new Timer();
        float xPos, yPos, zPos;
        float width, height;
        float xSize, ySize, zSize;

        int currentScore;
        int deathCount;
        bool death = false;
    protected:

    private:
};

#endif // PLAYER_H
