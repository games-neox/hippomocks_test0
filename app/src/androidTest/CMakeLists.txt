#
# Copyright (c) 2017. Games Neox. All rights reserved.
#
# This file is an original work developed by Games Neox
#

cmake_minimum_required(VERSION 3.4.1)

project(HDHomeRun)

add_library(hdhomerun SHARED "")

target_compile_options(hdhomerun PRIVATE -fexceptions)

include(test_source_files.cmake)
include(../main/production_source_files.cmake)
