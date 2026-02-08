#ifndef ANYCONFIG_HPP
#define ANYCONFIG_HPP

#include <iostream>
#include <string_view>
#include "parser.hpp"
#include "config.hpp"
#include "types_decl.hpp"

namespace anyconfig {
    
    std::string_view TypeToString(const types::ConfigFileType& type);

    template<types::ConfigFileType T>  // Note: using T as template parameter
    class AnyConfig {
    private:
        // You can store the type if needed, but template parameter T is compile-time
        static constexpr types::ConfigFileType _configFileType = T;
        
        AnyConfig() {
            std::cout << "Config Type: " << TypeToString(T) << '\n';
        }
        
    public:
        AnyConfig(AnyConfig const&) = delete;
        void operator=(AnyConfig const&) = delete;

        static AnyConfig& GetInstance() {
            static AnyConfig instance;
            return instance;
        }
        
        config::Config Parse() {
            auto parserFactory = parsing::CreateParser(T);
            if (!parserFactory) {
                throw std::runtime_error("Parser factory returned null");
            }
            auto config = parserFactory->parse();
            return config;
        }
    };
}

#endif // ANYCONFIG_HPP