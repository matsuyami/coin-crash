#include "Model.h"
#include "TextureLoader.h"

TextureLoader* tex = new TextureLoader();

Model::Model()
{
        RotateX = 0.0;
        RotateY = 0.0;
        RotateZ = 0.0;

        zoom = -8.0;
        xPos = 0.0;
        yPos = 0.0;

}

void Model::modelInit(char * filename){
    tex->binder();
    tex->loadTexture(filename);
}

Model::~Model()
{
    //dtor
}
void Model::drawModel()
{

    glColor3f(0.8f, 0.5f, 0.0f);
    glTranslated(xPos, yPos, zoom);
    cout << "(" << xPos << ", " << yPos << ")" << endl;
    glRotated(RotateX, 1.0f, 0.0f, 0.0f);
    glRotated(RotateY, 0.0f, 1.0f, 0.0f);
    glRotated(RotateZ, 0.0f, 0.0f, 1.0f);

    // whatever model you want to draw
    glutSolidTeapot(1.5);
}

void Model::drawTriangle(){
    glTranslatef(xPos, yPos, zoom);
    glRotated(RotateX, 1.0f, 0.0f, 0.0f);
    glRotated(RotateY, 0.0f, 1.0f, 0.0f);
    glRotated(RotateZ, 0.0f, 0.0f, 1.0f);


    glBegin(GL_TRIANGLES);
        glColor3f(0.1, 0.2, 0.3);
        glVertex3f(0.0, 0.1, 0.0);
        glVertex3f(-1.0, -1.0, 0.0);
        glVertex3f(1, -1.0, 0.0);
    glEnd();
}

