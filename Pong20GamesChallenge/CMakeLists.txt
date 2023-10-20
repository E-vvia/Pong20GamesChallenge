# CMakeList.txt: proyecto de CMake para Pong20GamesChallenge, incluya el origen y defina
# la lógica específica del proyecto aquí.
#
cmake_minimum_required(VERSION 3.11) # FetchContent is available in 3.11+

project(Pong20GamesChallenge)

# Generate compile_commands.json
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Dependencies
set(RAYLIB_VERSION 4.5.0)

find_package(raylib ${RAYLIB_VERSION} QUIET) # QUIET or REQUIRED
if (NOT raylib_FOUND) # If there's none, fetch and build raylib
  include(FetchContent)
  FetchContent_Declare(
    raylib
    DOWNLOAD_EXTRACT_TIMESTAMP OFF
    URL https://github.com/raysan5/raylib/archive/refs/tags/${RAYLIB_VERSION}.tar.gz
  )
  FetchContent_GetProperties(raylib)
  if (NOT raylib_POPULATED) # Have we downloaded raylib yet?
    set(FETCHCONTENT_QUIET NO)
    FetchContent_Populate(raylib)
    set(BUILD_EXAMPLES OFF CACHE BOOL "" FORCE) # don't build the supplied examples
    add_subdirectory(${raylib_SOURCE_DIR} ${raylib_BINARY_DIR})
  endif()
endif()

add_executable (${PROJECT_NAME} "main.cpp"  "main.cpp" "player.h" "player.cpp" "game.cpp" "game.h" "scene.h" "game_2P_scene.h" "game_2P_scene.cpp" "ball.h" "ball.cpp" "main_menu.cpp" "main_menu.h" "game_1P_scene.h" "game_1P_scene.cpp" "player_ai.h" "player_ai.cpp")

#set(raylib_VERBOSE 1)
target_link_libraries(${PROJECT_NAME} raylib)

if (${PLATFORM} STREQUAL "Web")
    # Tell Emscripten to build an example.html file.
    set_target_properties(${PROJECT_NAME} PROPERTIES SUFFIX ".html")
endif()

# Checks if OSX and links appropriate frameworks (Only required on MacOS)
if (APPLE)
    target_link_libraries(${PROJECT_NAME} "-framework IOKit")
    target_link_libraries(${PROJECT_NAME} "-framework Cocoa")
    target_link_libraries(${PROJECT_NAME} "-framework OpenGL")
endif()

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET ${PROJECT_NAME}  PROPERTY CXX_STANDARD 20)
endif()

if(WIN32)
    set_target_properties(${PROJECT_NAME}
    PROPERTIES
        LINK_FLAGS_DEBUG "/SUBSYSTEM:CONSOLE"
        LINK_FLAGS_RELEASE "/SUBSYSTEM:windows /ENTRY:mainCRTStartup"
        LINK_FLAGS_RELWITHDEBINFO "/SUBSYSTEM:windows /ENTRY:mainCRTStartup"
        LINK_FLAGS_MINSIZEREL "/SUBSYSTEM:windows /ENTRY:mainCRTStartup"
    )
else()
    set_target_properties(${PROJECT_NAME}
    PROPERTIES
        LINK_FLAGS_DEBUG "-mconsole"
        LINK_FLAGS_RELEASE "-mwindows"
        LINK_FLAGS_RELWITHDEBINFO "-mwindows"
        LINK_FLAGS_MINSIZEREL "-mwindows"
    )
endif()