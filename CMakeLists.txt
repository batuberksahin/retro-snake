cmake_minimum_required(VERSION 3.23)

project(RetroSnake)

set(CMAKE_CXX_STANDARD 17)

add_executable(RetroSnake main.cpp
        Engine/Engine.cpp
        Engine/Engine.h
        Engine/Graphics/Graphics.cpp
        Engine/Graphics/Graphics.h
        Engine/Renderer.cpp
        Engine/Renderer.h
        Engine/Utils.cpp
        Engine/Scene.h
        Scenes/StartScene.cpp
        Scenes/StartScene.h
        Scenes/GameScene.cpp
        Scenes/GameScene.h
        Scenes/EndScene.cpp
        Scenes/EndScene.h
        Scenes/SceneManager.cpp
        Scenes/SceneManager.h
        Engine/Graphics/Timer.cpp
        Engine/Graphics/Timer.h
)

# find GLUT and OpenGL
find_package(GLUT REQUIRED)
find_package(OpenGL REQUIRED)
find_package(Freetype REQUIRED)

# include directories
include_directories(${OPENGL_INCLUDE_DIR} ${GLUT_INCLUDE_DIR} ${FREETYPE_INCLUDE_DIRS})

# link libraries
target_link_libraries(RetroSnake ${OPENGL_LIBRARIES} ${GLUT_LIBRARIES} ${FREETYPE_LIBRARIES})