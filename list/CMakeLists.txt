cmake_minimum_required(VERSION 3.5)

project(Module12)

set (SRC_LIST main.cpp linkedlist.cpp)
set (HEAD_LST linkedlist.h node.h)
set (CXX_FLAGS "${CXX_FLAGS} -std=c++11 - Wall")

add_executable(linkedlist ${SRC_LIST} ${HEAD_LST})



