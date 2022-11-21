#include "../inc/Scene.hh"

MobileObj* Scene::FindMobileObj(const char* name)
{
    MobileObj* pObj = nullptr;
    auto it = MobileObjs.find(name);
    if(it == MobileObjs.end())
    {
        std::cout << "Cannot find object " << name << std::endl;
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
        return 0;
    }
        std::cout << "Object "  << pObj->GetName() << " already exists" << std::endl;
        return 1;
}

Scene::Scene(Configuration &config)
{ 
    std::vector<std::string> object_names = config.getObjects_names();
    std::vector<Vector3D> scales = config.getObjects_scales();
    std::vector<Vector3D> color = config.getObjects_colors();
    std::vector<Vector3D> pos_shift = config.getObjects_position_shift();
    std::vector<Vector3D> rotation = config.getObjects_rotations();
    std::vector<Vector3D> translation = config.getObjects_translations();
    
    for (unsigned int i = 0; i < object_names.size(); i++)
    {
        MobileObj tmp_mobileObj;
        tmp_mobileObj.SetName(object_names[i].c_str());
        
        tmp_mobileObj.SetAng_Roll_deg(rotation[i][0]);
        tmp_mobileObj.SetAng_Pitch_deg(rotation[i][1]);
        tmp_mobileObj.SetAng_Yaw_deg(rotation[i][2]);

        tmp_mobileObj.SetPosition_m(pos_shift[i]);
        tmp_mobileObj.setColor(color[i]);

        tmp_mobileObj.setScale(scales[i]);
        tmp_mobileObj.setTranslation(translation[i]);
        
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