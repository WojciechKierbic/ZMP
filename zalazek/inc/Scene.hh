#ifndef SCENE_HH
#define SCENE_HH

#include <iostream>

#include <map>
#include <memory>
#include "MobileObj.hh"

using namespace std;

class Scene
{

private:

std::map<string,std::shared_ptr<MobileObj>> MobileObjs;

public:

std::shared_ptr<MobileObj> FindMobileObj(const std::string &ObjName);
void AddMobileObj (const std::string &objName);
Scene(){};
~Scene(){};
};
#endif