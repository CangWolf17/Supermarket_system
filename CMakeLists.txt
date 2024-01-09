cmake_minimum_required(VERSION 3.22)
project(Supermarket_system)

set(CMAKE_CXX_STANDARD 14)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}) #设置release模式可执行文件的输出路径为项目根路径

add_subdirectory(src)
add_subdirectory(src/login)
