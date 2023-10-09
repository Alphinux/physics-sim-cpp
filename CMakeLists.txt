cmake_minimum_required(VERSION 3.0.0)
project(oreid VERSION 0.1.0 LANGUAGES C CXX)

include(CTest)
enable_testing()

add_executable(oreid main.cpp)

# Include SDL2 headers from MinGW-w64's directory
include_directories(${CMAKE_PREFIX_PATH}/include/raylib)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)

target_link_libraries(oreid ${CMAKE_PREFIX_PATH}/lib/libraylib.a winmm)