#ifndef PARTICLES_H
#define PARTICLES_H

#include <string.h>
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#define GLEW_STATIC
#include <GL/glew.h>
#include <GL/glut.h>
#endif

#include <stdlib.h>
#include <iostream>
#include <math.h>
#include <fstream>
#include <SOIL.h>

#include <TextureLoader.h>

#define PI 3.14159

#define MAX_DROPS 5000


class Particles
{
    public:
        int NumDrops;
        Particles();
        virtual ~Particles();

        typedef struct {
            bool alive;
            float xpos;
            float ypos;
            float xdir;
            float ydir;
            float mass;

            float radius;

            float explosionRadius;

            float angle;
            //int color = 255;

            float velocityX;
            float velocityY;
            float alpha;
        }Particle;

        Particle drops[MAX_DROPS];
        void drawParticle(); //output
        void lifeTime(); // update
        void generateParticles(float,float); // emitter
        TextureLoader* particleTex = new TextureLoader();
    protected:

    private:
};

#endif // PARTICLES_H
