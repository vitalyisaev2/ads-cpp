cmake_minimum_required(VERSION 3.0)

enable_testing()

# set up coverage
# set(CMAKE_MODULE_PATH "${PROJECT_SOURCE_DIR}/CMakeModules")
# find_library(gcov REQUIRED)
# include(CodeCoverage)
# setup_target_for_coverage(ads_test_coverage ads_test coverage)
# set(CMAKE_CXX_FLAGS "-O0 -Wall -fprofile-arcs -ftest-coverage")
# set(LCOV_REMOVE_EXTRA "'test/*'")

# build test executable
find_package(Catch2 REQUIRED)
file(GLOB ads_test_src "*.cpp")
add_executable(ads_test "${ads_test_src}")
target_include_directories(
    ads_test 
    PRIVATE
        "${PROJECT_SOURCE_DIR}/include"
)
target_link_libraries(ads_test Catch2::Catch2 gcov)

# enable all checks
target_compile_options(ads_test PRIVATE 
    -pedantic -Wall -Wextra -Wcast-align -Wcast-qual -Wctor-dtor-privacy
    -Wdisabled-optimization -Wformat=2 -Winit-self -Wlogical-op 
    -Wmissing-declarations -Wmissing-include-dirs -Wnoexcept 
    -Wold-style-cast -Woverloaded-virtual -Wredundant-decls 
    -Wshadow -Wsign-conversion -Wsign-promo -Wstrict-null-sentinel
    -Wstrict-overflow=5 -Wswitch-default -Wundef -Werror -Wno-unused)

# run tests
include(CTest)
include(Catch)
catch_discover_tests(ads_test)

# run tests under valgrind
find_program(VALGRIND "valgrind")
add_test(
    ads_test_valgrind
    "${VALGRIND}" --error-exitcode=1 --tool=memcheck --leak-check=yes --run-libc-freeres=no "${CMAKE_CURRENT_BINARY_DIR}/ads_test")