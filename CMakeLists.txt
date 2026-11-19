cmake_minimum_required(VERSION 3.30)
project(LinearAlgebra LANGUAGES CXX)

##setting c++ standard;
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_CXX_EXTENSIONS False)

set(CMAKE_EXPORT_COMPILE_COMMANDS true) #need this to make clangd lsp work properly, as it tells lsp where proj root is, etc.

##debug handling (rendered irrelevant by presets)
#if(NOT CMAKE_BUILD_TYPE)
#    set(CMAKE_BUILD_TYPE Debug)
#endif()

##adding executable from src/main.cpp;
add_executable(LA_row_reduction 
    src/main.cpp
)

##headers
target_include_directories(LA_row_reduction PRIVATE include)

##macro for debug
target_compile_definitions(LA_row_reduction PRIVATE
    $<$<CONFIG:Debug>:LA_DEBUG>
)

##enabling compiler warnings;
if(MSVC)
    target_compile_options(LA_row_reduction PRIVATE /W4)
else()
    target_compile_options(LA_row_reduction PRIVATE
    -Wall -Wextra -Wpedantic -g
    )
endif()

#build commands should be:
#   cmake -S . -B build -G "Ninja Multi-Config" 
#(note, you only need to run the above once)


#   cmake --build build --config Debug
#   cmake --build build --config Release
