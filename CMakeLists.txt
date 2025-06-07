cmake_minimum_required(VERSION 3.10.0)

project(
    memo
    VERSION 0.1.0
    LANGUAGES C CXX
)

set(CXX_STANDARD 17)
set(CXX_STANDARD_REQUIRED True)

find_package(nlohmann_json REQUIRED)

add_executable(
    memo
    main.cpp
    src/memo.cpp
)
target_link_libraries(
    memo
    PRIVATE nlohmann_json::nlohmann_json
)
target_include_directories(
    memo
    PUBLIC src
)
