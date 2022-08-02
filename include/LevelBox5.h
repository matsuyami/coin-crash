#ifndef LEVELBOX5_H
#define LEVELBOX5_H

#include <GL/gl.h>
#include <TextureLoader.h>
#include <Timer.h>

typedef struct {

    float x;
    float y;
    float z;
}vec5;

class LevelBox5
{
    public:
        LevelBox5();
        virtual ~LevelBox5();
        void drawLevelBox5();
        void levelbox5Init(char *);
//        void playerActions();
//        string actionTrigger;
        vec5 verticies[4];

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
