#ifndef LEVELBOX2_H
#define LEVELBOX2_H

#include <GL/gl.h>
#include <TextureLoader.h>
#include <Timer.h>

typedef struct {

    float x;
    float y;
    float z;
}vec2;

class LevelBox2
{
    public:
        LevelBox2();
        virtual ~LevelBox2();
        void drawLevelBox2();
        void levelbox2Init(char *);
//        void playerActions();
//        string actionTrigger;
        vec2 verticies[4];

//        static Player* player;
        float get_xpos();
        float get_ypos();
        float get_width();
        float get_height();
        float xMin, yMin, xMax, yMax;
        TextureLoader * T = new TextureLoader();
        float xPos, yPos, zPos;
        float width, height;
        float xSize, ySize, zSize;

    protected:


    private:
};

#endif // LEVELBOX_H
