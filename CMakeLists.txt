cmake_minimum_required(VERSION 3.15)
project(nodecoil VERSION 0.1 LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 20)

find_package(glfw3 REQUIRED)
find_package(OpenGL REQUIRED)

# IMGUI
set(IMGUI_DIR ${CMAKE_CURRENT_SOURCE_DIR}/external/imgui)
add_library(imgui STATIC
        ${IMGUI_DIR}/imgui.cpp
        ${IMGUI_DIR}/imgui_draw.cpp
        ${IMGUI_DIR}/imgui_tables.cpp
        ${IMGUI_DIR}/imgui_widgets.cpp
        ${IMGUI_DIR}/backends/imgui_impl_glfw.cpp
        ${IMGUI_DIR}/backends/imgui_impl_opengl3.cpp
)
target_include_directories(imgui PUBLIC
        ${IMGUI_DIR}
        ${IMGUI_DIR}/backends
)
target_compile_definitions(imgui PUBLIC IMGUI_DEFINE_MATH_OPERATORS)
target_link_libraries(imgui PUBLIC glfw OpenGL::GL)

# IMGUI-NODE
set(IMGUI_NODE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/external/imgui-node)
add_library(imgui-node STATIC
        ${IMGUI_NODE_DIR}/imgui_node_editor.cpp
        ${IMGUI_NODE_DIR}/imgui_canvas.cpp
        ${IMGUI_NODE_DIR}/crude_json.cpp
        ${IMGUI_NODE_DIR}/examples/application/source/application.cpp
)
target_include_directories(imgui-node PUBLIC
        ${IMGUI_NODE_DIR}
        ${IMGUI_NODE_DIR}/examples/application/include
)

configure_file(
        ${IMGUI_NODE_DIR}/examples/application/source/config.h.in
        ${IMGUI_NODE_DIR}/examples/application/source/config.h
)

target_compile_definitions(imgui-node PUBLIC IMGUI_DEFINE_MATH_OPERATORS)
target_link_libraries(imgui-node PUBLIC imgui)

# APP
add_executable(nodecoil src/main.cpp)
target_link_libraries(nodecoil PRIVATE imgui imgui-node)