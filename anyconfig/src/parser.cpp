#include "parser.hpp"
#include "anyconfig.hpp"
#include "config.hpp"
#include "types_decl.hpp"
#include <iostream>
#include <memory>
#include <stdexcept>

namespace anyconfig::parsing {

class JsonParser : public Parser {
public:
    config::Config parse() override {
        return {};
    }
private:
    
};

class IniParser : public Parser {
public:
    config::Config parse() override {
        return {};
    }
private:

};

class TomlParser : public Parser {
public:
    config::Config parse() override {
        return {};
    }
private:
};

class YamlParser : public Parser {
public:
    config::Config parse() override {
        return {};
    }
private:

};

class ServerParser : public Parser {
public:
    config::Config parse() override {
        return {};
    }
private:
};

static const std::unordered_map<types::ConfigFileType, ParserFactory> parserFactoryMap = {
    { types::ConfigFileType::JSON, []{ return std::make_unique<JsonParser>();     } },
    { types::ConfigFileType::INI, []{ return std::make_unique<IniParser>();       } },
    { types::ConfigFileType::TOML, []{ return std::make_unique<TomlParser>();     } },
    { types::ConfigFileType::YAML, []{ return std::make_unique<YamlParser>();     } },
    { types::ConfigFileType::SERVER, []{ return std::make_unique<ServerParser>(); } },
};

// Factory implementation
std::unique_ptr<Parser> CreateParser(types::ConfigFileType type) {
    std::cout << "Creating parser for type: " << TypeToString(type) << std::endl;

    auto it = parserFactoryMap.find(type);
    if (it == parserFactoryMap.end()) {
        throw std::runtime_error("No parser registered for type: " + std::to_string(static_cast<int>(type)));
    }

    return it->second();
}


} // namespace anyconfig::parsing