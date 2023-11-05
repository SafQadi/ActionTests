cmake_minimum_required(VERSION 3.16)

project(main)

add_executable(main main.cpp)

install(TARGETS main)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_STANDARD 11)

if(DEFINED ENV{GITHUB_ACTIONS} AND DEFINED ENV{GITHUB_WORKSPACE})
  set(ARTIFACTS_DIR "$ENV{GITHUB_WORKSPACE}/artifacts")
  if(CMAKE_SYSTEM_NAME MATCHES "Windows")
    set(GTest_DIR "${ARTIFACTS_DIR}/googletest/$ENV{googletest_tag}/windows-x64/lib/cmake/GTest")
  elseif(CMAKE_SYSTEM_NAME MATCHES "Linux")
    set(GTest_DIR "${ARTIFACTS_DIR}/googletest/$ENV{googletest_tag}/linux-x64/lib/cmake/GTest")
  elseif(CMAKE_SYSTEM_NAME MATCHES "Darwin")
    set(GTest_DIR "${ARTIFACTS_DIR}/googletest/$ENV{googletest_tag}/mac-x64/lib/cmake/GTest")
  endif()
  message(STATUS ">>> ENV{GITHUB_ACTIONS} is: $ENV{GITHUB_ACTIONS}")
  message(STATUS ">>> ENV{GITHUB_WORKSPACE} is: $ENV{GITHUB_WORKSPACE}")
  message(STATUS ">>> ARTIFACTS_DIR is: ${ARTIFACTS_DIR}")
  message(STATUS ">>> GTest_DIR is: ${GTest_DIR}")
  find_package(GTest REQUIRED)
endif()

enable_testing()
add_executable(
    tests 
    tests.cpp
)
target_link_libraries(
    tests
    GTest::gtest
    GTest::gtest_main
)

# add_test(NAME main COMMAND main)
# add_test(NAME tests COMMAND tests)