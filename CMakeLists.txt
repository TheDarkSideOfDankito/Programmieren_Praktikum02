cmake_minimum_required(VERSION 3.4)
project(P2)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -lm -Werror")

set(SOURCE_FILES main.c Artikel.h io.h io.c lagerdat.h lagerdat.c inventar.c inventar.h bestell.c bestell.h)
add_executable(P2 ${SOURCE_FILES} inventar.c inventar.h bestell.c bestell.h)