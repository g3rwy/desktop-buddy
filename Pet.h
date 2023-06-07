#ifndef DESKTOP_BUDDY_PET_H
#define DESKTOP_BUDDY_PET_H
#include <gtkmm-4.0/gtkmm.h>

class Pet {
public:
    Pet();

private:
    GString name;
    double health;
    double hunger;
    double bored;
};

#endif //DESKTOP_BUDDY_PET_H
