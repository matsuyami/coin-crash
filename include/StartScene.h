#ifndef STARTSCENE_H
#define STARTSCENE_H

#include <GLScene.h>
#include <Parallax.h>
#include <Inputs.h>
#include <SceneLoader.h>
#include <LevelOne.h>

class SceneLoader;

class StartScene : public GLScene
{
    public:
        StartScene();
        virtual ~StartScene();

        GLint initGL();
        GLint drawGLScene();

        int winMsg (HWND, UINT, WPARAM, LPARAM);
        GLvoid resizeGLScene(GLsizei width, GLsizei height);
        SceneLoader* loader;
        bool f1;
        bool f2;

    private:
        float screenWidth, screenHeight;

        // loader loads scene


};

#endif // STARTSCENE_H
