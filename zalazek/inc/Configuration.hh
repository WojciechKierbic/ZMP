#ifndef CONFIGURATION_HH
#define CONFIGURATION_HH

#include <vector>
#include "Vector3D.hh"
#include <string>


class Configuration {
  
  std::vector<std::string> lib_vector;
  std::vector<std::string> obj_names;
  std::vector<Vector3D> obj_scales;
  std::vector<Vector3D> obj_colors;
  std::vector<Vector3D> obj_position_shift;
  std::vector<Vector3D> obj_rotations;
  std::vector<Vector3D> obj_translations;

  public:
  
  void add_lib(std::string name);
  std::vector<std::string> getLibs();
  void add_object_name(std::string name);
  std::vector<std::string> getObjects_names();
  void add_object_scale(Vector3D scale);
  std::vector<Vector3D> getObjects_scales();
  void add_object_color(Vector3D color);
  std::vector<Vector3D> getObjects_colors();
  void add_object_position_shift(Vector3D shift);
  std::vector<Vector3D> getObjects_position_shift();
  void add_object_rotation(Vector3D rotation);
  std::vector<Vector3D> getObjects_rotations();
  void add_object_translation(Vector3D translation);
  std::vector<Vector3D> getObjects_translations();
};


#endif
