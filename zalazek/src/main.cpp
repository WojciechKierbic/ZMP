#include <iostream>
#include <dlfcn.h>
#include <cassert>
#include <sstream>
#include <cstdio>
#include <memory>
#include <thread>
#include "Interp4Command.hh"
#include "Set4Libinterfaces.hh"
#include "Scene.hh"
#include "MobileObj.hh"
#include "Configuration.hh"
#include "Reader.hh"
#include "Sender.hh"
#include "xmlinterp.hh"
#include <unistd.h>

#define LINE_SIZE 500

using namespace std;



int main(int argc, char **argv)
{
  if (argc < 2)
  {
    std::cerr<<"No command file" << std::endl;
    return 1;
  }
  if (argc < 3)
  {
    std::cerr<<"No XML file" << std::endl;
    return 1;
  }
  Configuration config;
  Reader reader;
  Set4Libinterfaces libinterfaces;
  std::istringstream IStrm4Cmnds;
  reader.init(argv[1]);
  if(!reader.ReadFile(argv[2],config))
  {
    std::cerr<<"Error reading xml config"<<std::endl;
    return 1;
  }
  Scene scene (config);
  Sender sender (&scene);
  if(!sender.OpenConnection())
  {
    std::cerr << "Opening Connection fail" <<std::endl;
    return 1;
  }
  libinterfaces.init(config.lib_vector);
  std::thread Thread4Sending(&Sender::Watching_and_Sending, &sender);
  std::vector<std::thread> Threads;
  std::string key;
  if (!reader.execPreprocesor(IStrm4Cmnds))
  {
    std::cerr<<"ExecPrep fault"<<std::endl;
  }
  Interp4Command *cmd;
  while (IStrm4Cmnds >> key)
  {
    cmd = libinterfaces.execCmd(key);
    if (libinterfaces.isParallel() && cmd != nullptr)
    {
      cmd->ReadParams(IStrm4Cmnds);
      Threads.push_back(std::thread(&Interp4Command::ExecCmd, cmd, &scene));
    }
    else if (!libinterfaces.isParallel())
    {
      for (int i = 0; i < Threads.size(); ++i)
      {
        if (Threads[i].joinable())
        {
          Threads[i].join();
        }
      }
      Threads.clear();
    }
  }

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

