# #########################################################################
# 文件: CMakeLists.txt
# 作者: shyfan
# 日期: 2024/07/29 16:15:22
# 功能: CMakeLists.txt
# #########################################################################

cmake_minimum_required(VERSION 3.5)

project(skywalkerPlugin)

# gcc 插件
add_subdirectory(skywalker-gcc-plugin)

# 插件测试
add_subdirectory(example)
