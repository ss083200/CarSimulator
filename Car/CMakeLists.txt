cmake_minimum_required(VERSION 3.20)
project(CarSimulator)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Set vcpkg toolchain
set(CMAKE_TOOLCHAIN_FILE "$ENV{VCPKG_ROOT}/scripts/buildsystems/vcpkg.cmake" CACHE STRING "Vcpkg toolchain file")

# Set target triplet
set(VCPKG_TARGET_TRIPLET "x64-windows-static" CACHE STRING "Vcpkg target triplet")

# Find SFML package
find_package(SFML COMPONENTS system window graphics audio CONFIG REQUIRED)

set(GTest_DIR "C:/vcpkg/installed/x64-windows-static/share/gtest")
# Find GoogleTest
find_package(GTest REQUIRED)

# Include directories
include_directories(include)

# Main executable
add_executable(CarSimulator 
    src/main.cpp 
    src/Car.cpp
)

# Link SFML libraries
target_link_libraries(CarSimulator PRIVATE 
    sfml-system 
    sfml-window 
    sfml-graphics 
    sfml-audio
)

# Optional: Add unit tests
enable_testing()
add_executable(CarTests 
    tests/test_car.cpp 
    src/Car.cpp
)

target_link_libraries(CarTests PRIVATE 
    GTest::gtest 
    GTest::gtest_main
    sfml-system 
    sfml-window 
    sfml-graphics
)

add_test(NAME CarTests COMMAND CarTests)