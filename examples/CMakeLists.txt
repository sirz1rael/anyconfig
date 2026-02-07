add_executable(usage_example_1 usage_example_1.cpp)

target_link_libraries(usage_example_1 PRIVATE anyconfig::anyconfig)

if(CMAKE_BUILD_TYPE STREQUAL "Debug")
    target_compile_definitions(usage_example_1 PRIVATE DEBUG=1)
endif()