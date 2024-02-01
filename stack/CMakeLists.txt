cmake_minimum_required(VERSION 3.5)

project(Module12)

set (SOURCE_LIST main.cpp stackarray.cpp stacklinkedlist.cpp stacklinkedlisttop.cpp)
set (HEADER_LIST stackarray.h stacklinkedlist.h node.h stacklinkedlisttop.h)

set (CXX_FLAGS "${CXX_FLAGS} -std=c++11 - Wall")

add_executable(stack ${SOURCE_LIST} ${HEADER_LIST})
