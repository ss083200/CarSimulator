cmake_minimum_required(VERSION 3.10)
project(CarProject)

set(CMAKE_CXX_STANDARD 17)

# Find and include SFML library components
find_package(SFML 2.5 COMPONENTS graphics window system REQUIRED)

# Add the main executable for the Car project
add_executable(CarProject src/main.cpp src/Car.cpp)
# Include directories for the Car project, including SFML and local include
target_include_directories(CarProject PRIVATE ${SFML_INCLUDE_DIRS} include)
# Link the necessary SFML libraries to the Car project
target_link_libraries(CarProject PRIVATE sfml-graphics sfml-window sfml-system)

# Add Google Test
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

# Add the test executable
add_executable(CarTests tests/test_car.cpp src/Car.cpp)
# Include directories for the CarTests executable
target_include_directories(CarTests PRIVATE include)
# Link the necessary libraries to the CarTests executable, including Google Test and SFML
target_link_libraries(CarTests PRIVATE GTest::GTest GTest::Main sfml-graphics sfml-window sfml-system)

# Enable testing
enable_testing()
add_test(NAME CarTests COMMAND CarTests)