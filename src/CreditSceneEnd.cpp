#include "CreditSceneEnd.h"
#include <GLLight.h>
#include <Parallax.h>
#include <SceneLoader.h>
#include <StartScene.h>
#include <Objects.h>
#include <Coin.h>
#include <Sounds.h>
static Timer* Time2 = new Timer();
static Sounds *snd = new Sounds();
static Parallax *plx = new Parallax();
static Objects obj[5];
static TextureLoader *objTex = new TextureLoader;
static TextureLoader *objTex1 = new TextureLoader;
static TextureLoader *objTex2 = new TextureLoader;
static Coin bitcoin[10];

static TextureLoader *bitcoinTex = new TextureLoader();
static float parallaxYpos = -5;
CreditSceneEnd::CreditSceneEnd(SceneLoader *loader)
{
    //ctor
    this->loader = loader;
    screenHeight = GetSystemMetrics(SM_CYSCREEN);
    screenWidth = GetSystemMetrics(SM_CXSCREEN);
    float xSize = 1;
    float ySize = 0.5;
}

CreditSceneEnd::~CreditSceneEnd()
{
    //dtor
}
GLint CreditSceneEnd::initGL()
{
    glShadeModel(GL_SMOOTH);
    glClearDepth(1.0f);
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LEQUAL);


    plx->parallaxInit("images/credscene1.png");
    objTex2->loadTexture("images/creds.png");
    bitcoinTex->loadTexture("images/coin.png");

    glPushMatrix();

    for(int j = 0; j < 10; j++){
    // don't use scaled. fuck scaled. get rid of scaled.
    pair<float, float> rand_pair = bitcoin[j].gen_rand_pair();
    bitcoin[j].placeCoins(rand_pair.first, rand_pair.second, -0.5);//((rand()% 10)-10)/10.0,-0.5);
    bitcoin[j].coinInit();
    }

glPopMatrix();
snd->playMusic("sounds/open.mp3");
}

GLint CreditSceneEnd::drawGLScene()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();

    glPushMatrix();
    plx->drawSquare(screenWidth,screenHeight);
    glPopMatrix();
    glPushMatrix();
    {
    bitcoinTex->binder();
    for(int i =0; i < 10; i++){
        bitcoin[i].drawCoin();
    }
glPopMatrix();
    }

    if(Time2->getTicks()>1000)
    {
    obj[1].placeObjects(-1.25,parallaxYpos,-1);//z -0.5
    obj[1].objectsInit();
    objTex2->binder();
    obj[1].drawObjects(1.1,4);

    if(parallaxYpos>=-5)
    {
        parallaxYpos+=0.0005;
    }
    }

    if(parallaxYpos>=2)
    {
        parallaxYpos=-5;
    }


}

int CreditSceneEnd::winMsg(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    switch(uMsg){
        case WM_KEYDOWN:
            {
                if(wParam == VK_BACK){
                snd->stopAllSounds();
                //GLScene* startScene = new StartScene();
                //loader->loadScene("Start", startScene);
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
            GLScene::convertMouseCoord((float)LOWORD(lParam), (float) viewport[3] - (GLfloat)HIWORD(lParam) - 1, modelMat, projMat, viewport);
            // play button
            if(mouseX > -4.9767 && mouseX < 0.668879 && mouseY > 0.68 && mouseY < 1.4114){
            //    GLScene* crediteScene = new CreditSceneEnd(loader);
             //   loader->loadScene("Credits", crediteScene);
            }
            // info button

            /*else if(mouseX > -4.99511 && mouseX < -0.570695 &&
                    mouseY > -0.564558 && mouseY < 0.159549){
                GLScene* infoScene = new InfoScene(loader);
                loader->loadScene("Info", infoScene);
            }
            // quit the game
            else if(mouseX > -4.96443 && mouseX < -1.96982 && mouseY < -0.902066 && mouseY > -1.68754){
                DestroyWindow(hWnd);
            }
*/

        break;								// Jump Back
        }
    }
}
