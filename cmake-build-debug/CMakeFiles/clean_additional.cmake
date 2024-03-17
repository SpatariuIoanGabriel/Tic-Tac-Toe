# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles/Tic-Tac-Toe1_autogen.dir/AutogenUsed.txt"
  "CMakeFiles/Tic-Tac-Toe1_autogen.dir/ParseCache.txt"
  "Tic-Tac-Toe1_autogen"
  )
endif()
