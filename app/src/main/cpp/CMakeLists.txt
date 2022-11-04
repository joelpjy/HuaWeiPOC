# At least CMake 3.10.2 is required.
cmake_minimum_required(VERSION 3.10.2)

# Include the header file directory.
include_directories(${CMAKE_SOURCE_DIR}/include
        ${CMAKE_SOURCE_DIR}/include/CGRenderingFramework
        ${CMAKE_SOURCE_DIR}/include/AIFaceMod)

# Add the source code files of libmain.so.
add_library(
        main-lib
        SHARED
        source/Main.cpp
        source/MainApplication.cpp
        source/OSRPlugin.cpp )

# Import libcgkit.so.
ADD_LIBRARY(
        cgkit
        SHARED
        IMPORTED)

# Set the libcgkit.so directory.
set_target_properties(cgkit
        PROPERTIES IMPORTED_LOCATION
        ${CMAKE_SOURCE_DIR}/../../../libs/${ANDROID_ABI}/libcgkit.so
        )


# Include the Vulkan header files.
SET(
        VULKAN_INCLUDE_DIR
        "$ENV{VULKAN_SDK}/include")
#"${ANDROID_NDK}/sources/third_party/vulkan/src/include")

include_directories(${VULKAN_INCLUDE_DIR})

# Set the native_app_glue directory.
SET(
        NATIVE_APP_GLUE_DIR
        "${ANDROID_NDK}/sources/android/native_app_glue")

FILE(
        GLOB NATIVE_APP_GLUE_FILLES
        "${NATIVE_APP_GLUE_DIR}/*.c"
        "${NATIVE_APP_GLUE_DIR}/*.h")

# Import native_app_glue.
ADD_LIBRARY(native_app_glue
        STATIC
        ${NATIVE_APP_GLUE_FILLES})

TARGET_INCLUDE_DIRECTORIES(
        native_app_glue
        PUBLIC
        ${NATIVE_APP_GLUE_DIR})

# Search for the log module.
find_library(
        log-lib
        log )



ADD_LIBRARY(
        AIFaceMod
        SHARED
        IMPORTED)
set_target_properties(AIFaceMod
        PROPERTIES IMPORTED_LOCATION
        ${CMAKE_SOURCE_DIR}/../../../libs/${ANDROID_ABI}/libAIFaceMod.so
        )

ADD_LIBRARY(
        ai_fmk_dnnacl
        SHARED
        IMPORTED)
set_target_properties(ai_fmk_dnnacl
        PROPERTIES IMPORTED_LOCATION
        ${CMAKE_SOURCE_DIR}/../../../libs/${ANDROID_ABI}/libai_fmk_dnnacl.so
        )

ADD_LIBRARY(
        cpucl
        SHARED
        IMPORTED)
set_target_properties(cpucl
        PROPERTIES IMPORTED_LOCATION
        ${CMAKE_SOURCE_DIR}/../../../libs/${ANDROID_ABI}/libcpucl.so
        )
ADD_LIBRARY(
        hcl
        SHARED
        IMPORTED)
set_target_properties(hcl
        PROPERTIES IMPORTED_LOCATION
        ${CMAKE_SOURCE_DIR}/../../../libs/${ANDROID_ABI}/libhcl.so
        )
ADD_LIBRARY(
        hiai
        SHARED
        IMPORTED)
set_target_properties(hiai
        PROPERTIES IMPORTED_LOCATION
        ${CMAKE_SOURCE_DIR}/../../../libs/${ANDROID_ABI}/libhiai.so
        )
ADD_LIBRARY(
        hiai_aar_adapter
        SHARED
        IMPORTED)
set_target_properties(hiai_aar_adapter
        PROPERTIES IMPORTED_LOCATION
        ${CMAKE_SOURCE_DIR}/../../../libs/${ANDROID_ABI}/libhiai_aar_adapter.so
        )
ADD_LIBRARY(
        hiai_binary_model_runtime
        SHARED
        IMPORTED)
set_target_properties(hiai_binary_model_runtime
        PROPERTIES IMPORTED_LOCATION
        ${CMAKE_SOURCE_DIR}/../../../libs/${ANDROID_ABI}/libhiai_binary_model_runtime.so
        )
ADD_LIBRARY(
        hiai_hcl_model_runtime
        SHARED
        IMPORTED)
set_target_properties(hiai_hcl_model_runtime
        PROPERTIES IMPORTED_LOCATION
        ${CMAKE_SOURCE_DIR}/../../../libs/${ANDROID_ABI}/libhiai_hcl_model_runtime.so
        )
ADD_LIBRARY(
        hiai_ir
        SHARED
        IMPORTED)
set_target_properties(hiai_ir
        PROPERTIES IMPORTED_LOCATION
        ${CMAKE_SOURCE_DIR}/../../../libs/${ANDROID_ABI}/libhiai_ir.so
        )
ADD_LIBRARY(
        hiai_ir_build
        SHARED
        IMPORTED)
set_target_properties(hiai_ir_build
        PROPERTIES IMPORTED_LOCATION
        ${CMAKE_SOURCE_DIR}/../../../libs/${ANDROID_ABI}/libhiai_ir_build.so
        )
ADD_LIBRARY(
        hiai_v1cl
        SHARED
        IMPORTED)
set_target_properties(hiai_v1cl
        PROPERTIES IMPORTED_LOCATION
        ${CMAKE_SOURCE_DIR}/../../../libs/${ANDROID_ABI}/libhiai_v1cl.so
        )
ADD_LIBRARY(
        modelcrypto
        SHARED
        IMPORTED)
set_target_properties(modelcrypto
        PROPERTIES IMPORTED_LOCATION
        ${CMAKE_SOURCE_DIR}/../../../libs/${ANDROID_ABI}/libmodelcrypto.so
        )


target_link_libraries(
        main-lib
        cgkit
        AIFaceMod
        ai_fmk_dnnacl
        cpucl
        hcl
        hiai
        hiai_aar_adapter
        hiai_binary_model_runtime
        hiai_hcl_model_runtime
        hiai_ir
        hiai_ir_build
        hiai_v1cl
        modelcrypto
        native_app_glue
        android
        ${log-lib} )

SET(
        CMAKE_SHARED_LINKER_FLAGS
        "${CMAKE_SHARED_LINKER_FLAGS} -u ANativeActivity_onCreate")