#ifndef SCENE_HH
#define SCENE_HH

#include <iostream>

#include <map>
#include <memory>
#include "MobileObj.hh"
#include "AccessControl.hh"
#include "Vector3D.hh"
#include <vector>
#include <sstream>

using namespace std;

class Scene : public AccessControl
{

private:

std::map<string,std::shared_ptr<MobileObj>> MobileObjs;

public:

std::shared_ptr<MobileObj> FindMobileObj(const std::string &ObjName);
void AddMobileObj (const std::string &objName);
// void AddObjectColor (const std::string &objName, std::string RGB_Value);
// void AddObjectPos (const std::string &objName, std::string Pos_Value);
// void AddObjectSize (const std::string &objName, std::string Size_Value);
Scene(){};
~Scene(){};
};
#endif