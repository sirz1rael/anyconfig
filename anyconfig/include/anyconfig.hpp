#ifndef ANYCONFIG_HPP
#define ANYCONFIG_HPP


#include <iostream>
#include <string_view>

namespace anyconfig {
    enum class ConfigFileType {
        YAML, JSON, INI, TOML, ENV, SERVER
    };

    std::string_view typeToString(const ConfigFileType& type);

    template<ConfigFileType type>
    class AnyConfig {
    private:
        ConfigFileType _config_file_type;
        AnyConfig() {
            _config_file_type = type;
            std::cout << "Config Type: " << typeToString(_config_file_type) << '\n';
        }
        
    public:
        AnyConfig(AnyConfig const&) = delete;
        void operator=(AnyConfig const&) = delete;

        static AnyConfig& getInstance() {
            static AnyConfig instance;
            return instance;
        }
        void parse() {
            std::cout << "Parsing " << typeToString(type) << " config" << std::endl;
        }
    };
}

#endif // ANYCONFIG_HPP