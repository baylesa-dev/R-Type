cmake_minimum_required(VERSION 2.6)

add_definitions("--std=c++11")

include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup()

set(BINGE_PHYSICS_INCS ${CMAKE_CURRENT_SOURCE_DIR}/src )
set(BINGE_PHYSICS_INCS ${BINGE_PHYSICS_INCS} GLOBAL)
set_property(GLOBAL PROPERTY BINGE_BINGE_PHYSICS_INCS ${BINGE_PHYSICS_INCS})

set(BINGE_PHYSICS_SRCS
    ./src/BingePhysics/Physics.cpp
)

add_library(BINGE_PHYSICS_OBJS OBJECT ${BINGE_PHYSICS_SRCS})

set_property(TARGET BINGE_PHYSICS_OBJS PROPERTY POSITION_INDEPENDENT_CODE 1)

add_library(BingePhysics SHARED $<TARGET_OBJECTS:BINGE_PHYSICS_OBJS>)
add_library(BingePhysics_static STATIC $<TARGET_OBJECTS:BINGE_PHYSICS_OBJS>)

target_link_libraries(BingePhysics ${CONAN_LIBS})
target_link_libraries(BingePhysics_static ${CONAN_LIBS})
