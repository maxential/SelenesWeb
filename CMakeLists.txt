cmake_minimum_required(VERSION 3.30)

set(VCPKG_TARGET_TRIPLET "x64-mingw-static" CACHE STRING "Target triplet for vcpkg")
set(CMAKE_PREFIX_PATH "C:/vcpkg/installed/x64-mingw-static" CACHE STRING "vcpkg prefix path")
set(CMAKE_TOOLCHAIN_FILE "C:/vcpkg/scripts/buildsystems/vcpkg.cmake" CACHE STRING "" FORCE)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_VERBOSE_MAKEFILE ON)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/build)

project(SelenesWeb)

if(WIN32)
    message(STATUS "Running on Windows")
    # Enable WIN32_LEAN_AND_MEAN
    add_definitions(-DWIN32_LEAN_AND_MEAN)
elseif(UNIX)
    # Unix-specific configurations
endif()

# Add include directories for the target (not globally)
add_executable(SelenesWeb
        src/main.cpp
        src/game/BaseCharacter.cpp
        src/game/BaseCharacter.h
        src/common/common.h
        src/game/LocalPlayer.cpp
        src/game/LocalPlayer.h
        src/game/BossCharacter.cpp
        src/game/BossCharacter.h
        src/game/game.cpp
        src/game/game.h
        src/common/ConsoleManager.cpp
        src/common/ConsoleManager.h
        src/Engine/Engine.cpp
        src/Engine/Engine.h
        dependencies/include/imgui/imconfig.h
        dependencies/include/imgui/imgui.cpp
        dependencies/include/imgui/imgui.h
        dependencies/include/imgui/imgui_demo.cpp
        dependencies/include/imgui/imgui_draw.cpp
        dependencies/include/imgui/imgui_impl_sdl3.cpp
        dependencies/include/imgui/imgui_impl_sdl3.h
        dependencies/include/imgui/imgui_impl_sdlrenderer3.cpp
        dependencies/include/imgui/imgui_impl_sdlrenderer3.h
        dependencies/include/imgui/imgui_internal.h
        dependencies/include/imgui/imgui_tables.cpp
        dependencies/include/imgui/imgui_widgets.cpp
        dependencies/include/imgui/imstb_rectpack.h
        dependencies/include/imgui/imstb_textedit.h
        dependencies/include/imgui/imstb_truetype.h
        src/common/math.h
        src/Engine/Window.cpp
        src/Engine/Window.h
        src/Engine/TextureManager.cpp
        src/Engine/TextureManager.h
        src/Engine/Renderer.cpp
        src/Engine/Renderer.h
        src/Engine/InputHandler.cpp
        src/Engine/InputHandler.h
)

# Add the include directories
target_include_directories(SelenesWeb PRIVATE ${PROJECT_SOURCE_DIR}/src)
target_include_directories(SelenesWeb PRIVATE ${PROJECT_SOURCE_DIR}/dependencies/include)

find_package(glm CONFIG REQUIRED)
target_link_libraries(SelenesWeb PRIVATE glm::glm)

# Print the include directories
get_target_property(INCLUDE_DIRS SelenesWeb INCLUDE_DIRECTORIES)
message(STATUS "Include directories for SelenesWeb: ${INCLUDE_DIRS}")
message(STATUS "CMAKE_PREFIX_PATH: ${CMAKE_PREFIX_PATH}")
message(STATUS "VCPKG_INCLUDE_DIRS: ${VCPKG_INCLUDE_DIRS}")

if(CMAKE_BUILD_TYPE STREQUAL "Debug")
    message(STATUS "Configuring for Debug mode")
    # Link the Debug version of SDL libraries
    target_link_libraries(SelenesWeb PRIVATE ${PROJECT_SOURCE_DIR}/dependencies/lib/Debug/SDL/libSDL3.dll.a)
    target_link_libraries(SelenesWeb PRIVATE ${PROJECT_SOURCE_DIR}/dependencies/lib/Debug/SDL/libSDL3_image.dll.a)

    # Copy the Debug version of SDL3.dll and SDL3_image.dll
    set(SDL3_DLL "${PROJECT_SOURCE_DIR}/dependencies/lib/Debug/SDL/SDL3.dll")
    set(SDL3_IMAGE_DLL "${PROJECT_SOURCE_DIR}/dependencies/lib/Debug/SDL/SDL3_image.dll")

    # Ensure the build directory exists
    file(MAKE_DIRECTORY ${CMAKE_BINARY_DIR}/build)

    # Add custom commands to copy the DLLs
    add_custom_command(
            TARGET SelenesWeb POST_BUILD
            COMMAND ${CMAKE_COMMAND} -E copy_if_different
            ${SDL3_DLL}
            ${CMAKE_BINARY_DIR}/build
    )
    add_custom_command(
            TARGET SelenesWeb POST_BUILD
            COMMAND ${CMAKE_COMMAND} -E copy_if_different
            ${SDL3_IMAGE_DLL}
            ${CMAKE_BINARY_DIR}/build
    )
elseif(CMAKE_BUILD_TYPE STREQUAL "Release")
    message(STATUS "Configuring for Release mode")
    # Link the Release version of SDL libraries
    target_link_libraries(SelenesWeb PRIVATE ${PROJECT_SOURCE_DIR}/dependencies/lib/Release/SDL/libSDL3.dll.a)
    target_link_libraries(SelenesWeb PRIVATE ${PROJECT_SOURCE_DIR}/dependencies/lib/Release/SDL/libSDL3_image.dll.a)

    # Copy the Release version of SDL3.dll and SDL3_image.dll
    set(SDL3_DLL "${PROJECT_SOURCE_DIR}/dependencies/lib/Release/SDL/SDL3.dll")
    set(SDL3_IMAGE_DLL "${PROJECT_SOURCE_DIR}/dependencies/lib/Release/SDL/SDL3_image.dll")

    add_custom_command(
            TARGET SelenesWeb POST_BUILD
            COMMAND ${CMAKE_COMMAND} -E copy_if_different
            ${SDL3_DLL}
            ${CMAKE_BINARY_DIR}/build
    )
    add_custom_command(
            TARGET SelenesWeb POST_BUILD
            COMMAND ${CMAKE_COMMAND} -E copy_if_different
            ${SDL3_IMAGE_DLL}
            ${CMAKE_BINARY_DIR}/build
    )

endif()