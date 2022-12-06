#ifndef SCENE_HH
#define SCENE_HH

#include <iostream>
#include <map>
#include <memory>
#include "MobileObj.hh"
#include "AccessControl.hh"
#include "Configuration.hh"
#include <vector>
#include <sstream>

using namespace std;

class Scene : public AccessControl
{

private:

std::map <string, MobileObj> MobileObjs;

public:
Scene(Configuration &config);
MobileObj* FindMobileObj(const char* ObjName)
{
    MobileObj* pObj = nullptr;
    auto it = MobileObjs.find(ObjName);
    if(it == MobileObjs.end())
    {
        std::cout << "Cannot find object " << ObjName << std::endl;
        return pObj;
    }
    pObj =  &(it->second);
    return pObj;
};
bool AddMobileObj (MobileObj *pObj);
std::map<string, MobileObj> getMObjects();
};
#endif