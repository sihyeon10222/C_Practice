cmake_minimum_required(VERSION 3.15)

project(C_Practice C)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)

file(GLOB PRACTICE_FILES CONFIGURE_DEPENDS "*.c")
list(REMOVE_ITEM PRACTICE_FILES
        ${CMAKE_CURRENT_SOURCE_DIR}/Class9.c
        ${CMAKE_CURRENT_SOURCE_DIR}/company.c)

foreach(source_file ${PRACTICE_FILES})
    get_filename_component(file_name ${source_file} NAME_WE)

    add_executable(practice_${file_name} ${source_file})
endforeach()

add_executable(practice_Class9 Class9.c company.c company.h)
