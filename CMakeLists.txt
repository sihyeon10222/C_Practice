cmake_minimum_required(VERSION 3.15)

project(C_Practice C)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)

file(GLOB PRACTICE_FILES CONFIGURE_DEPENDS "*.c")

foreach(source_file ${PRACTICE_FILES})
    get_filename_component(file_name ${source_file} NAME_WE)

    add_executable(practice_${file_name} ${source_file})
endforeach()