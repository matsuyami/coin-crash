#ifndef CREDITSCENE_H
#define CREDITSCENE_H

#include <SceneLoader.h>
#include <GLScene.h>
#include <Objects.h>
#include <Parallax.h>

class SceneLoader;

class CreditScene : public GLScene
{
    public:
        CreditScene(SceneLoader*);
        virtual ~CreditScene();
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
