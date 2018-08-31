cmake_minimum_required(VERSION 2.8)

set (CMAKE_CXX_STANDARD 14)

project(extendible_hashing)


file(GLOB EXECUTABLES
    "include/*.h"
    "src/*.cpp"
)


add_executable(${PROJECT_NAME} ${EXECUTABLES} )


target_include_directories(${PROJECT_NAME}
    PRIVATE
        ${PROJECT_SOURCE_DIR}/include
)
