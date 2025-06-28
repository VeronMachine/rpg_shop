cmake_minimum_required(VERSION 3.20)

project(rpgshop
    LANGUAGES CXX
)

file(GLOB_RECURSE sources CONFIGURE_DEPENDS code/*.cpp)

add_executable(${CMAKE_PROJECT_NAME} ${sources})
target_include_directories(${CMAKE_PROJECT_NAME} PUBLIC code/)
set_target_properties(${CMAKE_PROJECT_NAME} PROPERTIES
    CXX_STANDARD 20
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin/
)