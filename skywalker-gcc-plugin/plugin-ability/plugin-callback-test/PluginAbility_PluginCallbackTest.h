/*************************************************************************
**文件: skywalker-gcc-plugin/plugin-ability/plugin-callback-test/PluginAbility_PluginCallbackTest.h
**作者: shyfan
**日期: 2024/08/12 15:58:35
**功能: 插件回调测试插件能力
*************************************************************************/

#ifndef __PLUGIN_ABILITY_PLUGIN_CALLBACK_TEST_H__
#define __PLUGIN_ABILITY_PLUGIN_CALLBACK_TEST_H__

#include "IPluginAbility.h"

class PluginAbility_PluginCallbackTest : public IPluginAbility
{
public:
    PluginAbility_PluginCallbackTest();
    virtual ~PluginAbility_PluginCallbackTest();

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
};

#endif // __PLUGIN_ABILITY_PLUGIN_CALLBACK_TEST_H__
