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

add_library(order include/order.h src/order.cpp)
add_library(new_order include/new_order.h src/new_order.cpp)
add_library(payment_processor include/payment_processor.h src/payment_processor.cpp)

add_executable(main_plain examples/main_plain.cpp)
target_link_libraries(main_plain order ${CONAN_LIBS})

add_executable(main_single_responsibility examples/main_single_responsibility.cpp)
target_link_libraries(main_single_responsibility new_order payment_processor ${CONAN_LIBS})

add_executable(main_open_closed examples/main_open_closed.cpp)
target_link_libraries(main_open_closed new_order ${CONAN_LIBS})

add_executable(main_liskov examples/main_liskov.cpp)
target_link_libraries(main_liskov new_order ${CONAN_LIBS})

add_executable(main_is_inh examples/main_is_inh.cpp)
target_link_libraries(main_is_inh new_order ${CONAN_LIBS})

add_executable(main_is_comp examples/main_is_comp.cpp)
target_link_libraries(main_is_comp new_order ${CONAN_LIBS})

add_executable(main_di_comp examples/main_di_comp.cpp)
target_link_libraries(main_di_comp new_order ${CONAN_LIBS})