cmake_minimum_required(VERSION 3.10)

# Project name and version
project(AppExample VERSION 1.0)

# Specify the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)
#set(CMAKE_CXX_FLAGS "-Wall -Wextra")
#set(CMAKE_CXX_FLAGS_DEBUG "-g")

set(CMAKE_BUILD_TYPE Debug)

#add_compile_options(-fsanitize=address)
#add_link_options(-fsanitize=address)

# Include header files
include_directories(${PROJECT_SOURCE_DIR})

# Add the executable
add_executable(simple-logger simple-console-logger.cc)
add_executable(app-example app-example.cc)

# Optionally, if you want to create a library from your headers
add_library(logger SHARED
    console-log.h
    file-log.h
    log-formatter.h
    logger.h
    log-manager.h
    log-writer.h
    logger.cc
)

# Link the library to the executable
target_link_libraries(simple-logger logger)
target_link_libraries(app-example logger)
