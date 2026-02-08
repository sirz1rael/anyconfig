#ifndef PARSER_HPP
#define PARSER_HPP

#include "config.hpp"
#include "types_decl.hpp"
#include <memory>
#include <functional>

namespace anyconfig::parsing {



class Parser {
public:
    virtual ~Parser() = default;
    virtual config::Config parse() = 0;
    
protected:
    Parser() = default;
};

using ParserFactory = std::function<std::unique_ptr<Parser>()>;

// Factory function, not a template method
std::unique_ptr<Parser> CreateParser(types::ConfigFileType type);

} // namespace anyconfig::parsing

#endif // PARSER_HPP