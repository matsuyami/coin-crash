#include "PauseScene.h"
//#include<Sounds.h>
static Parallax* Plx = new Parallax();//background
//static Sounds *SND = new Sounds();
static Timer* Time3 = new Timer();
static Timer* Time4 = new Timer();//used for fire 1
static Timer* Time5 = new Timer();//used for fire 2
static Timer* Time6 = new Timer();//used for fire 3
static Timer* Time7 = new Timer();//used for fire 4

static Player *Ply1 = new Player();//fire1
static Player *Ply2 = new Player();//fire2
static Player *Ply3 = new Player();//fire3
static Player *Ply4 = new Player();//fire4

static float parallYpos = 3.25;

static Objects obj[2];
static TextureLoader *objTe = new TextureLoader;//used for the object that was messing with the pause menu
static TextureLoader *objTe1 = new TextureLoader;//used for nothing at the moment
static TextureLoader *objTe2 = new TextureLoader;

PauseScene::PauseScene(SceneLoader* loader)//Sounds* SND)
{
    //ctor
    //this->SND = SND;
    this->loader = loader;
    screenHeight = GetSystemMetrics(SM_CYSCREEN);
    screenWidth = GetSystemMetrics(SM_CXSCREEN);
}

PauseScene::~PauseScene()
{
    //dtor
}
GLint PauseScene::initGL()
{
    glShadeModel(GL_SMOOTH);
    glClearDepth(1.0f);
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LEQUAL);
    GLLight Light(GL_LIGHT0);
    Light.setLight(GL_LIGHT0);

///parallax //////////////////////////////////////////
Plx->parallaxInit("images/pause.png");
/// objects/////////////////////////////////////////////
objTe->loadTexture("images/streakLeft.png");//left streak
objTe1->loadTexture("images/streakRight.png");//right streak
/// players////////////////////////////////////////////
Ply1->playerInit("images/fire.png");
Ply2->playerInit("images/fire.png");
Ply3->playerInit("images/fire.png");
Ply4->playerInit("images/fire.png");
///fire flags //////////////////////////////////////////////
fire1  = true;
fire2 = true;
fire3 = true;
fire4 = true;
/// player inits//////////////////////////////////////////////
Ply1->xMin = 0.0;
Ply1->xMax = 1.0/10.0;

Ply2->xMin = 0.0;
Ply2->xMax = 1.0/10.0;

Ply3->xMin = 0.0;
Ply3->xMax = 1.0/10.0;

Ply4->xMin = 0.0;
Ply4->xMax = 1.0/10.0;
/// ////////////////////////////////////////////////////
        //float xize = 2;
        //float yize = 2;
        //float zize = 2;

return 1;

}

GLint PauseScene::drawGLScene()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
     glLoadIdentity();

    glPushMatrix();
        Plx->drawSquare(screenWidth, screenHeight);
    glPopMatrix();
///BLC fire /////////////////////////////////////////////
    glPushMatrix();
        glTranslatef(-0.55,-0.32,-.1);
        Ply1->drawPlayer();
    glPopMatrix();
///BRC fire/////////////////////////////////////////////////////////
    glPushMatrix();
        glTranslatef(0.55,-0.32,-.1);
        Ply2->drawPlayer();
    glPopMatrix();
///TLC fire /////////////////////////////////////////////////
    glPushMatrix();
        glTranslatef(-0.55,0.145,-.1);
        Ply3->drawPlayer();
    glPopMatrix();
///TRC fire ///////////////////////////////////////////////////
    glPushMatrix();
        glTranslatef(0.55,0.145,-.1);
        Ply4->drawPlayer();
    glPopMatrix();
/// ///////////////////////////////////////////////////////////////////////

///BLC fire /////////////////////////////////////////////////////////////////////////
glPushMatrix();
    if(fire1 == true){
        //yPos = -0.6;
        Ply1->yMin = 0.0;
        Ply1->yMax = 1.0/6.0;
        if(Time4->getTicks() > 65){
        Ply1->xMin += (1.0/10.0);//
        Ply1->xMax += (1.0/10.0);//
        //Ply->xPos += .03;//.06
//cout << "xPos is: " << xPos << "and yPos is: " << yPos << endl;
        if(Ply1->xMax >= 1.0){
            Ply1->yMin += 1.0/6.0;
            Ply1->yMax += 1.0/6.0;
        }
        if(Ply1->yMax >= 1.0){
            Ply1->xMin = 0.0;
            Ply1->xMax = 1.0/10.0;
        }
        Time4->reset();
        }
    }
    glPopMatrix();
/// ////////////////////////////////////////////////////////////////////////

///BRC fire//////////////////////////////////////////////////////////////////////////////
    glPushMatrix();
    if(fire2 == true){
        //yPos = -0.6;
        Ply2->yMin = 0.0;
        Ply2->yMax = 1.0/6.0;
        if(Time5->getTicks() > 65){
        Ply2->xMin += (1.0/10.0);//
        Ply2->xMax += (1.0/10.0);//
        //Ply->xPos += .03;//.06
//cout << "xPos is: " << xPos << "and yPos is: " << yPos << endl;
        if(Ply2->xMax >= 1.0){
            Ply2->yMin += 1.0/6.0;
            Ply2->yMax += 1.0/6.0;
        }
        if(Ply2->yMax >= 1.0){
            Ply2->xMin = 0.0;
            Ply2->xMax = 1.0/10.0;
        }
        Time5->reset();
        }
    }
    glPopMatrix();
/// ////////////////////////////////////////////////////////////

///TLC fire/////////////////////////////////////////////////////////////
    glPushMatrix();
    if(fire3 == true){
        //yPos = -0.6;
        Ply3->yMin = 0.0;
        Ply3->yMax = 1.0/6.0;
        if(Time6->getTicks() > 65){
        Ply3->xMin += (1.0/10.0);//
        Ply3->xMax += (1.0/10.0);//
        //Ply->xPos += .03;//.06
//cout << "xPos is: " << xPos << "and yPos is: " << yPos << endl;
        if(Ply3->xMax >= 1.0){
            Ply3->yMin += 1.0/6.0;
            Ply3->yMax += 1.0/6.0;
        }
        if(Ply3->yMax >= 1.0){
            Ply3->xMin = 0.0;
            Ply3->xMax = 1.0/10.0;
        }
        Time6->reset();
        }
    }
    glPopMatrix();
/// //////////////////////////////////////////////////////////////////////////////////////////////////

/// TRC fire////////////////////////////////////////////////////////////////
glPushMatrix();
    if(fire4 == true){
        //yPos = -0.6;
        Ply4->yMin = 0.0;
        Ply4->yMax = 1.0/6.0;
        if(Time7->getTicks() > 65){
        Ply4->xMin += (1.0/10.0);//
        Ply4->xMax += (1.0/10.0);//
        //Ply->xPos += .03;//.06
//cout << "xPos is: " << xPos << "and yPos is: " << yPos << endl;
        if(Ply4->xMax >= 1.0){
            Ply4->yMin += 1.0/6.0;
            Ply4->yMax += 1.0/6.0;
        }
        if(Ply4->yMax >= 1.0){
            Ply4->xMin = 0.0;
            Ply4->xMax = 1.0/10.0;
        }
        Time7->reset();
        }
    }
    glPopMatrix();
/// ////////////////////////////////////////////////////////////////////

///Left streak/////////////////////////////////////////////////////////////////////////////////////
    glPushMatrix();
if(Time3->getTicks()>1000)
    {
    obj[0].placeObjects(-3.43,parallYpos,-3.75);//z -0.5  -9.25
    obj[0].objectsInit();
    objTe->binder();
    obj[0].drawObjects(.25,8.5);

    if(parallYpos>-10.43)
    {
        parallYpos-=0.0005;
    }
    }
    if(parallYpos<=-10.43)
    {
        parallYpos=2.5;
    }
    glPopMatrix();

/// //////////////////////////////////////////////////////////////////////////////////////////

///Right streak////////////////////////////////////////////////////////////////////////////////////////
     glPushMatrix();
if(Time3->getTicks()>1000)
    {
    obj[1].placeObjects(3.19,parallYpos,-3.75);//z -0.5  -9.25
    obj[1].objectsInit();
    objTe1->binder();
    obj[1].drawObjects(.25,8.5);

    if(parallYpos>-10.43)
    {
        parallYpos-=0.0005;
    }
    }
    if(parallYpos<=-10.43)
    {
        parallYpos=2.5;
    }
    glPopMatrix();

///  ////////////////////////////////////////////////////////////////////////////////////////////////

}

int PauseScene::winMsg(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
//case WM_KEYDOWN:
            //if(wParam == VK_SPACE){
               // loader->actuallyLoadScene("Start");
            //}
      switch(uMsg){
        case WM_KEYDOWN:
            if(wParam == VK_SPACE){
                   // GLScene *pause = new PauseScene(loader);
                   // loader->loadScene("Pause",pause);
                    ///loader->actuallyLoadScene("Pause");
                // go to first level.
                /*
                if(mouseX > -4.9767 && mouseX < 0.668879 && mouseY > 0.68 && mouseY < 1.4114){
                    GLScene* scene = new GLScene();
                    loader->loadScene("level1", scene);
                }
                */
            }
            if(wParam == VK_BACK){
               // GLScene *L1 = new LevelOne(loader);
               // loader->loadScene("L1",L1);
                loader->actuallyLoadScene("select");
                cout << "BACKSPACE" << endl;
            }
            // user presses backspace

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

            //resume button
            if(mouseX > -4.61752  && mouseX < 4.5715  && mouseY > 1.80252  && mouseY < 3.10647){
                //SND->stopAllSounds();
                loader->actuallyLoadScene(loader->prevSceneName);//or select
            }
            //main menu
              if(mouseX > -3.14482 && mouseX < 3.12948  && mouseY > 0.130395  && mouseY < 1.44969){
               ///SND->initSounds();/// ///////////////address with the return value as you wish
               ///SND->playMusic("sounds/startscene.mp3");/// ////////////////////
               //loader->actuallyLoadScene("Info");
               //GLScene *star = new StartScene();
               //loader->loadScene("Start",star);



               loader->actuallyLoadScene("Start");
              }
            //how to play/info button
            if(mouseX > -4.80161 && mouseX < 5.14677 && mouseY > -1.5494 && mouseY < -0.214768){
            GLScene *iS = new InfoScene(loader);
            loader->loadScene("Info",iS);
            ///loader->actuallyLoadScene("Info");
            }

            //Exit game
           if(mouseX > -2.76898  && mouseX < 2.92238  && mouseY >  -3.19084 && mouseY < -1.90223){
                DestroyWindow(hWnd);

            }
            /*
            // play button
            if(mouseX > -4.9767 && mouseX < 0.668879 && mouseY > 0.68 && mouseY < 1.4114){
                GLScene* scene = new LevelOne(loader);

                loader->loadScene("select", scene);
            }

            // info button
            else if(mouseX > -4.99511 && mouseX < -0.570695 && mouseY > -0.564558 && mouseY < 0.159549){
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



