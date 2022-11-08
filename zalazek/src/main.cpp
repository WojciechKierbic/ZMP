#include <iostream>
#include <dlfcn.h>
#include <cassert>
#include <sstream>
#include <cstdio>
#include "Interp4Command.hh"
#include "Set4Libinterfaces.hh"
#include "../inc/Scene.hh"

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

int main(int argc, char **argv)
{
  if (argc < 2)
  {
    cout<<"Za mało parametrów w linii wywołania"<<endl;
    return 1;
  }

istringstream istrm4cmnds;
Set4Libinterfaces Libinterfaces;
Scene scene;

std::cout<<istrm4cmnds.str()<<std::endl;

//while (istrm4cmnds.eof())
//{
  
//}


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
