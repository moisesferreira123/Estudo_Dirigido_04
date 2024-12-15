cmake_minimum_required(VERSION 3.15)
project(Estudo_Dirigido_04)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Definindo o modo Debug
set(CMAKE_BUILD_TYPE Debug)

# Adiciona as informações de depuração para todas as compilações
add_compile_options(-g)

include(FetchContent)

FetchContent_Declare(
    googletest
    GIT_REPOSITORY https://github.com/google/googletest.git
    GIT_TAG release-1.12.1
)

FetchContent_Declare(
    spdlog
    GIT_REPOSITORY https://github.com/gabime/spdlog.git
    GIT_TAG v1.12.0
)

FetchContent_MakeAvailable(googletest spdlog)

add_subdirectory(source)
add_subdirectory(test)

add_library(my_library source/main.cpp)
target_include_directories(my_library PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

find_package(fmt REQUIRED)
target_link_libraries(my_library PRIVATE fmt::fmt)