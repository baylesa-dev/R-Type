project(r-type)
cmake_minimum_required(VERSION 2.6)

add_definitions("--std=c++11")

include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup()

add_subdirectory(Binge)

get_property(BINGE_INCS GLOBAL PROPERTY BINGE_BINGE_INCS)

include_directories(${BINGE_INCS})

get_property(BINGE_NETWORK_INCS GLOBAL PROPERTY BINGE_BINGE_NETWORK_INCS)
include_directories(${BINGE_NETWORK_INCS})

set(COMMON_SRCS
)

set(CLIENT_SRCS
    ./src/client/main.cpp
)

add_executable(r-type_client ${CLIENT_SRCS})
target_link_libraries(r-type_client Binge ${CONAN_LIBS})

set(SERVER_SRCS
    ./src/server/main.cpp
)

add_executable(r-type_server ${SERVER_SRCS})

target_link_libraries(r-type_server Binge BingeNetwork ${CONAN_LIBS})
