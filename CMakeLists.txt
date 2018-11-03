cmake_minimum_required(VERSION 3.12)
project(Mathelium)

set(CMAKE_CXX_STANDARD 17)

add_executable(Mathelium main.cpp mathelium.h
        mathelium/src/Vector.hpp mathelium/include/Vector.h
        mathelium/src/Matrix.hpp mathelium/include/Matrix.h
        mathelium/src/Vec3D.hpp mathelium/include/Vec3D.h mathelium/src/Complex.cpp mathelium/include/Complex.h mathelium/src/Algorithme.cpp mathelium/include/Algorithme.h)