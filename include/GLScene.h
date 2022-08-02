#ifndef GLSCENE_H
#define GLSCENE_H

#include <windows.h>
#include <GL/glut.h>

class GLScene
{
    public:
        GLScene();
        virtual ~GLScene();

        virtual GLint initGL();
        virtual GLint drawGLScene();
        GLvoid resizeGLScene(GLsizei, GLsizei);

        virtual int winMsg (HWND, UINT, WPARAM, LPARAM);

        void convertMouseCoord(float, float, GLdouble*, GLdouble*, GLint*);
        void convertMouseCoord(float, float);
        float screenWidth, screenHeight;
        double mouseX, mouseY, mouseZ;


    protected:

    private:
};

#endif // GLSCENE_H
