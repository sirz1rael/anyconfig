#ifndef TYPES_DECL_HPP
#define TYPES_DECL_HPP

#include <cstdint>

namespace anyconfig::types {
    enum class ConfigFileType : std::uint8_t{
        YAML = 0,
        JSON,
        INI,
        TOML, 
        SERVER
    };
} // namespace anyconfig::types

#endif //TYPES_DECL_HPP