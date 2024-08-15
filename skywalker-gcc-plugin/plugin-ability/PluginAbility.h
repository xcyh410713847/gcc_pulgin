/*************************************************************************
**文件: skywalker-gcc-plugin/plugin-ability/PluginAbility.h
**作者: shyfan
**日期: 2024/08/15 11:22:01
**功能: 插件能力
*************************************************************************/

#ifndef __PLUGIN_ABILITY_H__
#define __PLUGIN_ABILITY_H__

#include <map>

#include "gcc_plugin.h"

#include "IPluginAbility.h"

class PluginAbility : public IPluginAbility
{
public:
    PluginAbility();
    virtual ~PluginAbility();

public:
    /**
     * 注册
     */
    virtual void Register() override;

    /**
     * 反注册
     */
    virtual void UnRegister() override;

    /**
     * 释放
     */
    virtual void Release() override;

protected:
    std::map<int, plugin_callback_func> PluginCallbackMap;
};

/**
 * 注册插件回调
*/
#define REGISTER_PLUGIN_CALLBACK(callbackId, callbackFunc) \
    PluginCallbackMap[callbackId] = callbackFunc;

#endif // __PLUGIN_ABILITY_H__
