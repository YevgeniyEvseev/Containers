add_executable(test 
    test_stack.cc )

target_link_libraries(test gtest gmock pthread)