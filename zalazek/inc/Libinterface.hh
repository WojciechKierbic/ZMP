#ifndef LIBINTERFACE_HH
#define LIBINTERFACE_HH
#include "geomVector.hh"
#include "Interp4Command.hh"
#include "MobileObj.hh"
#include "Vector3D.hh"
#include <string>

using namespace std;

class Libinterface 
{
    public:
    void * LibHandler;
    void * pFun;
    Interp4Command *(*pCreateCmd)(void);
    std::string CmdName;
    
    Libinterface(std::string name);
    ~Libinterface();
    
} 

#endif