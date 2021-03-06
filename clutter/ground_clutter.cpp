#include "ground_clutter.h"

#include "../world/voxel_chunk.h"

bool GroundClutter::should_spawn(VoxelChunk *chunk, int x, int y, int z) {
	if (has_method("_should_spawn"))
		return call("_should_spawn", chunk, x, y, z);

	return false;
}
bool GroundClutter::should_spawn_bind(Node *chunk, int x, int y, int z) {
	VoxelChunk *c = Object::cast_to<VoxelChunk>(chunk);

	ERR_FAIL_COND_V(!ObjectDB::instance_validate(c), false);

	return should_spawn(c, x, y, z);
}

void GroundClutter::add_meshes_to(Ref<VoxelMesher> mesher, VoxelChunk *chunk, int x, int y, int z) {
	if (has_method("_add_meshes_to"))
		call("_add_meshes_to", mesher, chunk, x, y, z);
}
void GroundClutter::add_meshes_to_bind(Ref<VoxelMesher> mesher, Node *chunk, int x, int y, int z) {
	VoxelChunk *c = Object::cast_to<VoxelChunk>(chunk);

	ERR_FAIL_COND(!ObjectDB::instance_validate(c));

	add_meshes_to(mesher, c, x, y, z);
}

void GroundClutter::add_textures_to(Ref<TexturePacker> packer) {
	if (has_method("_add_textures_to"))
		call("_add_textures_to", packer);
}

GroundClutter::GroundClutter() {
}

GroundClutter::~GroundClutter() {
}

void GroundClutter::_bind_methods() {
	BIND_VMETHOD(MethodInfo(PropertyInfo(Variant::BOOL, "should"), "_should_spawn", PropertyInfo(Variant::OBJECT, "chunk", PROPERTY_HINT_RESOURCE_TYPE, "VoxelChunk"), PropertyInfo(Variant::INT, "x"), PropertyInfo(Variant::INT, "y"), PropertyInfo(Variant::INT, "z")));
	BIND_VMETHOD(MethodInfo("_add_meshes_to", PropertyInfo(Variant::OBJECT, "mesher", PROPERTY_HINT_RESOURCE_TYPE, "VoxelMesher"), PropertyInfo(Variant::OBJECT, "chunk", PROPERTY_HINT_RESOURCE_TYPE, "VoxelChunk"), PropertyInfo(Variant::INT, "x"), PropertyInfo(Variant::INT, "y"), PropertyInfo(Variant::INT, "z")));
	BIND_VMETHOD(MethodInfo("_add_textures_to", PropertyInfo(Variant::OBJECT, "packer", PROPERTY_HINT_RESOURCE_TYPE, "TexturePacker")));

	ClassDB::bind_method(D_METHOD("should_spawn", "chunk", "x", "y", "z"), &GroundClutter::should_spawn_bind);
	ClassDB::bind_method(D_METHOD("add_meshes_to", "mesher", "chunk", "x", "y", "z"), &GroundClutter::add_meshes_to_bind);
	ClassDB::bind_method(D_METHOD("add_textures_to", "packer"), &GroundClutter::add_textures_to);
}
