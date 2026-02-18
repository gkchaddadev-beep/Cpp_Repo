cmake_minimum_required(VERSION 3.12)

# Define the project name and language
project(MyCppProject VERSION 0.1.0 LANGUAGES CXX)

# Specify the C++ standard to use
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Add an executable target named "MyApp" from the source file
add_executable(MyApp main.cpp)
