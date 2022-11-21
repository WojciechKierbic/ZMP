#include <iostream>
#include <dlfcn.h>
#include <cassert>
#include <sstream>
#include <cstdio>
#include <memory>
#include <thread>
#include "Interp4Command.hh"
#include "../inc/Set4Libinterfaces.hh"
#include "../inc/Scene.hh"
#include "../inc/MobileObj.hh"
#include "../inc/Configuration.hh"
#include "../inc/Reader.hh"
#include "../inc/Sender.hh"
#include "../inc/xmlinterp.hh"

#define LINE_SIZE 500

using namespace std;



int main(int argc, char **argv)
{
  if (argc < 2)
  {
    cout<<"Za mało parametrów w linii wywołania"<<endl;
    return 1;
  }
  Configuration config;
  Reader reader;
  std::istringstream IStrm4Cmnds;
  reader.init("../opis_dzialan/opis_dzialan.cmd");
  if (!reader.execPreprocesor(IStrm4Cmnds))
  {
    std::cerr<<"ExecPrep fault"<<std::endl;
  }
  if(!reader.ReadFile("../config/config.xml",config))
  {
    std::cerr<<"Error reading xml config"<<std::endl;
    return 1;
  }
  Scene scene(config);
  Sender sender(&scene);

  if(!sender.OpenConnection())
  {
    std::cerr<<"Error opening connection"<<std::endl;
    return 1;
  }
  
std::thread   Thread4Sending(Fun_CommunicationThread,&ClientSender);
  const char *sConfigCmds =
"Clear\n"
"AddObj Name=Podstawa1 RGB=(20,200,200) Scale=(4,2,1) Shift=(0.5,0,0) RotXYZ_deg=(0,-45,20) Trans_m=(-1,3,0)\n"
"AddObj Name=Podstawa1.Ramie1 RGB=(200,0,0) Scale=(3,3,1) Shift=(0.5,0,0) RotXYZ_deg=(0,-45,0) Trans_m=(4,0,0)\n"
"AddObj Name=Podstawa1.Ramie1.Ramie2 RGB=(100,200,0) Scale=(2,2,1) Shift=(0.5,0,0) RotXYZ_deg=(0,-45,0) Trans_m=(3,0,0)\n"       
"AddObj Name=Podstawa2 RGB=(20,200,200) Scale=(4,2,1) Shift=(0.5,0,0) RotXYZ_deg=(0,-45,0) Trans_m=(-1,-3,0)\n"
"AddObj Name=Podstawa2.Ramie1 RGB=(200,0,0) Scale=(3,3,1) Shift=(0.5,0,0) RotXYZ_deg=(0,-45,0) Trans_m=(4,0,0)\n"
"AddObj Name=Podstawa2.Ramie1.Ramie2 RGB=(100,200,0) Scale=(2,2,1) Shift=(0.5,0,0) RotXYZ_deg=(0,-45,0) Trans_m=(3,0,0)\n";

Set4Libinterfaces libinterfaces;
libinterfaces.init(config.getLibs());
libinterfaces.execLib(IStrm4Cmnds);

sender.Send(sConfigCmds);
sender.Send("Close\n");
sender.CancelCountinueLooping();
if(Thread4Sending.joinable()) Thread4Sending.join();
return 0;

  // {
  //   std::cout<<"Lib added"<<endl;
  // 

//   //// scene.AddMobileObj(obj_name);
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

