#ifndef LEVELBOX4_H
#define LEVELBOX4_H

#include <GL/gl.h>
#include <TextureLoader.h>
#include <Timer.h>

typedef struct {

    float x;
    float y;
    float z;
}vec4;

class LevelBox4
{
    public:
        LevelBox4();
        virtual ~LevelBox4();
        void drawLevelBox4();
        void levelbox4Init(char *);
//        void playerActions();
//        string actionTrigger;
        vec4 verticies[4];

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
