#ifndef LEVELBOX6_H
#define LEVELBOX6_H

#include <GL/gl.h>
#include <TextureLoader.h>
#include <Timer.h>

typedef struct {

    float x;
    float y;
    float z;
}vec6;

class LevelBox6
{
    public:
        LevelBox6();
        virtual ~LevelBox6();
        void drawLevelBox6();
        void levelbox6Init(char *);
//        void playerActions();
//        string actionTrigger;
        vec6 verticies[4];

//        static Player* player;
        float get_xpos();
        float get_ypos();
        float get_width();
        float get_height();
        float get_width(bool);
        float get_height(bool);

        float xMin, yMin, xMax, yMax;
        TextureLoader * T = new TextureLoader();
        float xPos, yPos, zPos;
        float width, height;
        float xSize, ySize, zSize;

    protected:


    private:
};

#endif // LEVELBOX_H
