# #########################################################################
# 文件: skywalker-gcc-plugin/CMakeLists.txt
# 作者: shyfan
# 日期: 2024/07/29 16:16:03
# 功能: 使用插件编译的例子
# #########################################################################

cmake_minimum_required(VERSION 3.0)

set(example_Name "skywalker-plugin-example")

project(${example_Name})

# 设置C++标准
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# 增加编译选项 使用 插件
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fplugin=${CMAKE_BINARY_DIR}/../bin/skywalker-gcc-plugin.so")

# 设置源代码
file(GLOB example_Source
    # cpp
    *.cpp

    # h
    *.h
)

# 添加可执行文件
add_executable(${example_Name} ${example_Source})

# 将编译的可执行文件拷贝到 bin 目录
add_custom_command(TARGET ${example_Name} POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_FILE:${example_Name}> ${CMAKE_BINARY_DIR}/../bin/
)
