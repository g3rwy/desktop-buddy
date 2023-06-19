#ifndef VIRTUAL_PET_CLASS_H
#define VIRTUAL_PET_CLASS_H

#ifdef WIN32
#include <windows.h>
#endif

#include <godot_cpp/classes/ref.hpp>
#include <godot_cpp/variant/variant.hpp>

#include <atomic>

using namespace godot;

class VirtualPet : public RefCounted
{
    GDCLASS(VirtualPet, RefCounted);

protected:
    static void _bind_methods();


public:
    std::atomic<bool> stop_tray;
    void set_stop_tray(bool val);
    bool get_stop_tray();

    void _start_tray();
    VirtualPet();
    ~VirtualPet();
};

#endif // VIRTUAL_PET_CLASS_H
