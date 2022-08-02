#ifndef INFOSCENE_H
#define INFOSCENE_H
#include <GLScene.h>
#include <Inputs.h>
#include <SceneLoader.h>
#include <Objects.h>
#include <CreditScene.h>

class InfoScene : public GLScene
{
    public:
        InfoScene(SceneLoader*);
        virtual ~InfoScene();
        GLint initGL();
        GLint drawGLScene();
        int winMsg(HWND, UINT, WPARAM, LPARAM);
        GLvoid resizeGLScene(GLsizei width, GLsizei height);
        SceneLoader* loader;


    protected:

    private:
        float screenWidth, screenHeight;
};

#endif // INFOSCENE_H
