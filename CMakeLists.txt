cmake_minimum_required(VERSION 3.20)
project(word_count)

add_subdirectory(functions)

add_executable(
        word_count
        main.cpp
)

target_compile_features(word_count PRIVATE cxx_std_20)
target_link_libraries(word_count PRIVATE functions)

