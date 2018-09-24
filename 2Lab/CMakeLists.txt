cmake_minimum_required(VERSION 2.6)
 
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})
 

add_executable(executeTests CalcTest.cpp ArgsParser.cpp ExecValue.cpp InstructionFactory.cpp Instruction.cpp InputHandler.cpp run_time_exceptions.cpp StackCalc.cpp)
target_link_libraries(executeTests ${GTEST_LIBRARIES} pthread)