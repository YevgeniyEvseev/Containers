add_executable(list_v test_list.cc)
add_executable(list_ch check.cc)

target_link_libraries(list_v gtest gmock pthread -g)