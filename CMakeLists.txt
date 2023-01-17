cmake_minimum_required(VERSION 3.25.1)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

project(Pong VERSION 1.0)
add_executable(Main src/Game/game.cpp src/GameObject/GameObject.cpp src/Graphics/Shader/Shader.cpp src/Input/Input.cpp src/Time/Time.cpp src/Window/Window.cpp src/main.cpp)
add_compile_definitions(DEBUG)

find_package(OpenGL REQUIRED)
find_package(SDL2 REQUIRED)
find_package(GLEW REQUIRED)

target_include_directories(Main PUBLIC ./include PUBLIC ${SDL2_INCLUDE_DIRS} PUBLIC ${GLEW_INCLUDE_DIRS} PUBLIC ${OPENGL_INCLUDE_DIR} PUBLIC ./Shaders)
target_link_libraries(Main ${SDL2_LIBRARIES} GLEW::GLEW ${OPENGL_LIBRARIES})