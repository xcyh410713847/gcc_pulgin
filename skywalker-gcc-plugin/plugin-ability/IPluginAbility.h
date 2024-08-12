/*************************************************************************
**文件: skywalker-gcc-plugin/plugin-ability/IPluginAbility.h
**作者: shyfan
**日期: 2024/07/30 17:30:05
**功能: 插件能力接口
*************************************************************************/

#ifndef __I_PLUGIN_ABILITY_H__
#define __I_PLUGIN_ABILITY_H__

class IPluginAbility
{
public:
    /**
     * 注册
     */
    virtual void Register() = 0;

    /**
     * 反注册
     */
    virtual void UnRegister() = 0;

    /**
     * 释放
     */
    virtual void Release() = 0;
};

#endif // __I_PLUGIN_ABILITY_H__
