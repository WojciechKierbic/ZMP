#ifndef CONFIGURATION_HH
#define CONFIGURATION_HH

#include <vector>
#include "Vector3D.hh"
#include <string>

struct MobileObjStruct
{
  std::string name;
  Vector3D scale;
  Vector3D color;
  Vector3D shift;
  Vector3D rotation;
  Vector3D translation;
};


class Configuration {
  
  public:
  
  std::vector<std::string> lib_vector;
  std::vector<MobileObjStruct> obj_vector;
};


#endif
