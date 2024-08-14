/*************************************************************************
**文件: skywalker-gcc-plugin/plugin-ability/plugin-callback-test/PluginAbility_PluginCallbackTest.cpp
**作者: shyfan
**日期: 2024/08/12 15:59:34
**功能: 插件回调测试插件能力
*************************************************************************/

#include "PluginAbility_PluginCallbackTest.h"

#include "SkywalkerPlugin.h"

#pragma region Event

/**
 * PLUGIN_START_PARSE_FUNCTION
 */
static void Event_PLUGIN_START_PARSE_FUNCTION(void *gcc_data, void *user_data)
{
    // skywalker_plugin.Debug("PLUGIN_START_PARSE_FUNCTION");

    // 打印函数返回值类型和函数名
    tree func_decl = (tree)gcc_data;
    if (func_decl && TREE_CODE(func_decl) == FUNCTION_DECL)
    {
        // UID
        skywalker_plugin.Debug("PLUGIN_START_PARSE_FUNCTION Func Decl UID: %u,", DECL_UID(func_decl));

        // 函数名
        skywalker_plugin.Debug("PLUGIN_START_PARSE_FUNCTION Func Name: %s", IDENTIFIER_POINTER(DECL_NAME(func_decl)));

        // 返回值类型
        tree return_type = TREE_TYPE(TREE_TYPE(func_decl));
        skywalker_plugin.Debug("PLUGIN_START_PARSE_FUNCTION Func Type: %s", get_tree_code_name(TREE_CODE(return_type)));

        // 参数
        tree param_decl = DECL_ARGUMENTS(func_decl);
        while (param_decl)
        {
            // UID
            skywalker_plugin.Debug("PLUGIN_START_PARSE_FUNCTION Param Decl UID: %u,", DECL_UID(param_decl));

            // 参数名
            skywalker_plugin.Debug("PLUGIN_START_PARSE_FUNCTION Param Name: %s", IDENTIFIER_POINTER(DECL_NAME(param_decl)));

            // 参数类型
            tree param_type = TREE_TYPE(param_decl);
            if (TREE_CODE(param_type) == INTEGER_TYPE)
            {
                if (TYPE_UNSIGNED(param_type))
                {
                    skywalker_plugin.Debug("PLUGIN_START_PARSE_FUNCTION Param Type: unsigned %s", get_tree_code_name(TREE_CODE(param_type)));
                }
                else
                {
                    skywalker_plugin.Debug("PLUGIN_START_PARSE_FUNCTION Param Type: signed %s", get_tree_code_name(TREE_CODE(param_type)));
                }
            }
            else
            {
                skywalker_plugin.Debug("PLUGIN_START_PARSE_FUNCTION Param Type: %s", get_tree_code_name(TREE_CODE(param_type)));
            }

            param_decl = DECL_CHAIN(param_decl);
        }
    }
}

/**
 * PLUGIN_FINISH_PARSE_FUNCTION
 */
static void Event_PLUGIN_FINISH_PARSE_FUNCTION(void *gcc_data, void *user_data)
{
    // skywalker_plugin.Debug("PLUGIN_FINISH_PARSE_FUNCTION");
}

/**
 * PLUGIN_PASS_MANAGER_SETUP
 */
static void Event_PLUGIN_PASS_MANAGER_SETUP(void *gcc_data, void *user_data)
{
    // skywalker_plugin.Debug("PLUGIN_PASS_MANAGER_SETUP");
}

/**
 * PLUGIN_FINISH_TYPE
 */
static void Event_PLUGIN_FINISH_TYPE(void *gcc_data, void *user_data)
{
    // skywalker_plugin.Debug("PLUGIN_FINISH_TYPE");
}

/**
 * PLUGIN_FINISH_DECL
 */
static void Event_PLUGIN_FINISH_DECL(void *gcc_data, void *user_data)
{
    // skywalker_plugin.Debug("PLUGIN_FINISH_DECL");

    // 打印变量名
    tree val_decl = (tree)gcc_data;
    if (val_decl && TREE_CODE(val_decl) == VAR_DECL)
    {
        // UID
        skywalker_plugin.Debug("PLUGIN_FINISH_DECL Val Decl UID: %u,", DECL_UID(val_decl));

        // 变量名
        skywalker_plugin.Debug("PLUGIN_FINISH_DECL Val Name: %s", IDENTIFIER_POINTER(DECL_NAME(val_decl)));

        // 变量类型
        tree val_type = TREE_TYPE(val_decl);
        if (TREE_CODE(val_type) == INTEGER_TYPE)
        {
            if (TYPE_UNSIGNED(val_type))
            {
                skywalker_plugin.Debug("PLUGIN_FINISH_DECL Val Type: unsigned %s", get_tree_code_name(TREE_CODE(val_type)));
            }
            else
            {
                skywalker_plugin.Debug("PLUGIN_FINISH_DECL Val Type: signed %s", get_tree_code_name(TREE_CODE(val_type)));
            }
        }
        else
        {
            skywalker_plugin.Debug("PLUGIN_FINISH_DECL Val Type: %s", get_tree_code_name(TREE_CODE(val_type)));
        }
    }
}

/**
 * PLUGIN_FINISH_UNIT
 */
static void Event_PLUGIN_FINISH_UNIT(void *gcc_data, void *user_data)
{
    // skywalker_plugin.Debug("PLUGIN_FINISH_UNIT");
}

/**
 * PLUGIN_PRE_GENERICIZE
 */
static void Event_PLUGIN_PRE_GENERICIZE(void *gcc_data, void *user_data)
{
    // skywalker_plugin.Debug("PLUGIN_PRE_GENERICIZE");
}

/**
 * PLUGIN_FINISH
 */
static void Event_PLUGIN_FINISH(void *gcc_data, void *user_data)
{
    // skywalker_plugin.Debug("PLUGIN_FINISH");
}

/**
 * PLUGIN_INFO
 */
static void Event_PLUGIN_INFO(void *gcc_data, void *user_data)
{
    // skywalker_plugin.Debug("PLUGIN_INFO");
}

/**
 * PLUGIN_GGC_START
 */
static void Event_PLUGIN_GGC_START(void *gcc_data, void *user_data)
{
    // skywalker_plugin.Debug("PLUGIN_GGC_START");
}

/**
 * PLUGIN_GGC_MARKING
 */
static void Event_PLUGIN_GGC_MARKING(void *gcc_data, void *user_data)
{
    // skywalker_plugin.Debug("PLUGIN_GGC_MARKING");
}

/**
 * PLUGIN_GGC_END
 */
static void Event_PLUGIN_GGC_END(void *gcc_data, void *user_data)
{
    // skywalker_plugin.Debug("PLUGIN_GGC_END");
}

/**
 * PLUGIN_REGISTER_GGC_ROOTS
 */
static void Event_PLUGIN_REGISTER_GGC_ROOTS(void *gcc_data, void *user_data)
{
    // skywalker_plugin.Debug("PLUGIN_REGISTER_GGC_ROOTS");
}

/**
 * 属性回调函数
 */
static tree handle_skywalker_attribute(tree *node, tree name, tree args, int flags, bool *no_add_attrs)
{
    skywalker_plugin.Error("handle_skywalker_attribute");

    return NULL_TREE;
}

/**
 * 自定义属性
 */
static struct attribute_spec skywalker_attribute = {"skywalker", 0, -1, true, false, false, false, handle_skywalker_attribute, NULL};

/**
 * PLUGIN_ATTRIBUTES
 */
static void Event_PLUGIN_ATTRIBUTES(void *gcc_data, void *user_data)
{
    skywalker_plugin.Debug("PLUGIN_ATTRIBUTES Register Attribute: %s", skywalker_attribute.name);
    register_attribute(&skywalker_attribute);
}

/**
 * PLUGIN_START_UNIT
 */
static void Event_PLUGIN_START_UNIT(void *gcc_data, void *user_data)
{
    // skywalker_plugin.Debug("PLUGIN_START_UNIT");
}

/**
 * PLUGIN_PRAGMAS
 */
static void Event_PLUGIN_PRAGMAS(void *gcc_data, void *user_data)
{
    // skywalker_plugin.Debug("PLUGIN_PRAGMAS");
}

/**
 * PLUGIN_ALL_PASSES_START
 */
static void Event_PLUGIN_ALL_PASSES_START(void *gcc_data, void *user_data)
{
    // skywalker_plugin.Debug("PLUGIN_ALL_PASSES_START");
}

/**
 * PLUGIN_ALL_PASSES_END
 */
static void Event_PLUGIN_ALL_PASSES_END(void *gcc_data, void *user_data)
{
    // skywalker_plugin.Debug("PLUGIN_ALL_PASSES_END");
}

/**
 * PLUGIN_ALL_IPA_PASSES_START
 */
static void Event_PLUGIN_ALL_IPA_PASSES_START(void *gcc_data, void *user_data)
{
    // skywalker_plugin.Debug("PLUGIN_ALL_IPA_PASSES_START");
}

/**
 * PLUGIN_ALL_IPA_PASSES_END
 */
static void Event_PLUGIN_ALL_IPA_PASSES_END(void *gcc_data, void *user_data)
{
    // skywalker_plugin.Debug("PLUGIN_ALL_IPA_PASSES_END");
}

/**
 * PLUGIN_OVERRIDE_GATE
 */
static void Event_PLUGIN_OVERRIDE_GATE(void *gcc_data, void *user_data)
{
    // skywalker_plugin.Debug("PLUGIN_OVERRIDE_GATE");
}

/**
 * PLUGIN_PASS_EXECUTION
 */
static void Event_PLUGIN_PASS_EXECUTION(void *gcc_data, void *user_data)
{
    // skywalker_plugin.Debug("PLUGIN_PASS_EXECUTION");
}

/**
 * PLUGIN_EARLY_GIMPLE_PASSES_START
 */
static void Event_PLUGIN_EARLY_GIMPLE_PASSES_START(void *gcc_data, void *user_data)
{
    // skywalker_plugin.Debug("PLUGIN_EARLY_GIMPLE_PASSES_START");
}

/**
 * PLUGIN_EARLY_GIMPLE_PASSES_END
 */
static void Event_PLUGIN_EARLY_GIMPLE_PASSES_END(void *gcc_data, void *user_data)
{
    // skywalker_plugin.Debug("PLUGIN_EARLY_GIMPLE_PASSES_END");
}

/**
 * PLUGIN_NEW_PASS
 */
static void Event_PLUGIN_NEW_PASS(void *gcc_data, void *user_data)
{
    // skywalker_plugin.Debug("PLUGIN_NEW_PASS");
}

/**
 * PLUGIN_INCLUDE_FILE
 */
static void Event_PLUGIN_INCLUDE_FILE(void *gcc_data, void *user_data)
{
    // skywalker_plugin.Debug("PLUGIN_INCLUDE_FILE");

    // 打印文件名
    const char *file_name = (const char *)gcc_data;
    skywalker_plugin.Debug("PLUGIN_INCLUDE_FILE File Name: %s", file_name);
}

/**
 * PLUGIN_ANALYZER_INIT
 */
static void Event_PLUGIN_ANALYZER_INIT(void *gcc_data, void *user_data)
{
    // skywalker_plugin.Debug("PLUGIN_ANALYZER_INIT");
}

/**
 * PLUGIN_EVENT_FIRST_DYNAMIC
 */
static void Event_PLUGIN_EVENT_FIRST_DYNAMIC(void *gcc_data, void *user_data)
{
    // skywalker_plugin.Debug("PLUGIN_EVENT_FIRST_DYNAMIC");
}

#pragma endregion Event

PluginAbility_PluginCallbackTest::PluginAbility_PluginCallbackTest()
{
}

PluginAbility_PluginCallbackTest::~PluginAbility_PluginCallbackTest()
{
}

void PluginAbility_PluginCallbackTest::Register()
{
    skywalker_plugin.Debug("PluginAbility_PluginCallbackTest::Register");

    // 注册事件
    // register_callback(skywalker_plugin.GetPluginName(), PLUGIN_START_PARSE_FUNCTION, (plugin_callback_func)Event_PLUGIN_START_PARSE_FUNCTION, nullptr);
    // register_callback(skywalker_plugin.GetPluginName(), PLUGIN_FINISH_PARSE_FUNCTION, (plugin_callback_func)Event_PLUGIN_FINISH_PARSE_FUNCTION, nullptr);
    // register_callback(skywalker_plugin.GetPluginName(), PLUGIN_PASS_MANAGER_SETUP, (plugin_callback_func)Event_PLUGIN_PASS_MANAGER_SETUP, nullptr); 使用这个回调会导致编译器崩溃
    // register_callback(skywalker_plugin.GetPluginName(), PLUGIN_FINISH_TYPE, (plugin_callback_func)Event_PLUGIN_FINISH_TYPE, nullptr); 没有回调
    // register_callback(skywalker_plugin.GetPluginName(), PLUGIN_FINISH_DECL, (plugin_callback_func)Event_PLUGIN_FINISH_DECL, nullptr);
    // register_callback(skywalker_plugin.GetPluginName(), PLUGIN_FINISH_UNIT, (plugin_callback_func)Event_PLUGIN_FINISH_UNIT, nullptr);
    // register_callback(skywalker_plugin.GetPluginName(), PLUGIN_PRE_GENERICIZE, (plugin_callback_func)Event_PLUGIN_PRE_GENERICIZE, nullptr);
    // register_callback(skywalker_plugin.GetPluginName(), PLUGIN_FINISH, (plugin_callback_func)Event_PLUGIN_FINISH, nullptr);
    // register_callback(skywalker_plugin.GetPluginName(), PLUGIN_INFO, (plugin_callback_func)Event_PLUGIN_INFO, nullptr); 使用这个回调会导致编译器崩溃
    // register_callback(skywalker_plugin.GetPluginName(), PLUGIN_GGC_START, (plugin_callback_func)Event_PLUGIN_GGC_START, nullptr); 没有回调
    // register_callback(skywalker_plugin.GetPluginName(), PLUGIN_GGC_MARKING, (plugin_callback_func)Event_PLUGIN_GGC_MARKING, nullptr); 没有回调
    // register_callback(skywalker_plugin.GetPluginName(), PLUGIN_GGC_END, (plugin_callback_func)Event_PLUGIN_GGC_END, nullptr); 没有回调
    // register_callback(skywalker_plugin.GetPluginName(), PLUGIN_REGISTER_GGC_ROOTS, (plugin_callback_func)Event_PLUGIN_REGISTER_GGC_ROOTS, nullptr); 使用这个回调会导致编译器崩溃
    register_callback(skywalker_plugin.GetPluginName(), PLUGIN_ATTRIBUTES, (plugin_callback_func)Event_PLUGIN_ATTRIBUTES, nullptr);
    // register_callback(skywalker_plugin.GetPluginName(), PLUGIN_START_UNIT, (plugin_callback_func)Event_PLUGIN_START_UNIT, nullptr);
    // register_callback(skywalker_plugin.GetPluginName(), PLUGIN_PRAGMAS, (plugin_callback_func)Event_PLUGIN_PRAGMAS, nullptr);
    // register_callback(skywalker_plugin.GetPluginName(), PLUGIN_ALL_PASSES_START, (plugin_callback_func)Event_PLUGIN_ALL_PASSES_START, nullptr);
    // register_callback(skywalker_plugin.GetPluginName(), PLUGIN_ALL_PASSES_END, (plugin_callback_func)Event_PLUGIN_ALL_PASSES_END, nullptr);
    // register_callback(skywalker_plugin.GetPluginName(), PLUGIN_ALL_IPA_PASSES_START, (plugin_callback_func)Event_PLUGIN_ALL_IPA_PASSES_START, nullptr);
    // register_callback(skywalker_plugin.GetPluginName(), PLUGIN_ALL_IPA_PASSES_END, (plugin_callback_func)Event_PLUGIN_ALL_IPA_PASSES_END, nullptr);
    // register_callback(skywalker_plugin.GetPluginName(), PLUGIN_OVERRIDE_GATE, (plugin_callback_func)Event_PLUGIN_OVERRIDE_GATE, nullptr); 打印太多了
    // register_callback(skywalker_plugin.GetPluginName(), PLUGIN_PASS_EXECUTION, (plugin_callback_func)Event_PLUGIN_PASS_EXECUTION, nullptr); 打印太多了
    // register_callback(skywalker_plugin.GetPluginName(), PLUGIN_EARLY_GIMPLE_PASSES_START, (plugin_callback_func)Event_PLUGIN_EARLY_GIMPLE_PASSES_START, nullptr);
    // register_callback(skywalker_plugin.GetPluginName(), PLUGIN_EARLY_GIMPLE_PASSES_END, (plugin_callback_func)Event_PLUGIN_EARLY_GIMPLE_PASSES_END, nullptr);
    // register_callback(skywalker_plugin.GetPluginName(), PLUGIN_NEW_PASS, (plugin_callback_func)Event_PLUGIN_NEW_PASS, nullptr); 没有回调
    // register_callback(skywalker_plugin.GetPluginName(), PLUGIN_INCLUDE_FILE, (plugin_callback_func)Event_PLUGIN_INCLUDE_FILE, nullptr);
    // register_callback(skywalker_plugin.GetPluginName(), PLUGIN_ANALYZER_INIT, (plugin_callback_func)Event_PLUGIN_ANALYZER_INIT, nullptr); 没有回调
    // register_callback(skywalker_plugin.GetPluginName(), PLUGIN_EVENT_FIRST_DYNAMIC, (plugin_callback_func)Event_PLUGIN_EVENT_FIRST_DYNAMIC, nullptr); 使用这个回调会导致编译器崩溃
}

void PluginAbility_PluginCallbackTest::UnRegister()
{
    skywalker_plugin.Debug("PluginAbility_PluginCallbackTest::UnRegister");

    // 反注册事件
    // unregister_callback(skywalker_plugin.GetPluginName(), PLUGIN_START_PARSE_FUNCTION);
    // unregister_callback(skywalker_plugin.GetPluginName(), PLUGIN_FINISH_PARSE_FUNCTION);
    // unregister_callback(skywalker_plugin.GetPluginName(), PLUGIN_PASS_MANAGER_SETUP); 使用这个回调会导致编译器崩溃
    // unregister_callback(skywalker_plugin.GetPluginName(), PLUGIN_FINISH_TYPE); 没有回调
    // unregister_callback(skywalker_plugin.GetPluginName(), PLUGIN_FINISH_DECL);
    // unregister_callback(skywalker_plugin.GetPluginName(), PLUGIN_FINISH_UNIT);
    // unregister_callback(skywalker_plugin.GetPluginName(), PLUGIN_PRE_GENERICIZE);
    // unregister_callback(skywalker_plugin.GetPluginName(), PLUGIN_FINISH);
    // unregister_callback(skywalker_plugin.GetPluginName(), PLUGIN_INFO); 使用这个回调会导致编译器崩溃
    // unregister_callback(skywalker_plugin.GetPluginName(), PLUGIN_GGC_START); 没有回调
    // unregister_callback(skywalker_plugin.GetPluginName(), PLUGIN_GGC_MARKING); 没有回调
    // unregister_callback(skywalker_plugin.GetPluginName(), PLUGIN_GGC_END); 没有回调
    // unregister_callback(skywalker_plugin.GetPluginName(), PLUGIN_REGISTER_GGC_ROOTS); 使用这个回调会导致编译器崩溃
    unregister_callback(skywalker_plugin.GetPluginName(), PLUGIN_ATTRIBUTES);
    // unregister_callback(skywalker_plugin.GetPluginName(), PLUGIN_START_UNIT);
    // unregister_callback(skywalker_plugin.GetPluginName(), PLUGIN_PRAGMAS);
    // unregister_callback(skywalker_plugin.GetPluginName(), PLUGIN_ALL_PASSES_START);
    // unregister_callback(skywalker_plugin.GetPluginName(), PLUGIN_ALL_PASSES_END);
    // unregister_callback(skywalker_plugin.GetPluginName(), PLUGIN_ALL_IPA_PASSES_START);
    // unregister_callback(skywalker_plugin.GetPluginName(), PLUGIN_ALL_IPA_PASSES_END);
    // unregister_callback(skywalker_plugin.GetPluginName(), PLUGIN_OVERRIDE_GATE); 打印太多了
    // unregister_callback(skywalker_plugin.GetPluginName(), PLUGIN_PASS_EXECUTION); 打印太多了
    // unregister_callback(skywalker_plugin.GetPluginName(), PLUGIN_EARLY_GIMPLE_PASSES_START);
    // unregister_callback(skywalker_plugin.GetPluginName(), PLUGIN_EARLY_GIMPLE_PASSES_END);
    // unregister_callback(skywalker_plugin.GetPluginName(), PLUGIN_NEW_PASS); 没有回调
    // unregister_callback(skywalker_plugin.GetPluginName(), PLUGIN_INCLUDE_FILE);
    // unregister_callback(skywalker_plugin.GetPluginName(), PLUGIN_ANALYZER_INIT);
    // unregister_callback(skywalker_plugin.GetPluginName(), PLUGIN_EVENT_FIRST_DYNAMIC); 使用这个回调会导致编译器崩溃
}

void PluginAbility_PluginCallbackTest::Release()
{
    skywalker_plugin.Debug("PluginAbility_PluginCallbackTest::Release");

    delete this;
}
