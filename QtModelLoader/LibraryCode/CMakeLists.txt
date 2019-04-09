cmake_minimum_required(VERSION 3.3 FATAL_ERROR)

set(CMAKE_CXX_STANDARD 17)

PROJECT( ModelLib )
include(CTest)

add_library( ModelLib
				Model.cpp
				Model.h
				Cell.cpp
				Cell.h
				Vertex.cpp
				Vertex.h
				Material.cpp
				Material.h)
				
add_executable( ModelLibTest catchTest.cpp codeTest.cpp)
target_link_libraries (ModelLibTest ModelLib)

add_test(ModelLibTest ModelLibTest)
