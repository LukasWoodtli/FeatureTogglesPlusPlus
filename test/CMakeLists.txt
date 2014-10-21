FILE (GLOB_RECURSE test_SRCS *.cpp *.cxx *.cc *.C *.c *.h *.hpp)
SET (test_BIN ${PROJECT_NAME}-unittests)
add_gmock_test(${test_BIN} ${test_SRCS})
target_link_libraries(${test_BIN} project_BIN)
