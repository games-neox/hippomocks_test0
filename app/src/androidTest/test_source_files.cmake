#
# Copyright (c) 2017. Games Neox. All rights reserved.
#
# This file is an original work developed by Games Neox
#

target_sources(hdhomerun
        PUBLIC
        "${CMAKE_CURRENT_LIST_DIR}/cpp/hippomocks/hippomocks.h"
        PRIVATE
        "${CMAKE_CURRENT_LIST_DIR}/cpp/core/cpp_core_TunersNativeTest.cxx")

include_directories(${CMAKE_CURRENT_LIST_DIR}/cpp/)
