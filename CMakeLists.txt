cmake_minimum_required(VERSION 3.25)
project(desktop_buddy)

set(CMAKE_CXX_STANDARD 20)

find_package(PkgConfig REQUIRED)
pkg_check_modules(GTK4 REQUIRED gtkmm-4.0)

link_directories(${GTK4_LIBRARY_DIRS})
add_compile_options(${GTK4_CFLAGS_OTHER})
include_directories(${GTK4_INCLUDE_DIRS})

set(LIBRARIES ${LIBRARIES} ${GTK4_LIBRARIES})

set(FLAGS "-I${GTK4_INCLUDE_DIRS}")
set(CMAKE_C_FLAGS ${CMAKE_C_FLAGS} ${GTK4_FLAGS} ${FLAGS})

add_executable(desktop_buddy main.cpp Pet.cpp Pet.h)
target_link_libraries(desktop_buddy ${LIBRARIES})

