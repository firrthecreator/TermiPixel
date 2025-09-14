# Set the minimum required version of CMake and define the project.
cmake_minimum_required(VERSION 3.14)
project(TermiPixel VERSION 1.0)

# Set the C++ standard to C++17.
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Create a static library for the core application logic.
# This allows the logic to be shared between the main executable and the tests.
add_library(termipixel_lib
    src/image_processor.cpp
    src/ascii_converter.cpp
)

target_include_directories(termipixel_lib PUBLIC
    ${PROJECT_SOURCE_DIR}/include
    ${PROJECT_SOURCE_DIR}/third_party
)

# Define STB_IMAGE_IMPLEMENTATION, which is required by the stb_image library.
target_compile_definitions(termipixel_lib PRIVATE STB_IMAGE_IMPLEMENTATION)

# Create the main executable for the application.
add_executable(termipixel
    src/main.cpp
)

target_link_libraries(termipixel PRIVATE termipixel_lib)

# Add an install rule for the main executable.
install(TARGETS termipixel DESTINATION bin)

# Enable testing with CTest for the project.
enable_testing()

# Fetch the GoogleTest framework automatically from the official repository.
include(FetchContent)
FetchContent_Declare(
    googletest
    GIT_REPOSITORY https://github.com/google/googletest.git
    GIT_TAG v1.14.0
)
FetchContent_MakeAvailable(googletest)

# Create the executable for running tests.
add_executable(run_tests
    tests/test_converter.cpp
)

# Link the test executable against our library and GoogleTest.
target_link_libraries(run_tests
    PRIVATE termipixel_lib gtest_main
)

# Discover and add the tests to CTest.
include(GoogleTest)
gtest_discover_tests(run_tests)
