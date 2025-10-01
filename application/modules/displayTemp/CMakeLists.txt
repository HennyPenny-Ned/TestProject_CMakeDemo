# Create a static library
add_library(displayTemp
    src/displayTemp.c
)

target_include_directories(displayTemp PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/inc
)
