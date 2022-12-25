# CMakeList.txt : CMake project for Algo_HW, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

project ("Algo_HW")

# Add source to this project's executable.
add_executable (Algo_HW "Algo_HW.cpp" "Algo_HW.h" "HW_03.cpp" "HW_03.h" "HW_06.cpp" "HW_06.h" "EXP_01.cpp" "EXP_01.h" "EXP_02.cpp" "EXP_02.h" "EXP_03.cpp" "EXP_03.h" "EXP_04.cpp" "EXP_04.h" "HW_04.cpp" "HW_04.h"  "EXP_05.h" "EXP_05.cpp")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET Algo_HW PROPERTY CXX_STANDARD 20)
endif()

# TODO: Add tests and install targets if needed.
