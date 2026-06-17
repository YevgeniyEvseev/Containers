cmake_minimum_required(VERSION 3.2)

add_executable(test 
    src/tests/test_stack.cc 
    src/tests/test.cc)

target_link_libraries(test gtest gmock pthread)