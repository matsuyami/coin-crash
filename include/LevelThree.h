#ifndef LEVELTHREE_H
#define LEVELTHREE_H
#include<windows.h>
#include <GLScene.h>
#include <Parallax.h>
#include <Inputs.h>
#include <SceneLoader.h>
#include <Player.h>
#include <Coin.h>
#include <LevelTwo.h>
#include <LevelOne.h>
#include <Spikes.h>
class SceneLoader;

class LevelThree : public GLScene
{
    public:
        LevelThree(SceneLoader*);
        virtual ~LevelThree();
        GLint initGL();
        GLint drawGLScene();

        int winMsg (HWND, UINT, WPARAM, LPARAM);
        GLvoid resizeGLScene(GLsizei width, GLsizei height);
        float screenWidth, screenHeight;
        void playerMovements(Player *);
        WPARAM wParam;
        bool keys[256];
        SceneLoader* loader;

    protected:

    private:
};

#endif // LEVELTHREE_H
