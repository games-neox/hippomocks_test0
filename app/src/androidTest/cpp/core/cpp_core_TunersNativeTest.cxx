/*
 * Copyright (c) 2017. Games Neox. All rights reserved.
 *
 * This file is an original work developed by Games Neox
 */

#include "cpp_core_TunersNativeTest.h"

#include "core/tuners_native.hxx"
#include "hippomocks/hippomocks.h"

#include <android/log.h>
#include <hdhomerun.h>



#define TUNERS_NATIVE_TEST_LOG_TAG        "TunersNativeTest-JNI"


static int hdhomerun_discover_find_devices_custom_v2_for_nativeTestScanErrorFindingDevices(
        uint32_t targetIp, uint32_t deviceType, uint32_t deviceId, struct hdhomerun_discover_device_t resultList[], int maxCount);
static bool unexpectedParameterForNativeTestScanFound;

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus

/*!
  \return \a JNI_TRUE if the test succeeded, \a JNI_FALSE otherwise
 */
JNIEXPORT jboolean JNICALL Java_cpp_core_TunersNativeTest_nativeTestScanErrorFindingDevices(JNIEnv* jniEnv, jobject jniTunersNativeTest)
{
    unexpectedParameterForNativeTestScanFound = false;

    MockRepository mocks;
    mocks.OnCallFunc(hdhomerun_discover_find_devices_custom_v2)
            .With(_, _, _, _, _)
            .Do(hdhomerun_discover_find_devices_custom_v2_for_nativeTestScanErrorFindingDevices);

    jobject tunersNativeScanResult = tuners_native_scan(jniEnv);

    if (unexpectedParameterForNativeTestScanFound)
    {
        __android_log_write(ANDROID_LOG_ERROR, TUNERS_NATIVE_TEST_LOG_TAG, "nativeTestScanErrorFindingDevices(_,_): expectations failed!");
        return JNI_FALSE;
    }

    if (JNI_FALSE == jniEnv->IsSameObject(NULL, tunersNativeScanResult))
    {
        __android_log_write(ANDROID_LOG_ERROR, TUNERS_NATIVE_TEST_LOG_TAG, "nativeTestScanErrorFindingDevices(_,_): not a NULL returned!");
        return JNI_FALSE;
    }

    return JNI_TRUE;
}

#ifdef __cplusplus
}
#endif // __cplusplus

static bool hdhomerun_discover_find_devices_custom_v2_validateParameters(
        uint32_t targetIp, uint32_t deviceType, uint32_t deviceId, struct hdhomerun_discover_device_t resultList[], int maxCount)
{
    // TODO: enhance this validation
    if ((HDHOMERUN_DEVICE_TYPE_TUNER != deviceType)
            || (HDHOMERUN_DEVICE_ID_WILDCARD != deviceId)
            || (nullptr == resultList)
            || (1 > maxCount))
    {
        unexpectedParameterForNativeTestScanFound = true;
    }

    return unexpectedParameterForNativeTestScanFound;
}


static int hdhomerun_discover_find_devices_custom_v2_for_nativeTestScanErrorFindingDevices(
        uint32_t targetIp, uint32_t deviceType, uint32_t deviceId, struct hdhomerun_discover_device_t resultList[], int maxCount)
{
    hdhomerun_discover_find_devices_custom_v2_validateParameters(targetIp, deviceType, deviceId, resultList, maxCount);

    return (-1);
}
