cmake_minimum_required(VERSION 3.15)
project(orderbook CXX)

# C++ standard
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Generate compile_commands.json for IDE tooling (clangd, VS Code, etc.)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Optional: enable AddressSanitizer (build with -DENABLE_ASAN=ON)
option(ENABLE_ASAN "Enable AddressSanitizer" OFF)
if(ENABLE_ASAN)
    message(STATUS "AddressSanitizer enabled")
    add_compile_options(-fsanitize=address -fno-omit-frame-pointer -g)
    add_link_options(-fsanitize=address)
endif()

# Compile flags applied to all targets in this project
add_compile_options(-Wall -Wextra -Wpedantic)

# ---- Library: the order book engine ----
add_library(orderbook_lib
    src/price_level.cpp
    src/orderbook.cpp
)
target_include_directories(orderbook_lib PUBLIC include)

# ---- Executable: CSV driver ----
add_executable(csv_driver apps/csv_driver.cpp)
target_link_libraries(csv_driver PRIVATE orderbook_lib)

# ---- Testing ----
include(FetchContent)
FetchContent_Declare(
    googletest
    GIT_REPOSITORY https://github.com/google/googletest.git
    GIT_TAG        v1.14.0
)
# For Windows: don't override parent project compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()
add_subdirectory(tests)