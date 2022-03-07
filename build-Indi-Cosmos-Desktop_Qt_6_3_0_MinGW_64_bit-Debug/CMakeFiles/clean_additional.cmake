# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\Indi-Cosmos_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\Indi-Cosmos_autogen.dir\\ParseCache.txt"
  "Indi-Cosmos_autogen"
  )
endif()
