/*************************************************************************
**文件: skywalker-gcc-plugin/SkywalkerPlugin.cpp
**作者: shyfan
**日期: 2024/07/29 16:09:13
**功能: Skywalker插件
*************************************************************************/

#include "SkywalkerPlugin.h"

SkywalkerPlugin skywalker_plugin;

SkywalkerPlugin::SkywalkerPlugin()
{
    SkywalkerPlugin_Debug("SkywalkerPlugin Launch");
}

SkywalkerPlugin::~SkywalkerPlugin()
{
    SkywalkerPlugin_Debug("SkywalkerPlugin Exit");
}

void SkywalkerPlugin::Help()
{
    SkywalkerPlugin_Debug("Test");
    SkywalkerPlugin_Info("Test");
    SkywalkerPlugin_Warning("Test");
    SkywalkerPlugin_Error("Test");
}
