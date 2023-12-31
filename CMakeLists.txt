cmake_minimum_required(VERSION 3.5)
project(LeetCode)

if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE Debug)
endif()

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS ON)
set(CMAKE_CXX_COMPILER clang++)
add_compile_options(-Wall -Werror -fsanitize=address -Wno-unused-function
  -Wno-unused-variable -Wno-sign-compare -fno-limit-debug-info)

# Clang-tidy
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(BUILD_DES_SRC
  "src/"
  CACHE PATH "source file directory to compile")

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/bin")

add_definitions(-DPROJECT_PATH="${PROJECT_SOURCE_DIR}")
add_definitions(-DMAX_LINE_SIZE=1000000)

# include_directories(include)

# ##############################################################################
# Build  ##
# ##############################################################################
file(GLOB_RECURSE LEETCODE_LIST ${BUILD_DES_SRC}/*.cpp)
include_directories(include)

foreach(LC IN LISTS LEETCODE_LIST)
  message(STATUS "add_leetcode_exec=${LC}") # fatal用于停止构建
  string(REGEX REPLACE ".+/(.+)\\..*" "\\1" LC_EXEC ${LC})
  add_executable(${LC_EXEC} ${LC})
  target_link_libraries(${LC_EXEC} -lpthread -fsanitize=address)
endforeach(LC IN ${LEETCODE_LIST})
