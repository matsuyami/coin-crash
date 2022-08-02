#include "StartScene.h"
#include <GLLight.h>
#include <Parallax.h>
#include <SceneLoader.h>
#include <InfoScene.h>
#include <Sounds.h>
#include <LevelDisplay.h>
#include <Player.h>
#include <Timer.h>
#include <Inputs.h>

static Parallax* Plx = new Parallax();
static Sounds *snds = new Sounds();
static Player *P1 = new Player();//fire1
static Player *P2 = new Player();//fire2
static Timer *T1 = new Timer();
static Timer *T2 = new Timer();
static Timer *SW = new Timer();
static Inputs *KbMs = new Inputs();
StartScene::StartScene()
{
    screenHeight = GetSystemMetrics(SM_CYSCREEN);
    screenWidth = GetSystemMetrics(SM_CXSCREEN);
}

StartScene::~StartScene()
{
    //dtor
}

GLint StartScene::initGL()
{

    snds->initSounds();
    glShadeModel(GL_SMOOTH);                    // for good transition in animations
    //glClearColor(0.0f, 0.0f, 0.0f, 0.0f);       // set background color
    glClearDepth(1.0f);                         // decide what is at front and behind
    glEnable(GL_DEPTH_TEST);                    // for the depth calculation
    glDepthFunc(GL_LEQUAL);

    //glEnable(GL_COLOR_MATERIAL);                // this is for the base color of the object (color3f)
    GLLight Light(GL_LIGHT0);
    Light.setLight(GL_LIGHT0);
    Plx->parallaxInit("images/title_screen.png");
        snds->playMusic("sounds/startscene.mp3");
        P1->playerInit("images/fire.png");
        P2->playerInit("images/fire.png");
        f1  = true;
        f2 = true;

        P1->xMin = 0.0;
P1->xMax = 1.0/10.0;

P2->xMin = 0.0;
P2->xMax = 1.0/10.0;
    return 1;
}

GLint StartScene::drawGLScene()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();

    //snds->playMusic("sounds/music.mp3");
    /*
    glPushMatrix();
        Mdl->drawModel();
    glPopMatrix();
    */

    /*
    glPushMatrix();
        Mdl->drawTriangle();
    glPopMatrix();
*/


    glPushMatrix();
        Plx->drawSquare(screenWidth, screenHeight);
    glPopMatrix();
        glPushMatrix();
        glTranslatef(0.685,-0.1,-.1);
        P1->drawPlayer();
    glPopMatrix();
    glPushMatrix();
        glTranslatef(0.67,-0.1,-.1);
        P2->drawPlayer();
    glPopMatrix();

    glPushMatrix();
    if(f1 == true){
        //yPos = -0.6;
        P1->yMin = 0.0;
        P1->yMax = 1.0/6.0;
        if(T1->getTicks() > 65){
        P1->xMin += (1.0/10.0);//
        P1->xMax += (1.0/10.0);//
        //Ply->xPos += .03;//.06
//cout << "xPos is: " << xPos << "and yPos is: " << yPos << endl;
        if(P1->xMax >= 1.0){
            P1->yMin += 1.0/6.0;
            P1->yMax += 1.0/6.0;
        }
        if(P1->yMax >= 1.0){
            P1->xMin = 0.0;
            P1->xMax = 1.0/10.0;
        }
        T1->reset();
        }
    }
    glPopMatrix();


    glPushMatrix();
    if(f2 == true){
        //yPos = -0.6;
        P2->yMin = 0.0;
        P2->yMax = 1.0/6.0;
        if(T2->getTicks() > 65){
        P2->xMin += (1.0/10.0);//
        P2->xMax += (1.0/10.0);//
        //Ply->xPos += .03;//.06
//cout << "xPos is: " << xPos << "and yPos is: " << yPos << endl;
        if(P2->xMax >= 1.0){
            P2->yMin += 1.0/6.0;
            P2->yMax += 1.0/6.0;
        }
        if(P2->yMax >= 1.0){
            P2->xMin = 0.0;
            P2->xMax = 1.0/10.0;
        }
        T2->reset();
        }
    }
    glPopMatrix();
}

// implement keys, if player presses 'p' - Play the game.
int StartScene::winMsg(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    switch(uMsg){
        case WM_KEYDOWN:
            KbMs ->wParam = wParam;
            KbMs->keySounds(snds);
            if(wParam == int('p') || wParam == int('P')){
                // go to first level.
                /*
                if(mouseX > -4.9767 && mouseX < 0.668879 && mouseY > 0.68 && mouseY < 1.4114){
                    GLScene* scene = new GLScene();
                    loader->loadScene("level1", scene);
                }
                */
            }
            // user presses backspace
            if(wParam == VK_BACK){
                cout << "BACKSPACE" << endl;
            }
	    break;
/*
	    case WM_KEYUP:								// Has A Key Been Released?
		{
			keyboardPress->wParam = wParam;
			keyboardPress->keyUp();
		break;								// Jump Back
		}
		*/

		case WM_LBUTTONDOWN:
        {

            //KbMs->wParam = wParam;
            //KbMs->mouseEventDown(Mdl, LOWORD(lParam),HIWORD(lParam));

            GLdouble modelMat[16];
            GLdouble projMat[16];
            GLint viewport[4];
            glGetDoublev(GL_MODELVIEW_MATRIX, modelMat);
            glGetDoublev(GL_PROJECTION_MATRIX, projMat);
            glGetIntegerv(GL_VIEWPORT, viewport);
            //cout << LOWORD(lParam) << ", " << HIWORD(lParam) << endl;
            GLScene::convertMouseCoord((float)LOWORD(lParam), (float) viewport[3] - (GLfloat)HIWORD(lParam) - 1, modelMat, projMat, viewport);
            // play button
            if(mouseX > -4.9767 && mouseX < 0.668879 && mouseY > 0.68 && mouseY < 1.4114){

                snds->stopAllSounds();
                GLScene* scene = new LevelDisplay(loader);
                //loader->loadScene("level1", scene);
                //GLScene* scene = new MusicSelectScene(loader);
                loader->loadScene("level", scene);
                ;
            }
            // info button

            else if(mouseX > -4.99511 && mouseX < -0.570695 &&
                    mouseY > -0.564558 && mouseY < 0.159549){
                snds->stopAllSounds();
                GLScene* infoScene = new InfoScene(loader);
                loader->loadScene("Info", infoScene);
            }
            // quit the game
            else if(mouseX > -4.96443 && mouseX < -1.96982 && mouseY < -0.902066 && mouseY > -1.68754){
                DestroyWindow(hWnd);
            }


        break;								// Jump Back
        }
    }

    /*
    switch (uMsg){                                                  // check for windows msg
        case WM_KEYDOWN:
	        KbMs->wParam = wParam;
	        KbMs->keyPress(Mdl);
	        KbMs->keyEnv(Plx, 0.005);
	    break;

	    case WM_KEYUP:								// Has A Key Been Released?
		{
			KbMs->wParam = wParam;
			KbMs->keyUp();
		break;								// Jump Back
		}

		case WM_LBUTTONDOWN:
        {
            KbMs->wParam = wParam;
            KbMs->mouseEventDown(Mdl, LOWORD(lParam),HIWORD(lParam));
        break;								// Jump Back
        }

   		case WM_RBUTTONDOWN:
        {
            KbMs->wParam = wParam;
            KbMs->mouseEventDown(Mdl, LOWORD(lParam),HIWORD(lParam));
        break;								// Jump Back
        }

          case WM_MBUTTONDOWN:
        {
            KbMs->wParam = wParam;
            KbMs->mouseEventDown(Mdl, LOWORD(lParam),HIWORD(lParam));
        break;								// Jump Back
        }

        case WM_LBUTTONUP:
        case WM_RBUTTONUP:
        case WM_MBUTTONUP:
        {
            KbMs->mouseEventUp();
        break;								// Jump Back
        }

        case WM_MOUSEMOVE:
        {
             KbMs->mouseEventMove(Mdl, LOWORD(lParam),HIWORD(lParam));
        break;								// Jump Back
        }

        case WM_MOUSEWHEEL:
        {
            KbMs->mouseEventWheel(Mdl, (double)GET_WHEEL_DELTA_WPARAM(wParam));
        break;								// Jump Back
        }
    }
    */
}
