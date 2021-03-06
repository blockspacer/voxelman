#include "environment_data.h"

Ref<Environment> EnvironmentData::get_environment() {
	return _environment;
}
void EnvironmentData::set_environment(Ref<Environment> value) {
	_environment = value;
}

Color EnvironmentData::get_color(int index) {
	ERR_FAIL_INDEX_V(index, LIGHT_COUNT, Color());

	return _colors[index];
}
void EnvironmentData::set_color(int index, Color value) {
	ERR_FAIL_INDEX(index, LIGHT_COUNT);

	_colors[index] = value;
}
float EnvironmentData::get_energy(int index) {
	ERR_FAIL_INDEX_V(index, LIGHT_COUNT, 0);

	return _energies[index];
}
void EnvironmentData::set_energy(int index, float value) {
	ERR_FAIL_INDEX(index, LIGHT_COUNT);

	_energies[index] = value;
}
float EnvironmentData::get_indirect_energy(int index) {
	ERR_FAIL_INDEX_V(index, LIGHT_COUNT, 0);

	return _indirect_energies[index];
}
void EnvironmentData::set_indirect_energy(int index, float value) {
	ERR_FAIL_INDEX(index, LIGHT_COUNT);

	_indirect_energies[index] = value;
}

void EnvironmentData::setup(WorldEnvironment *world_environment, DirectionalLight *primary_light, DirectionalLight *secondary_light) {
	if (has_method("_setup"))
		call("_setup", world_environment, primary_light, secondary_light);
}
void EnvironmentData::setup_bind(Node *world_environment, Node *primary_light, Node *secondary_light) {
	setup(Object::cast_to<WorldEnvironment>(world_environment), Object::cast_to<DirectionalLight>(primary_light), Object::cast_to<DirectionalLight>(secondary_light));
}

EnvironmentData::EnvironmentData() {
	_colors[0] = Color(1, 1, 1, 1);
	_colors[1] = Color(1, 1, 1, 1);

	_energies[0] = 1;
	_energies[1] = 1;

	_indirect_energies[0] = 1;
	_indirect_energies[1] = 1;
}

EnvironmentData::~EnvironmentData() {
	_environment.unref();
}

void EnvironmentData::_bind_methods() {
	BIND_VMETHOD(MethodInfo("_setup", PropertyInfo(Variant::OBJECT, "world_environment", PROPERTY_HINT_RESOURCE_TYPE, "WorldEnvironment"), PropertyInfo(Variant::OBJECT, "primary_light", PROPERTY_HINT_RESOURCE_TYPE, "DirectionalLight"), PropertyInfo(Variant::OBJECT, "secondary_light", PROPERTY_HINT_RESOURCE_TYPE, "DirectionalLight")));

	ClassDB::bind_method(D_METHOD("get_environment"), &EnvironmentData::get_environment);
	ClassDB::bind_method(D_METHOD("set_environment", "value"), &EnvironmentData::set_environment);
	ADD_PROPERTY(PropertyInfo(Variant::OBJECT, "environment", PROPERTY_HINT_RESOURCE_TYPE, "Environment"), "set_environment", "get_environment");

	ClassDB::bind_method(D_METHOD("get_color", "index"), &EnvironmentData::get_color);
	ClassDB::bind_method(D_METHOD("set_color", "index", "value"), &EnvironmentData::set_color);

	ClassDB::bind_method(D_METHOD("get_energy", "index"), &EnvironmentData::get_energy);
	ClassDB::bind_method(D_METHOD("set_energy", "index", "value"), &EnvironmentData::set_energy);

	ClassDB::bind_method(D_METHOD("get_indirect_energy", "index"), &EnvironmentData::get_indirect_energy);
	ClassDB::bind_method(D_METHOD("set_indirect_energy", "index", "value"), &EnvironmentData::set_indirect_energy);

	ADD_PROPERTYI(PropertyInfo(Variant::COLOR, "primary_light_color"), "set_color", "get_color", 0);
	ADD_PROPERTYI(PropertyInfo(Variant::REAL, "primary_light_energy"), "set_energy", "get_energy", 0);
	ADD_PROPERTYI(PropertyInfo(Variant::REAL, "primary_light_indirect_energy"), "set_indirect_energy", "get_indirect_energy", 0);

	ADD_PROPERTYI(PropertyInfo(Variant::COLOR, "secondary_light_color"), "set_color", "get_color", 1);
	ADD_PROPERTYI(PropertyInfo(Variant::REAL, "secondary_light_energy"), "set_energy", "get_energy", 1);
	ADD_PROPERTYI(PropertyInfo(Variant::REAL, "secondary_light_indirect_energy"), "set_indirect_energy", "get_indirect_energy", 1);

	ClassDB::bind_method(D_METHOD("setup", "world_environment", "primary_light", "secondary_light"), &EnvironmentData::setup_bind);

	BIND_CONSTANT(LIGHT_COUNT);
}
