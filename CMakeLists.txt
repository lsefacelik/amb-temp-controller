cmake_minimum_required(VERSION 3.14)
project(amb-temp-controller)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>")

enable_testing()

include_directories(src)
add_subdirectory(src)
add_subdirectory(test)
#add_subdirectory(lib)

