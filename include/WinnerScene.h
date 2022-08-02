#ifndef WINNERSCENE_H
#define WINNERSCENE_H
#define GLEW_STATIC
#include <GL/glew.h>
#include<windows.h>
#include <GLScene.h>
#include <SceneLoader.h>
#include <freetype.h>
#include <Parallax.h>
#include <Particles.h>
#include <CollisionChecker.h>
#include <Player.h>
#include <Spikes.h>
#include <Inputs.h>
#include <Sounds.h>
#include <Node.h>
#include <cstdlib>
#include <utility>
#include <set>
#include <vector>
#include <algorithm>
#include <future>       // async

using std::vector;
using std::string;
using freetype::font_data;

class SceneLoader;

class WinnerScene : public GLScene
{
    public:
        WinnerScene(SceneLoader*);
        virtual ~WinnerScene();

        GLint initGL();
        GLint drawGLScene();
        int winMsg (HWND, UINT, WPARAM, LPARAM);
        GLvoid resizeGLScene(GLsizei width, GLsizei height);
        void displayText();
        WPARAM wParam;
        bool keys[256];

        SceneLoader* loader;
        Parallax* Plx = new Parallax();
        Player* Ply = new Player();
        Inputs* KbMs = new Inputs();
        Sounds* intro = new Sounds();
        Sounds* itBegins = new Sounds();
        Sounds* death = new Sounds();

        vector<Spikes> spikey;

        float screenHeight = GetSystemMetrics(SM_CYSCREEN);
        float screenWidth = GetSystemMetrics(SM_CXSCREEN);
        const int textOffsetX = -375 + screenWidth / 2;
        const int textOffsetY = screenHeight / 2;

        font_data font;
        bool cutsceneOver;
        vector<Loc> path;

        int now = 0;
        int prev = 0;

    protected:

    private:
};

#endif // WINNERSCENE_H
