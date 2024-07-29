/*************************************************************************
**文件: skywalker-gcc-plugin/gcc-plugin-api.cpp
**作者: shyfan
**日期: 2024/07/29 15:45:22
**功能: GCC插件API
*************************************************************************/

#include <gcc-plugin.h>
#include <plugin-version.h>
#include <tree.h>
#include <coretypes.h>
#include <diagnostic.h>
#include <vec.h>
#include <function.h>

#include "SkywalkerPlugin.h"

int plugin_is_GPL_compatible;

int plugin_init(struct plugin_name_args *plugin_info, struct plugin_gcc_version *version)
{
    fprintf(stderr, "Skywalker GCC Plugin loaded\n");

    return 0;
}
