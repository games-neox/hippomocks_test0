/*
 * Copyright (c) 2017. Games Neox. All rights reserved.
 *
 * This file is an original work developed by Games Neox
 */

#include "tuners_native.hxx"

#include <android/log.h>
#include <hdhomerun.h>

#define FIND_DEVICES_MAX_COUNT (10)



static const char* const LOG_TAG = "TunersNative-JNI";


jobject tuners_native_scan(JNIEnv* jniEnv)
{
    hdhomerun_discover_device_t discoverDevices[FIND_DEVICES_MAX_COUNT];
    const int findDevicesResult = hdhomerun_discover_find_devices_custom_v2(
            0, HDHOMERUN_DEVICE_TYPE_TUNER, HDHOMERUN_DEVICE_ID_WILDCARD, discoverDevices, FIND_DEVICES_MAX_COUNT);
    if (-1 == findDevicesResult)
    {
        __android_log_write(ANDROID_LOG_INFO, LOG_TAG, "scan(_,_): error while finding devices!, Exit(NULL)");
        return NULL;
    }
    else if (0 == findDevicesResult)
    {
        __android_log_write(ANDROID_LOG_INFO, LOG_TAG, "scan(_,_): no devices found!, Exit(NULL)");
        return NULL;
    }

    return NULL;
}
