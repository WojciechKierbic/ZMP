#ifndef LIBINTERFACE_HH
#define LIBINTERFACE_HH

#include "geomVector.hh"
#include "Interp4Command.hh"
#include "MobileObj.hh"
#include "Vector3D.hh"
#include <cstring>
#include <sstream>
#include <dlfcn.h>
#include <memory>
#include <map>

using namespace std;

/*
* \file
* \brief Interfejs klasy Libinterface
*
*/

class Libinterface 
{
    private:
    void * LibHandler;
    Interp4Command *(*pCreateCmd)(void);
    std::string CmdName;

    public:
    Libinterface();
    ~Libinterface();
    bool init(const std::string name);
    Interp4Command *CreateCmd();
    //bool execActions(std::istream &rIstrm, std::shared_ptr<MobileObj> &mobileObj);
};

#endif