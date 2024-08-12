/*************************************************************************
**文件: skywalker-gcc-plugin/plugin-ability/PluginAbility_FunctionCount.h
**作者: shyfan
**日期: 2024/07/30 17:36:03
**功能: 函数计数插件能力
*************************************************************************/

#ifndef __PLUGIN_ABILITY_FUNCTION_COUNT_H__
#define __PLUGIN_ABILITY_FUNCTION_COUNT_H__

#include "IPluginAbility.h"

class PluginAbility_FunctionCount : public IPluginAbility
{
public:
    PluginAbility_FunctionCount();
    virtual ~PluginAbility_FunctionCount();

    /**
     * 函数计数
     */
    void OnFunctionCount();

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

private:
    /**
     * 函数计数
     */
    int FunctionCount = 0;
};

#endif // __PLUGIN_ABILITY_FUNCTION_COUNT_H__
