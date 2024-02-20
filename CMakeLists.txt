cmake_minimum_required(VERSION 3.23)

project(RetroSnake)

set(CMAKE_CXX_STANDARD 17)

add_executable(RetroSnake main.cpp)

# find GLUT and OpenGL
find_package(GLUT REQUIRED)
find_package(OpenGL REQUIRED)

# include directories
include_directories(${OPENGL_INCLUDE_DIR} ${GLUT_INCLUDE_DIR})

# link libraries
target_link_libraries(RetroSnake ${OPENGL_LIBRARIES} ${GLUT_LIBRARIES})