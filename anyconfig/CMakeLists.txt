set(LIB_SOURCES 
    src/anyconfig.cpp
    src/parser.cpp
    src/config.cpp
)

add_library(anyconfig ${LIB_SOURCES})

target_include_directories(anyconfig
    PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        $<INSTALL_INTERFACE:include>
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/${LIB_SOURCES}
)

target_compile_features(anyconfig PUBLIC cxx_std_20)
target_compile_options(anyconfig PRIVATE -Wall -Wextra -Wpedantic -Werror)

add_library(anyconfig_interface INTERFACE)
target_link_libraries(anyconfig_interface INTERFACE anyconfig)
add_library(anyconfig::anyconfig ALIAS anyconfig_interface)

find_package(nlohmann_json 3.2.0 CONFIG REQUIRED)
target_link_libraries(anyconfig PUBLIC nlohmann_json::nlohmann_json)

set_target_properties(anyconfig PROPERTIES
    VERSION ${PROJECT_VERSION}
    SOVERSION ${PROJECT_VERSION_MAJOR}
    PUBLIC_HEADER "${CMAKE_CURRENT_SOURCE_DIR}/include/anyconfig/anyconfig.hpp"
)

set_source_files_properties(
    include/anyconfig/anyconfig.ipp
    PROPERTIES HEADER_FILE_ONLY TRUE
)

if(ANYCONFIG_INSTALL)
    include(GNUInstallDirs)
    
    install(TARGETS anyconfig
        EXPORT anyconfig-targets
        ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
        LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
        RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
        PUBLIC_HEADER DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/anyconfig
        INCLUDES DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
    )
    
    install(DIRECTORY include/ DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})
    
    install(EXPORT anyconfig-targets
        FILE anyconfig-config.cmake
        NAMESPACE anyconfig::
        DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/anyconfig
    )
endif()