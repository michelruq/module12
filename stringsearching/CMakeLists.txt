cmake_minimum_required(VERSION 3.5)

project(Module12)

add_executable(stringsearching 
                main.cpp 
				./bruteforce/bruteforce.cpp 
				./knuthmorrispratt/knuthmorrispratt.cpp
				./boyermoore/boyermoore.cpp)

include_directories(
                ./bruteforce 
				./knuthmorrispratt
				./boyermoore)

set_target_properties(
    stringsearching PROPERTIES
    CXX_STANDARD 11
    CXX_STANDARD_REQUIRED ON
)