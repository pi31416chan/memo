cmake_minimum_required(VERSION 3.10.0)

project(
    memo
    VERSION 1.0.0
    LANGUAGES C CXX
)

set(CXX_STANDARD 17)
set(CXX_STANDARD_REQUIRED True)

find_package(nlohmann_json REQUIRED)

add_executable(
    memo
    main.cpp
    src/memo.cpp
    src/message.cpp
    src/util.cpp
)
target_link_libraries(
    memo
    PRIVATE nlohmann_json::nlohmann_json
)
target_include_directories(
    memo
    PUBLIC src
)

# Build junk_.cpp for development testing if CMAKE_BUILD_TYPE == "Debug"
if(CMAKE_BUILD_TYPE STREQUAL "Debug" AND EXISTS "${PROJECT_SOURCE_DIR}/junk_.cpp")
    add_executable(
        junk junk_.cpp
    )
    target_link_libraries(
        junk
        PRIVATE nlohmann_json::nlohmann_json
    )
    target_include_directories(
        junk
        PUBLIC src
    )
endif()
