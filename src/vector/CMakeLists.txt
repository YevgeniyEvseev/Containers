add_executable(vect_v test_vector.cc)

target_link_libraries(vect_v gtest gmock pthread)