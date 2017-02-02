/*
 * Copyright (c) 2017. Games Neox. All rights reserved.
 *
 * This file is an original work developed by Games Neox
 */

package cpp.test;

import org.junit.BeforeClass;

public abstract class LibraryLoader {

    @BeforeClass
    public static void beforeClass() {
        System.loadLibrary("hdhomerun");
    }
}
