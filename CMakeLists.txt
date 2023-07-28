cmake_minimum_required(VERSION 3.26)
project(Biblioteca_U)

set(CMAKE_CXX_STANDARD 17)

add_executable(Biblioteca_U
        main.cxx
        library.cxx
        book.cxx
        user.cxx)
