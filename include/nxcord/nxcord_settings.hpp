#pragma once

#include <SimpleIniParser.hpp>
#include <cstring>
#include <memory>

#define CONFIG_PATH "/config/nxcord"
#define CONFIG_NAME "nxcord.ini"

class NXCordSettings {
 private:
  NXCordSettings();

  std::unique_ptr<simpleIniParser::Ini> _ini_instance;
  std::string _file_path;

#define CREATE_SETTING(SECTION, KEY, DEFAULT)                            \
  std::string get##SECTION##KEY() const {                                \
    std::string value;                                                   \
    if (strlen(#SECTION) > 0) {                                          \
      auto section = _ini_instance->findSection(#SECTION);               \
      if (section) {                                                     \
        auto option = section->findFirstOption(#KEY);                    \
        if (option) {                                                    \
          value = option->value;                                         \
        }                                                                \
      }                                                                  \
    } else {                                                             \
      auto option = _ini_instance->findFirstOption(#KEY);                \
      if (option) {                                                      \
        value = option->value;                                           \
      }                                                                  \
    }                                                                    \
    return value.empty() ? #DEFAULT : value;                             \
  }                                                                      \
  void set##SECTION##KEY(const std::string& value) {                     \
    if (strlen(#SECTION) > 0) {                                          \
      auto section = _ini_instance->findSection(#SECTION);               \
      if (!section) {                                                    \
        section = new simpleIniParser::IniSection(                       \
            simpleIniParser::IniSectionType::Section, #SECTION);         \
        _ini_instance->sections.push_back(section);                      \
      }                                                                  \
      auto option = section->findFirstOption(#KEY);                      \
      if (option) {                                                      \
        option->value = value;                                           \
        _ini_instance->writeToFile(_file_path);                          \
      } else {                                                           \
        _ini_instance->options.push_back(new simpleIniParser::IniOption( \
            simpleIniParser::IniOptionType::Option, #KEY, value));       \
        _ini_instance->writeToFile(_file_path);                          \
      }                                                                  \
    } else {                                                             \
      auto option = _ini_instance->findFirstOption(#KEY);                \
      if (option) {                                                      \
        option->value = value;                                           \
        _ini_instance->writeToFile(_file_path);                          \
      } else {                                                           \
        _ini_instance->options.push_back(new simpleIniParser::IniOption( \
            simpleIniParser::IniOptionType::Option, #KEY, value));       \
        _ini_instance->writeToFile(_file_path);                          \
      }                                                                  \
    }                                                                    \
  }

 public:
  inline bool valid() const { return _ini_instance != nullptr; }

  CREATE_SETTING(, token, )

  static std::unique_ptr<NXCordSettings> New();
};
