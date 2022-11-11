# add_subdirectory(proLog)
add_subdirectory(testable)

add_executable(prolog-test
    main.cpp
)

target_link_libraries(prolog-test
    PRIVATE
        prolog-testable
)
