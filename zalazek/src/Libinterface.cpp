#include "Libinterface.hh"

Libinterface::Libinterface(std::string name)
{
  LibHandler = dlopen(name.c_str(),RTLD_LAZY);

  if (!LibHandler) {
    cerr << "!!! Brak biblioteki: " << name.c_str() << endl;
    return 1;
  }

  pFun = dlsym(LibHandler,"CreateCmd");

  if (!pFun) {
    cerr << "!!! Nie znaleziono funkcji CreateCmd" << endl;
    return 1;
  }

  pCreateCmd = *reinterpret_cast<Interp4Command* (**)(void)>(&pFun);


  Interp4Command *pCmd = pCreateCmd;

  CmdName=pCmd->GetCmdName();
  
}

Libinterface::~Libinterface()
{
    dlclose(LibHandler);
}