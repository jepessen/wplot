cmake_minimum_required (VERSION 3.0.0)

project (demo_background)

set (CMAKE_PREFIX_PATH ${QT_DIR}/lib/cmake)
set (CMAKE_AUTOMOC ON)
set (CMAKE_INCLUDE_CURRENT_DIR ON)

find_package (Qt5Widgets REQUIRED)
include_directories (${CMAKE_SOURCE_DIR} ${Qt5Widgets_INCLUDE_DIRS})
file (GLOB DEMO_SOURCES "*.cpp")

# Compile project
add_executable (demo_background ${DEMO_SOURCES})
target_link_libraries(demo_background  ${Qt5Widgets_LIBRARIES})
target_link_libraries(demo_background  wplot)
set_property(TARGET demo_background PROPERTY CXX_STANDARD 11)
set_property(TARGET demo_background PROPERTY CXX_STANDARD_REQUIRED ON)