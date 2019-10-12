cmake_minimum_required(VERSION 3.10)

# ------------------------------------------------------------ Compiler options
set(PROJECT_NAME advectionEquation)
project(${PROJECT_NAME})

if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Debug)
endif()

message(STATUS "Build type: ${CMAKE_BUILD_TYPE}")

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
set(CMAKE_CXX_FLAGS_DEBUG "-g")
set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -O3")


# ------------------------------------------------------------ Setup paths

set(ROOT_DIR ${CMAKE_CURRENT_SOURCE_DIR})
set(SRC_DIR ${ROOT_DIR}/src)
set(INC_DIR ${ROOT_DIR}/include)
set(LIB_DIR ${ROOT_DIR}/lib)


# ------------------------------------------------------------ Source files
file(GLOB SOURCE ${SRC_DIR}/*.cpp
        ${INC_DIR}/*.h
        ${LIB_DIR}/simplePlot/include/*)

include_directories(
        ${INC_DIR}
        ${LIB_DIR}/simplePlot/include/)

link_directories(
        ${LIB_DIR}/simplePlot/bin/
)

# ------------------------------------------------------------ advectionEquation
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${ROOT_DIR})

add_executable(${PROJECT_NAME} ${SOURCE})
target_link_libraries(${PROJECT_NAME} simplePlot)
