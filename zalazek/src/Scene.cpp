#include "Scene.hh"


std::shared_ptr<MobileObj> Scene::FindMobileObj(const std::string &ObjName)
{
    std::map<std::string, std::shared_ptr<MobileObj>>::iterator it = MobileObjs.find(ObjName);
    if (it == MobileObjs.end()) return nullptr;
    return it->second;
}



void Scene::AddMobileObj(const std::string &objName)
{
    if(FindMobileObj(objName))
    {
        class std::shared_ptr<MobileObj> mobileObj = std::make_shared<MobileObj>();
        mobileObj->SetName(objName);
        MobileObjs.insert({objName, mobileObj});
    }
}