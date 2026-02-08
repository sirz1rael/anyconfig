#include "anyconfig.hpp"
#include "types_decl.hpp"

namespace anyconfig {
    
    // Реализация нетемплейтной функции
    std::string_view TypeToString(const types::ConfigFileType& type) {
        switch(type) {
            case types::ConfigFileType::YAML: return "YAML";
            case types::ConfigFileType::JSON: return "JSON";
            case types::ConfigFileType::INI: return "INI";
            case types::ConfigFileType::TOML: return "TOML";
            case types::ConfigFileType::SERVER: return "SERVER";
            default: throw std::runtime_error("Unhandled ConfigFileType parameter");
        };
    }
} // namespace anyconfig