cmake_minimum_required(VERSION 3.27)
project(CProject C)

set(CMAKE_C_STANDARD 11)

include_directories(cDataFrame)
include_directories(column)
include_directories(list)

add_executable(CProject
        cDataFrame/cDataFrame.c
        cDataFrame/cDataFrame.h
        column/column.c
        column/column.h
        list/list.c
        list/list.h
        CDataframe.c
        Column.c
        testing.c
        Union.h
        Union.c
        Union.c
        union/union.h
        main.c
        main.c
        main2.c
)
