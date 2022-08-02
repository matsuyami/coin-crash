#ifndef LEVELBOX3_H
#define LEVELBOX3_H

#include <GL/gl.h>
#include <TextureLoader.h>
#include <Timer.h>

typedef struct {

    float x;
    float y;
    float z;
}vect3;

class LevelBox3
{
    public:
        LevelBox3();
        virtual ~LevelBox3();
        void drawLevelBox3();
        void levelbox3Init(char *);
//        void playerActions();
//        string actionTrigger;
        vect3 verticies[4];

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
