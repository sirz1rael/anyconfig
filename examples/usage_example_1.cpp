#include <iostream>
#include <anyconfig>

int main() {
    auto& config = anyconfig::AnyConfig<anyconfig::ConfigFileType::SERVER>::getInstance();
    config.parse();
    std::cout << "Hello from usage_example_1!" << std::endl;
}