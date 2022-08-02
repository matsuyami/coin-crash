#include "CollisionChecker.h"

CollisionChecker::CollisionChecker()
{
    //ctor
    //coinSound->initSounds();
}

CollisionChecker::~CollisionChecker()
{
    //dtor
}

void CollisionChecker::showPlayerBox(Player* ply){
    float pwOffset = ply->get_width();
    float phOffset = ply->get_height();
    float p_xmin = ply->get_xpos() - pwOffset;
    float p_xmax = ply->get_xpos() + pwOffset;
    float p_ymin = ply->get_ypos() - phOffset;
    float p_ymax = ply->get_ypos() + phOffset;
    glBegin(GL_QUADS);
    glVertex3f(p_xmin , p_ymin, -1.0);
    glVertex3f(p_xmax, p_ymin, -1.0);
    glVertex3f(p_xmax, p_ymax, -1.0);
    glVertex3f(p_xmin, p_ymax, -1.0);
    glEnd();
}
