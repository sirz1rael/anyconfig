#include "anyconfig.hpp"

namespace anyconfig {
    
    // Реализация нетемплейтной функции
    std::string_view typeToString(const ConfigFileType& type) {
        switch(type) {
            case ConfigFileType::YAML: return "YAML";
            case ConfigFileType::JSON: return "JSON";
            case ConfigFileType::INI: return "INI";
            case ConfigFileType::TOML: return "TOML";
            case ConfigFileType::ENV: return "ENV";
            case ConfigFileType::SERVER: return "SERVER";
            default: throw std::runtime_error("Unhandled ConfigFileType parameter");
        };
    }
    
    // Другие нетемплейтные функции
    void someUtilityFunction() {
        
    }

} // namespace anyconfig