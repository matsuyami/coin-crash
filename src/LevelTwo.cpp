#include <loadShader.h>
#include "LevelTwo.h"
#include <GLLight.h>
#include<Model.h>
#include<Parallax.h>
#include<windows.h>
#include <Litecoin.h>
#include <CollisionChecker.h>
#include <Sounds.h>
#include <LevelDisplay.h>
#include <PauseScene.h>
#include <HUD.h>

static loadShader* shader = new loadShader();
static CollisionChecker* cc = new CollisionChecker();
static Parallax* plx = new Parallax();
static Inputs *KbMs = new Inputs();
static Player *ply = new Player();
static Coin bitcoin[6];
static Litecoin litecoin[15];
static Spikes spike2[6];
static Sounds *snds = new Sounds();
static TextureLoader *bitcoinTex = new TextureLoader();
static TextureLoader *litecoinTex = new TextureLoader();
HUD* hud = new HUD();
static float a, h;
static GLint loc;


LevelTwo::LevelTwo(SceneLoader* loader)
{
    //ctor
    screenHeight = GetSystemMetrics(SM_CYSCREEN);
    screenWidth = GetSystemMetrics(SM_CXSCREEN);
    this->loader = loader;
    //cout << screenHeight << " " << screenWidth << endl;
}

LevelTwo::~LevelTwo()
{
    //dtor
}
GLint LevelTwo::initGL()
{
    snds->initSounds();
    glewInit();
    glShadeModel(GL_SMOOTH);//for good transition in animations
    glClearColor(0.5f,1.0f,0.0f,0.0f);//set background color
    glClearDepth(1.0f);//decide what is at front and behind
    glEnable(GL_DEPTH_TEST);//for the depth calculations
    //glEnable(GL_COLOR_MATERIAL);
    GLLight Light(GL_LIGHT0);//create light instance

    Light.setLight(GL_LIGHT5);
    //Mdl->modelInit("images/teapot.png");
    plx->parallaxInit("images/L2new.png");
    ply->playerInit("images/Car2.png");
    bitcoinTex->loadTexture("images/coin.png");
    litecoinTex->loadTexture("images/litecoin.png");
    //ETex->loadTexture("images/enemy.png");
    hud->initHUD();
    shader->initShader("v.vs", "f.fs");
    a = 2;
    h = 2;

    for(int i = 0; i < 6; i++){
        spike2[i].spikeInit("images/spikeball.png");
    }

    for(int z = 0; z < 15; z++){
        litecoin[z].placeCoins(((rand()% 20)-10)/10.0,(rand()% 10)/10.0, -0.5);
        litecoin[z].coinInit();
    }


glPushMatrix();

    for(int j = 0; j < 6; j++){
    // don't use scaled. fuck scaled. get rid of scaled.
    pair<float, float> rand_pair = bitcoin[j].gen_rand_pair();
    bitcoin[j].placeCoins(rand_pair.first, rand_pair.second, -0.5);//((rand()% 10)-10)/10.0,-0.5);
    bitcoin[j].coinInit();
    }

glPopMatrix();
snds->playMusic("sounds/game.mp3");

    return true;
}

GLint LevelTwo::drawGLScene()
{
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
/*
// DRAW TRIANGLE
glPushMatrix();
    glUseProgram(shader->program);
    loc = glGetUniformLocation(shader->program, "scale");
    if(loc != -1) glUniform1f(loc, a);
    glBegin(GL_TRIANGLES);
    glVertex3f(-3.0, 0.0, 0.0);
    glVertex3f(0.0, -2.0, 0.0);
    glVertex3f(0.0, 0.0, 0.0);
    glUseProgram(0);
glPopMatrix();

(a <0.1) ? h = 1 : NULL;
(a > 1.5) ? h = 1 : NULL;
a += 0.01 * h;
*/
///////////////////////////////////////////////////////
glPushMatrix();
plx->drawSquare(screenWidth,screenHeight);
glPopMatrix();
//////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////


glPushMatrix();

    bitcoinTex->binder();
    for(int i =0; i < 6; i++){
        bitcoin[i].drawCoin();
    }
glPopMatrix();

///////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////

glPushMatrix();
    {
    litecoinTex->binder();
    for(int z =0; z < 15; z++){
        litecoin[z].drawCoin();

    }
    }
glPopMatrix();

//////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////
glPushMatrix();
for(int a = 0; a < 6; a++){
    spike2[a].drawSpike();
}
glPopMatrix();


/////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////
glPushMatrix();
    ply->drawPlayer();
    ply->playerActions();
    hud->displayHUD(ply->currentScore, 45000);

    // Drawing player bounding box

    /*
    float pwOffset = ply->width / 20;
    float phOffset = ply->height / 20;
    float p_xmin = ply->get_xpos() - pwOffset;
    float p_xmax = ply->get_xpos() + pwOffset;
    float p_ymin = ply->get_ypos() - phOffset;
    float p_ymax = ply->get_ypos() + phOffset;
    // need to add texture loader again if you wanna see this.
    //testing->binder();
    //glRectd(p_xmin, p_ymin, p_xmax, p_ymin);
    glBegin(GL_POLYGON);
    glVertex3f(p_xmin, p_ymin, -1.0);
    glVertex3f(p_xmax, p_ymin, -1.0);
    glVertex3f(p_xmax, p_ymax, -1.0);
    glVertex3f(p_xmin, p_ymax, -1.0);
    glEnd();
    */

glPopMatrix();
/////////////////////////////////////////////////



// Collision Stuff begins
glPushMatrix();

    for(int i = 0; i < 6; i++){
        if(cc->playerToObject(ply, bitcoin[i])){
            // if player hits btc do something
            // aka move or delete the coin
            // then increment the score
            // hitbox seems a little too large
            bitcoin[i].yPos = 0.6;
            bitcoin[i].xPos = ((rand()% 20)-10.0)/10.0;
            ply->currentScore += 1000;

            snds->playSound("sounds/coin.wav");

            cout << "Player Score: " << ply->currentScore << endl;

        }
    }
glPopMatrix();

glPushMatrix();

    for(int i = 0; i < 15; i++){
        if(cc->playerToObject(ply, litecoin[i])){
            //if player hits ltc do something
            // aka move or delete the ltc
            // then decrement the score.
            litecoin[i].yPos = 0.6;
            litecoin[i].xPos = ((rand() % 20) - 10.0) / 10.0;
            ply->currentScore -= 500;
            snds->playSound("sounds/oof.mp3");
            cout << "Player Score: " << ply->currentScore << endl;
        }
    }

glPopMatrix();

glPushMatrix();
for(int a = 0; a < 6; a++){
        if(cc->playerToObject(ply, spike2[a])){
            //if player hits ltc do something
            // aka move or delete the ltc
            // then decrement the score.
            ///put sound here


            spike2[a].yPos = 0.6;
            spike2[a].xPos = ((rand() % 20) - 10.0) / 10.0;
            ply->currentScore -= 2000;
            ply->deathCount += 1;

            snds->playSound("sounds/spikeS.mp3");
            cout << "Player Score: " << ply->currentScore << endl;
            cout << "Player deathCount: " << ply->deathCount << endl;
        }
    }

glPopMatrix();


    if(ply->currentScore >= 45000){
        snds->stopAllSounds();
        GLScene* levelthree = new LevelThree(loader);
        loader->loadScene("level3", levelthree);

    }
}


///////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////



int LevelTwo::winMsg(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    switch(wParam){
        case VK_LEFT:
            ply->actionTrigger = "Left";
            break;
        case VK_RIGHT:
            ply->actionTrigger = "Right";
            break;
        case VK_UP:
            ply->actionTrigger = "Up";
            break;
        case VK_DOWN:
            ply->actionTrigger = "Down";
            break;
    }


   switch(uMsg){
        case WM_KEYDOWN:

            KbMs ->wParam = wParam;
			//KbMs ->keyPressed(Mdl);
			KbMs ->keyEnv(plx,0.005);
			KbMs ->playerAction(ply);
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
            if(wParam == VK_BACK){
                snds->stopAllSounds();
                GLScene* scene = new LevelDisplay(loader);
                loader->loadScene("level", scene);
            }
            if(wParam == VK_SPACE){
                //SND->~Sounds();
                 //SND->stopAllSounds();
                 snds->stopAllSounds();
                PauseScene *t = new PauseScene(this->loader);//,SND);
                this->loader->loadScene("Pause", t);
            }
            //ply ->actionTrigger = "Down";
	    break;

        case WM_KEYUP:								// Has A Key Been Released?
		{
			ply ->actionTrigger = "Stand";								// Jump Back


		}break;

		case VK_BACK:
        {
            loader->actuallyLoadScene("Start");
        }



		case WM_LBUTTONDOWN:
        {
            //ply ->actionTrigger = "Left";
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
            if(mouseX > -4.9767 && mouseX < 0.668879 && mouseY > 0.68 && mouseY < 1.4114){
                //GLScene* scene = new GLScene();
                //loader->loadScene("level1", scene);
            }
            else if(mouseX > -4.96443 && mouseX < -1.96982 && mouseY < -0.902066 && mouseY > -1.68754){
                DestroyWindow(hWnd);
            }

        break;								// Jump Back
        }
    }
}

