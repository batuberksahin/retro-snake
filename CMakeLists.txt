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
        Assets/GameObject.h
        Assets/Objects/Text.cpp
        Assets/Objects/Text.h
        Assets/Objects/DebugTriangle.cpp
        Assets/Objects/DebugTriangle.h
        Engine/Scene.cpp
        Engine/Config.h
        Assets/Objects/Snake.cpp
        Assets/Objects/Snake.h
        Assets/Objects/GridLayout.cpp
        Assets/Objects/GridLayout.h
        Assets/Objects/FoodSpawner.cpp
        Assets/Objects/FoodSpawner.h
)

# find GLUT and OpenGL
find_package(GLUT REQUIRED)
find_package(OpenGL REQUIRED)

# include directories
include_directories(${OPENGL_INCLUDE_DIR} ${GLUT_INCLUDE_DIR})

# link libraries
target_link_libraries(RetroSnake ${OPENGL_LIBRARIES} ${GLUT_LIBRARIES})