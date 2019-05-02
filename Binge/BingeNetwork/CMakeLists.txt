cmake_minimum_required(VERSION 2.6)

add_definitions("--std=c++11")

include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup()

set(BINGE_NETWORK_INCS ${CMAKE_CURRENT_SOURCE_DIR}/src )
set(BINGE_NETWORK_INCS ${BINGE_NETWORK_INCS} GLOBAL)

set_property(GLOBAL PROPERTY BINGE_BINGE_NETWORK_INCS ${BINGE_NETWORK_INCS})

get_property(BINGE_INCS GLOBAL PROPERTY BINGE_BINGE_INCS)
include_directories(${BINGE_INCS})

set(BINGE_NETWORK_SRCS
    ./src/BingeNetwork/Network.cpp
    ./src/BingeNetwork/NetworkException.cpp
)

add_library(BINGE_NETWORK_OBJS OBJECT ${BINGE_NETWORK_SRCS})

set_property(TARGET BINGE_NETWORK_OBJS PROPERTY POSITION_INDEPENDENT_CODE 1)

add_library(BingeNetwork SHARED $<TARGET_OBJECTS:BINGE_NETWORK_OBJS>)
add_library(BingeNetwork_static STATIC $<TARGET_OBJECTS:BINGE_NETWORK_OBJS>)

target_link_libraries(BingeNetwork Binge ${CONAN_LIBS})
target_link_libraries(BingeNetwork_static Binge ${CONAN_LIBS})
