#pragma once
#include <map>
#include <string>
#include "json/value.h"

class ConfigManager
{
public:
    ConfigManager();
    ~ConfigManager();
    bool Initialize(const std::string& configPath);

    std::map<std::string, std::string> GetCmdConfigMap();

private:
    bool Parse();
    void ParseCmdConfig(const Json::Value& jsCmd);

private:
    std::string m_configPath = "";
    std::map<std::string, std::string> m_cmdConfigMap;
};
