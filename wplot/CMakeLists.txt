# wPlot project

cmake_minimum_required (VERSION 3.0.0)

project (wplot)

set (major_version 0)
set (minor_version 0)
set (bugfix_version 1)
set (project_version ${major_version}.${minor_version}.${bugfix_version})
set (CMAKE_PREFIX_PATH ${QT_DIR}/lib/cmake)
set (CMAKE_AUTOMOC ON)
set (CMAKE_INCLUDE_CURRENT_DIR ON)

message ("=== Generating WPlot ===")
message ("Setting QT_DIR To ${QT_DIR}")
message ("CMAKE_PREFIX_PATH set to ${CMAKE_PREFIX_PATH}")
find_package (Qt5Widgets REQUIRED)
include_directories (${CMAKE_CURRENT_SOURCE_DIR})
file (GLOB WPLOT_SOURCES "*.cpp")

# Compile project
add_library (wplot SHARED ${WPLOT_SOURCES})
set_target_properties(
  wplot
  PROPERTIES
    VERSION ${project_version}
    SOVERSION ${project_version}
)
