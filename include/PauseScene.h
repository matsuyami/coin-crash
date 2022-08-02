#ifndef PauseScene_H
#define PauseScene_H
#include<GLScene.h>
#include<Inputs.h>
#include<SceneLoader.h>
#include<GLLight.h>
#include<LevelOne.h>
///should include other level headers
#include <Player.h>
#include<InfoScene.h>
#include <GL/gl.h>
#include <StartScene.h>
#include <Sounds.h>
class SceneLoader;
class PauseScene : public GLScene
{
    public:
        PauseScene(SceneLoader*);//, Sounds*);

        virtual ~PauseScene();
        GLint initGL();
        GLint drawGLScene();
        int winMsg(HWND, UINT, WPARAM, LPARAM);
        GLvoid resizeGLScene(GLsizei width, GLsizei height);
        SceneLoader* loader;
        bool fire1;
        bool fire2;
        bool fire3;
        bool fire4;
        float xize;
        float yize;
        float zize;
        Sounds* SND;
        string prevSceneName;


    protected:

    private:
};

#endif // PauseScene_H
