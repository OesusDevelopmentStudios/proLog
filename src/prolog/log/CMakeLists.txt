project(prolog-log)

set(SOURCES
    Log.cpp
)

add_library(${PROJECT_NAME})
target_sources(${PROJECT_NAME} PRIVATE ${SOURCES})
target_include_directories(${PROJECT_NAME}
    PUBLIC
        include
)

target_link_libraries(${PROJECT_NAME}
    PRIVATE
        prolog-config
        prolog-enums
)
