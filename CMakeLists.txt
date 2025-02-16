cmake_minimum_required(VERSION 3.30)
project(SelenesWeb)

set(CMAKE_CXX_STANDARD 23)

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
)

# Add the include directories for this target
target_include_directories(SelenesWeb PRIVATE ${PROJECT_SOURCE_DIR}/src)

# Print the include directories for SelenesWeb
get_target_property(INCLUDE_DIRS SelenesWeb INCLUDE_DIRECTORIES)
message(STATUS "Include directories for SelenesWeb: ${INCLUDE_DIRS}")
