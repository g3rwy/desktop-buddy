#include "virtualPet.h"

#include "tray_src.h"

#include <godot_cpp/core/class_db.hpp>
#include <godot_cpp/variant/utility_functions.hpp>
#include <memory>

using namespace godot;

void VirtualPet::_start_tray(){
    UtilityFunctions::print("Started a thread successfully");

    if (tray_init(&tray) < 0) {
      fprintf( stderr, "Failed to create tray");
      UtilityFunctions::print("failed to create tray\n");
      return;
    }

    while (tray_loop(1) == 0 && !stop_tray) {}


    UtilityFunctions::print("Oh okay so i should stop");
    stop_tray = true;
    // TODO Signal to main thread to exit
    emit_signal("close_window");
    return;
}

void VirtualPet::set_stop_tray(bool val){
    this->stop_tray = val;
}

bool VirtualPet::get_stop_tray(){
    return this->stop_tray.load();
}

VirtualPet::VirtualPet()
{
    this->stop_tray = false;
}

VirtualPet::~VirtualPet()
{
    fprintf( stderr, "Stopped thread object");
    this->stop_tray = true;
    UtilityFunctions::print("Stopped thread object");
}

void VirtualPet::_bind_methods()
{
    ClassDB::bind_method(D_METHOD("_start_tray"), &VirtualPet::_start_tray);

    ADD_GROUP("Some group", "group_");

    ClassDB::bind_method(D_METHOD("set_stop_tray","val"), &VirtualPet::set_stop_tray);
    ClassDB::bind_method(D_METHOD("get_stop_tray"), &VirtualPet::get_stop_tray);
    ADD_PROPERTY(PropertyInfo( Variant::BOOL, "group_atomic" ), "set_stop_tray", "get_stop_tray");
    ADD_SIGNAL(MethodInfo("close_window"));
}
