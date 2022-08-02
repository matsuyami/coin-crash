#ifndef OBJECTS_H
#define OBJECTS_H
#include <gl/gl.h>
#include <TextureLoader.h>
#include <Timer.h>
#include <Player.h>
#include <SceneLoader.h>
#include <StartScene.h>

class Objects
{
    public:
        Objects();
        virtual ~Objects();

        void objectsInit();
        void assignTexture(char *);
        void placeObjects(float, float, float);
        void drawObjects(float,float);

        bool isObjectLive=true;
        GLuint objectTex;


        float xPos;
        float yPos;
        float zPos;

        float xSize;
        float ySize;

        float rotateX;
        float rotateY;
        float rotateZ;

        float xMin,xMax,yMin,yMax;
        vec verticies[4];

    protected:

    private:
};

#endif // OBJECTS_H
