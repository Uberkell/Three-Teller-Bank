#William Class - Class054
cmake_minimum_required(VERSION 3.24)
project(Project6_single_teller)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(Project6_three_teller_new
        project6.cpp PrecondViolatedExcep.cpp Event.cpp EventBuilder.cpp Statistics.cpp Simulation.cpp)
