#include <iostream>
#include <dlfcn.h>
#include <cassert>
#include <sstream>
#include <cstdio>
#include "Interp4Command.hh"
#include "Set4Libinterfaces.hh"
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
      return 1;
    }
    else
    {
      rInterp.ExecCmd();
      return true;
    }
  }

  else if(CmdKey == "Pause")
  {
    if(!rInterp.ReadParams(rIStream))
    {
      cout<<"Nie udalo sie odczytac parametrow"<<endl;
      return 1;
    }
    else
    {
      rInterp.ExecCmd();
      return true;
    }
  }

  else if(CmdKey == "Rotate")
  {
    if(!rInterp.ReadParams(rIStream))
    {
      cout<<"Nie udalo sie odczytac parametrow"<<endl;
      return 1;
    }
    else
    {
      rInterp.ExecCmd();
      return true;
    }
  }

  else if(CmdKey == "Set")
  {
    if(!rInterp.ReadParams(rIStream))
    {
      cout<<"Nie udalo sie odczytac parametrow"<<endl;
      return 1;
    }
    else
    {
      rInterp.ExecCmd();
      return true;
    }
  }
  return false;
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

Set4Libinterfaces Libinterfaces;


while(!istrm4cmnds.eof())
  if(!ExecActions(istrm4cmnds, Libinterfaces["Move"].pCreateCmd) || !ExecActions(istrm4cmnds, Libinterfaces["Pause"].pCreateCmd) || !ExecActions(istrm4cmnds, Libinterfaces["Rotate"].pCreateCmd) || !ExecActions(istrm4cmnds, Libinterfaces["Set"].pCreateCmd))
  {
    cerr<<"ExecACtions not OK"<<endl;
    return 2;
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
