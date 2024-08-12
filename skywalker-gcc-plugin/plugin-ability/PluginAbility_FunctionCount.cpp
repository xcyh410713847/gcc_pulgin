/*************************************************************************
**文件: skywalker-gcc-plugin/plugin-ability/PluginAbility_FunctionCount.cpp
**作者: shyfan
**日期: 2024/07/30 17:37:08
**功能: 函数计数插件能力
*************************************************************************/

#include "PluginAbility_FunctionCount.h"

#include "../SkywalkerPlugin.h"

static void Event_PLUGIN_ALL_PASSES_START(void *gcc_data, void *user_data)
{
    IPluginAbility *plugin_ability = skywalker_plugin.GetPluginAbility<PluginAbility_FunctionCount>();
    if (plugin_ability)
    {
        PluginAbility_FunctionCount *function_count = dynamic_cast<PluginAbility_FunctionCount *>(plugin_ability);
        if (function_count)
        {
            function_count->OnFunctionCount();
        }
    }
}

PluginAbility_FunctionCount::PluginAbility_FunctionCount()
{
}

PluginAbility_FunctionCount::~PluginAbility_FunctionCount()
{
}

void PluginAbility_FunctionCount::OnFunctionCount()
{
    FunctionCount++;
    skywalker_plugin.Debug("FunctionCount: %d", FunctionCount);
}

void PluginAbility_FunctionCount::Register()
{
    skywalker_plugin.Info("PluginAbility_FunctionCount::Register");

    // 注册事件
    register_callback(skywalker_plugin.GetPluginName(), PLUGIN_ALL_PASSES_START, (plugin_callback_func)Event_PLUGIN_ALL_PASSES_START, nullptr);
}

void PluginAbility_FunctionCount::UnRegister()
{
    skywalker_plugin.Info("PluginAbility_FunctionCount::UnRegister");

    // 反注册事件
    unregister_callback(skywalker_plugin.GetPluginName(), PLUGIN_ALL_PASSES_START);
}

void PluginAbility_FunctionCount::Release()
{
    skywalker_plugin.Info("PluginAbility_FunctionCount::Release");

    delete this;
}
