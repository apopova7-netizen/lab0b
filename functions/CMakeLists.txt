add_library(functions STATIC count_words.cpp
                             read_lines.cpp
                             sort_words.cpp
                             write_results.cpp
                             word_count.h)

target_compile_features(functions PRIVATE cxx_std_20)
target_include_directories(functions PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

