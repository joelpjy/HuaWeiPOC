/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2020-2021. All rights reserved.
 * Description: The entry point class in sample, use different defined to distinct platform handle.
 */

#include "MainApplication/MainApplication.h"

#ifdef CG_ANDROID_PLATFORM
#include <android_native_app_glue.h>
#endif

#include <iostream>

using namespace CGKit;

void android_main(android_app* state)
{
    std::cout << "JOELLL YYY" << std::endl;

    // Instantiate the demo home page.
    auto app = CreateMainApplication();
    if (app == nullptr) {
        return;
    }

    std::cout << "JOELLL YYY" << std::endl;

    // Start platform rendering.
    app->Start(reinterpret_cast<void*>(state));

    // Start the rendering main loop.
    app->MainLoop();
    CG_SAFE_DELETE(app);
}
