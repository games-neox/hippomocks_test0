/*
 * Copyright (c) 2017. Games Neox. All rights reserved.
 *
 * This file is an original work developed by Games Neox
 */

package cpp.core;

import android.support.test.runner.AndroidJUnit4;

import org.junit.Test;
import org.junit.runner.RunWith;

import cpp.test.LibraryLoader;

import static org.junit.Assert.assertTrue;

@RunWith(AndroidJUnit4.class)
public final class TunersNativeTest extends LibraryLoader {

    @Test
    public void testScanErrorFindingDevices() {
        assertTrue(nativeTestScanErrorFindingDevices());
    }

    private native boolean nativeTestScanErrorFindingDevices();
}
