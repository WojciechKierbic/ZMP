#include "Configuration.hh"

void Configuration::add_lib(std::string name)
{
    this->lib_vector.push_back(name);
}

std::vector<std::string> Configuration::getLibs()
{
    return lib_vector;
}

void Configuration::add_object_name(std::string name)
{
    this->obj_names.push_back(name);
}

std::vector<std::string> Configuration::getObjects_names()
{
    return obj_names;
}

void Configuration::add_object_scale(Vector3D scale)
{
    this->obj_scales.push_back(scale);
}

std::vector<Vector3D> Configuration::getObjects_scales()
{
    return obj_scales;
}

void Configuration::add_object_color(Vector3D color)
{
    this->obj_colors.push_back(color);
}

std::vector<Vector3D> Configuration::getObjects_colors()
{
    return obj_colors;
}

void Configuration::add_object_position_shift(Vector3D shift)
{
    this->obj_position_shift.push_back(shift);
}

std::vector<Vector3D> Configuration::getObjects_position_shift()
{
    return obj_position_shift;
}

void Configuration::add_object_rotation(Vector3D rotation)
{
    this->obj_rotations.push_back(rotation);
}

std::vector<Vector3D> Configuration::getObjects_rotations()
{
    return obj_rotations;
}

void Configuration::add_object_translation(Vector3D translation)
{
    this->obj_translations.push_back(translation);
}

std::vector<Vector3D> Configuration::getObjects_translations()
{
    return obj_translations;
}

