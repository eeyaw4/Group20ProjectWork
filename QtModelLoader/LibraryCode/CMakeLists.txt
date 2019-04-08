cmake_minimum_required(VERSION 3.3 FATAL_ERROR)

PROJECT( ModelLib )

add_library( ModelLib
				Model.cpp
				Model.h
				Cell.cpp
				Cell.h
				Vertex.cpp
				Vertex.h
				Material.cpp
				Material.h)