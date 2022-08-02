#include "Inputs.h"
#include <Sounds.h>
#include <time.h>

static Timer* timeSND = new Timer();
Inputs::Inputs()
{
    //ctor
    prev_mouse_X = 0;
    prev_mouse_Y = 0;

    mouse_Translate = 0;
    mouse_Rotate = 0;

}

Inputs::~Inputs()
{
    //dtor
}
void Inputs::keyPressed(Model * Mdl)
{
      switch(wParam){

      case VK_LEFT:
          Mdl->RotateY -= 1.0;
          break;
      case VK_RIGHT:
          Mdl->RotateY += 1.0;
           break;
      case VK_UP:
          Mdl->RotateX += 1.0;
          break;
      case VK_DOWN:
          Mdl->RotateX -=1.0;
          break;
      case VK_ADD:
          Mdl->zoom += 1.0;
          break;
      case VK_SUBTRACT:
          Mdl->zoom -= 1.0;
          break;
      }
}

void Inputs::keyUp()
{

}

void Inputs::mouseEventDown(Model * Mdl,double x, double y)
{
    prev_mouse_X = x;
    prev_mouse_Y = y;

    switch(wParam){
        case MK_LBUTTON:
            mouse_Rotate = true;
        break;

        case MK_RBUTTON:
            mouse_Translate = true;
        break;

        case MK_MBUTTON: //if you want to do something with the mouse middle button
            break;
        default: break;
    }


}

void Inputs::mouseEventUp()
{
mouse_Rotate = false;  //set rotation to false
mouse_Translate = false;// set translation to false
}

void Inputs::mouseEventWheel(Model* Mdl,double Delta)
{
Mdl->zoom += Delta/100;
}

void Inputs::mouseEventMove(Model * Mdl, double x, double y)
{
    if(mouse_Translate){
    Mdl->xPos += (x-prev_mouse_X)/10;
    Mdl->yPos -= (y-prev_mouse_Y)/10;

    prev_mouse_X = x;
    prev_mouse_Y = y;
    }
    if(mouse_Rotate){
    Mdl->RotateX += (y-prev_mouse_Y)/10;
    Mdl->RotateY -= (x-prev_mouse_X)/10;

    prev_mouse_X = x;
    prev_mouse_Y = y;
    }
}
void Inputs::keyEnv(Parallax* plx, float speed)
{
    switch(wParam){
case VK_LEFT:
   // plx->scroll("left",speed);
    break;
case VK_RIGHT:
    //plx->scroll("right",speed);
    break;
case VK_UP:
    //plx->scroll("up",speed);
    break;
case VK_DOWN:
    //plx->scroll("down",speed);
    break;


    }
}
void Inputs::playerAction(Player* ply)
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
}
void Inputs::playerAction2(Player* ply)
{


}
void Inputs::keySounds(Sounds *snds)
{
    switch(wParam)
    {
    case 0x48:///H
        snds->playSound("sounds/carH.mp3");
        break;

    case VK_LEFT:
        if(timeSND->getTicks()>400){
            snds->playSound("sounds/carN.mp3");
            timeSND->reset();
        }

    break;

    case VK_RIGHT:
        if(timeSND->getTicks()>400){
            snds->playSound("sounds/carN.mp3");
            timeSND->reset();
        }

    break;

    case VK_UP:
        if(timeSND->getTicks()>400){
            snds->playSound("sounds/carN.mp3");
            timeSND->reset();
        }

    break;

    case VK_DOWN:
        if(timeSND->getTicks()>400){
            snds->playSound("sounds/carN.mp3");
            timeSND->reset();
        }

    break;

    case VK_RETURN:
        snds->playSound("sounds/whoosh.mp3");

    break;
    }
}

