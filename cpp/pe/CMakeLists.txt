cmake_minimum_required (VERSION 2.8.11)

project(pe)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_FLAGS "-Og -Wall")

find_package(GTest REQUIRED)
enable_testing()

add_executable(pe_test
  test/pe1_test.cc src/pe1.cc
  test/pe2_test.cc src/pe2.cc
  test/pe3_test.cc src/pe3.cc src/divs.cc
  test/pe4_test.cc src/pe4.cc src/palindrome.cc
  test/pe5_test.cc src/pe5.cc
  test/pe6_test.cc src/pe6.cc
  test/pe7_test.cc src/pe7.cc src/prime.cc
  test/pe8_test.cc src/pe8.cc
  test/pe9_test.cc src/pe9.cc
  test/pe10_test.cc src/pe10.cc
  test/pe11_test.cc src/pe11.cc
  test/pe12_test.cc src/pe12.cc
  test/pe13_test.cc src/pe13.cc
  test/pe14_test.cc src/pe14.cc
  test/pe15_test.cc src/pe15.cc
  test/pe16_test.cc src/pe16.cc
  test/pe17_test.cc src/pe17.cc
  test/pe18_test.cc src/pe18.cc
  test/pe19_test.cc src/pe19.cc
  test/pe20_test.cc src/pe20.cc
  test/pe21_test.cc src/pe21.cc src/spd.cc
  test/pe22_test.cc src/pe22.cc
)
target_link_libraries(pe_test
#  GTest::gtest GTest::gtest_main
  GTest::GTest GTest::Main
)
add_test(NAME pe_test COMMAND pe_test)

include(GoogleTest)
gtest_discover_tests(pe_test)
