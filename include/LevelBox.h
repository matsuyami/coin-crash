#ifndef LEVELBOX_H
#define LEVELBOX_H

#include <GL/gl.h>
#include <TextureLoader.h>
#include <Timer.h>

typedef struct {

    float x;
    float y;
    float z;
}vec1;

class LevelBox
{
    public:
        LevelBox();
        virtual ~LevelBox();
        void drawLevelBox();
        void levelboxInit(char *);
//        void playerActions();
//        string actionTrigger;
        vec1 verticies[4];

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
