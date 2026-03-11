#******************************************************************************U*
# Define tests
#*******************************************************************************

# testcases
add_executable(cases
    cases.cpp)

target_link_libraries(cases
    PRIVATE GTest::gtest_main)

gtest_add_tests(TARGET cases)
