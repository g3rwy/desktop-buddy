#!/usr/bin/env python
import os
import sys

env = SConscript("godot-cpp/SConstruct")

# For the reference:
# - CCFLAGS are compilation flags shared between C and C++
# - CFLAGS are for C-specific compilation flags
# - CXXFLAGS are for C++-specific compilation flags
# - CPPFLAGS are for pre-processor flags
# - CPPDEFINES are for pre-processor defines
# - LINKFLAGS are for linking flags

# Compile tray library for specific platform
# c++ -DTRAY_APPINDICATOR=1 
# -I/usr/include/libayatana-appindicator3-0.1 -I/usr/include/libayatana-indicator3-0.4 -I/usr/include/gtk-3.0 -I/usr/include/pango-1.0 -I/usr/include/glib-2.0 -I/usr/lib/glib-2.0/include -I/usr/include/sysprof-4 -I/usr/include/harfbuzz -I/usr/include/freetype2 -I/usr/include/libpng16 -I/usr/include/libmount -I/usr/include/blkid -I/usr/include/fribidi -I/usr/include/cairo -I/usr/include/pixman-1 -I/usr/include/gdk-pixbuf-2.0 -I/usr/include/gio-unix-2.0 -I/usr/include/cloudproviders -I/usr/include/atk-1.0 -I/usr/include/at-spi2-atk/2.0 -I/usr/include/at-spi-2.0 -I/usr/include/dbus-1.0 -I/usr/lib/dbus-1.0/include -I/usr/include/libayatana-ido3-0.4 -I/usr/include/libdbusmenu-glib-0.4 -pthread -o tray_linux.c.o 
# -c src/tray_repo/tray_linux.c

# Make a static library
# rm -f libtray.a && ar qc libtray.a tray_linux.c.o && ranlib libtray.a

# Compile the program and link required libraries
# c++ example.c.o -o desktop_buddy libtray.a -layatana-appindicator3  -layatana-indicator3  -layatana-ido3-0.4  -ldbusmenu-glib  -lgtk-3  -lgdk-3  -lz  -lpangocairo-1.0  -lpango-1.0  -lharfbuzz  -latk-1.0  -lcairo-gobject  -lcairo  -lgdk_pixbuf-2.0  -lgio-2.0  -lgobject-2.0  -lglib-2.0 -lfltk_images -ljpeg -lpng -lz -lfltk_gl -lGLU -lGL -lfltk_forms -lfltk -lm -lX11 -lXext -lpthread -lXinerama -lXfixes -lXcursor -lXft -lXrender -lm -lfontconfig -ldl

# TODO make an if statement later to compile for different platforms
tray_env = Environment()
libtray = tray_env.StaticLibrary(target="game/bin/libtray{}".format(env["SHLIBSUFFIX"]) ,source="extension/src/tray_repo/tray_linux.c",
     CPPDEFINES="-DTRAY_APPINDICATOR=1",
     CFLAGS="-I/usr/include/libayatana-appindicator3-0.1 -I/usr/include/libayatana-indicator3-0.4 -I/usr/include/gtk-3.0 -I/usr/include/pango-1.0 -I/usr/include/glib-2.0 -I/usr/lib/glib-2.0/include -I/usr/include/sysprof-4 -I/usr/include/harfbuzz -I/usr/include/freetype2 -I/usr/include/libpng16 -I/usr/include/libmount -I/usr/include/blkid -I/usr/include/fribidi -I/usr/include/cairo -I/usr/include/pixman-1 -I/usr/include/gdk-pixbuf-2.0 -I/usr/include/gio-unix-2.0 -I/usr/include/cloudproviders -I/usr/include/atk-1.0 -I/usr/include/at-spi2-atk/2.0 -I/usr/include/at-spi-2.0 -I/usr/include/dbus-1.0 -I/usr/lib/dbus-1.0/include -I/usr/include/libayatana-ido3-0.4 -I/usr/include/libdbusmenu-glib-0.4 -pthread")


env.Append(CPPPATH=["extension/src/"],LIBS=["$LIBS","libtray"], LIBPATH=["$LIBPATH","game/bin/"])
sources = Glob("extension/src/*.cpp")

if env["platform"] == "macos":
    library = env.SharedLibrary(
        "game/bin/libgdvirtualpet.{}.{}.framework/libgdvirtualpet.{}.{}".format(
            env["platform"], env["target"], env["platform"], env["target"]
        ),
        source=sources,
    )
else:
    library = env.SharedLibrary(
        "game/bin/libgdvirtualpet{}{}".format(env["suffix"], env["SHLIBSUFFIX"]),
        source=sources, LINKFLAGS="-layatana-appindicator3  -layatana-indicator3  -layatana-ido3-0.4  -ldbusmenu-glib  -lgtk-3  -lgdk-3  -lz  -lpangocairo-1.0  -lpango-1.0  -lharfbuzz  -latk-1.0  -lcairo-gobject  -lcairo  -lgdk_pixbuf-2.0  -lgio-2.0  -lgobject-2.0  -lglib-2.0"
    )

Default(libtray, library)
