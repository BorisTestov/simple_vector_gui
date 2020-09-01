# Set executables names
set(main ${PROJECT_NAME})

# Create list with executables names
set(EXECUTABLES_LIST ${main})

# Set sources
aux_source_directory(${SRC_DIR} SOURCES)

aux_source_directory(${INCLUDE_DIR} HEADERS)

# Add executables
add_executable(${main} ${SOURCES} ${HEADERS})

foreach(TARGET ${EXECUTABLES_LIST})
    # Include directories
    target_include_directories(${TARGET} PRIVATE "${INCLUDE_DIR}")
    # Set target properties
    set_target_properties(${TARGET} PROPERTIES ${TARGET_PROPERTIES})
    # Link libraries
    target_link_libraries(${TARGET} PRIVATE ${LIBRARIES_LIST})
    # Set compile options
    target_compile_options(${TARGET} PRIVATE ${COMPILE_OPTIONS})
endforeach()

# Install executables
install(TARGETS ${EXECUTABLES_LIST} RUNTIME DESTINATION bin)

