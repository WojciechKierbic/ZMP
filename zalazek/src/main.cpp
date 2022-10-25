#include <iostream>
#include <dlfcn.h>
#include <cassert>
#include <sstream>
#include <cstdio>
#include "Interp4Command.hh"
//#include "MobileObj.hh"

#define LINE_SIZE 500

using namespace std;

bool ExecPreprocesor(const char * NazwaPliku, istringstream &IStrm4Cmds)
{
  string Cmd4Preproc = "cpp -P ";
  char Line[LINE_SIZE];
  ostringstream OTmpStrm;
  Cmd4Preproc += NazwaPliku;
  FILE* pProc = popen(Cmd4Preproc.c_str(),"r");
  if (!pProc) return false;
  while (fgets(Line,LINE_SIZE,pProc)) 
  {
    OTmpStrm << Line;
  }
  IStrm4Cmds.str(OTmpStrm.str());
  return pclose(pProc) == 0;
}

bool ExecActions(istream &rIStream, Interp4Command &rInterp)
{
  string CmdKey;
  rIStream >> CmdKey;
  if(CmdKey == "Move")
  {
    if(!rInterp.ReadParams(rIStream))
    {
      cout<<"Nie udalo sie odczytac parametrow"<<endl;
      return 4;
    }
    else
    {
      rInterp.PrintCmd();
    }
  }
  cout<< " Polecenie: "<<CmdKey<<endl;
  return true;
}

int main(int argc, char **argv)
{
  if (argc < 2)
  {
    cout<<"Za mało parametrów w linii wywołania"<<endl;
    return 1;
  }
istringstream istrm4cmnds;
if(!ExecPreprocesor(argv[1], istrm4cmnds))
{
  cout<<"ExecpProc not OK"<<endl;
  return 2;
}

void *pLibHnd_Move = dlopen("libInterp4Move.so",RTLD_LAZY);
  Interp4Command *(*pCreateCmd_Move)(void);
  void *pFun;

  if (!pLibHnd_Move) {
    cerr << "!!! Brak biblioteki: Interp4Move.so" << endl;
    return 1;
  }


  pFun = dlsym(pLibHnd_Move,"CreateCmd");
  if (!pFun) {
    cerr << "!!! Nie znaleziono funkcji CreateCmd" << endl;
    return 1;
  }
  pCreateCmd_Move = *reinterpret_cast<Interp4Command* (**)(void)>(&pFun);


  Interp4Command *pCmd = pCreateCmd_Move();


  //cout<<endl<<istrm4cmnds.str()<<endl;

  if(!ExecActions(istrm4cmnds, *pCmd))
  {
    cerr<<"ExecACtions not OK"<<endl;
    return 3;
  }
  /*
  

  cout << endl;
  cout << pCmd->GetCmdName() << endl;
  cout << endl;
  pCmd->PrintSyntax();
  cout << endl;
  pCmd->PrintCmd();
  cout << endl;
  
  delete pCmd;

  dlclose(pLibHnd_Move);
  */
}
