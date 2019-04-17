cmake_minimum_required(VERSION 3.0)

enable_testing()

find_package(Catch2 REQUIRED)

file(GLOB ads_test_src "*.cpp")
add_executable(ads_test "${ads_test_src}")
target_include_directories(
    ads_test 
    PRIVATE
        "${PROJECT_SOURCE_DIR}/include"
)
target_link_libraries(ads_test Catch2::Catch2)

# run tests
include(CTest)
include(Catch)
catch_discover_tests(ads_test)

# run tests under valgrind
find_program(VALGRIND "valgrind")
add_test(
    ads_test_valgrind
    "${VALGRIND}" --error-exitcode=1 --tool=memcheck --leak-check=yes --run-libc-freeres=no "${CMAKE_CURRENT_BINARY_DIR}/ads_test")