cmake_minimum_required(VERSION 3.8)
project(lesson11 C)

find_program(GCC11 gcc-11)
if(GCC11)
    set(CMAKE_C_COMPILER ${GCC11})
else()
    message(FATAL_ERROR "gcc-11 not found")
endif()

# 设置默认构建类型为 Release（可选）
if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Release)
endif()

set(SOURCE_FILES lesson11.c)
add_executable(lesson11 ${SOURCE_FILES})

target_link_libraries(lesson11 m)

# 根据构建类型设置优化级别
if(CMAKE_BUILD_TYPE STREQUAL "Release")
    target_compile_options(lesson11 PRIVATE -O2)
    #message(FATAL_ERROR "-O2 message")
elseif(CMAKE_BUILD_TYPE STREQUAL "Debug")
    target_compile_options(lesson11 PRIVATE -O0)  # 不优化
    #message(FATAL_ERROR "-O0 message")
endif()