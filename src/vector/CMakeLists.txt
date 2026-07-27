add_executable(vect_v test_vector.cc)
add_executable(vect_ch check.cc)

target_link_libraries(vect_v gtest gmock pthread)

