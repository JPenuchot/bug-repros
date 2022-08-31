cmake_minimum_required(VERSION 3.23)
project(repros)

file(GLOB_RECURSE SOURCES "repros/*.cpp")

set(CMAKE_CXX_STANDARD 20)

# Build

foreach(SRC ${SOURCES})
  cmake_path(GET SRC STEM src_stem)
  add_executable(${src_stem} ${SRC})
endforeach()
