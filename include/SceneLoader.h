#ifndef SCENELOADER_H
#define SCENELOADER_H

#include <unordered_map>
#include <string>
#include <StartScene.h>
#include <SceneLoader.h>
#include <LevelOne.h>
using namespace std;

class SceneLoader
{
    public:
        SceneLoader(GLScene*);
        SceneLoader(string, GLScene*);
        virtual ~SceneLoader();

        // loads scene from sceneMap
        void loadScene(string, GLScene*);

        // delete scene from sceneMap
        void deleteScene(string);

        // returns current screen
        GLScene* getCurrScene();

        void actuallyLoadScene(string);
        string getCurrentSceneName();
        string prevSceneName;
    protected:

    private:
        // hash table of scenes
        unordered_map<string, GLScene*> sceneMap;

        // current scene string
        string currScene;

};

#endif // SCENELOADER_H
