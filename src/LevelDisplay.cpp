#include <loadShader.h>
#include "LevelDisplay.h"
#include <GLScene.h>
#include <Sounds.h>
static Sounds *Snd = new Sounds();
static Parallax *plx = new Parallax();

LevelDisplay::LevelDisplay(SceneLoader *loader)
{
    //ctor
    this->loader = loader;
    screenHeight = GetSystemMetrics(SM_CYSCREEN);
    screenWidth = GetSystemMetrics(SM_CXSCREEN);
    float xSize = 1;
    float ySize = 0.5;
}

LevelDisplay::~LevelDisplay()
{
    //dtor
}
GLint LevelDisplay::initGL()
{
    glShadeModel(GL_SMOOTH);
    glClearDepth(1.0f);
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LEQUAL);

    plx->parallaxInit("images/level_select.png");
    Snd->playMusic("sounds/game.mp3");
}

GLint LevelDisplay::drawGLScene()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    glPushMatrix();
    plx->drawSquare(screenWidth, screenHeight);
    glPopMatrix();
}

int LevelDisplay::winMsg(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{

   switch(uMsg){
       case WM_KEYDOWN:
            {
                if(wParam == VK_BACK){
                //GLScene* infoScene = new InfoScene(loader);
                //loader->loadScene("Info", infoScene);
                Snd->stopAllSounds();
                loader->actuallyLoadScene("Start");
            }
            }
		case WM_LBUTTONDOWN:
        {
            GLdouble modelMat[16];
            GLdouble projMat[16];
            GLint viewport[4];
            glGetDoublev(GL_MODELVIEW_MATRIX, modelMat);
            glGetDoublev(GL_PROJECTION_MATRIX, projMat);
            glGetIntegerv(GL_VIEWPORT, viewport);
            //cout << LOWORD(lParam) << ", " << HIWORD(lParam) << endl;
            GLScene::convertMouseCoord((float)LOWORD(lParam), (float) viewport[3] - (GLfloat)HIWORD(lParam) - 1, modelMat, projMat, viewport);
            if(mouseX > -4.461 && mouseX < -2.466 && mouseY > -2.749 && mouseY < 2.87){
                Snd->stopAllSounds();
                GLScene* levelone = new LevelOne(loader);
                loader->loadScene("level1", levelone);
            }
            cout << mouseX << " X " << mouseY << " Y " << endl;
            if(mouseX > -1.58315 && mouseX < 0.44 && mouseY > -2.749 && mouseY < 2.87){
                Snd->stopAllSounds();
                GLScene* leveltwo = new LevelTwo(loader);
                loader->loadScene("level2", leveltwo);
            }
            if(mouseX > 1.28094 && mouseX < 3.31357 && mouseY > -2.79199 && mouseY < 2.84568){
               Snd->stopAllSounds();
               GLScene* levelthree = new LevelThree(loader);
               loader->loadScene("levle3", levelthree);
            }

            if(mouseX > 3.663 && mouseX < 5.55 && mouseY > 2.35 && mouseY < 2.87){
                Snd->stopAllSounds();
                loader->actuallyLoadScene("Start");
            }

            ///LEVEL 3
           /// if(mouseX > 1.3663 && mouseX < 3.26 && mouseY > -2.687 && mouseY < 2.83){
                //add LevelThree
           /// }




        break;								// Jump Back
        }
    }
}
