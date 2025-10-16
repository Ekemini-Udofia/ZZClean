cmake_minimum_required(VERSION 4.0)

project(ZZClEAN VERSION 1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)



add_executable(ZZCLEAN src/main.cpp)

target_include_directories(
  ZZCLEAN
  PRIVATE
  ${CMAKE_CURRENT_SOURCE_DIR}/include
  ${CMAKE_CURRENT_SOURCE_DIR}/lib/cxxopts/include
)

if (CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
  if (CMAKE_CXX_COMPILER_VERSION VERSION_LESS "9")
    target_link_libraries(zzclean PRIVATE stdc++fs)
  endif()
endif()

