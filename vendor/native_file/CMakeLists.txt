cmake_minimum_required(VERSION 3.15)

project(nativefiledialog LANGUAGES C CXX)

set(NFD_COMMON_SRC
        src/nfd_common.c
)

if(WIN32)
    list(APPEND NFD_COMMON_SRC src/nfd_win.cpp)
elseif(APPLE)
    list(APPEND NFD_COMMON_SRC src/nfd_cocoa.m)
    set_source_files_properties(src/nfd_cocoa.m PROPERTIES LANGUAGE C)
elseif(UNIX)
    list(APPEND NFD_COMMON_SRC src/nfd_gtk.c)
endif()

add_library(nfd STATIC ${NFD_COMMON_SRC})

target_include_directories(nfd PUBLIC src/include)

if(UNIX AND NOT APPLE)
    find_package(PkgConfig REQUIRED)
    pkg_check_modules(GTK REQUIRED gtk+-3.0)

    target_include_directories(nfd PRIVATE ${GTK_INCLUDE_DIRS})
    target_link_libraries(nfd PRIVATE ${GTK_LIBRARIES})
endif()
