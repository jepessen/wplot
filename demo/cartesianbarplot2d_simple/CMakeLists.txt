cmake_minimum_required (VERSION 3.0.2)

project (demo_cartesianbarplot2d_simple)

set (CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/export/bin)
set (CMAKE_PREFIX_PATH ${QT_ROOT}/lib/cmake)
set (CMAKE_AUTOMOC ON)
set (CMAKE_INCLUDE_CURRENT_DIR ON)

find_package (Qt5Widgets REQUIRED)
include_directories (${CMAKE_SOURCE_DIR} ${Qt5Widgets_INCLUDE_DIRS})
file (GLOB DEMO_SOURCES "*.cpp")

# Compile project
add_executable (demo_cartesianbarplot2d_simple ${DEMO_SOURCES})
target_link_libraries(demo_cartesianbarplot2d_simple  ${Qt5Widgets_LIBRARIES})
target_link_libraries(demo_cartesianbarplot2d_simple  wplot)

# This enable C++11 for CMake version >= 3.1.0
set_property(TARGET demo_cartesianbarplot2d_simple PROPERTY CXX_STANDARD 11)
set_property(TARGET demo_cartesianbarplot2d_simple PROPERTY CXX_STANDARD_REQUIRED ON)

# This enable C++11 for gcc for CMake version priors to 3.1.0
include(CheckCXXCompilerFlag)
CHECK_CXX_COMPILER_FLAG("-std=c++11" COMPILER_SUPPORTS_CXX11)
CHECK_CXX_COMPILER_FLAG("-std=c++0x" COMPILER_SUPPORTS_CXX0X)
if(COMPILER_SUPPORTS_CXX11)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
elseif(COMPILER_SUPPORTS_CXX0X)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++0x")
endif()

