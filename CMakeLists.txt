cmake_minimum_required(VERSION 4.0)

project(ZZClean VERSION 1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)



add_executable(ZZClean src/main.cpp)

target_include_directories(
  ZZClean
  PRIVATE
  ${CMAKE_CURRENT_SOURCE_DIR}/include
  ${CMAKE_CURRENT_SOURCE_DIR}/lib/cxxopts/include
)

if (CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
  if (CMAKE_CXX_COMPILER_VERSION VERSION_LESS "9")
    target_link_libraries(ZZClean PRIVATE stdc++fs)
  endif()
endif()

