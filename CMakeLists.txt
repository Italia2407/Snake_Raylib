cmake_minimum_required(VERSION 3.0)
project(snake C)

set(CMAKE_C_STANDARD 99)

# Setting parameters for raylib
set(BUILD_EXAMPLES OFF CACHE BOOL "" FORCE) # don't build the supplied examples
set(BUILD_GAMES    OFF CACHE BOOL "" FORCE) # or games

add_subdirectory(libs/raylib)

set(SRC_FILES src/main.c)
set(SRC_FILES_OBJ src/objects/snake.c)
set(SRC_FILES_MGT src/management/grid-manager.c)

add_executable(snake ${SRC_FILES} ${SRC_FILES_OBJ} ${SRC_FILES_MGT})
target_link_libraries(snake PRIVATE raylib)