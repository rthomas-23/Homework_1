# CMakeList.txt : CMake project for AERSP424_Homework_1, include source and define
# project specific logic here.
#

# Add source to this project's executable.
add_executable (AERSP424_Homework_1 "AERSP424_Homework_1.cpp" "AERSP424_Homework_1.h" "Q1.cpp" "Q1.h" "Q2.cpp" "Q2.h" "Q3.cpp" "Q3.h" "Q4.cpp" "Q4.h" "Q5.cpp" "Q5.h" "Q6.h" "Q6.cpp" "Q7.cpp" "Q7.h" "Q8.cpp" "Q8.h" "Q9.cpp" "Q9.h")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET AERSP424_Homework_1 PROPERTY CXX_STANDARD 20)
endif()

# TODO: Add tests and install targets if needed.
