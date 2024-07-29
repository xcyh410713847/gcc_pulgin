/*************************************************************************
**文件: skywalker-gcc-plugin/SkywalkerPlugin.h
**作者: shyfan
**日期: 2024/07/29 16:08:59
**功能: Skywalker插件
*************************************************************************/

#ifndef __PLUGIN_H__
#define __PLUGIN_H__

class SkywalkerPlugin
{
public:
    SkywalkerPlugin();
    virtual ~SkywalkerPlugin();

    void Help();
};

extern "C" SkywalkerPlugin skywalker_plugin;

#endif // __PLUGIN_H__
