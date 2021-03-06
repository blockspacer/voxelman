#include "voxelman_library_merger.h"

int VoxelmanLibraryMerger::get_texture_flags() const {
	return _packer->get_texture_flags();
}
void VoxelmanLibraryMerger::set_texture_flags(const int flags) {
	_packer->set_texture_flags(flags);
}

int VoxelmanLibraryMerger::get_max_atlas_size() const {
	return _packer->get_max_atlas_size();
}
void VoxelmanLibraryMerger::set_max_atlas_size(const int size) {
	_packer->set_max_atlas_size(size);
}

bool VoxelmanLibraryMerger::get_keep_original_atlases() const {
	return _packer->get_keep_original_atlases();
}
void VoxelmanLibraryMerger::set_keep_original_atlases(const bool value) {
	_packer->set_keep_original_atlases(value);
}

Color VoxelmanLibraryMerger::get_background_color() const {
	return _packer->get_background_color();
}
void VoxelmanLibraryMerger::set_background_color(const Color color) {
	_packer->set_background_color(color);
}

int VoxelmanLibraryMerger::get_margin() const {
	return _packer->get_margin();
}
void VoxelmanLibraryMerger::set_margin(const int margin) {
	_packer->set_margin(margin);
}

//Surfaces
Ref<VoxelSurface> VoxelmanLibraryMerger::get_voxel_surface(int index) const {
	ERR_FAIL_INDEX_V(index, _voxel_surfaces.size(), Ref<VoxelSurface>(NULL));

	return _voxel_surfaces[index];
}

void VoxelmanLibraryMerger::add_voxel_surface(Ref<VoxelSurface> value) {
	ERR_FAIL_COND(!value.is_valid());

	value->set_library(Ref<VoxelmanLibraryMerger>(this));
	value->set_id(_voxel_surfaces.size());

	_voxel_surfaces.push_back(value);
}

void VoxelmanLibraryMerger::set_voxel_surface(int index, Ref<VoxelSurface> value) {
	ERR_FAIL_COND(index < 0);

	if (_voxel_surfaces.size() < index) {
		_voxel_surfaces.resize(index + 1);
	}

	if (_voxel_surfaces[index].is_valid()) {
		_voxel_surfaces.get(index)->set_library(Ref<VoxelmanLibraryMerger>(NULL));
	}

	if (value.is_valid()) {
		value->set_library(Ref<VoxelmanLibraryMerger>(this));

		_voxel_surfaces.set(index, value);
	}
}

void VoxelmanLibraryMerger::remove_surface(int index) {
	_voxel_surfaces.remove(index);
}

int VoxelmanLibraryMerger::get_num_surfaces() {
	return _voxel_surfaces.size();
}

void VoxelmanLibraryMerger::clear_surfaces() {
	_packer->clear();

	for (int i = 0; i < _voxel_surfaces.size(); i++) {
		Ref<VoxelSurfaceMerger> surface = _voxel_surfaces[i];

		if (surface.is_valid()) {
			surface->set_library(NULL);
		}
	}

	_voxel_surfaces.clear();

	for (int i = 0; i < _liquid_surfaces.size(); i++) {
		Ref<VoxelSurfaceMerger> surface = _liquid_surfaces[i];

		if (surface.is_valid()) {
			surface->set_library(NULL);
		}
	}

	_liquid_surfaces.clear();
}

Vector<Variant> VoxelmanLibraryMerger::get_voxel_surfaces() {
	Vector<Variant> r;
	for (int i = 0; i < _voxel_surfaces.size(); i++) {
		r.push_back(_voxel_surfaces[i].get_ref_ptr());
	}
	return r;
}

void VoxelmanLibraryMerger::set_voxel_surfaces(const Vector<Variant> &surfaces) {
	_voxel_surfaces.clear();

	for (int i = 0; i < surfaces.size(); i++) {
		Ref<VoxelSurfaceMerger> surface = Ref<VoxelSurfaceMerger>(surfaces[i]);

		if (surface.is_valid()) {
			surface->set_library(this);
		}

		_voxel_surfaces.push_back(surface);
	}
}

//Liquids
Ref<VoxelSurface> VoxelmanLibraryMerger::get_liquid_voxel_surface(int index) const {
	ERR_FAIL_INDEX_V(index, _liquid_surfaces.size(), Ref<VoxelSurface>(NULL));

	return _liquid_surfaces[index];
}

void VoxelmanLibraryMerger::add_liquid_voxel_surface(Ref<VoxelSurface> value) {
	ERR_FAIL_COND(!value.is_valid());

	value->set_library(Ref<VoxelmanLibraryMerger>(this));
	value->set_id(_liquid_surfaces.size());

	_liquid_surfaces.push_back(value);
}

void VoxelmanLibraryMerger::set_liquid_voxel_surface(int index, Ref<VoxelSurface> value) {
	ERR_FAIL_COND(index < 0);

	if (_liquid_surfaces.size() < index) {
		_liquid_surfaces.resize(index + 1);
	}

	if (_liquid_surfaces[index].is_valid()) {
		_liquid_surfaces.get(index)->set_library(Ref<VoxelmanLibraryMerger>(NULL));
	}

	if (value.is_valid()) {
		value->set_library(Ref<VoxelmanLibraryMerger>(this));

		_liquid_surfaces.set(index, value);
	}
}

void VoxelmanLibraryMerger::remove_liquid_surface(int index) {
	_liquid_surfaces.remove(index);
}

int VoxelmanLibraryMerger::get_liquid_num_surfaces() {
	return _liquid_surfaces.size();
}

void VoxelmanLibraryMerger::clear_liquid_surfaces() {
	_packer->clear();

	for (int i = 0; i < _liquid_surfaces.size(); i++) {
		Ref<VoxelSurfaceMerger> surface = _liquid_surfaces[i];

		if (surface.is_valid()) {
			surface->set_library(NULL);
		}
	}

	_liquid_surfaces.clear();
}

Vector<Variant> VoxelmanLibraryMerger::get_liquid_voxel_surfaces() {
	Vector<Variant> r;
	for (int i = 0; i < _liquid_surfaces.size(); i++) {
		r.push_back(_liquid_surfaces[i].get_ref_ptr());
	}
	return r;
}

void VoxelmanLibraryMerger::set_liquid_voxel_surfaces(const Vector<Variant> &surfaces) {
	_liquid_surfaces.clear();

	for (int i = 0; i < surfaces.size(); i++) {
		Ref<VoxelSurfaceMerger> surface = Ref<VoxelSurfaceMerger>(surfaces[i]);

		if (surface.is_valid()) {
			surface->set_library(this);
		}

		_liquid_surfaces.push_back(surface);
	}
}

void VoxelmanLibraryMerger::refresh_rects() {
	bool texture_added = false;
	for (int i = 0; i < _voxel_surfaces.size(); i++) {
		Ref<VoxelSurfaceMerger> surface = Ref<VoxelSurfaceMerger>(_voxel_surfaces[i]);

		if (surface.is_valid()) {
			for (int j = 0; j < VoxelSurface::VOXEL_SIDES_COUNT; ++j) {
				Ref<Texture> tex = surface->get_texture(static_cast<VoxelSurface::VoxelSurfaceSides>(j));

				if (!tex.is_valid())
					continue;

				if (!_packer->contains_texture(tex)) {
					texture_added = true;
					surface->set_region(static_cast<VoxelSurface::VoxelSurfaceSides>(j), _packer->add_texture(tex));
				} else {
					surface->set_region(static_cast<VoxelSurface::VoxelSurfaceSides>(j), _packer->get_texture(tex));
				}
			}

			Ref<GroundClutter> gc = surface->get_clutter();

			if (gc.is_valid()) {
				gc->add_textures_to(_packer);
			}
		}
	}

	for (int i = 0; i < _liquid_surfaces.size(); i++) {
		Ref<VoxelSurfaceMerger> surface = Ref<VoxelSurfaceMerger>(_liquid_surfaces[i]);

		if (surface.is_valid()) {
			for (int j = 0; j < VoxelSurface::VOXEL_SIDES_COUNT; ++j) {
				Ref<Texture> tex = surface->get_texture(static_cast<VoxelSurface::VoxelSurfaceSides>(j));

				if (!tex.is_valid())
					continue;

				if (!_packer->contains_texture(tex)) {
					texture_added = true;
					surface->set_region(static_cast<VoxelSurface::VoxelSurfaceSides>(j), _packer->add_texture(tex));
				} else {
					surface->set_region(static_cast<VoxelSurface::VoxelSurfaceSides>(j), _packer->get_texture(tex));
				}
			}
		}
	}

	if (texture_added) {
		_packer->merge();

		ERR_FAIL_COND(_packer->get_texture_count() == 0);

		Ref<Texture> tex = _packer->get_generated_texture(0);

		setup_material_albedo(MATERIAL_INDEX_VOXELS, tex);
	}

	for (int i = 0; i < _voxel_surfaces.size(); i++) {
		Ref<VoxelSurfaceMerger> surface = _voxel_surfaces[i];

		if (surface.is_valid()) {
			surface->refresh_rects();
		}
	}

	for (int i = 0; i < _liquid_surfaces.size(); i++) {
		Ref<VoxelSurfaceMerger> surface = _liquid_surfaces[i];

		if (surface.is_valid()) {
			surface->refresh_rects();
		}
	}
}

void VoxelmanLibraryMerger::_setup_material_albedo(int material_index, Ref<Texture> texture) {
	Ref<SpatialMaterial> mat;

	switch (material_index) {
		case MATERIAL_INDEX_VOXELS:
			mat = get_material();
			break;
		case MATERIAL_INDEX_PROP:
			mat = get_prop_material();
			break;
		case MATERIAL_INDEX_LIQUID:
			mat = get_liquid_material();
			break;
		case MATERIAL_INDEX_CLUTTER:
			mat = get_clutter_material();
			break;
	}

	Ref<SpatialMaterial> spmat;

	if (spmat.is_valid()) {
		spmat->set_texture(SpatialMaterial::TEXTURE_ALBEDO, texture);
	}

	Ref<ShaderMaterial> shmat = get_material();

	if (shmat.is_valid()) {
		shmat->set_shader_param("texture_albedo", texture);
	}
}

VoxelmanLibraryMerger::VoxelmanLibraryMerger() {
	_packer.instance();
	_packer->set_texture_flags(Texture::FLAG_MIPMAPS | Texture::FLAG_FILTER);
	_packer->set_max_atlas_size(1024);
	_packer->set_keep_original_atlases(false);
	_packer->set_margin(0);
}

VoxelmanLibraryMerger::~VoxelmanLibraryMerger() {
	for (int i = 0; i < _voxel_surfaces.size(); ++i) {
		Ref<VoxelSurface> surface = _voxel_surfaces[i];

		if (surface.is_valid()) {
			surface->set_library(Ref<VoxelmanLibraryMerger>());
		}
	}

	_voxel_surfaces.clear();

	for (int i = 0; i < _liquid_surfaces.size(); ++i) {
		Ref<VoxelSurface> surface = _liquid_surfaces[i];

		if (surface.is_valid()) {
			surface->set_library(Ref<VoxelmanLibraryMerger>());
		}
	}

	_liquid_surfaces.clear();

	_packer->clear();
	_packer.unref();
}

void VoxelmanLibraryMerger::_bind_methods() {
	ClassDB::bind_method(D_METHOD("get_texture_flags"), &VoxelmanLibraryMerger::get_texture_flags);
	ClassDB::bind_method(D_METHOD("set_texture_flags", "flags"), &VoxelmanLibraryMerger::set_texture_flags);
	ADD_PROPERTY(PropertyInfo(Variant::INT, "texture_flags", PROPERTY_HINT_FLAGS, "Mipmaps,Repeat,Filter,Anisotropic Linear,Convert to Linear,Mirrored Repeat,Video Surface"), "set_texture_flags", "get_texture_flags");

	ClassDB::bind_method(D_METHOD("get_max_atlas_size"), &VoxelmanLibraryMerger::get_max_atlas_size);
	ClassDB::bind_method(D_METHOD("set_max_atlas_size", "size"), &VoxelmanLibraryMerger::set_max_atlas_size);
	ADD_PROPERTY(PropertyInfo(Variant::INT, "max_atlas_size"), "set_max_atlas_size", "get_max_atlas_size");

	ClassDB::bind_method(D_METHOD("get_keep_original_atlases"), &VoxelmanLibraryMerger::get_keep_original_atlases);
	ClassDB::bind_method(D_METHOD("set_keep_original_atlases", "value"), &VoxelmanLibraryMerger::set_keep_original_atlases);
	ADD_PROPERTY(PropertyInfo(Variant::BOOL, "keep_original_atlases"), "set_keep_original_atlases", "get_keep_original_atlases");

	ClassDB::bind_method(D_METHOD("get_background_color"), &VoxelmanLibraryMerger::get_background_color);
	ClassDB::bind_method(D_METHOD("set_background_color", "color"), &VoxelmanLibraryMerger::set_background_color);
	ADD_PROPERTY(PropertyInfo(Variant::COLOR, "background_color"), "set_background_color", "get_background_color");

	ClassDB::bind_method(D_METHOD("get_margin"), &VoxelmanLibraryMerger::get_margin);
	ClassDB::bind_method(D_METHOD("set_margin", "size"), &VoxelmanLibraryMerger::set_margin);
	ADD_PROPERTY(PropertyInfo(Variant::INT, "margin"), "set_margin", "get_margin");

	ClassDB::bind_method(D_METHOD("get_voxel_surfaces"), &VoxelmanLibraryMerger::get_voxel_surfaces);
	ClassDB::bind_method(D_METHOD("set_voxel_surfaces"), &VoxelmanLibraryMerger::set_voxel_surfaces);
	ADD_PROPERTY(PropertyInfo(Variant::ARRAY, "voxel_surfaces", PROPERTY_HINT_NONE, "17/17:VoxelSurfaceMerger", PROPERTY_USAGE_DEFAULT, "VoxelSurfaceMerger"), "set_voxel_surfaces", "get_voxel_surfaces");

	ClassDB::bind_method(D_METHOD("get_liquid_voxel_surfaces"), &VoxelmanLibraryMerger::get_liquid_voxel_surfaces);
	ClassDB::bind_method(D_METHOD("set_liquid_voxel_surfaces"), &VoxelmanLibraryMerger::set_liquid_voxel_surfaces);
	ADD_PROPERTY(PropertyInfo(Variant::ARRAY, "liquid_voxel_surfaces", PROPERTY_HINT_NONE, "17/17:VoxelSurfaceMerger", PROPERTY_USAGE_DEFAULT, "VoxelSurfaceMerger"), "set_liquid_voxel_surfaces", "get_liquid_voxel_surfaces");

	ClassDB::bind_method(D_METHOD("_setup_material_albedo", "material_index", "texture"), &VoxelmanLibraryMerger::_setup_material_albedo);
}
