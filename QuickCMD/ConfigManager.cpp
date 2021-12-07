#include "CommonDefine.h"
#include <fstream>
#include "json/reader.h"
#include "ConfigManager.h"

static std::string CONFG_FILE = "setting.json";

ConfigManager::ConfigManager()
{
}

ConfigManager::~ConfigManager()
{
}

bool ConfigManager::Initialize(const std::string& configPath)
{
    m_configPath = configPath + "/" + CONFG_FILE;
    return Parse();
}

std::map<std::string, std::string> ConfigManager::GetCmdConfigMap()
{
    return m_cmdConfigMap;
}

bool ConfigManager::Parse()
{
    Json::CharReaderBuilder rbuilder;
    rbuilder["collectComments"] = false;
    Json::Value jsConfig;
    std::string errs;
    std::ifstream ifs;
    ifs.open(m_configPath);
    CHECK_FALSE_RETURN(ifs.is_open(), false);
    bool parseResult = Json::parseFromStream(rbuilder, ifs, &jsConfig, &errs);
    ifs.close();

    if (parseResult)
    {
        ParseCmdConfig(jsConfig);
    }
    return true;
}

void ConfigManager::ParseCmdConfig(const Json::Value& jsCmd)
{
    Json::Value::Members cmdMembers = jsCmd.getMemberNames();
    for (auto cmd : cmdMembers)
    {
        std::string config = jsCmd[cmd].asString();
        auto finder = m_cmdConfigMap.find(cmd);
        if (finder == m_cmdConfigMap.end())
        {
            m_cmdConfigMap.emplace(std::make_pair(cmd, config));
            LOG(INFO) << cmd << " : " << config;
        }
        else
        {
            LOG(WARNING) << cmd << " is overwrite by new value, old:" << finder->second << " new:" << config;
            m_cmdConfigMap[cmd] = config;
        }
    }
}