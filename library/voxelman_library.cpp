#include "voxelman_library.h"

Ref<Material> VoxelmanLibrary::get_material() const {
	return _material;
}
void VoxelmanLibrary::set_material(Ref<Material> mat) {
	_material = mat;
}

Ref<Material> VoxelmanLibrary::get_prop_material() const {
	return _prop_material;
}
void VoxelmanLibrary::set_prop_material(Ref<Material> mat) {
	_prop_material = mat;
}

Ref<Material> VoxelmanLibrary::get_liquid_material() const {
	return _liquid_material;
}
void VoxelmanLibrary::set_liquid_material(Ref<Material> mat) {
	_liquid_material = mat;
}

Ref<Material> VoxelmanLibrary::get_clutter_material() const {
	return _clutter_material;
}
void VoxelmanLibrary::set_clutter_material(Ref<Material> mat) {
	_clutter_material = mat;
}

//Surfaces
Ref<VoxelSurface> VoxelmanLibrary::get_voxel_surface(int index) const {
	return Ref<VoxelSurface>();
}
void VoxelmanLibrary::add_voxel_surface(Ref<VoxelSurface> value) {
}
void VoxelmanLibrary::set_voxel_surface(int index, Ref<VoxelSurface> value) {
}
void VoxelmanLibrary::remove_surface(int index) {
}
int VoxelmanLibrary::get_num_surfaces() {
	return 0;
}
void VoxelmanLibrary::clear_surfaces() {
}

//Liquids
Ref<VoxelSurface> VoxelmanLibrary::get_liquid_voxel_surface(int index) const {
	return Ref<VoxelSurface>();
}
void VoxelmanLibrary::add_liquid_voxel_surface(Ref<VoxelSurface> value) {
}
void VoxelmanLibrary::set_liquid_voxel_surface(int index, Ref<VoxelSurface> value) {
}
void VoxelmanLibrary::remove_liquid_surface(int index) {
}
int VoxelmanLibrary::get_liquid_num_surfaces() {
	return 0;
}
void VoxelmanLibrary::clear_liquid_surfaces() {
}

//Rects
void VoxelmanLibrary::refresh_rects() {
}

void VoxelmanLibrary::setup_material_albedo(int material_index, Ref<Texture> texture) {
	if (has_method("_setup_material_albedo"))
		call("_setup_material_albedo", material_index, texture);
}

VoxelmanLibrary::VoxelmanLibrary() {
}

VoxelmanLibrary::~VoxelmanLibrary() {
	_material.unref();
	_prop_material.unref();
	_liquid_material.unref();
	_clutter_material.unref();
}

void VoxelmanLibrary::_bind_methods() {
	BIND_VMETHOD(MethodInfo("_setup_material_albedo", PropertyInfo(Variant::INT, "material_index"), PropertyInfo(Variant::OBJECT, "texture", PROPERTY_HINT_RESOURCE_TYPE, "Texture")));

	ClassDB::bind_method(D_METHOD("get_material"), &VoxelmanLibrary::get_material);
	ClassDB::bind_method(D_METHOD("set_material", "value"), &VoxelmanLibrary::set_material);
	ADD_PROPERTY(PropertyInfo(Variant::OBJECT, "material", PROPERTY_HINT_RESOURCE_TYPE, "Material"), "set_material", "get_material");

	ClassDB::bind_method(D_METHOD("get_prop_material"), &VoxelmanLibrary::get_prop_material);
	ClassDB::bind_method(D_METHOD("set_prop_material", "value"), &VoxelmanLibrary::set_prop_material);
	ADD_PROPERTY(PropertyInfo(Variant::OBJECT, "prop_material", PROPERTY_HINT_RESOURCE_TYPE, "Material"), "set_prop_material", "get_prop_material");

	ClassDB::bind_method(D_METHOD("get_liquid_material"), &VoxelmanLibrary::get_liquid_material);
	ClassDB::bind_method(D_METHOD("set_liquid_material", "value"), &VoxelmanLibrary::set_liquid_material);
	ADD_PROPERTY(PropertyInfo(Variant::OBJECT, "liquid_material", PROPERTY_HINT_RESOURCE_TYPE, "Material"), "set_liquid_material", "get_liquid_material");

	ClassDB::bind_method(D_METHOD("get_clutter_material"), &VoxelmanLibrary::get_clutter_material);
	ClassDB::bind_method(D_METHOD("set_clutter_material", "value"), &VoxelmanLibrary::set_clutter_material);
	ADD_PROPERTY(PropertyInfo(Variant::OBJECT, "clutter_material", PROPERTY_HINT_RESOURCE_TYPE, "Material"), "set_clutter_material", "get_clutter_material");

	ClassDB::bind_method(D_METHOD("get_voxel_surface", "index"), &VoxelmanLibrary::get_voxel_surface);
	ClassDB::bind_method(D_METHOD("set_voxel_surface", "index", "surface"), &VoxelmanLibrary::set_voxel_surface);
	ClassDB::bind_method(D_METHOD("remove_surface", "index"), &VoxelmanLibrary::remove_surface);
	ClassDB::bind_method(D_METHOD("get_num_surfaces"), &VoxelmanLibrary::get_num_surfaces);
	ClassDB::bind_method(D_METHOD("clear_surfaces"), &VoxelmanLibrary::clear_surfaces);

	ClassDB::bind_method(D_METHOD("get_liquid_voxel_surface", "index"), &VoxelmanLibrary::get_liquid_voxel_surface);
	ClassDB::bind_method(D_METHOD("set_liquid_voxel_surface", "index", "surface"), &VoxelmanLibrary::set_liquid_voxel_surface);
	ClassDB::bind_method(D_METHOD("remove_liquid_surface", "index"), &VoxelmanLibrary::remove_liquid_surface);
	ClassDB::bind_method(D_METHOD("get_liquid_num_surfaces"), &VoxelmanLibrary::get_liquid_num_surfaces);
	ClassDB::bind_method(D_METHOD("clear_liquid_surfaces"), &VoxelmanLibrary::clear_liquid_surfaces);

	ClassDB::bind_method(D_METHOD("refresh_rects"), &VoxelmanLibrary::refresh_rects);

	ClassDB::bind_method(D_METHOD("setup_material_albedo", "material_index", "texture"), &VoxelmanLibrary::setup_material_albedo);

	BIND_CONSTANT(MATERIAL_INDEX_VOXELS);
	BIND_CONSTANT(MATERIAL_INDEX_PROP);
	BIND_CONSTANT(MATERIAL_INDEX_LIQUID);
	BIND_CONSTANT(MATERIAL_INDEX_CLUTTER);
}
