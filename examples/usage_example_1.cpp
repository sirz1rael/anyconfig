#include <iostream>
#include <anyconfig>

int main() {
    auto& configInstance = anyconfig::AnyConfig<anyconfig::types::ConfigFileType::JSON>::GetInstance();
    auto config = configInstance.Parse();

    std::cout << "Hello from usage_example_1!" << std::endl;
}
