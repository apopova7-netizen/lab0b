cmake_minimum_required(VERSION 3.20)
project(word_count)

add_executable(
        word_count
        main.cpp
        word_count.h
        functions.cpp)

target_compile_features(word_count PRIVATE cxx_std_20)


