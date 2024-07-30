/*************************************************************************
**文件: skywalker-gcc-plugin/SkywalkerPlugin.h
**作者: shyfan
**日期: 2024/07/29 16:08:59
**功能: Skywalker插件
*************************************************************************/

#ifndef __PLUGIN_H__
#define __PLUGIN_H__

#include <cstdarg>
#include <cstdio>

#include <gcc-plugin.h>
#include <plugin-version.h>
#include <tree.h>
#include <coretypes.h>
#include <diagnostic.h>
#include <vec.h>
#include <function.h>

/**
 * 插件信息
 */
struct SSkywalkerPluginInfo
{
    /**
     * 插件名称
     */
    const char *PluginName;

    /**
     * 插件版本
     */
    const char *PluginVersion;
};

class SkywalkerPlugin
{
public:
    SkywalkerPlugin();
    virtual ~SkywalkerPlugin();

    /**
     * 获取插件名称
     */
    const char *GetPluginName() const { return PluginInfo.PluginName; }

    /**
     * 获取插件版本
     */
    const char *GetPluginVersion() const { return PluginInfo.PluginVersion; }

#pragma region Log

    /**
     * Log Debug
    */
    void Debug(const char *format, ...);

    /**
     * Log Info
    */
    void Info(const char *format, ...);

    /**
     * Log Warning
    */
    void Warning(const char *format, ...);

    /**
     * Log Error
    */
    void Error(const char *format, ...);

#pragma endregion Log

    /**
     * 获取插件帮助
     */
    void Help();

public:
    static SSkywalkerPluginInfo PluginInfo;
};

extern "C" SkywalkerPlugin skywalker_plugin;

#endif // __PLUGIN_H__
