add_compile_options(-Werror=switch)

set(THREADS_PREFER_PTHREAD_FLAG ON)
find_package(Threads REQUIRED)

project(prolog)

add_subdirectory(config)
add_subdirectory(enums)
add_subdirectory(log)
add_subdirectory(server)

set(SOURCES
    Configurator.cpp
    Prolog.cpp
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
        prolog-log
        prolog-server
        Threads::Threads
)
