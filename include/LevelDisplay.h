#ifndef LEVELDISPLAY_H
#define LEVELDISPLAY_H

#include <SceneLoader.h>
#include <GLScene.h>
#include <Objects.h>
#include <Parallax.h>
#include <LevelOne.h>
#include <LevelTwo.h>
#include <LevelThree.h>
class SceneLoader;

class LevelDisplay : public GLScene
{
    public:
        LevelDisplay(SceneLoader*);
        virtual ~LevelDisplay();
        GLint initGL();
        GLint drawGLScene();
        int winMsg(HWND, UINT, WPARAM, LPARAM);
        GLvoid resizeGLScene(GLsizei width, GLsizei height);
        SceneLoader* loader;

    protected:

    private:
        float screenWidth, screenHeight;
};

#endif // CREDITSCENE_H

