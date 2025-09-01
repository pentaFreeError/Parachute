cmake_minimum_required(VERSION 3.10)
project(tp04)

set(CMAKE_CXX_STANDARD 17)

find_package(Qt5 COMPONENTS Widgets REQUIRED)

set(CMAKE_AUTOMOC ON)

include_directories(include)

file(GLOB_RECURSE SOURCES "src/**/*.cpp")
file(GLOB_RECURSE HEADERS "include/**/*.h")


add_executable(tp04
    src/main.cpp
    ${SOURCES}
    ${HEADERS}  
)

target_include_directories(tp04 PRIVATE include)

file(GLOB TRANSLATION_FILES resources/translations/*.qm)
add_custom_target(translations ALL DEPENDS ${TRANSLATION_FILES})

qt5_add_resources(RESOURCES resources/resources.qrc)
target_sources(tp04 PRIVATE ${RESOURCES})

target_link_libraries(tp04 Qt5::Widgets)