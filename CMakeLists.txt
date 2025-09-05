cmake_minimum_required(VERSION 3.16)
project(prime_efficiency CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_library(prime STATIC prime.cpp)
target_include_directories(prime PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

add_executable(main main.cpp)
target_link_libraries(main PRIVATE prime)

if(EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/test.cpp")
  add_executable(tests test.cpp)
  target_link_libraries(tests PRIVATE prime)
endif()
