#ifndef CreditSceneEnd_H
#define CreditSceneEnd_H

#include <SceneLoader.h>
#include <GLScene.h>
#include <Objects.h>
#include <Parallax.h>

class SceneLoader;

class CreditSceneEnd : public GLScene
{
    public:
        CreditSceneEnd(SceneLoader*);
        virtual ~CreditSceneEnd();
        GLint initGL();
        GLint drawGLScene();
        int winMsg(HWND, UINT, WPARAM, LPARAM);
        GLvoid resizeGLScene(GLsizei width, GLsizei height);
        SceneLoader* loader;

    protected:

    private:
        float screenWidth, screenHeight;
};

#endif // CreditSceneEnd_H
