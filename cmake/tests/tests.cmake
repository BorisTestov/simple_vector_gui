find_package(Qt5 REQUIRED COMPONENTS Test)

set(TESTS_INCLUDE_DIR ${INCLUDE_DIR}/tests)
set(TESTS_SRC_DIR ${SRC_DIR}/tests)

# Add tests
set(main_test "${PROJECT_NAME}_test")

# Set sources
aux_source_directory(${SRC_DIR} TEST_SOURCES)

aux_source_directory(${INCLUDE_DIR} TEST_HEADERS)

list(REMOVE_ITEM TEST_SOURCES ${SRC_DIR}/main.cpp)

list(APPEND TEST_SOURCES ${TESTS_SRC_DIR}/main_test.cpp)

list(APPEND TEST_HEADERS ${TESTS_INCLUDE_DIR}/main_test.h)

# Add tests executables
add_executable(${main_test} ${TEST_SOURCES} ${TEST_HEADERS})

# Create list with tests names
set(TESTS_LIST ${main_test})

foreach(TARGET ${TESTS_LIST})
    # Set target properties
    set_target_properties(${TARGET} PROPERTIES ${TARGET_PROPERTIES})
    # Include directories
    target_include_directories(${TARGET} PRIVATE ${INCLUDE_DIR} ${TESTS_INCLUDE_DIR})
    # Link libraries
    target_link_libraries(${TARGET} PRIVATE Qt5::Test)
    # Set compile options
    target_compile_options(${TARGET} PRIVATE ${COMPILE_OPTIONS})
endforeach()

enable_testing()
foreach(TESTNAME ${TESTS_LIST})
    add_test(${TESTNAME} ${BUILD_DIR}/${TESTNAME})
endforeach()
