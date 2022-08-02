#ifndef HUD_H
#define HUD_H
#include <freetype.h>
#include <string>

using std::string;
using freetype::font_data;

class HUD
{
    public:
        HUD();
        virtual ~HUD();
        void displayHUD(int, int);
        void initHUD();
        font_data font;
        int scoreOffsetx;
        int scoreOffsety;
        int goalOffsetx;
        int goalOffsety;
        string scoreTxt;
        string goalTxt;
    protected:

    private:
};

#endif // HUD_H
