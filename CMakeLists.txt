cmake_minimum_required(VERSION 3.19)
project(APINationalizeio)

set(CMAKE_CXX_STANDARD 20)

add_executable(APINationalizeio main.cpp Data/GetContent.cpp Data/GetContent.hpp Vue.cpp Vue.hpp Controller.cpp Controller.hpp)