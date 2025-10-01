# Create a static library
add_library(readTemp
    src/readTemp.c
)

target_include_directories(readTemp PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/inc
)
