### wPlot project ###

# In order to work following variables must be set
#
# QT_DIR: Path to Qt installation.

cmake_minimum_required (VERSION 3.1.0)

# Variables that should be set before execution
if (WIN32)
	set (QT_DIR "" CACHE PATH "Qt library path")
else (WIN32)
	set (QT_DIR "/usr/include" CACHE PATH "Qt library path")
endif (WIN32)

message ("Generating WPlot project")
message ("Setting QT_DIR To ${QT_DIR}")

add_subdirectory (wplot)
add_subdirectory (demo)
