cmake_minimum_required(VERSION 3.1.0 FATAL_ERROR)
cmake_policy(SET CMP0076 NEW) 

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(test_cpp_app)

# add_subdirectory(../fmt ${CMAKE_CURRENT_BINARY_DIR}/fmt)


add_executable(test_cpp_app "")
target_sources(test_cpp_app
    PRIVATE
        test_class.h
        test_class.cpp
        main.cpp
)

# external libs?
# INCLUDE_DIRECTORIES(../lib/fmt/include)
# LINK_DIRECTORIES(your/library/dir)

# target_link_libraries(test_cpp_app fmt)
