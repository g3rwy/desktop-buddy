extern "C" {
  #include <stdio.h>
  #include <string.h>

  #if defined (_WIN32) || defined (_WIN64)
  #define TRAY_WINAPI 1
  #elif defined (__linux__) || defined (linux) || defined (__linux)
  #define TRAY_APPINDICATOR 1
  #elif defined (__APPLE__) || defined (__MACH__)
  #define TRAY_APPKIT 1
  #endif

  #include "tray_repo/tray.h"

  #if TRAY_APPINDICATOR
  // #define TRAY_ICON1 "mail-message-new"
  #define TRAY_ICON1 "face-monkey"
  #define TRAY_ICON2 "mail-message-new"
  #elif TRAY_APPKIT
  #define TRAY_ICON1 "icon.png"
  #define TRAY_ICON2 "icon.png"
  #elif TRAY_WINAPI
  #define TRAY_ICON1 "icon.ico"
  #define TRAY_ICON2 "icon.ico"
  #endif


  static void toggle_cb(struct tray_menu *item);
  static void show_cb(struct tray_menu *item);
  static void submenu_cb(struct tray_menu *item);
  static void quit_cb(struct tray_menu *item);

  static struct tray tray = {
      .icon = TRAY_ICON1,
  #if TRAY_WINAPI
      .tooltip = "Virtual Pet",
  #endif
       .menu =
              (struct tray_menu[]) {
                  {.text = "Show", .cb = show_cb},
                  {.text = "Checked", .checked = 1, .checkbox = 1, .cb = toggle_cb},
                  {.text = "Disabled", .disabled = 1},
                  {.text = "-"},
                  {.text = "Quit", .cb = quit_cb},
                  {.text = NULL}},
      };
}

#include <godot_cpp/classes/display_server.hpp>

using namespace godot;
extern "C" void show_cb(struct tray_menu *item) {
  (void)item;
  auto display_server = DisplayServer::get_singleton();
  display_server->window_set_mode(DisplayServer::WINDOW_MODE_WINDOWED,0);
  tray_update(&tray);
}

extern "C" {
  static void toggle_cb(struct tray_menu *item) {
    printf("toggle cb\n");
    item->checked = !item->checked;
    tray_update(&tray);
  }

  static void quit_cb(struct tray_menu *item) {
    (void)item;
    printf("quit cb\n");
    tray_exit();
  }

  static void submenu_cb(struct tray_menu *item) {
    (void)item;
    printf("submenu: clicked on %s\n", item->text);
    tray_update(&tray);
  }

}