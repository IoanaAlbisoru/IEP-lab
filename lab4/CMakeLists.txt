cmake_minimum_required(VERSION 2.8)
project(dog)
add_executable(dog main.cpp)
install(TARGETS dog DESTINATION bin)
