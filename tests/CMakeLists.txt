#******************************************************************************U*
# Define tests
#*******************************************************************************

# testcases
add_executable(cases
    cases.cpp)

target_link_libraries(cases
    PRIVATE GTest::gtest_main
    PRIVATE file)

gtest_add_tests(TARGET cases
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})
