#include "Set4Libinterfaces.hh"

bool Set4Libinterfaces::Add_Interface(string &Interface_Name)
{
    shared_ptr<Libinterface> lib_if = make_shared<Libinterface>();
    if (!lib_if->init(Interface_Name))
    {
        return false;
    }
    Libinterfaces.insert({Interface_Name, lib_if});
    return true;
}
std::shared_ptr<Libinterface> Set4Libinterfaces::Find_Interface(string& name)
{
    auto it = Libinterfaces.find("../libs/libInterp4" + name + ".so");
    if(it == Libinterfaces.end()) return nullptr;
    return it->second;
}
