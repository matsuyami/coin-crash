#ifndef LEVELTWO_H
#define LEVELTWO_H
#include<windows.h>
#include <GLScene.h>
#include <Parallax.h>
#include <Inputs.h>
#include <SceneLoader.h>
#include <Player.h>
#include <Coin.h>
#include <LevelOne.h>
class SceneLoader;

class LevelTwo : public GLScene
{
    public:
        LevelTwo(SceneLoader*);
        virtual ~LevelTwo();
        GLint initGL();
        GLint drawGLScene();

        int winMsg (HWND, UINT, WPARAM, LPARAM);
        GLvoid resizeGLScene(GLsizei width, GLsizei height);
        float screenWidth, screenHeight;
        void playerMovements(Player *);
        WPARAM wParam;
        bool keys[256];
        SceneLoader* loader;
        bool isPaused = false;


    protected:

    private:
};

#endif // LEVELTWO_H
