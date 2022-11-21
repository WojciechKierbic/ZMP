#include "../inc/Libinterface.hh"

Libinterface::Libinterface()
{
  
}

Libinterface::~Libinterface()
{
  dlclose(LibHandler);
}

bool Libinterface::init(const std::string name)
{
  LibHandler = dlopen(name.c_str(), RTLD_LAZY);

  const char* (*CmdNameFcn)(void);

  
  if (!LibHandler)
  {
    cerr << "!!! Brak biblioteki: " << name << endl;
    return 1;
  }

  void *pFun = dlsym(LibHandler, "CreateCmd");

  if (!pFun)
  {
    std::cerr << "!!! Nie znaleziono funkcji CreateCmd" << endl;
    return 1;
  }

  this->pCreateCmd = *reinterpret_cast<Interp4Command *(**)(void)>(&pFun);

  pFun = dlsym(LibHandler, "GetCmdName");

  if (!pFun)
  {
    std::cerr << "!!! Nie znaleziono funkcji GetCmdName w " << name << endl;
    return 1;
  }

  CmdNameFcn = reinterpret_cast<const char*(*)(void)>(pFun);
  CmdName = CmdNameFcn();
  return 0;
}

Interp4Command *Libinterface::CreateCmd()
{
  return pCreateCmd();
}