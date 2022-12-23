add_compile_options(-Werror=switch)

project(prolog)

add_subdirectory(log_object)

set(SOURCES
    Configurator.cpp
    Prolog.cpp
)

add_library(${PROJECT_NAME})
target_sources(${PROJECT_NAME} PRIVATE ${SOURCES})
target_include_directories(${PROJECT_NAME}
    PUBLIC
        include
    PRIVATE
        private
)

target_link_libraries(${PROJECT_NAME}
    PRIVATE
        prolog-log_object
)
