/* register_types.cpp */

#include "register_types.h"

#include "core/object/class_db.h"
#include "llama2.h"

void initialize_llama2_module(ModuleInitializationLevel p_level) {
    if (p_level != MODULE_INITIALIZATION_LEVEL_SCENE) {
            return;
    }
    ClassDB::register_class<Llama2>();
}

void uninitialize_llama2_module(ModuleInitializationLevel p_level) {
    if (p_level != MODULE_INITIALIZATION_LEVEL_SCENE) {
            return;
    }

}