#ifndef LEVELONE_H
#define LEVELONE_H
#include<windows.h>
#include <GLScene.h>
#include <Parallax.h>
#include <Inputs.h>
#include <SceneLoader.h>
#include <Player.h>
#include <Coin.h>
#include <LevelTwo.h>
#include <string>
#include <HUD.h>

class SceneLoader;

class LevelOne : public GLScene
{
    public:
        LevelOne(SceneLoader*);
        virtual ~LevelOne();
        GLint initGL();
        GLint drawGLScene();

        int winMsg (HWND, UINT, WPARAM, LPARAM);
        GLvoid resizeGLScene(GLsizei width, GLsizei height);
        float screenWidth, screenHeight;
        void playerMovements(Player *);
        WPARAM wParam;
        bool keys[256];
        SceneLoader* loader;
        Player *ply = new Player();
    protected:

    private:
};

#endif // LEVELONE_H
