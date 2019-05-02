cmake_minimum_required(VERSION 2.6)

add_definitions("--std=c++11")

include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup()

set(BINGE_INCS ${CMAKE_CURRENT_SOURCE_DIR}/src )
set(BINGE_INCS ${BINGE_INCS} GLOBAL)

set_property(GLOBAL PROPERTY BINGE_BINGE_INCS ${BINGE_INCS})

set(BINGE_SRCS
    ./src/Binge/Binge.cpp
    ./src/Binge/BingeException.cpp
)

add_library(BINGE_OBJS OBJECT ${BINGE_SRCS})

set_property(TARGET BINGE_OBJS PROPERTY POSITION_INDEPENDENT_CODE 1)

add_library(Binge SHARED $<TARGET_OBJECTS:BINGE_OBJS>)
add_library(Binge_static STATIC $<TARGET_OBJECTS:BINGE_OBJS>)

target_link_libraries(Binge ${CONAN_LIBS})
target_link_libraries(Binge_static ${CONAN_LIBS})
