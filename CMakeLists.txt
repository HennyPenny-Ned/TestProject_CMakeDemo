# Set minimum CMake version
cmake_minimum_required(VERSION 3.10)
message("CMake version without STATUS: ${CMAKE_VERSION}")
message(STATUS "CMake version with STATUS: ${CMAKE_VERSION}")

# Set project name
# Set firmware version
# Specifies that the project is written in C
project(CMakeDemo VERSION 1.0.0 LANGUAGES C)
message(STATUS "Project Name: ${PROJECT_NAME}")
message(STATUS "Project Version: ${PROJECT_VERSION}")
message(STATUS "Version Major: ${PROJECT_VERSION_MAJOR}")
message(STATUS "Version Minor: ${PROJECT_VERSION_MINOR}")

# Specifies target architecture
set(CMAKE_SYSTEM_PROCESSOR cortex-m4)
message(STATUS "System Processor: ${CMAKE_SYSTEM_PROCESSOR}")

# Adds subdirectory for modules
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/application/modules)

# Defines source files for the main executable
set(MAIN ${CMAKE_CURRENT_SOURCE_DIR}/application/main.c)
set(SYSCALLS ${CMAKE_CURRENT_SOURCE_DIR}/board/syscalls/syscalls.c)
add_executable(CMakeDemo ${MAIN} ${SYSCALLS})

# Set compiler flags
target_compile_options(CMakeDemo PRIVATE
    -mcpu=cortex-m4
    -mthumb
    -Wall
    -O2
)

# Link module libraries
target_link_libraries(CMakeDemo
    readTemp
    procTemp
    displayTemp
)

# Add Output Format Targets
add_custom_command(TARGET CMakeDemo POST_BUILD
    COMMAND ${CMAKE_OBJCOPY} -O binary CMakeDemo CMakeDemo.bin
    COMMENT "Generating binary file"
)
