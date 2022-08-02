#include <loadShader.h>
#include "LevelOne.h"
#include <GLLight.h>
#include<Model.h>
#include<Parallax.h>
#include<windows.h>
#include <Litecoin.h>
#include <CollisionChecker.h>
#include <PauseScene.h>
///put sounds
#include<Sounds.h>
#include<Spikes.h>
#include <HUD.h>
#include <LevelBox.h>
#include <LevelBox2.h>
#include <LevelBox3.h>
#include <LevelBox4.h>
#include <LevelBox5.h>
#include <LevelBox6.h>
static LevelBox box1;
static LevelBox2 box2;
static LevelBox3 box3;
static LevelBox4 box4;
static LevelBox5 box5;
static LevelBox6 box6;
static Sounds* SND = new Sounds();
static loadShader* shader = new loadShader();
///put sound snd
static CollisionChecker* cc = new CollisionChecker();
static Parallax* plx = new Parallax();
static Inputs *KbMs = new Inputs();
static Player *ply = new Player();
static Coin bitcoin[10];
static Litecoin litecoin[6];
static Spikes spike[4];
static TextureLoader *bitcoinTex = new TextureLoader();
static TextureLoader *litecoinTex = new TextureLoader();
static TextureLoader *spikeTex = new TextureLoader();

float a, h;
GLint loc;

static HUD* hud = new HUD();


LevelOne::LevelOne(SceneLoader* loader)
{
    //ctor
    screenHeight = GetSystemMetrics(SM_CYSCREEN);
    screenWidth = GetSystemMetrics(SM_CXSCREEN);
    this->loader = loader;
    //cout << screenHeight << " " << screenWidth << endl;
}

LevelOne::~LevelOne()
{
    //dtor
}
GLint LevelOne::initGL()
{
    glewInit();
    glShadeModel(GL_SMOOTH);//for good transition in animations
    glClearColor(0.5f,1.0f,0.0f,0.0f);//set background color
    glClearDepth(1.0f);//decide what is at front and behind
    glEnable(GL_DEPTH_TEST);//for the depth calculations
    //glEnable(GL_COLOR_MATERIAL);
    GLLight Light(GL_LIGHT0);//create light instance

    Light.setLight(GL_LIGHT0);
    //Mdl->modelInit("images/teapot.png");
    plx->parallaxInit("images/L1new.png");
    ply->playerInit("images/CarSpriteSheet.png");
    bitcoinTex->loadTexture("images/coin.png");
    litecoinTex->loadTexture("images/litecoin.png");
    for(int i = 0; i < 4; i++){
        spike[i].spikeInit("images/spikeball.png");
    }
    //ETex->loadTexture("images/enemy.png");
    shader->initShader("v.vs", "f.fs");
    ply->currentScore = 0;
    ply->deathCount = 0;
    hud->initHUD();
    a = 2;
    h = 2;

    for(int z = 0; z < 6; z++){
        litecoin[z].placeCoins(((rand()% 20)-10)/10.0,(rand()% 10)/10.0, -0.5);
        litecoin[z].coinInit();
    }


glPushMatrix();
    for(int j = 0; j < 10; j++){
    // don't use scaled. fuck scaled. get rid of scaled.
    pair<float, float> rand_pair = bitcoin[j].gen_rand_pair();
    bitcoin[j].placeCoins(rand_pair.first, rand_pair.second, -0.5);//((rand()% 10)-10)/10.0,-0.5);
    bitcoin[j].coinInit();

    }

glPopMatrix();
/// ///////////////////////////////////////
///put sounds here
SND->playMusic("sounds/level.mp3");

    return true;
}

GLint LevelOne::drawGLScene()
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
    for(int i =0; i < 10; i++){
        bitcoin[i].drawCoin();
    }
glPopMatrix();

///////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////

glPushMatrix();
    litecoinTex->binder();
    for(int z =0; z < 6; z++){
           litecoin[z].drawCoin();
    }
glPopMatrix();

//////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////
glPushMatrix();
for(int a = 0; a < 4; a++){
    spike[a].drawSpike();
}
glPopMatrix();

/////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////
glPushMatrix();
    ply->drawPlayer();
    ply->playerActions();
    hud->displayHUD(ply->currentScore, 15000);

glPopMatrix();
/////////////////////////////////////////////////



// Collision Stuff begins
glPushMatrix();
    for(int i = 0; i < 10; i++){
        if(cc->playerToObject(ply, bitcoin[i])){
            // if player hits btc do something
            // aka move or delete the coin
            // then increment the score
            // hitbox seems a little too large
            ///put sound here


            bitcoin[i].yPos = 0.6;
            bitcoin[i].xPos = ((rand()% 20)-10.0)/10.0;
            ply->currentScore += 1000;
            cout << "Player Score: " << ply->currentScore << endl;
            SND->playSound("sounds/coin.wav");
        }
    }
glPopMatrix();

glPushMatrix();
    for(int i = 0; i < 6; i++){
        if(cc->playerToObject(ply, litecoin[i])){
            //if player hits ltc do something
            // aka move or delete the ltc
            // then decrement the score.
            ///put sound here
            litecoin[i].yPos = 0.6;
            litecoin[i].xPos = ((rand() % 20) - 10.0) / 10.0;
            ply->currentScore -= 500;
            cout << "Player Score: " << ply->currentScore << endl;
            SND->playSound("sounds/oof.mp3");
        }
    }
glPopMatrix();

glPushMatrix();
for(int a = 0; a < 4; a++){
        if(cc->playerToObject(ply, spike[a])){
            //if player hits spikes do something
            // aka move or delete the spike
            // then decrement the score.
            ///put sound here


            spike[a].yPos = 0.6;
            spike[a].xPos = ((rand() % 20) - 10.0) / 10.0;
            ply->currentScore -= 2000;
            ply->deathCount += 1;
            SND->playSound("sounds/spikeS.mp3");

            /*
            if(ply->deathCount >= 5){
                GLScene* credits = new CreditScene(loader);
                loader->loadScene("credits", credits);
            }
            */

            cout << "Player Score: " << ply->currentScore << endl;
            cout << "Player deathCount: " << ply->deathCount << endl;
        }
    }

glPopMatrix();

///
///put level 2 loader here
///

glPushMatrix();

// move to next level.
if(ply->currentScore >= 15000){
    SND->stopAllSounds();
    GLScene* leveltwo = new LevelTwo(loader);
    loader->loadScene("level2", leveltwo);

}

glPopMatrix();


/*
glPushMatrix();
    if(cc->playerToObject(ply, box1)){
        if(box1.xPos - ply->xPos <= 0){
       //     cout << ply->yPos << endl;
      //      cout << box1.yPos << endl;
      //      cout << "XPOS: " << ply->xPos << endl;
            ply->xPos += 0.03;
        }

   }
glPopMatrix();


glPushMatrix();
    if(cc->playerToObject(ply, box2)){
        if(box2.xPos - ply->xPos >= 0){
            ply->xPos -= 0.03;
        }
    }
glPopMatrix();

glPushMatrix();
    if(cc->playerToObject(ply, box3)){
        if(box3.xPos - ply->xPos >= 0){
            ply->xPos -= 0.03;
        }
    }
glPopMatrix();

glPushMatrix();
    if(cc->playerToObject(ply, box4)){
        if(box4.xPos - ply->xPos <= 0){
            ply->xPos += 0.015;
        }
    }
glPopMatrix();

*/
///////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////
}

int LevelOne::winMsg(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
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
			KbMs->keySounds(SND);

            if(wParam == int('p') || wParam == int('P')){
                // go to first level.
                /*
                if(mouseX > -4.9767 && mouseX < 0.668879 && mouseY > 0.68 && mouseY < 1.4114){
                    GLScene* scene = new GLScene();
                    loader->loadScene("level1", scene);
                }
                */
            }

            if(wParam == VK_SPACE){
                //SND->~Sounds();
                 SND->stopAllSounds();
                    GLScene *pause = new PauseScene(loader);///,SND);
                    loader->loadScene("Pause", pause);
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
                loader->actuallyLoadScene("Start");
                cout << "BACKSPACE" << endl;
            }

            //ply ->actionTrigger = "Down";
	    break;

        case WM_KEYUP:								// Has A Key Been Released?
		{
			ply ->actionTrigger = "Stand";								// Jump Back


		}break;



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

