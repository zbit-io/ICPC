cmake_minimum_required(VERSION 3.10)  # 指定 CMake 的最低版本要求
set(CMAKE_CXX_COMPILER "/usr/bin/g++")
# 设置项目名称和版本
project(ICPC)

# 指定 C++ 标准
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# 添加可执行文件
# 替换 main.cpp 为你的源文件
# 如果有多个源文件，可以在这里添加
add_executable(main main.cpp)

# 如果你的项目需要链接某些库，可以使用 target_link_libraries
# target_link_libraries(MyExecutable PUBLIC SomeLibrary)
