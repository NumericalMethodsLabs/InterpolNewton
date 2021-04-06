cmake_minimum_required(VERSION 3.17)
project(InterpolNewton)

set(CMAKE_CXX_STANDARD 17)

add_library(${PROJECT_NAME} InterpolNewton.cpp InterpolNewton.h)