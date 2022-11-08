#ifndef MOBILEOBJ_HH
#define MOBILEOBJ_HH
#include "MobileObj.hh"
using namespace std;

class Scene
{

private:

std::map<string,std::share_ptr<MobileObj>> _Set_MobileObjs();

public:

std::shared_ptr<MobileObj> FindMobileObj(const char * sObjName);
std::shared_ptr<MobileObj> FindMobileObj( std::string &rObjName);
void AddMobileObj (MobileObj *pMobObj);

#endif