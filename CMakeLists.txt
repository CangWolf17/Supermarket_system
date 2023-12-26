cmake_minimum_required(VERSION 3.26)
project(Supermarket_system)

set(CMAKE_CXX_STANDARD 14)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_DEBUG ${PROJECT_SOURCE_DIR}/cmake-build-debug) #设置debug模式文件的输出路径
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_RELEASE ${PROJECT_SOURCE_DIR}) #设置release模式可执行文件的输出路径为项目根路径

add_subdirectory(src)
add_subdirectory(src/login)
