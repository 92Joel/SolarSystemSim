cmake_minimum_required (VERSION 2.6)

project (SolarSystem)
# Add source files in /src
file(GLOB SOURCES src/*.cpp)
# Set executable output dir
set(CMAKE_BINARY_DIR ${CMAKE_SOURCE_DIR}/bin)
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR})

set(CMAKE_CXX_STANDARD 11) # C++11...
include_directories(include) #Headers

add_executable(main.exe ${SOURCES})
