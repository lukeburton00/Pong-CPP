cmake_minimum_required(VERSION 3.25.1)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

project(Pong VERSION 1.0)
add_executable(Main src/Game/game.cpp src/GameObject/GameObject.cpp src/Graphics/Shader/Shader.cpp src/Input/Input.cpp src/Time/Time.cpp src/Window/Window.cpp src/main.cpp)
add_compile_definitions(DEBUG)

find_package(OpenGL REQUIRED)

include_directories(/opt/homebrew/include ./include ${OPENGL_INCLUDE_DIR} ./Shaders)
target_link_libraries(Main /opt/homebrew/lib/libSDL2.dylib /opt/homebrew/Cellar/glew/2.2.0_1/lib/libGLEW.dylib ${OPENGL_LIBRARIES})