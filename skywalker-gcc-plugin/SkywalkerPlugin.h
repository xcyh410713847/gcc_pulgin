/*************************************************************************
**文件: skywalker-gcc-plugin/SkywalkerPlugin.h
**作者: shyfan
**日期: 2024/07/29 16:08:59
**功能: Skywalker插件
*************************************************************************/

#ifndef __PLUGIN_H__
#define __PLUGIN_H__

#include <stdio.h>

/**
 * 插件打印 DEBUG 信息
 */
#define SkywalkerPlugin_Debug(str) printf("[SkywalkerPlugin] [DEBUG     ] %s\n", str)

/**
 * 插件打印 INFO 信息
 */
#define SkywalkerPlugin_Info(str) printf("[SkywalkerPlugin] [INFO      ] %s\n", str)

/**
 * 插件打印 WARNING 信息
 */
#define SkywalkerPlugin_Warning(str) printf("[SkywalkerPlugin] [WARNING   ] %s\n", str)

/**
 * 插件打印 ERROR 信息
 */
#define SkywalkerPlugin_Error(str) printf("[SkywalkerPlugin] [ERROR     ] %s\n", str)

class SkywalkerPlugin
{
public:
    SkywalkerPlugin();
    virtual ~SkywalkerPlugin();

    void Help();
};

extern "C" SkywalkerPlugin skywalker_plugin;

#endif // __PLUGIN_H__
