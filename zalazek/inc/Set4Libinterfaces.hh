#ifndef SET4LIBINTERFACES_HH
#define SET4LIBINTERFACES_HH
#include "Libinterface.hh"
#include <map>
#include <iostream>

using namespace std;


class Set4Libinterfaces
{
private:

std::map<std::string, std::shared_ptr<Libinterface>> Libinterfaces;

public:

Set4Libinterfaces();
~Set4Libinterfaces();

};

#endif