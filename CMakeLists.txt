cmake_minimum_required(VERSION 3.5)
project(LeetCode)
# 如果没有设置 CMAKE_BUILD_TYPE
if(NOT CMAKE_BUILD_TYPE)
# 设置构建类型为 Debug
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

set(BUILD_DES_SRC "src/"
  CACHE PATH "source file directory to compile")
message(“BUILD_DES_SRC:”${BUILD_DES_SRC})
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/bin")

message(“CMAKE_SOURCE_DIR:”${CMAKE_SOURCE_DIR})

add_definitions(-DPROJECT_PATH="${PROJECT_SOURCE_DIR}")
add_definitions(-DMAX_LINE_SIZE=1000000)
add_definitions(-DMAX_LINE=100)

# include_directories(include)

# ##############################################################################
# Build  ##
# ##############################################################################
# 使用文件名通配符递归搜索指定目录下的所有 .cpp 文件
file(GLOB_RECURSE LEETCODE_LIST ${BUILD_DES_SRC}/*.cpp)
include_directories(include)
# 对于搜索到的每一个 .cpp 文件
foreach(LC IN LISTS LEETCODE_LIST)
  # 打印消息，显示即将添加的可执行文件路径
  message(STATUS "add_leetcode_exec=${LC}") # fatal用于停止构建
  # 使用正则表达式替换，提取文件名作为可执行文件名
  string(REGEX REPLACE ".+/(.+)\\..*" "\\1" LC_EXEC ${LC})
  message("LEC LC:"${LC_EXEC} ${LC})
  # 添加可执行文件，将当前 .cpp 文件编译成一个可执行文件
  add_executable(${LC_EXEC} ${LC})
  # 为每个可执行文件链接 pthread 库和 AddressSanitizer 进行内存检查
  target_link_libraries(${LC_EXEC} -lpthread -fsanitize=address)
endforeach(LC IN ${LEETCODE_LIST})
