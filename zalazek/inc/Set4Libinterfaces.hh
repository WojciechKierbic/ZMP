#ifndef SET4LIBINTERFACES_HH
#define SET4LIBINTERFACES_HH

#include "Interp4Command.hh"
#include "Libinterface.hh"
#include <map>
#include <iostream>
#include <memory>
#include <string>
#include <sstream>
#include <vector>

using namespace std;


class Set4Libinterfaces
{
private:

std::map<std::string, std::shared_ptr<Libinterface>> Libinterfaces;

public:

Set4Libinterfaces(){};
~Set4Libinterfaces(){};

bool init(std::vector<std::string> lib_vector);
bool execLib(std::istringstream &strm);

};

#endif