cmake_minimum_required(VERSION 4.2)
project(NodeCoil)

set(CMAKE_CXX_STANDARD 20)
project(nodecoil
        VERSION 0.1
        LANGUAGES CXX)

# IMGUI
set(IMGUI_DIR ${CMAKE_CURRENT_SOURCE_DIR}/external/imgui)
add_library(imgui STATIC
        ${IMGUI_DIR}/imgui.cpp
        ${IMGUI_DIR}/imgui.h
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

# IMGUI-NODE
set(IMGUI_NODE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/external/imgui-node)
add_library(imgui-node STATIC
        ${IMGUI_NODE_DIR}/imgui_node_editor.cpp
        ${IMGUI_NODE_DIR}/imgui_node_editor.h
        ${IMGUI_NODE_DIR}/examples/application/include/application.h
)

target_include_directories(imgui-node PUBLIC
        ${IMGUI_NODE_DIR}
        ${IMGUI_DIR}
)
target_compile_definitions(imgui-node PUBLIC IMGUI_DEFINE_MATH_OPERATORS)

add_executable(nodecoil
        src/main.cpp
)

find_package(glfw3 REQUIRED)
target_link_libraries(imgui PUBLIC glfw)

target_link_libraries(nodecoil
        PRIVATE
        imgui
        imgui-node
)
