add_executable(queue_v test_queue.cc)
add_executable(queue_ch check.cc)

target_link_libraries(queue_v gtest gmock pthread)
target_link_libraries(queue_ch -g)
