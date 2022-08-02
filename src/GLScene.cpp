#include "GLScene.h"
#include "GLLight.h"
#include "Inputs.h"
#include "windows.h"
#include "Model.h"
#include "Parallax.h"
#include "Player.h"
#include <math.h>
#include <algorithm>"

Inputs *KbMs = new Inputs();
Model *Mdl = new Model();
Parallax *Plx = new Parallax();

TextureLoader* cTex = new TextureLoader();

TextureLoader* enmTex = new TextureLoader();


bool start = false;

GLScene::GLScene()
{
    screenHeight = GetSystemMetrics(SM_CYSCREEN);
    screenWidth = GetSystemMetrics(SM_CXSCREEN);
}

GLScene::~GLScene()
{
    //dtorc
}

GLint GLScene::initGL()
{
    glShadeModel(GL_SMOOTH);                    // for good transition in animations
    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);       // set background color
    glClearDepth(1.0f);                         // decide what is at front and behind
    glEnable(GL_DEPTH_TEST);                    // for the depth calculation
    glDepthFunc(GL_LEQUAL);

    /*
    for(int i = 0; i < 20; i++){
        c[i].placeCoins(((rand() % 20) - 10) / 10.0, ((rand() % 20) -10) / 10.0, -0.05);

        c[i].xSize = c[i].ySize = (rand() % 5) / 10.0;
        c[i].coinInit();
    }*/

    //glEnable(GL_COLOR_MATERIAL);                // this is for the base color of the object (color3f)
    //GLLight Light(GL_LIGHT0);
    //Light.setLight(GL_LIGHT0);
    //Mdl->modelInit("images/teapot.jpg");
    //Plx->parallaxInit("images/background.jpg");

    //cTex->binder();
    return true;
}

GLint GLScene::drawGLScene()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();

    // draw background.
    glPushMatrix();
        Plx->drawSquare(screenWidth, screenHeight);
    glPopMatrix();


}

void GLScene::convertMouseCoord(float x, float y, GLdouble* modelMat, GLdouble* projMat, GLint* viewport ){
    GLfloat nx, ny, nz;
    nx = x;
    ny = y;
    glReadPixels(nx, (float)ny, 1, 1, GL_DEPTH_COMPONENT, GL_FLOAT, &nz);
    gluUnProject(nx, ny, nz, modelMat, projMat, viewport, &mouseX, &mouseY, &mouseZ);
    //cout << "Mouse  X: " << mouseX << " " << "Mouse Y: " << mouseY << endl;
}

// cleaner version.. tried to make it so it wouldn't mess up everyone's stuff.
// @PARAM LOWORD
// @PARAM HIWORD
void GLScene::convertMouseCoord(float x, float y){
        GLfloat nx, ny, nz;
        GLdouble modelMat[16];
        GLdouble projMat[16];
        GLint viewport[4];
        glGetDoublev(GL_MODELVIEW_MATRIX, modelMat);
        glGetDoublev(GL_PROJECTION_MATRIX, projMat);
        glGetIntegerv(GL_VIEWPORT, viewport);

        y = -y + viewport[3] - 1;
        nx = x;
        ny = y;
        glReadPixels(nx, (float)ny, 1, 1, GL_DEPTH_COMPONENT, GL_FLOAT, &nz);
        gluUnProject(nx, ny, nz, modelMat, projMat, viewport, &mouseX, &mouseY, &mouseZ);
        //cout << LOWORD(lParam) << ", " << HIWORD(lParam) << endl;
}

GLvoid GLScene::resizeGLScene(GLsizei width, GLsizei height)
{
    GLfloat aspectRatio = (GLfloat) width / (GLfloat) height;
    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0, aspectRatio, 1.0, 100.0f);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    screenHeight = GetSystemMetrics(SM_CYSCREEN);
    screenWidth = GetSystemMetrics(SM_CXSCREEN);
}


int GLScene::winMsg(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam){
    switch (uMsg){                                                  // check for windows msg
        case WM_KEYDOWN:
	        KbMs->wParam = wParam;
	        //KbMs->keyPress(Mdl);
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
            GLdouble modelMat[16];
            GLdouble projMat[16];
            GLint viewport[4];
            glGetDoublev(GL_MODELVIEW_MATRIX, modelMat);
            glGetDoublev(GL_PROJECTION_MATRIX, projMat);
            glGetIntegerv(GL_VIEWPORT, viewport);
            convertMouseCoord((float)LOWORD(lParam), (float) viewport[3] - (GLfloat)HIWORD(lParam) - 1, modelMat, projMat, viewport);

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
}

