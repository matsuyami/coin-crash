#include "HUD.h"

HUD::HUD()
{
    scoreOffsetx = 225;
    scoreOffsety = 50;
    goalOffsetx = scoreOffsetx + 600;
    goalOffsety = 50;
}

HUD::~HUD()
{
    //dtor
}

// @PARAMS (font, size);
void HUD::initHUD(){
    font.init("fonts/slkscr.TTF", 40);
}

// takes player score and level goal and display a HUD.
void HUD::displayHUD(int player_score, int goal_num){
    scoreTxt =  "Score: " + std::to_string(player_score);
    goalTxt = "Goal: " + std::to_string(goal_num);
    // print display to screen, x, y, text to display
    freetype::print(font, scoreOffsetx, scoreOffsety, scoreTxt.c_str());
    freetype::print(font, goalOffsetx, goalOffsety, goalTxt.c_str());
    return;
}
