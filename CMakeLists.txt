cmake_minimum_required(VERSION 3.22.1)

project(NomeProjeto)

include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)

conan_basic_setup()

add_executable(main main.cpp)

target_link_libraries(main ${CONAN_LIBS})