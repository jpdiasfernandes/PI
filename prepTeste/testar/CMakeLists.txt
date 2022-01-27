cmake_minimum_required(VERSION 3.15)
project(testar C)

set(CMAKE_C_STANDARD 99)

add_executable(testar testar.c testar.h  teste_19_20/teste_19_20.c teste_19_20/teste_19_20.h)
