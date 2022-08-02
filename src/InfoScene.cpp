#include "InfoScene.h"
#include "GLLight.h"

//Parallax* Para = new Parallax();

static Parallax* Plx = new Parallax();
static Parallax* Plx1 = new Parallax();

static Timer* Time1 = new Timer();
static Timer* Time2 = new Timer();

static Objects obj[5];
static TextureLoader *objTex = new TextureLoader;
static TextureLoader *objTex1 = new TextureLoader;
static TextureLoader *objTex2 = new TextureLoader;
static TextureLoader *objTex3 = new TextureLoader;
static TextureLoader *objTex4 = new TextureLoader;

static float parallaxYpos = -5;
static float parallaxXpos = -2.25;

InfoScene::InfoScene(SceneLoader* loader)
{
    // take the loader from the start screen
    this->loader = loader;
    screenHeight = GetSystemMetrics(SM_CYSCREEN);
    screenWidth = GetSystemMetrics(SM_CXSCREEN);
    float xSize = 1;
    float ySize = 0.5;
}
InfoScene::~InfoScene()
{
    //dtor
}
GLint InfoScene::initGL()
{
    glShadeModel(GL_SMOOTH);
    glClearDepth(1.0f);
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LEQUAL);


    //GLLight Light(GL_LIGHT0);
    //Light.setLight(GL_LIGHT5);
    Plx->parallaxInit("images/landingpage2.png");

    objTex->loadTexture("images/car.png");
    objTex1->loadTexture("images/red_button1.png");
    objTex2->loadTexture("images/Cred_button.png");
    objTex3->loadTexture("images/guide.png");
    objTex4->loadTexture("images/controls.png");
    //objTex4->loadTexture("images/flare.png");
    //Para->parallaxInit("images/landingpage.png");
    return 1;
}

GLint InfoScene::drawGLScene()
{
    int xMin,xMax,yMin,yMax;
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();

    /*
    glPushMatrix();
        Para->drawSquare(screenWidth, screenHeight);
    glPopMatrix();
    */
    glPushMatrix();
    Plx->drawSquare(screenWidth, screenHeight);
    glPopMatrix();
    Plx->scroll("right",0.004);

    //if(Time2->getTicks()>1000)
    //{

    obj[0].placeObjects(parallaxXpos,-1.17,-2.5);//z -0.5
    obj[0].objectsInit();
    objTex->binder();
    obj[0].drawObjects(1,0.5);
    if(parallaxXpos>=-3)
    {
        parallaxXpos+=0.005;
    }
   // }

    if(parallaxXpos>=3)
    {
        parallaxXpos=-3;
    }


    obj[1].placeObjects(2.3,1.3,-3.75);//z -0.5
    obj[1].objectsInit();
    objTex1->binder();
    obj[1].drawObjects(1.0,0.35);

//    if(Time2->getTicks()>1000)
    //{
    obj[2].placeObjects(1.45,-0.15,-2.5);//z -0.5
    obj[2].objectsInit();
    objTex2->binder();
    obj[2].drawObjects(1,0.3);
/*
    if(parallaxYpos>-5)
    {
        parallaxYpos-=0.05;
    }
    }
    if(parallaxYpos<=-5)
    {
        parallaxYpos=1.5;
    }
*/
    obj[3].placeObjects(-2,0,-2.00);//z -0.5
    obj[3].objectsInit();
    objTex3->binder();
    obj[3].drawObjects(1.28,1);

    obj[4].placeObjects(-0.25,-0.75,-2.75);//z -0.5
    obj[4].objectsInit();
    objTex4->binder();
    obj[4].drawObjects(1,2);
}

int InfoScene::winMsg(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    switch(uMsg){
        case WM_KEYDOWN:
            {
            if(wParam == VK_BACK){
                loader->actuallyLoadScene("Start");
            }
            else if(wParam == VK_TAB) {//right shift to go to credits
                GLScene* creditScene = new CreditScene(loader);
                loader->loadScene("Credits", creditScene);
            }//Clicking gave me trouble so I made it go to credits using tab
            }
        case WM_LBUTTONDOWN:
            {
            //  Copied from StartScene.cpp
            GLdouble modelMat[16];
            GLdouble projMat[16];
            GLint viewport[4];
            glGetDoublev(GL_MODELVIEW_MATRIX, modelMat);
            glGetDoublev(GL_PROJECTION_MATRIX, projMat);
            glGetIntegerv(GL_VIEWPORT, viewport);

            GLScene::convertMouseCoord((float)LOWORD(lParam), (float) viewport[3] - (GLfloat)HIWORD(lParam) - 1, modelMat, projMat, viewport);
            cout << mouseX << " X " << mouseY << " Y " << endl; //getting coords
            //if(mouseX > 4.28 && mouseX < 5.11 && mouseY > -0.55 && mouseY < 0.015){
             //   loader->actuallyLoadScene("Start");
            if(mouseX > 1.46 && mouseX < 2.34 && mouseY > -0.127 && mouseY < 0.138){

                GLScene* creditScene = new CreditScene(loader);
                loader->loadScene("Credits", creditScene);
            }
            else if(mouseX > 2.371 && mouseX < 3.21 && mouseY > 1.33 && mouseY < 1.621){

                loader->actuallyLoadScene("Start");
            }
            }
            break;
    }
}
