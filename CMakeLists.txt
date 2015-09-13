### wPlot project ###

# In order to work following variables must be set
#
# QT_ROOT: Path to Qt installation.

cmake_minimum_required (VERSION 3.0.2)

# Variables that should be set before execution
if (WIN32)
	set (QT_ROOT "" CACHE PATH "Qt library path")
else (WIN32)
	set (QT_ROOT "/usr/include" CACHE PATH "Qt library path")
endif (WIN32)

message ("Generating WPlot project")
message ("Setting QT_ROOT To ${QT_ROOT}")

add_subdirectory (wplot)
add_subdirectory (demo)
