#*******************************************************************************
# Define libraries
#*******************************************************************************

# File
add_library(file INTERFACE)

target_include_directories(file
    INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})

# Option reader
#add_library(reader INTERFACE)

#target_include_directories(reader
#    INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})
