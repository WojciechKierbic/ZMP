#include "Scene.hh"

MobileObj* Scene::FindMobileObj(const char* name)
{
    MobileObj* pObj = nullptr;
    auto it = MobileObjs.find(name);
    if(it == MobileObjs.end())
    {
        std::cout << "Cannot find object " << name << std::endl;
        return pObj;
    }
    pObj =  &(it->second);
    return pObj;
}

bool Scene::AddMobileObj(MobileObj *pObj)
{
    auto it = MobileObjs.find(pObj->GetName());
    if(it == MobileObjs.end())
    {
        this->MobileObjs.insert(std::make_pair(pObj->GetName(), *pObj));
        return 1;
    }
        std::cout << "Object "  << pObj->GetName() << " already exists" << std::endl;
        return 0;
}

Scene::Scene(Configuration &config)
{ 

    for (unsigned int i = 0; i < config.obj_vector.size(); i++)
    {
        MobileObj tmp_mobileObj;
        tmp_mobileObj.SetName(config.obj_vector[i].name.c_str());
        
        tmp_mobileObj.SetAng_Roll_deg(config.obj_vector[i].rotation[0]);
        tmp_mobileObj.SetAng_Pitch_deg(config.obj_vector[i].rotation[1]);
        tmp_mobileObj.SetAng_Yaw_deg(config.obj_vector[i].rotation[2]);

        tmp_mobileObj.SetPosition_m(config.obj_vector[i].shift);
        tmp_mobileObj.setColor(config.obj_vector[i].color);

        tmp_mobileObj.setScale(config.obj_vector[i].scale);
        tmp_mobileObj.setTranslation(config.obj_vector[i].translation);
        
        if(AddMobileObj(&tmp_mobileObj))
        {
            std::cout<<"Mobile Object "<<tmp_mobileObj.GetName()<< " added"<<std::endl;
        }
        else
        {
            std::cerr<<"Adding mobile object ERROR"<<std::endl;
        }
    }  
}
std::map<std::string, MobileObj> Scene::getMObjects()
{
    return MobileObjs;
}