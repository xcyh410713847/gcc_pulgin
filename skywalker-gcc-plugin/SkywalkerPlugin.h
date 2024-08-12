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
#include <map>
#include <typeinfo>

#include <gcc-plugin.h>
#include <plugin-version.h>
#include <tree.h>
#include <coretypes.h>
#include <diagnostic.h>
#include <vec.h>
#include <function.h>

#include "IPluginAbility.h"

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

#pragma region Plugin Ability

    /**
     * 注册插件能力
     */
    template <typename T>
    void RegisterPluginAbility()
    {
        // 获取 T 类型的名称
        const char *abilityName = typeid(T).name();
        if (abilityName == nullptr)
        {
            Error("RegisterPluginAbility failed, abilityName is nullptr");
            return;
        }

        // 判断是否已经注册
        if (PluginAbilityMap.find(abilityName) != PluginAbilityMap.end())
        {
            Error("RegisterPluginAbility failed, abilityName: %s has been registered", abilityName);
            return;
        }

        // 创建插件能力
        IPluginAbility *pluginAbility = new T();
        if (pluginAbility == nullptr)
        {
            Error("RegisterPluginAbility failed, create abilityName: %s failed", abilityName);
            return;
        }

        // 注册插件能力
        pluginAbility->Register();

        // 添加到插件能力列表
        PluginAbilityMap[abilityName] = pluginAbility;
    }

    /**
     * 反注册插件能力
     */
    template <typename T>
    void UnRegisterPluginAbility()
    {
        // 获取 T 类型的名称
        const char *abilityName = typeid(T).name();
        if (abilityName == nullptr)
        {
            Error("UnRegisterPluginAbility failed, abilityName is nullptr");
            return;
        }

        // 查找插件能力
        auto iter = PluginAbilityMap.find(abilityName);
        if (iter == PluginAbilityMap.end())
        {
            Error("UnRegisterPluginAbility failed, abilityName: %s not found", abilityName);
            return;
        }

        // 反注册插件能力
        iter->second->UnRegister();

        // 释放插件能力
        iter->second->Release();

        // 从插件能力列表中移除
        PluginAbilityMap.erase(iter);
    }

    /**
     * 获取插件能力
     */
    template <typename T>
    T *GetPluginAbility()
    {
        // 获取 T 类型的名称
        const char *abilityName = typeid(T).name();
        if (abilityName == nullptr)
        {
            Error("GetPluginAbility failed, abilityName is nullptr");
            return nullptr;
        }

        // 查找插件能力
        auto iter = PluginAbilityMap.find(abilityName);
        if (iter == PluginAbilityMap.end())
        {
            Error("GetPluginAbility failed, abilityName: %s not found", abilityName);
            return nullptr;
        }

        return dynamic_cast<T *>(iter->second);
    }

#pragma endregion Plugin Ability

    /**
     * 获取插件帮助
     */
    void Help();

public:
    static SSkywalkerPluginInfo PluginInfo;

private:
    std::map<const char *, IPluginAbility *> PluginAbilityMap;
};

extern "C" SkywalkerPlugin skywalker_plugin;

#endif // __PLUGIN_H__
