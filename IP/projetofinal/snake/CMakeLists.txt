cmake_minimum_required(VERSION 3.22)

project(Snake C)

# GLFW
set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)

add_subdirectory(libraries/glfw)

# GLEW
set(glew-cmake_BUILD_SHARED OFF)

add_subdirectory(libraries/glew)

# OpenGL
find_package(OpenGL REQUIRED)

# Setup
set (
	SOURCES
	source/main.c
	source/geometry.c
	source/settings.c
	source/snake.c
	source/functions.c
	source/object.c
	source/devices.c
	source/grid.c
	)

add_executable(snake ${SOURCES})
target_link_libraries(snake glfw libglew_static OpenGL::GL)
