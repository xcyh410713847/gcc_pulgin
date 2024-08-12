/*************************************************************************
**文件: skywalker-gcc-plugin/SkywalkerPlugin.cpp
**作者: shyfan
**日期: 2024/07/29 16:09:13
**功能: Skywalker插件
*************************************************************************/

#include "SkywalkerPlugin.h"

SkywalkerPlugin skywalker_plugin;

/**
 * 插件信息
 */
SSkywalkerPluginInfo SkywalkerPlugin::PluginInfo = {
	/**
	 * 插件名称
	 */
	"SkywalkerPlugin",

	/**
	 * 插件版本
	 */
	"1.0.0",
};

SkywalkerPlugin::SkywalkerPlugin()
{
	Info("Skywalker GCC Plugin Version: %s", skywalker_plugin.GetPluginVersion());
}

SkywalkerPlugin::~SkywalkerPlugin()
{
	// 释放插件能力
	for (auto iter = PluginAbilityMap.begin(); iter != PluginAbilityMap.end(); iter++)
	{
		// 反注册插件能力
		iter->second->UnRegister();

		// 释放插件能力
		iter->second->Release();
	}

	// 清空插件能力列表
	PluginAbilityMap.clear();
}

#pragma region Log

void SkywalkerPlugin::Debug(const char *format, ...)
{
	va_list args;
	va_start(args, format);

	// 获取格式化后的信息所需的总长度
	int len = std::vsnprintf(nullptr, 0, format, args);
	va_end(args);

	// 重新启动 var args, 因为长度计算后需要重置
	va_start(args, format);

	// 分配一个足够大的缓冲区
	char *message = new char[len + 1];
	std::vsnprintf(message, len + 1, format, args);
	va_end(args);

	// 打印调试信息
	printf("[%s] [DEBUG     ] %s\n", GetPluginName(), message);

	// 清理缓冲区
	delete[] message;
}

void SkywalkerPlugin::Info(const char *format, ...)
{
	va_list args;
	va_start(args, format);

	// 获取格式化后的信息所需的总长度
	int len = std::vsnprintf(nullptr, 0, format, args);
	va_end(args);

	// 重新启动 var args, 因为长度计算后需要重置
	va_start(args, format);

	// 分配一个足够大的缓冲区
	char *message = new char[len + 1];
	std::vsnprintf(message, len + 1, format, args);
	va_end(args);

	// 打印信息
	printf("[%s] [INFO      ] %s\n", GetPluginName(), message);

	// 清理缓冲区
	delete[] message;
}

void SkywalkerPlugin::Warning(const char *format, ...)
{
	va_list args;
	va_start(args, format);

	// 获取格式化后的信息所需的总长度
	int len = std::vsnprintf(nullptr, 0, format, args);
	va_end(args);

	// 重新启动 var args, 因为长度计算后需要重置
	va_start(args, format);

	// 分配一个足够大的缓冲区
	char *message = new char[len + 1];
	std::vsnprintf(message, len + 1, format, args);
	va_end(args);

	// 打印警告信息
	printf("[%s] [WARNING   ] %s\n", GetPluginName(), message);

	// 清理缓冲区
	delete[] message;
}

void SkywalkerPlugin::Error(const char *format, ...)
{
	va_list args;
	va_start(args, format);

	// 获取格式化后的信息所需的总长度
	int len = std::vsnprintf(nullptr, 0, format, args);
	va_end(args);

	// 重新启动 var args, 因为长度计算后需要重置
	va_start(args, format);

	// 分配一个足够大的缓冲区
	char *message = new char[len + 1];
	std::vsnprintf(message, len + 1, format, args);
	va_end(args);

	// 打印错误信息
	printf("[%s] [ERROR     ] %s\n", GetPluginName(), message);

	// 清理缓冲区
	delete[] message;
}

#pragma endregion Log

void SkywalkerPlugin::Help()
{
	Info("SkywalkerPlugin Help:");
}
