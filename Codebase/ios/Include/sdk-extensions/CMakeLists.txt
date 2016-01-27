cmake_minimum_required(VERSION 3.1)

# TODO: Add support for Windows, Android, iOS
# TODO2: consider creating a common macros cmake file to be included when needed 
#
# Macros:
#
# list_header_directories (BASE_DIR RETURN_LIST)
#  A macro that populates a list of paths with header files under a certain directory
#  Usefull when wanting sdk headers accessible for other libraries
#  Modified from https://cmake.org/pipermail/cmake/2012-June/050674.html  
#

# This macro populates a list of paths with header files under a certain directory
# Modified from https://cmake.org/pipermail/cmake/2012-June/050674.html
macro (list_header_directories base_dir return_list)
	file (GLOB_RECURSE new_list ${base_dir}/*.[h|hpp])
	set (dir_list "")
	foreach (file_path ${new_list})
     	get_filename_component (dir_path ${file_path} PATH)
	   	set(dir_list ${dir_list} ${dir_path})
	endforeach()
	list (REMOVE_DUPLICATES dir_list)
 	set (${return_list} ${dir_list})
endmacro (list_header_directories)

project(sdk-extensions)

###############################################
##### OSX SPECIFIC COMPILE/LINK SETTINGS ######
###############################################

if(${OSX})
    set(CMAKE_OSX_ARCHITECTURES "x86;x86_64")
    set(OSX_WARNING_FLAGS "-Wmost -Werror -Wno-four-char-constants -Wno-unknown-pragmas -Wno-reorder")
    remove_ndebug_flag_from_release_build()

    if(${COMPILE_CPP_03})
        set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -x objective-c++ ${OSX_WARNING_FLAGS}")
    else(${COMPILE_CPP_03})
        set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -x objective-c++ -DCOMPILE_CPP_11 ${OSX_WARNING_FLAGS}")
    endif(${COMPILE_CPP_03})

    SET(CMAKE_EXE_LINKER_FLAGS
        "-framework CoreLocation -framework MobileCoreServices -framework SystemConfiguration -framework CFNetwork -framework GLKit -framework OpenGLES -framework UIKit -framework Foundation -framework CoreGraphics -framework CoreData -ljpeg -lpng -L/usr/lib/ -lz -lcurl -luv"
    )

endif(${OSX})

list_header_directories(../../platform sdk_headers)

include_directories(${sdk_headers})

###########################################
##### CREATE sdk-extensions-sqlite.a ######
###########################################

set(library_name sdk-extensions-sqlite)
include(sqlite/CMakeLists.txt)

add_library(${library_name} STATIC ${sources})
target_include_directories(${library_name} PUBLIC ${headers})

#########################################
##### XCODE (OSX) PROJECT SETTINGS ######
#########################################

if(${OSX})
    set_xcode_property (${library_name} GCC_TREAT_WARNINGS_AS_ERRORS "Yes")
    set_xcode_property (${library_name} ENABLE_BITCODE "No")

    if(${COMPILE_CPP_03})
        set_xcode_property(${library_name} CLANG_CXX_LANGUAGE_STANDARD "c++98")
        set_xcode_property(${library_name} CLANG_CXX_LIBRARY "libstdc++")
    else(${COMPILE_CPP_03})
        add_definitions(-DCOMPILE_CPP_11)
        set_xcode_property(${library_name} CLANG_CXX_LANGUAGE_STANDARD "c++11")
        set_xcode_property(${library_name} CLANG_CXX_LIBRARY "libc++")
    endif(${COMPILE_CPP_03})

    set_target_properties(${library_name}
                      PROPERTIES
                      XCODE_ATTRIBUTE_ONLY_ACTIVE_ARCH "YES"
    )
endif(${OSX})


