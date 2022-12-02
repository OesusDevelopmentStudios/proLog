add_compile_options(-Werror=switch)

project(prolog)

set(SOURCES
    Prolog.cpp
)

add_library(${PROJECT_NAME})
target_sources(${PROJECT_NAME} PRIVATE ${SOURCES})
target_include_directories(${PROJECT_NAME}
    PUBLIC
        include
    PRIVATE
        enums
)
