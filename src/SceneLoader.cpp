#include "SceneLoader.h"
#include <StartScene.h>

SceneLoader::SceneLoader(GLScene* scene){
    currScene = "Start";
    sceneMap[currScene] = scene;
}

SceneLoader::SceneLoader(string name, GLScene* scene){
    currScene = name;
    sceneMap[currScene] = scene;
}


SceneLoader::~SceneLoader()
{
    //dtor
}

// load the initial scene into unordered map
// @PARAM scene's Name
// @PARAM GLScene to be used
void SceneLoader::loadScene(string name, GLScene* scene)
{
    auto exists = sceneMap.find(name);
    prevSceneName = currScene;

    // if it doesn't find scene
    if(exists == sceneMap.end()){
        cout << "Not found" << endl;
        string oldScene = currScene;
        sceneMap[name] = scene;             // link to hash table
        currScene = name;                   // set current scene
        sceneMap[name]->initGL();           // initialize instance.
    }
    else if(name == "Pause" && exists != sceneMap.end()){
        deleteScene("Pause");
        sceneMap[name] = scene;
        currScene = name;
        sceneMap[name]->initGL();
    }
    else{
        currScene = name;
        sceneMap[name]->initGL();
    }
}


// actually show us the new screen, if it is already initialized
// @PARAM scene's name
void SceneLoader::actuallyLoadScene(string sceneName){
    // TODO: add a check to see if the scene exists
    currScene = sceneName;
    sceneMap[currScene]->initGL();
}

void SceneLoader::deleteScene(string oldScene)
{
    if(sceneMap.erase(oldScene) == 1){
        cout << "Erased " << oldScene << endl;
    }
    // not sure if I want this here. we'll see later.
}

GLScene* SceneLoader::getCurrScene()
{
    return sceneMap[currScene];
}

string SceneLoader::getCurrentSceneName(){
    return currScene;
}
