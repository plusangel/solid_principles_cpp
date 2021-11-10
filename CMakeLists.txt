cmake_minimum_required(VERSION 3.20)
project(solid_principles)

set(CMAKE_CXX_STANDARD 20)

if (EXISTS ${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
    include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
    conan_basic_setup()
else ()
    message(WARNING "The file conanbuildinfo.cmake doesn't exist, you have to run conan install first")
endif ()

include_directories(
        include
)

add_library(order include/order.h order.cpp)

add_executable(solid_principles main.cpp)
target_link_libraries(solid_principles order ${CONAN_LIBS})
