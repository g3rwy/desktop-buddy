#include <gtkmm-4.0/gtkmm.h>
#include "Pet.h"

class MyApp : public Gtk::Window
{
protected:
    Gtk::Frame pet_frame;
    Gtk::Box indicators;
    Gtk::ProgressBar health;
    Pet main_pet;
public:
    MyApp();
};

MyApp::MyApp()
{
  set_title("Buddy - TEST");
  set_default_size(200, 200);

  pet_frame.set_margin(10);
  set_child(pet_frame);
  pet_frame.set_label("Tuxy");
  pet_frame.set_label_align(Gtk::Align::CENTER);

  health.set_text("Health");
  health.set_show_text(true);
  health.set_fraction(0.4);

  indicators.append(health);
  pet_frame.set_child(indicators);
}

int main(int argc, char* argv[])
{
  auto app = Gtk::Application::create("org.desktop_buddy.capy");
  return app->make_window_and_run<MyApp>(argc, argv);
}