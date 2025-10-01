# Create a static library
add_library(procTemp
    src/procTemp.c
)

target_include_directories(procTemp PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/inc
)
