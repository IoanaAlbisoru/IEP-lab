cmake_minimum_required(VERSION 2.8)

project(testl_project)
add_library(testl STATIC testl.cpp)

install(TARGETS testl DESTINATION lib)
install(FILES testl.h DESTINATION include)