cmake_minimum_required (VERSION 3.0.0)

project (demo_grid)

set (CMAKE_PREFIX_PATH ${QT_DIR}/lib/cmake)
set (CMAKE_AUTOMOC ON)
set (CMAKE_INCLUDE_CURRENT_DIR ON)

find_package (Qt5Widgets REQUIRED)
include_directories (${CMAKE_SOURCE_DIR} ${Qt5Widgets_INCLUDE_DIRS})
file (GLOB DEMO_SOURCES "*.cpp")

# Compile project
add_executable (demo_grid ${DEMO_SOURCES})
target_link_libraries(demo_grid  ${Qt5Widgets_LIBRARIES})
target_link_libraries(demo_grid  wplot)
set_property(TARGET demo_grid PROPERTY CXX_STANDARD 11)
set_property(TARGET demo_grid PROPERTY CXX_STANDARD_REQUIRED ON)