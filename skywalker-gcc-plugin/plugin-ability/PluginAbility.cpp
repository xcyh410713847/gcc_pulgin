/*************************************************************************
**文件: skywalker-gcc-plugin/plugin-ability/PluginAbility.cpp
**作者: shyfan
**日期: 2024/08/15 11:22:15
**功能: 插件能力
*************************************************************************/

#include "PluginAbility.h"

#include "SkywalkerPlugin.h"

PluginAbility::PluginAbility()
{
    PluginCallbackMap.clear();
}

PluginAbility::~PluginAbility()
{
    PluginCallbackMap.clear();
}

void PluginAbility::Register()
{
    for(auto& iter : PluginCallbackMap)
    {
        // 注册插件回调
        register_callback(skywalker_plugin.GetPluginName(), iter.first, iter.second, nullptr);
    }
}

void PluginAbility::UnRegister()
{
    for(auto& iter : PluginCallbackMap)
    {
        // 反注册插件回调
        unregister_callback(skywalker_plugin.GetPluginName(), iter.first);
    }
}

void PluginAbility::Release()
{
    delete this;
}
