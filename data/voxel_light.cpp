#include "voxel_light.h"

_FORCE_INLINE_ int VoxelLight::get_world_position_x() const {
    return _world_position_x;
}
_FORCE_INLINE_ int VoxelLight::get_world_position_y() const {
    return _world_position_y;
}
_FORCE_INLINE_ int VoxelLight::get_world_position_z() const {
    return _world_position_z;
}
Vector3 VoxelLight::get_world_position() { 
    return Vector3(_world_position_x, _world_position_y, _world_position_z); 
    
}
void VoxelLight::set_world_position(const int x, const int y, const int z) {
    _world_position_x = x; 
    _world_position_y = y; 
    _world_position_z = z; 
}

_FORCE_INLINE_ Color VoxelLight::get_color() const { 
    return _color; 
    
}
void VoxelLight::set_color(Color color) { 
    _color = color; 
    
}

_FORCE_INLINE_ float VoxelLight::get_size() const { 
    return _size; 
}
void VoxelLight::set_size(const float size) { 
    _size = size; 
}

VoxelLight::VoxelLight() {
    _size = 0;
}

VoxelLight::~VoxelLight() {
}

void VoxelLight::_bind_methods() {
    ClassDB::bind_method(D_METHOD("get_world_position_x"), &VoxelLight::get_world_position_x);
    ClassDB::bind_method(D_METHOD("get_world_position_y"), &VoxelLight::get_world_position_y);
    ClassDB::bind_method(D_METHOD("get_world_position_z"), &VoxelLight::get_world_position_z);
    ClassDB::bind_method(D_METHOD("set_world_position", "x", "y", "z"), &VoxelLight::set_world_position);
    
    ClassDB::bind_method(D_METHOD("get_color"), &VoxelLight::get_color);
    ClassDB::bind_method(D_METHOD("set_color"), &VoxelLight::set_color);
    ADD_PROPERTY(PropertyInfo(Variant::COLOR, "color"), "set_color", "get_color");
    
    ClassDB::bind_method(D_METHOD("get_size"), &VoxelLight::get_size);
    ClassDB::bind_method(D_METHOD("set_size"), &VoxelLight::set_size);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "size"), "set_size", "get_size");
}
