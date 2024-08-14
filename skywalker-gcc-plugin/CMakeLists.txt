# #########################################################################
# 文件: skywalker-gcc-plugin/CMakeLists.txt
# 作者: shyfan
# 日期: 2024/07/29 16:16:03
# 功能: skywalker-gcc-plugin CMakeLists.txt
# #########################################################################

cmake_minimum_required(VERSION 3.5)

set(plugin_Name "skywalker-gcc-plugin")

project(${plugin_Name})

# 设置C++标准
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fPIC") # 设置为位置独立代码

# 宏开关
option(ENABLE_PLUGIN_CALLBACK_TEST "Enable plugin callback test" ON)

# 宏定义
if(ENABLE_PLUGIN_CALLBACK_TEST)
    add_definitions(-DENABLE_PLUGIN_CALLBACK_TEST)
endif()

# 查找 GCC 插件头文件路径
find_path(GCC_PLUGIN_INCLUDE_DIR NAMES gcc-plugin.h
    PATHS
    /usr/lib/gcc/x86_64-linux-gnu/*/plugin/include
    /usr/lib/gcc/x86_64-redhat-linux/*/plugin/include
    /usr/local/lib/gcc/x86_64-pc-linux-gnu/*/plugin/include
)

# 包含插件头文件目录
include_directories(
    ${GCC_PLUGIN_INCLUDE_DIR}
    ./
    ./plugin-ability/
)

# 设置插件源代码
file(GLOB plugin_Source

    # cpp
    *.cpp
    ./*/*.cpp
    ./*/*/*.cpp

    # h
    *.h
    ./*/*.h
    ./*/*/*.h
)

# 添加共享库即插件
add_library(${plugin_Name} SHARED ${plugin_Source})

# 取消库名前的lib前缀
set_target_properties(${plugin_Name} PROPERTIES PREFIX "")

# 将编译的库拷贝到 bin 目录
add_custom_command(TARGET ${plugin_Name} POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_FILE:${plugin_Name}> ${CMAKE_BINARY_DIR}/../bin/
)
