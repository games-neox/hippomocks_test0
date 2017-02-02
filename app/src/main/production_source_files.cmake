#
# Copyright (c) 2017. Games Neox. All rights reserved.
#
# This file is an original work developed by Games Neox
#

target_sources(hdhomerun
        PUBLIC
        PRIVATE
        "${CMAKE_CURRENT_LIST_DIR}/cpp/core/tuners_native.cxx"
        "${CMAKE_CURRENT_LIST_DIR}/libhdhomerun/hdhomerun_channels.c"
        "${CMAKE_CURRENT_LIST_DIR}/libhdhomerun/hdhomerun_channelscan.c"
        "${CMAKE_CURRENT_LIST_DIR}/libhdhomerun/hdhomerun_control.c"
        "${CMAKE_CURRENT_LIST_DIR}/libhdhomerun/hdhomerun_debug.c"
        "${CMAKE_CURRENT_LIST_DIR}/libhdhomerun/hdhomerun_device.c"
        "${CMAKE_CURRENT_LIST_DIR}/libhdhomerun/hdhomerun_device_selector.c"
        "${CMAKE_CURRENT_LIST_DIR}/libhdhomerun/hdhomerun_discover.c"
        "${CMAKE_CURRENT_LIST_DIR}/libhdhomerun/hdhomerun_os_posix.c"
        "${CMAKE_CURRENT_LIST_DIR}/libhdhomerun/hdhomerun_pkt.c"
        "${CMAKE_CURRENT_LIST_DIR}/libhdhomerun/hdhomerun_sock_posix.c"
        "${CMAKE_CURRENT_LIST_DIR}/libhdhomerun/hdhomerun_video.c")

find_library(log-lib
        log)

include_directories(${CMAKE_CURRENT_LIST_DIR}/cpp/)
include_directories(${CMAKE_CURRENT_LIST_DIR}/libhdhomerun/)

target_link_libraries(hdhomerun
        ${log-lib})