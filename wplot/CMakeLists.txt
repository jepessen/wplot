# wPlot project

cmake_minimum_required (VERSION 3.0.2)

project (wplot)

set (major_version 0)
set (minor_version 0)
set (bugfix_version 1)
set (project_version ${major_version}.${minor_version}.${bugfix_version})
set (OUTPUT_DIR "build")
set (CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/export/lib)
set (CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/export/lib)
set (CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/export/bin)
set (INCLUDE_EXPORT_DIRECTORY ${CMAKE_BINARY_DIR}/export/include/wplot)
set (CMAKE_DOC_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/export/doc)
set (CMAKE_PREFIX_PATH ${QT_ROOT}/lib/cmake)
set (CMAKE_AUTOMOC ON)
set (CMAKE_INCLUDE_CURRENT_DIR ON)

message ("=== Generating WPlot ===")
message ("Setting QT_ROOT To ${QT_ROOT}")
message ("CMAKE_PREFIX_PATH set to ${CMAKE_PREFIX_PATH}")
find_package (Qt5Widgets REQUIRED)
include_directories (${CMAKE_CURRENT_SOURCE_DIR}/.. ${Qt5Widgets_INCLUDE_DIRS})
file (GLOB_RECURSE WPLOT_SOURCES "*.cpp")
file (GLOB WPLOT_PUBLIC_HEADERS "*.h")
file (COPY ${WPLOT_PUBLIC_HEADERS} DESTINATION ${INCLUDE_EXPORT_DIRECTORY})

# Compile project
add_definitions(-DWPLOT_LIBRARY)
add_library (wplot SHARED ${WPLOT_SOURCES})
target_link_libraries(wplot ${Qt5Widgets_LIBRARIES})
set_target_properties(
  wplot
  PROPERTIES
    VERSION ${project_version}
    SOVERSION ${project_version}
)

# This enable C++11 for CMake version >= 3.1.0
set_property(TARGET wplot PROPERTY CXX_STANDARD 11)
set_property(TARGET wplot PROPERTY CXX_STANDARD_REQUIRED ON)

# This enable C++11 for gcc for CMake version priors to 3.1.0
include(CheckCXXCompilerFlag)
CHECK_CXX_COMPILER_FLAG("-std=c++11" COMPILER_SUPPORTS_CXX11)
CHECK_CXX_COMPILER_FLAG("-std=c++0x" COMPILER_SUPPORTS_CXX0X)
if(COMPILER_SUPPORTS_CXX11)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
elseif(COMPILER_SUPPORTS_CXX0X)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++0x")
endif()

