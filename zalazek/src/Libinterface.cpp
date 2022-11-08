#include "Libinterface.hh"

Libinterface::Libinterface()
{
  
}

Libinterface::~Libinterface()
{
  dlclose(LibHandler);
}

bool Libinterface::init(std::string &name)
{
  LibHandler = dlopen(name.c_str(), RTLD_LAZY);
  if (!LibHandler)
  {
    cerr << "!!! Brak biblioteki: " << name.c_str() << endl;
    return false;
  }

  void *pFun = dlsym(LibHandler, "CreateCmd");

  if (!pFun)
  {
    cerr << "!!! Nie znaleziono funkcji CreateCmd" << endl;
    return false;
  }

  pCreateCmd = *reinterpret_cast<Interp4Command *(**)(void)>(&pFun);

  return true;
}

bool Libinterface::execActions(std::istream &rIstrm, std::shared_ptr<MobileObj> &mobileObj)
{
  Interp4Command *pCmd = pCreateCmd();
  std::cout<<"Action: "<<std::endl;
  pCmd->PrintSyntax();

  if(!pCmd->ReadParams(rIstrm))
  {
    return false;
  }
  std::cout << "Action for Obj: "<<mobileObj->GetName() <<std::endl;
  return true;
}