/*************************************************************************
**文件: skywalker-gcc-plugin/gcc-plugin-api.cpp
**作者: shyfan
**日期: 2024/07/29 15:45:22
**功能: GCC插件API
*************************************************************************/

#include "SkywalkerPlugin.h"

#include "IPluginAbility.h"
#include "function-count/PluginAbility_FunctionCount.h"

#ifdef ENABLE_PLUGIN_CALLBACK_TEST
#include "plugin-callback-test/PluginAbility_PluginCallbackTest.h"
#endif

int plugin_is_GPL_compatible;

/**
 * 版本检查
 */
static bool version_check(struct plugin_gcc_version *gcc_version,
                          struct plugin_gcc_version *plugin_version)
{
    if (!gcc_version || !plugin_version)
        return false;

    if (strcmp(gcc_version->basever, plugin_version->basever))
        return false;

    return true;
}

/**
 * 插件初始化
 */
int plugin_init(struct plugin_name_args *plugin_info, struct plugin_gcc_version *version)
{
    SKYWALKER_DEBUG("Plugin Init");

    if (!version_check(version, &gcc_version))
    {
        SKYWALKER_ERROR("GCC版本不匹配， plugin compiled by gcc %s and used by %s", version->basever, gcc_version.basever);
        return 1;
    }

    for (int i = 0; i < plugin_info->argc; i++)
    {
        // 打印帮助
        if (!strcmp(plugin_info->argv[i].key, "help"))
        {
            skywalker_plugin.Help();
        }
    }

    // 注册插件能力
    SKYWALKER_REGISTER_PLUGIN_ABILITY(PluginAbility_FunctionCount);

#ifdef ENABLE_PLUGIN_CALLBACK_TEST
    SKYWALKER_REGISTER_PLUGIN_ABILITY(PluginAbility_PluginCallbackTest);
#endif

    return 0;
}
