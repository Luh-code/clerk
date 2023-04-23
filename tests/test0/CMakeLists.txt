cmake_minimum_required(VERSION 3.1)
include(CTest)

enable_testing()

file(GLOB testSrcFiles
  ./src/*.h
  ./src/**/*.h
  ./src/*.hpp
  ./src/**/*.hpp
  ./src/*.c
  ./src/**/*.c
  ./src/*.cpp
  ./src/**/*.cpp
)

add_compile_definitions(
  CLERK_AIXTERM_COMPLIANT
  # CLERK_HIGH_COLOR_RANGE
  # CLERK_TRUE_COLOR
)

add_executable(test0 ${testSrcFiles})
target_include_directories(test0 PUBLIC ${PROJECT_SOURCE_DIR}/src/include)
target_compile_options(test0 PRIVATE -Wall)
add_test(test0 ../bin/test0.exe)
