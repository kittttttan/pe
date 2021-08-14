cmake_minimum_required (VERSION 2.8.11)

project(pe)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_FLAGS "-O2 -Wall")

add_executable(pe_cli
  src/main.cc
  src/pe1.cc ../pe/src/pe1.cc
  src/pe2.cc ../pe/src/pe2.cc
  src/pe3.cc ../pe/src/pe3.cc ../pe/src/divs.cc
  src/pe4.cc ../pe/src/pe4.cc ../pe/src/palindrome.cc
  src/pe5.cc ../pe/src/pe5.cc
  src/pe6.cc ../pe/src/pe6.cc
  src/pe7.cc ../pe/src/pe7.cc ../pe/src/prime.cc
  src/pe8.cc ../pe/src/pe8.cc
  src/pe9.cc ../pe/src/pe9.cc
  src/pe10.cc ../pe/src/pe10.cc
  src/pe11.cc ../pe/src/pe11.cc
  src/pe12.cc ../pe/src/pe12.cc
  src/pe13.cc ../pe/src/pe13.cc
  src/pe14.cc ../pe/src/pe14.cc
  src/pe15.cc ../pe/src/pe15.cc
  src/pe16.cc ../pe/src/pe16.cc
  src/pe17.cc ../pe/src/pe17.cc
  src/pe18.cc ../pe/src/pe18.cc
  src/pe19.cc ../pe/src/pe19.cc
  src/pe20.cc ../pe/src/pe20.cc
  src/pe21.cc ../pe/src/pe21.cc ../pe/src/spd.cc
  src/pe22.cc ../pe/src/pe22.cc
)
