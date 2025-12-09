cmake_minimum_required(VERSION 3.14)
project(PrimeFinder)

set(CMAKE_CXX_STANDARD 17)

add_subdirectory(googletest)

add_library(prime_lib src/primes.cpp)

add_executable(prime_tests tests/test_primes.cpp)

target_link_libraries(prime_tests prime_lib gtest gtest_main)

target_include_directories(prime_lib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/src)