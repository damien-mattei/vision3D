# file: CMakeLists.txt
# use with: cmake -S . -B ./build
# cd build
# make or make VERBOSE=1

cmake_minimum_required(VERSION 3.22.0)

project(vision3D)

add_executable(${PROJECT_NAME}
Panorama.cpp Point2D.cpp Point3D.cpp Edge2D.cpp Edge3D.cpp Vector3D.cpp Matrix3x3.cpp Face3D.cpp Object.cpp ObjFile.cpp Universe.cpp Vision3D.cpp  main.cpp
)

set_target_properties(${PROJECT_NAME} PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/.."
)

target_compile_options(${PROJECT_NAME} PRIVATE
    -std=c++17
)

#add_compile_options(-std=c++17)

add_definitions(-DDEBUG_BUILD -DDISPLAY_CONSTRUCTOR -DCHECK_MEMORY)

# only for Mac OS buggy system that do not have directory in system
# path include
if (${CMAKE_SYSTEM_NAME} MATCHES "Darwin")
    target_include_directories(${PROJECT_NAME} PRIVATE
         /opt/homebrew/Cellar/boost/1.90.0/include) 
endif()


