/*************************************************************************
**文件: skywalker-gcc-plugin/include/IPluginAbility.h
**作者: shyfan
**日期: 2024/08/15 11:22:26
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
